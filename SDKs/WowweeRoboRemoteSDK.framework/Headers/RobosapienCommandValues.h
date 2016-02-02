//
//  RobosapienCommandValues.h
//  BluetoothRobotControlLibrary
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2014 WowWee Group Limited. All rights reserved.
//

@import Foundation;

FOUNDATION_EXPORT NSUInteger const ROBOSAPIEN_BLUETOOTH_PRODUCT_ID;
FOUNDATION_EXPORT NSUInteger const ROBOSAPIEN_BLUETOOTH_DFU_PRODUCT_ID;
FOUNDATION_EXPORT NSString *const ROBOSAPIEN_BLUETOOTH_CUSTOM_DATA_IDENTIFIER;

typedef NS_OPTIONS(uint8_t, kRobosapienCommand) {
    kRobosapienSetIRRemoteEnabledDisabled = 0x10, // kMipSetIRRemoteValue
    kRobosapienGetIRRemoteEnabledDisabled = 0x11,

};

typedef NS_OPTIONS(NSUInteger, kRobosapienActivationStatus) {
    kRobosapienActivation_FactoryDefault               = 0,        // => 00000000
    kRobosapienActivation_Activate                     = (1 << 0), // => 00000001
    kRobosapienActivation_ActivationSentToFlurry       = (1 << 1), // => 00000010
    kRobosapienActivation_HackerUartUsed               = (1 << 2), // => 00000100
    kRobosapienActivation_HackerUartUsedSentToFlurry   = (1 << 3), // => 00001000
};

@interface RobosapienCommandValues : NSObject

@end

