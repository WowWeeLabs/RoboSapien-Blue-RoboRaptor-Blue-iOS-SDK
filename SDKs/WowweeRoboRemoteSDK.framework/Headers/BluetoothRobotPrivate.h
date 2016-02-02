//
//  Private.h
//  WowWeeMiPSDK
//
//  Created by Andy on 10/9/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>


#import "BluetoothRobot.h"
#import "YMSCBPeripheral.h"
#import "BluetoothRobotServices.h"
#import "MSWeakTimer.h"

#if defined(FIRMWARE_UPDATING_ENABLED) && FIRMWARE_UPDATING_ENABLED==1
#import "FirmwareUpdateProtocol.h"
#endif

static int ddLogLevel;

#define EnableSpecialCommands 1

@class FirmwareUpdateCommand;

typedef enum {
    kBluetoothRobotStateDisconnected = 0,
    kBluetoothRobotStateConnecting,
    kBluetoothRobotStateConnected,
    kBluetoothRobotStateDisconnecting,
} kBluetoothRobotState;


@protocol NuvotonBootloaderDelegate <NSObject>

@optional
- (void)bluetoothRobot:(id)sender didReceiveNuvotonBootloaderStatus:(NuvotonBootloaderMode)bootloaderMode;
- (void)bluetoothRobot:(id)sender didReceiveFirmwareDataStatus:(NuvotonFirmwareStatus)firmwareStatus;
- (void)bluetoothRobot:(id)sender didReceiveFirmwareCompleteStatus:(NuvotonFirmwareCompleteStatus)firmwareCompleteStatus;

@end

@interface BluetoothRobot()

@property (nonatomic, assign) bool processRobotCommands;
@property (nonatomic, assign) bool firmwareUpdateMode;

@property (nonatomic, strong) NSString *bleSystemId;
@property (nonatomic, strong) NSString *bleModuleSoftwareVersion;

@property (nonatomic, assign) bool debugLogging;
@property (nonatomic, strong, readonly) YMSCBPeripheral *ymsPeripheral;

@property (nonatomic, assign) kBluetoothRobotState state;

@property (nonatomic, strong) NSMutableArray *servicesReady;
@property (nonatomic, strong) dispatch_queue_t privateQueue;
#if defined(FIRMWARE_UPDATING_ENABLED) && FIRMWARE_UPDATING_ENABLED == 1
@property (nonatomic, strong, readonly) FirmwareUpdateProtocol *firmwareUpdateProtocol;
#endif
@property (nonatomic, assign) NSUInteger productId;

@property (nonatomic, strong) NSMutableDictionary *customBroadcastData;

@property (nonatomic, strong) MSWeakTimer *connectTimeout;
@property (nonatomic, strong) MSWeakTimer *reconnectTimer;
@property (nonatomic, assign) int connectAttempts;

@property (nonatomic, assign) NSTimeInterval connectTimeoutSeconds;

// Nordic DFU bootloader
@property (nonatomic, readonly) BOOL isDFUSupported;
@property (nonatomic, assign) BOOL isDFUMode;

// Nuvoton bootloader
@property (nonatomic, strong) id<NuvotonBootloaderDelegate> nuvotonBootloaderDelegate;

+ (NSArray *) getAdvertisedServiceUUIDs;

- (id) initWithPeripheral:(YMSCBPeripheral *)peripheral advertisingData:(NSDictionary *)advertisingData;

- (NSUUID *) uuid;

- (void)discoverCharacteristicForService:(YMSCBService *)service withCallback:(void (^)(NSError *))callback;
- (void)serviceReady:(NSString *)serviceName callback:(void (^)(NSError *))callback;

- (id) findService:(NSString *)serviceName;

- (void) resetConnectTimeout;
    
/** Peripheral Commands **/
-(void) peripheralFailedToConnectWithError:(NSError *)error;
-(void) peripheralDidConnect;
-(void) peripheralDidDisconnectWithError:(NSError *)error;
-(void) peripheralDidBecomeReady;
-(void) peripheralDidTryReconnect;

-(void)enableBluetoothRssiUpdateWithSampleInterval:(int)interval;
-(void)disableBluetoothRssiUpdate;
-(bool)isBluetoothRssiUpdatesEnabled;
-(void)setBluetoothRssiSampleIntervalMS:(int16_t)value;
-(void)getBluetoothRssiSampleIntervalMS;
-(void)getBluetoothRssiReading;

-(void)enableBluetoothBatteryLevelUpdates;
-(void)disableBluetoothBatteryLevelUpdates;
-(bool)isBluetoothBatteryLevelUpdatesEnabled;
-(void)getBluetoothBatteryLevel;

-(void)getBluetoothModuleSoftwareVersion;
-(void)getBluetoothModuleSystemID;

-(void)setBluetoothCommunicationInterval:(kModuleParameterBTCommunicationIntervalValues)value;
-(void)getBluetoothCommunicationInterval;

-(void)getBluetoothUARTBuardRate;
-(void)setBluetoothUARTBuardRate:(kModuleParameterUARTBaudRateValues)value;

-(void)getBluetoothDeviceName;
-(void)setBluetoothDeviceName:(NSString *)newName;

-(void)setBroadcastPeriod:(kModuleParameter_BroadcastPeriodValues)period;
-(void)getBroadcastPeriod;
-(void)setProductIdentifier:(uint16_t)productIdentifier;
-(void)getProductIdentifier;
-(void)setTransmitPower:(kMipModuleParameter_TransmitPowerValues)transmitPower;
-(void)getTransmitPower;
-(void)setBroadcastData:(NSDictionary *)broadcastData;
-(void)setBroadcastDataToDefault;
-(void)getBroadcastData;
-(void)forceModuleSleep;
-(void)saveCurrentIOOutputInputState;
-(void)setStandbyPulsedSleepMode:(bool)pulsedSleep;
-(void)getStandbyPulsedSleepMode;
-(void)setConnectedBroadcastData:(NSData *)data;
-(void)setConnectedBroadcastOn:(BOOL)isOn;

// Available in 2.3u
-(void)setBluetoothConnectionTimeout;
-(void)getBluetoothConnectionTimeout;
-(void)saveBroadcastDataFlash;

/** PWM Functions **/
-(void)setBluetoothPwmAllOutputChannel1Power:(kPwmOutputPowerValue)channel1power channel2power:(kPwmOutputPowerValue)channel2power channel3power:(kPwmOutputPowerValue)channel3power channel4power:(kPwmOutputPowerValue)channel4power;
-(void)readBluetoothPwmChannelPowerOutput;

-(void)setBluetoothPwmChannelOutputFrequency:(float)pwmFrequency;
-(void)readBluetoothPwmChannelOutputFrequency;
-(void)setBluetoothPwmInitialOutputPower:(kPwmInitialStateValues)initialState;
-(void)readBluetoothPwmInitialOutputPower;
-(void)setBluetoothPwmTransitionTiming:(NSUInteger)transitionTimingInMilliseconds;
-(void)readBluetoothPwmInitialOutputPowerTransitionTiming;

/** Pin IO Functions **/
-(void)readBluetoothIOPinStates;
-(void)setBluetoothIOPinStates:(kMipProgrammableIOStateValue)io0 io1:(kMipProgrammableIOStateValue)io1 io2:(kMipProgrammableIOStateValue)io2 io3:(kMipProgrammableIOStateValue)io3 io4:(kMipProgrammableIOStateValue)io4 io5:(kMipProgrammableIOStateValue)io5 io6:(kMipProgrammableIOStateValue)io6 io7:(kMipProgrammableIOStateValue)io7;
-(void)readBluetoothIOPinModes;
-(void)setBluetoothIOPinModes:(kMipProgrammableIOModeValue)io0 io1:(kMipProgrammableIOModeValue)io1 io2:(kMipProgrammableIOModeValue)io2 io3:(kMipProgrammableIOModeValue)io3 io4:(kMipProgrammableIOModeValue)io4 io5:(kMipProgrammableIOModeValue)io5 io6:(kMipProgrammableIOModeValue)io6 io7:(kMipProgrammableIOModeValue)io7;

/** ADC Input Reading Functions **/
- (void) setBluetoothAdcChannelEnabledDisabled:(bool)channel0 channel1:(bool)channel1;
- (void) readBluetoothAdcChannelEnabledDisabled;
- (void) readBluetoothAdcChannelValue:(kBluetoothRobotAdcInputChannel)channel;
- (void) setBluetoothAdcSamplePeriod:(uint16_t)samplePeriod;
- (void) readBluetoothAdcSamplePeriod;
- (void) enableBluetoothAdcChannel0Updates;
- (void) disableBluetoothAdcChannel0Updates;
- (void) enableBluetoothAdcChannel1Updates;
- (void) disableBluetoothAdcChannel1Updates;
- (void) getBluetoothInitialAdcValues;

/** Module Param Functions **/
-(void)restartBluetoothDevice;
-(void)factoryResetBluetoothDevice:(bool)userDataOnly;
-(void) didReceiveModuleDeviceName:(NSString *)deviceName;

/** Command Sending Functions **/
-(void)_processRobotCommand:(RobotCommand *)robotCommand;

-(void)sendRobotCommand:(RobotCommand *)robotCommand;
-(void)sendRobotCommand:(RobotCommand *)robotCommand callback:(void (^)(NSError *))callback;
-(void)sendRawCommandData:(NSData *)data withCallback:(void (^)(NSError *))callback;

#if defined(FIRMWARE_UPDATING_ENABLED)
-(void) sendFirmwareCommand:(FirmwareUpdateCommand *)command withCallback:(void (^)(NSError *))callback;
#endif

-(void) didReceiveModuleUARTBuadRate:(kModuleParameterUARTBaudRateValues)rate;

#if defined(FIRMWARE_UPDATING_ENABLED) && FIRMWARE_UPDATING_ENABLED == 1
/** Firmware uploading functions **/
-(void) firmwareUploadFromFilePath:(NSURL *)filePath firmwareDate:(NSDate *)firmwareDate firmwareRevision:(uint8_t)firmwareRevision withSuccessCallback:(void (^)(void))sucessCallback withErrorCallback:(void (^)(NSError *error))errorCallback withProgressCallback:(firmwareUploadProgressCallback)progressCallback;
-(void) firmwareUploadFromFilePath:(NSURL *)filePath firmwareDate:(NSDate *)firmwareDate firmwareRevision:(uint8_t) firmwareRevision flashFilePath:(NSURL *)flashPath withSuccessCallback:(void (^)(void))sucessCallback withErrorCallback:(void (^)(NSError *error))errorCallback withProgressCallback:(firmwareUploadProgressCallback)progressCallback;
-(void) firmwareUploadFromFilePath:(NSURL *)filePath firmwareDate:(NSDate *)firmwareDate firmwareRevision:(uint8_t) firmwareRevision flashData:(NSData *)flashData withSuccessCallback:(void (^)(void))sucessCallback withErrorCallback:(void (^)(NSError *error))errorCallback withProgressCallback:(firmwareUploadProgressCallback)progressCallback;
-(void) cancelFirmwareUpdate;
#endif

// Nordic DFU Service
- (void)nordicRebootToMode:(uint8_t)mode;

// Settings Service
- (void) readActivationStatus;
- (void) setActivationStatus:(uint8_t)status;

#pragma mark - Nuvoton Firmware Update
- (void) readNuvotonChipStatus;
- (void) readFirmwareDataStatus;
- (void) restartNuvotonChipToMode:(NuvotonBootloaderMode)mode;
- (void) stopTransfer;
- (void) writeFirmwareToNuvoton;
- (void)sendFirmwareDataToCache:(NSData *)data
   withAppToBleProgressCallback:(void (^)(int sentByte))appToBleProgressCallback
   bleToNuvotonProgressCallback:(void (^)(int sentByte))bleToNuvotonProgressCallback;

@end
