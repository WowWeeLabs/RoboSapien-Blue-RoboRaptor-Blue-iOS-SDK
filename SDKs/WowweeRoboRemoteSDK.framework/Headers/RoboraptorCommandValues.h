//
//  RoboraptorCommandValues.h
//  BluetoothRobotControlLibrary
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2014 WowWee Group Limited. All rights reserved.
//

@import Foundation;

FOUNDATION_EXPORT NSUInteger const ROBORAPTOR_BLUETOOTH_PRODUCT_ID;
FOUNDATION_EXPORT NSUInteger const ROBORAPTOR_BLUETOOTH_DFU_PRODUCT_ID;
FOUNDATION_EXPORT NSString *const ROBORAPTOR_BLUETOOTH_CUSTOM_DATA_IDENTIFIER;

typedef NS_OPTIONS(uint8_t, kRoboraptorCommand) {
    kRoboraptorCommandSetIRRemoteEnabledDisabled = 0x10, // kMipSetIRRemoteValue
    kRoboraptorCommandGetIRRemoteEnabledDisabled = 0x11,

};

typedef NS_OPTIONS(NSUInteger, kRoboraptorActivationStatus) {
    kRoboraptorActivation_FactoryDefault               = 0,        // => 00000000
    kRoboraptorActivation_Activate                     = (1 << 0), // => 00000001
    kRoboraptorActivation_ActivationSentToFlurry       = (1 << 1), // => 00000010
    kRoboraptorActivation_HackerUartUsed               = (1 << 2), // => 00000100
    kRoboraptorActivation_HackerUartUsedSentToFlurry   = (1 << 3), // => 00001000
};

@interface RoboraptorCommandValues : NSObject

@end

