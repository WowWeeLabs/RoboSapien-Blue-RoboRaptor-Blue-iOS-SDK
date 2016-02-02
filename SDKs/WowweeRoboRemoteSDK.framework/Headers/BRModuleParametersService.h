//
//  MIPModuleParametersService.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef moduleParamsKVOContext
#define moduleParamsKVOContext "moduleParams"
#endif
// KeyPaths
FOUNDATION_EXPORT NSString *const deviceNameKeyPathKVO;
FOUNDATION_EXPORT NSString *const btCommIntervalKeyPathKVO;
FOUNDATION_EXPORT NSString *const uartBaudRateKeyPathKVO;
FOUNDATION_EXPORT NSString *const productIdKeyPathKVO;
FOUNDATION_EXPORT NSString *const broadcastPeriodKeyPathKVO;
FOUNDATION_EXPORT NSString *const transmitPowerKeyPathKVO;
FOUNDATION_EXPORT NSString *const customBroadcastDataKeyPathKVO;
FOUNDATION_EXPORT NSString *const pulseSleepModeKeyPathKVO;

@interface BRModuleParametersService : BRBaseService

@property (nonatomic, strong) NSString *deviceName;
@property (nonatomic, assign) kModuleParameterBTCommunicationIntervalValues btCommInterval;
@property (nonatomic, assign) kModuleParameterUARTBaudRateValues moduleUartBaudRate;
@property (nonatomic, assign) kModuleParameter_BroadcastPeriodValues btBroadcastPeriod;
@property (nonatomic, assign) NSUInteger productId;
@property (nonatomic, assign) kMipModuleParameter_TransmitPowerValues moduleTransmitPower;
@property (nonatomic, strong) NSDictionary *customBroadcastData;
@property (nonatomic, assign) bool pulseSleepMode;

- (void) readBTDeviceName;
- (void) setBTDeviceName:(NSString *)deviceName;
- (void) readBTCommunicationInterval;
- (void) setBTCommunicationInterval:(kModuleParameterBTCommunicationIntervalValues)value;
- (void) readUartBaudRate;
- (void) setUartBuadRate:(kModuleParameterUARTBaudRateValues)value;
- (void) restartModule;
- (void) restoreUserDataToFactorySettings;
- (void) restoreFullyFactorySettings;
- (void) setBroadcastPeriod:(kModuleParameter_BroadcastPeriodValues)period;
- (void) readBroadcastPeriod;
- (void) setProductIdentifier:(uint16_t)productIdentifier;
- (void) readProductIdentifier;
- (void) setTransmitPower:(kMipModuleParameter_TransmitPowerValues)transmitPower;
- (void) readTransmitPower;
- (void) setBroadcastDataToDefault;
- (void) setBroadcastData:(NSDictionary *)broadcastData;
- (void) readBroadcastData;
- (void) forceModuleSleep;
- (void) saveCurrentIOOutputInputState;
- (void) setStandbyPulsedSleepMode:(bool)pulsedSleep;
- (void) readStandbyPulsedSleepMode;
- (void) setConnectedBroadcastData:(NSData *)data;
- (void) setConnectedBroadcastOn:(BOOL)isOn;

// Available in 2.3u
- (void) writeCurrentCustomBroadcastDataToFlash;
- (void) disconnectCurrentBluetoothClient;

@end
