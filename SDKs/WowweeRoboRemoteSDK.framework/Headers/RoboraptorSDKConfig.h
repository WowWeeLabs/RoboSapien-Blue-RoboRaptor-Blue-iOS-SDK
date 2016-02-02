//
//  RoboraptorSDKConfig.h
//  WowWeeRoboraptorSDK
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

// These can be overridden by defining them before importing the SDK

typedef enum {
    MRFRoboraptorScanOptionMask_ShowAllDevices       = 0,
    MRFRoboraptorScanOptionMask_FilterByProductId    = 1 << 0,
    MRFRoboraptorScanOptionMask_FilterByServices     = 1 << 1,
    MRFRoboraptorScanOptionMask_FilterByDeviceName   = 1 << 2,
} RoboraptorRobotFinderScanOptions;

#ifndef ROBORAPTOR_SCAN_OPTIONS
//#define SNAPPET_SCAN_OPTIONS MRFScanOptionMask_ShowAllDevices | MRFScanOptionMask_FilterByProductId | MRFScanOptionMask_FilterByServices
#define ROBORAPTOR_SCAN_OPTIONS MRFRoboraptorScanOptionMask_ShowAllDevices | MRFRoboraptorScanOptionMask_FilterByProductId
#endif

@interface RoboraptorSDKConfig : NSObject
@end
