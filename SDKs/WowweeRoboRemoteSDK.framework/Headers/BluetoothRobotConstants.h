//
//  MipBluetoothConstants.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  This file is updated for BT Chip Version 2.1
//  Copyright (c) 2013 Andy. All rights reserved.
//
#import <Foundation/Foundation.h>

@import Foundation;

#ifndef MipBluetoothChip_h
#define MipBluetoothChip_h

#define MipBluetoothChipVersion 210 // This protocal is setup for this version

// Bug fixing
#define FIX_GATT_WRITEWITHOUTRESPONSE_BUG 1 // https://devforums.apple.com/message/878122#878122
#define FIX_BOBI_CONNECT_BUG 1 // 1 to change connect miposaur falldown/getup values
#define FIX_BOBI_BATTERY_BUG 1 // 1 to use alternative battery values

#define kMipMip_BASE_ADDRESS_HI 0x0000000000000000
#define kMipMip_BASE_ADDRESS_LO 0x0000000000000000

//=================  TransmitMoudel =====================
// TransmitMoudel Receive Data Service UUID
#define kMipReceiveDataServiceString "recieveData"
#define kMipReceiveDataServiceUUID                                               0xFFE0
#define kMipReceiveDataCharateristicString                                       "receiveData"
#define kMipReceiveDataCharateristicUUID                                         0xFFE4

// TransmitMoudel Send Data Service UUID
#define kMipSendDataServiceString "sendData"
#define kMipSendDataServiceUUID                                                  0xFFE5
#define kMipSendBytesDataCharateristicString                                     "sendData"
#define kMipSendBytesDataCharateristicUUID                                       0xFFE9

// Programmable Pin IO (8 channels) Pin Services
#define KMipProgrammableIOServiceString                                          "pinHighLowIO"
#define KMipProgrammableIOServiceUUID                                            0xFFF0
#define KMipProgrammableIOCharacteristic_ConfigurePinString                      "configureIOPin"
#define KMipProgrammableIOCharacteristic_ConfigurePinUUID                        0xFFF1
#define KMipProgrammableIOCharacteristic_SetPinString                            "setIOPinValue"
#define KMipProgrammableIOCharacteristic_SetPinUUID                              0xFFF2
#define KMipProgrammableIOCharacteristic_ReadOrNotifyPinString                   "readIOPinValue"
#define KMipProgrammableIOCharacteristic_ReadOrNotifyPinUUID                     0xFFF3

// Timing turnover output (2 channel) Services
#define KMipPinTimingTurnoverOutputServiceString                                 "pinTimingTurnoverOutput"
#define KMipPinTimingTurnoverOutputServiceUUID                                   0xFFF0
// IO6 & 7 are output channels
#define KMipPinTimingTurnoverIO6Characteristic_SetOrReadTurnoverTime1String      "setOrReadPinTimingTurnoverIO6_turnover1"
#define KMipPinTimingTurnoverIO6Characteristic_SetOrReadTurnoverTime1UUID           0xFFF4
#define KMipPinTimingTurnoverIO6Characteristic_SetOrReadTurnoverTime2String      "setOrReadPinTimingTurnoverIO6_turnover2"
#define KMipPinTimingTurnoverIO6Characteristic_SetOrReadTurnoverTime2UUID        0xFFF5
#define KMipPinTimingTurnoverIO7Characteristic_SetOrReadTurnoverTime1String      "setOrReadPinTimingTurnoverIO7_turnover1"
#define KMipPinTimingTurnoverIO7Characteristic_SetOrReadTurnoverTime1UUID        0xFFF6
#define KMipPinTimingTurnoverIO7Characteristic_SetOrReadTurnoverTime2String      "setOrReadPinTimingTurnoverIO7_turnover2"
#define KMipPinTimingTurnoverIO7Characteristic_SetOrReadTurnoverTime2UUID        0xFFF7
// IO4 & 5 are input channels
#define KMipPinTimingTurnoverIO4Characteristic_ReadorNotifyTurnoverTime1String   "readOrNotifyPinTimingTurnoverIO4"
#define KMipPinTimingTurnoverIO4Characteristic_ReadorNotifyTurnoverTime1UUID     0xFFF8
#define KMipPinTimingTurnoverIO5Characteristic_ReadorNotifyTurnoverTime2String   "readOrNotifyPinTimingTurnoverIO5"
#define KMipPinTimingTurnoverIO5Characteristic_ReadorNotifyTurnoverTime2UUID     0xFFF9

// PWM output
#define KMipPwmOutputServiceString                                               "pinPwmOutput"
#define KMipPwmOutputServiceUUID                                                 0xFFB0
#define KMipPwmCharacteristic_SetOrReadInitalStateString                         "setOrReadPwmInitialPower"
#define KMipPwmCharacteristic_SetOrReadInitalStateUUID                           0xFFB1
#define KMipPwmCharacteristic_SetOrReadWavePowerString                           "setOrReadPwmPower"
#define KMipPwmCharacteristic_SetOrReadWavePowerUUID                             0xFFB2
#define KMipPwmCharacteristic_SetOrReadWaveFrequencyString                       "setOrReadPwmFrequency"
#define KMipPwmCharacteristic_SetOrReadWaveFrequencyUUID                         0xFFB3
#define KMipPwmCharacteristic_SetOrReadTransitionTimeString                      "setOrReadPwmTransitionTime"
#define KMipPwmCharacteristic_SetOrReadTransitionTimeUUID                        0xFFB4

typedef NS_OPTIONS(uint8_t, kPwmInitialStateValues) {
    kPwmInitialStateFullPower = 0x01,
    kPwmInitialStateAllOff = 0x00,
    kPwmInitialStateUseCurrentStateAndSuspendSleep = 0x02
};

// ADC Input (2 channels)
#define KMipADCInputServiceString                                                "pinADCInput"
#define KMipADCInputServiceUUID                                                  0xFFD0
#define KMipADCInputCharacteristic_SetOrReadEnableDisableString                  "setOrReadADC_EnabledDisabled"
#define KMipADCInputCharacteristic_SetOrReadEnableDisableUUID                    0xFFD1
#define KMipADCInputCharacteristic_SetOrReadSamplingPeriodString                 "setOrReadADC_SamplePeriod"
#define KMipADCInputCharacteristic_SetOrReadSamplingPeriodUUID                   0xFFD2
#define KMipADCInputCharacteristic_ReadOrNotifyADC0SampleValueString             "readOrNotifyADC0_SampleValue"
#define KMipADCInputCharacteristic_ReadOrNotifyADC0SampleValueUUID               0xFFD3
#define KMipADCInputCharacteristic_ReadOrNotifyADC1SampleValueString             "readOrNotifyADC1_SampleValue"
#define KMipADCInputCharacteristic_ReadOrNotifyADC1SampleValueUUID               0xFFD4

// Anti Hijacking
#define kMipAntiHijackingServiceString                                           "antiHijacking"
#define kMipAntiHijackingServiceUUID                                             0xFFC0
#define kMipAntiHijackingCharateristic_SetOrChangeSecurityPasswordString         "setPassword"
#define kMipAntiHijackingCharateristic_SetOrChangeSecurityPasswordUUID           0xFFC1
#define kMipAntiHijackingCharateristic_ReceiveSecurityInfoString                 "securityInfo"
#define kMipAntiHijackingCharateristic_ReceiveSecurityInfoUUID                   0xFFC2

// Battery Level Service
#define kMipBatteryLevelServiceString                                            "batteryLevel"
#define kMipBatteryLevelServiceUUID                                              0x180F
#define kMipBatteryLevelReportCharacteristicString                               "batteryLevelReport"
#define kMipBatteryLevelReportCharacteristicUUID                                 0x2A19

#define kMipRSSIReportServiceString                                              "rssiReport"
#define kMipRSSIReportServiceUUID                                                0xFFA0
#define kMipRSSIReportReadChracteristicString                                    "rssiLevel"
#define kMipRSSIReportReadChracteristicUUID                                      0xFFA1
#define kMipRSSIReportSetIntervalChracteristicString                             "setRssiNotification"
#define kMipRSSIReportSetIntervalChracteristicUUID                               0xFFA2

#define kMipModuleParametersServiceString                                        "moduleParams"
#define kMipModuleParametersServiceUUID                                          0xFF90
#define kMipModuleParameterDeviceNameCharacteristicString                        "deviceName"
#define kMipModuleParameterDeviceNameCharacteristicUUID                          0xFF91
#define kMipModuleParameterBTCommunicationIntervalCharacteristicString           "btCommInterval"
#define kMipModuleParameterBTCommunicationIntervalCharacteristicUUID             0xFF92
typedef enum {
    kModuleParameterBTCommunicationInterval20ms = 0,
    kModuleParameterBTCommunicationInterval50ms = 1,
    kModuleParameterBTCommunicationInterval100ms = 2,
    kModuleParameterBTCommunicationInterval200ms = 3,
    kModuleParameterBTCommunicationInterval300ms = 4,
    kModuleParameterBTCommunicationInterval400ms = 5,
    kModuleParameterBTCommunicationInterval500ms = 6,
    kModuleParameterBTCommunicationInterval1000ms = 7,
    kModuleParameterBTCommunicationInterval2000ms = 8,
} kModuleParameterBTCommunicationIntervalValues;
#define kMipModuleParameterUARTBaudRateCharacteristicString                      "uartBaudRate"
#define kMipModuleParameterUARTBaudRateCharacteristicUUID                        0xFF93
typedef enum {
    kModuleParameterUARTBaudRate4800 = 0,
    kModuleParameterUARTBaudRate9600 = 1,
    kModuleParameterUARTBaudRate19200 = 2,
    kModuleParameterUARTBaudRate38400 = 3,
    kModuleParameterUARTBaudRate57600 = 4,
    kModuleParameterUARTBaudRate115200 = 5
} kModuleParameterUARTBaudRateValues;
#define kMipModuleParameterResetModuleCharacteristicString                       "resetModule"
#define kMipModuleParameterResetModuleCharacteristicUUID                         0xFF94
typedef enum {
    kModuleParameter_ResetModuleRestoreFactorySettings = 0x36, // Only available in version >= 2.1
    kModuleParameter_ResetModuleResetUserData = 0x35, // Only available in version >= 2.1
    kModuleParameter_RestartModule = 0x55,
} kModuleParameterValues;
#define kMipModuleParameterBroadcastPeriodCharacteristicString                   "setOrReadBroadcastPeriod"
#define kMipModuleParameterBroadcastPeriodCharacteristicUUID                     0xFF95
typedef enum : uint8_t {
    kModuleParameter_BroadcastPeriod200MS = 0,
    kModuleParameter_BroadcastPeriod500MS = 1,
    kModuleParameter_BroadcastPeriod1000MS = 2,
    kModuleParameter_BroadcastPeriod1500MS = 3,
    kModuleParameter_BroadcastPeriod2000MS = 4,
    kModuleParameter_BroadcastPeriod2500MS = 5,
    kModuleParameter_BroadcastPeriod3000MS = 6,
    kModuleParameter_BroadcastPeriod4000MS = 7,
    kModuleParameter_BroadcastPeriod5000MS = 8,
} kModuleParameter_BroadcastPeriodValues;
#define kMipModuleParameterProductIDCharacteristicString                         "setOrReadProductID"
#define kMipModuleParameterProductIDCharacteristicUUID                           0xFF96
#define kMipModuleParameterTransmitPowerCharacteristicString                     "setOrReadTransmitPower"
#define kMipModuleParameterTransmitPowerCharacteristicUUID                       0xFF97
typedef enum : uint8_t {
    kMipModuleParameter_TransmitPower_Plus4dBm = 0,
    kMipModuleParameter_TransmitPower_0dBm = 1,
    kMipModuleParameter_TransmitPower_Minus6dBm = 2,
    kMipModuleParameter_TransmitPower_Minus23dBm = 3,
} kMipModuleParameter_TransmitPowerValues;
#define kMipModuleParameterCustomBroadcastDataCharacteristicString               "setOrReadCustomBroadcastData"
#define kMipModuleParameterCustomBroadcastDataCharacteristicUUID                 0xFF98
#define kMipModuleParameterRemoteControlExtensionCharacteristicString            "setRemoteControlExtension"
#define kMipModuleParameterRemoteControlExtensionCharacteristicUUID              0xFF99
typedef enum : uint8_t {
    kMipModuleParameter_RemoteControlExtension_SaveIOState = 0x01,
    kMipModuleParameter_RemoteControlExtension_ForceSleepMode = 0x02,
    kMipModuleParameter_RemoteControlExtension_DisconnectBluetoothClient = 0x03,
    kMipModuleParameter_RemoteControlExtension_WriteCustomBroadcastDataToFlash = 0x04
} kMipModuleParameter_RemoteControlExtensionValues;
#define kMipModuleParameterStandbyModeCharacteristicString                       "readOrWriteStandbyMode"
#define kMipModuleParameterStandbyModeCharacteristicUUID                         0xFF9A
#define kMipModuleParameterSetConnectedBroadcastDataCharacteristicString         "setConnectedBroadcastData"
#define kMipModuleParameterSetConnectedBroadcastDataCharacteristicUUID           0xFF9B
#define kMipModuleParameterSetConnectedBroadcastOnOffCharacteristicString        "setConnectedBroadcastOnOff"
#define kMipModuleParameterSetConnectedBroadcastOnOffCharacteristicUUID          0xFF9C

// Device Information Service
#define kMipDeviceInformationServiceString                                       "deviceInfo"
#define kMipDeviceInformationServiceUUID                                         0x180A
#define kMipDeviceInformationSystemIDCharacteristicString                        "systemId"
#define kMipDeviceInformationSystemIDCharacteristicUUID                          0x2A23
#define kMipDeviceInformationModuleSoftwareVerCharacteristicString               "softwareVersion"
#define kMipDeviceInformationModuleSoftwareVerCharacteristicUUID                 0x2A26

// DFU Service
#define kDeviceDFUServiceString                                                  "dfu"
#define kDeviceDFUServiceUUID                                                    0xFF30
#define kDeviceDFUCharacteristicString                                           "dfuchar"
#define kDeviceDFUCharacteristicUUID                                             0xFF31

typedef enum : uint8_t {
    kDeviceApplicationMode = 0x01,
    kDeviceDFUMode = 0x02,
} kDFURebootMode;

// Port timed event Service
#define kMipPortTimedEventServiceString                                         "portTimedEvent"
#define kMipPortTimedEventServiceUUID                                           0xFE00
#define kMipPortTimedEvent_SetOrReadRealTimeClockCharacteristicString           "setRealTimeclock"
#define kMipPortTimedEvent_SetOrReadRealTimeClockCharacteristicUUID             0xFE01
// Value range: Seconds: 0 to 59; min: 0 to 59;: 0 to 23; Days: 1 to 31; month: 1 to 12; year: 2000 or more
//The default time is at 0:00:00 on January 1, 2000

#define kMipPortTimedEvent_SetOrReadEventIndexChannelCharacteristicString       "setOrReadEventIndexChannelForReading" // used for FE03
#define kMipPortTimedEvent_SetOrReadEventIndexChannelCharacteristicUUID         0xFE02
#define kMipPortTimedEvent_SetOrReadEventByEventIndexCharacteristicString       "setOrReadEventByEventIndex"
#define kMipPortTimedEvent_SetOrReadEventByEventIndexCharacteristicUUID         0xFE03

#define kMipPortTimedEvent_SetOrReadPortIndexChannelCharacteristicString        "setOrReadPortIndexChannelForReading" // used for FE05,
#define kMipPortTimedEvent_SetOrReadPortIndexChannelCharacteristicUUID          0xFE04
typedef enum : uint8_t {
    kPortTimedEvent_EventIOPortValue_IO0 = 0x00,
    kPortTimedEvent_EventIOPortValue_IO1 = 0x01,
    kPortTimedEvent_EventIOPortValue_IO2 = 0x02,
    kPortTimedEvent_EventIOPortValue_IO3 = 0x03,
    kPortTimedEvent_EventIOPortValue_IO4 = 0x04,
    kPortTimedEvent_EventIOPortValue_IO5 = 0x05,
    kPortTimedEvent_EventIOPortValue_PWM0 = 0x06,
    kPortTimedEvent_EventIOPortValue_PWM1 = 0x07,
    kPortTimedEvent_EventIOPortValue_PWM2 = 0x08,
    kPortTimedEvent_EventIOPortValue_PWM3 = 0x09,
} kPortTimedEvent_EventIOPortValue;
// kPortTimedEvent_EventPortValue
typedef enum : uint8_t {
    kPortTimedEvent_EventAction_NoAction = 0x00,
    kPortTimedEvent_EventAction_IOLow = 0x01,
    kPortTimedEvent_EventAction_IOHigh = 0x02,
    kPortTimedEvent_EventAction_IOToggle = 0x03,
    kPortTimedEvent_EventAction_PwmPower = 0x04,
    kPortTimedEvent_EventAction_PwmTransitionTime = 0x05,
} kPortTimedEvent_EventActionValue;

#define kMipPortTimedEvent_SetOrReadEventByPortIndexCharacteristicString        "setOrReadEventByPortIndex"
#define kMipPortTimedEvent_SetOrReadEventByPortIndexCharacteristicUUID          0xFE05
// kPortTimedEvent_EventPortValue
#define kMipPortTimedEvent_SetOrReadEventPortConfigurationCharacteristicString  "setOrReadEventPortConfiguration"
#define kMipPortTimedEvent_SetOrReadEventPortConfigurationCharacteristicUUID    0xFE06
// Byte 0 Values
typedef enum : uint8_t {
    kPortTimedEvent_ConfigurationPortValueByte0_EventOn = 0x00,
    kPortTimedEvent_ConfigurationPortValueByte0_EventOff = 0x01,
} kPortTimedEvent_ConfigurationPortByte0Value;
// Byte1 Values
typedef enum : uint8_t {
    kPortTimedEvent_ConfigurationPortValueByte1_TimingAlwaysEnabled = 0x00,
    kPortTimedEvent_ConfigurationPortValueByte1_IO0 = 0x01,
    kPortTimedEvent_ConfigurationPortValueByte1_IO1 = 0x02,
    kPortTimedEvent_ConfigurationPortValueByte1_IO2 = 0x03,
    kPortTimedEvent_ConfigurationPortValueByte1_IO3 = 0x04,
    kPortTimedEvent_ConfigurationPortValueByte1_IO4 = 0x05,
    kPortTimedEvent_ConfigurationPortValueByte1_IO5 = 0x06,
    kPortTimedEvent_ConfigurationPortValueByte2_PWM0 = 0x07,
} kPortTimedEvent_ConfigurationPortByte1Value;
// Byte2 Values
typedef enum : uint8_t {
    kPortTimedEvent_ConfigurationPortValueByte2_PWM1 = 0x00,
    kPortTimedEvent_ConfigurationPortValueByte2_PWM2 = 0x01,
    kPortTimedEvent_ConfigurationPortValueByte2_PWM3 = 0x02,
    kPortTimedEvent_ConfigurationPortValueByte2_ClearAllEvents = 0x03,
    kPortTimedEvent_ConfigurationPortValueByte2_ClearAllEventResponses = 0x04,
} kPortTimedEvent_ConfigurationPortByte2Value;


typedef enum {
    kAntiHijackingReceiveSecurityInfo_PasswordRight = 0,
    kAntiHijackingReceiveSecurityInfo_PasswordError = 1,
    kAntiHijackingReceiveSecurityInfo_PasswordUpdated = 2,
    kAntiHijackingReceiveSecurityInfo_PasswordCancelled = 3
} kAntiHijackingReceiveSecurityInfoValues;

typedef enum {
    kPwmOutputChannel1 = 1,
    kPwmOutputChannel2,
    kPwmOutputChannel3,
    kPwmOutputChannel4,
} kPwmOutputChannelValue;

typedef enum : uint64_t {
    kPwmOutputSpecialValueAllOff = 0xFFFFFFFF,
    kPwmOutputSpecialValueAllFullPower = 0x20202020,
} kPwmOutputSpecialValues;

typedef enum : uint8_t {
    kPwmOutputPowerOff = 0,
    kPwmOutputPower10Percent = 10/255,
    kPwmOutputPower20Percent = 20/255,
    kPwmOutputPower30Percent = 30/255,
    kPwmOutputPower40Percent = 40/255,
    kPwmOutputPower50Percent = 50/255,
    kPwmOutputPower60Percent = 60/255,
    kPwmOutputPower70Percent = 70/255,
    kPwmOutputPower80Percent = 80/255,
    kPwmOutputPower90Percent = 90/255,
    kPwmOutputPower100Percent  = 255
} kPwmOutputPowerValue;

// Nuvoton bootloader service
// Note: Only implemented in Nordic Chips, not in older Ti Chips
#define kDeviceNuvotonBootloaderServiceString                                         "nuvotonBootloader"
#define kDeviceNuvotonBootloaderServiceUUID                                           0xFF00
#define kDeviceNuvotonBootloader_GetChipStatusCharacteristicString                    "getChipStatus"
#define kDeviceNuvotonBootloader_GetChipStatusCharacteristicUUID                      0xFF01
#define kDeviceNuvotonBootloader_RestartChipCharacteristicString                      "restartChip"
#define kDeviceNuvotonBootloader_RestartChipCharacteristicUUID                        0xFF02
#define kDeviceNuvotonBootloader_TransferFirmwareHeaderCharacteristicString           "headerData"
#define kDeviceNuvotonBootloader_TransferFirmwareHeaderCharacteristicUUID             0xFF03
#define kDeviceNuvotonBootloader_StopTransferCharacteristicString                     "stoptransfer"
#define kDeviceNuvotonBootloader_StopTransferCharacteristicUUID                       0xFF04
#define kDeviceNuvotonBootloader_TransferFirmwareStatusCharacteristicString           "transferFirmwareStatus"
#define kDeviceNuvotonBootloader_TransferFirmwareStatusCharacteristicUUID             0xFF05
#define kDeviceNuvotonBootloader_ReadFirmwareDataStatusCharacteristicString           "readFirmwareDataStatus"
#define kDeviceNuvotonBootloader_ReadFirmwareDataStatusCharacteristicUUID             0xFF06
#define kDeviceNuvotonBootloader_WriteFirmwareToNuvotonCharacteristicString           "writeFirmwareToNuvoton"
#define kDeviceNuvotonBootloader_WriteFirmwareToNuvotonCharacteristicUUID             0xFF07
#define kDeviceNuvotonBootloader_FirmwareWriteCompleteCharacteristicString            "firmwareWriteComplete"
#define kDeviceNuvotonBootloader_FirmwareWriteCompleteCharacteristicUUID              0xFF08
#define kDeviceNuvotonBootloader_TransferFirmwareDataCharacteristicString             "transferData"
#define kDeviceNuvotonBootloader_TransferFirmwareDataCharacteristicUUID               0xFF09
#define kDeviceNuvotonBootloader_WriteFirmwareToNuvotonProgressCharacteristicString   "firmwareToNuvotonProgress"
#define kDeviceNuvotonBootloader_WriteFirmwareToNuvotonProgressCharacteristicUUID     0xFF0A

typedef enum : uint8_t {
    kNuvotonAppMode = 0x00,
    kNuvotonBootloaderMode = 0x01,
} NuvotonBootloaderMode;

typedef enum : uint8_t {
    kNuvotonFirmwareStatus_DataOK = 0x00,
    kNuvotonFirmwareStatus_BadChecksum = 0x01,
    kNuvotonFirmwareStatus_BadData = 0x02,
    kNuvotonFirmwareStatus_DataEmpty = 0x03,
    kNuvotonFirmwareStatus_NextPacket = 0x04,
    kNuvotonFirmwareStatus_HeaderOK = 0x05,
} NuvotonFirmwareStatus;

typedef enum : uint8_t {
    kNuvotonFirmwareCompleteStatus_Success = 0x00,
    kNuvotonFirmwareCompleteStatus_BadFirmwareData,
    kNuvotonFirmwareCompleteStatus_UpdateFailure,
} NuvotonFirmwareCompleteStatus;

// Settings service
// Up to May 2015 only implemented in REV / RS Blue / RR Blue / Snappets
#define kDeviceSettingsServiceString                                         "settingsService"
#define kDeviceSettingsServiceUUID                                           0xFF10
#define kDeviceSettings_ActivationStatusCharacteristicString                 "activationStatus"
#define kDeviceSettings_ActivationStatusCharacteristicUUID                   0xFF1B

#endif
