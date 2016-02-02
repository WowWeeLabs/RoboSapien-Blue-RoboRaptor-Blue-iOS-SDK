//
//  RobosapienSDKConfig.h
//  WowWeeRobosapienSDK
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
// These can be overridden by defining them before importing the SDK

typedef enum {
    MRFRobosapienScanOptionMask_ShowAllDevices       = 0,
    MRFRobosapienScanOptionMask_FilterByProductId    = 1 << 0,
    MRFRobosapienScanOptionMask_FilterByServices     = 1 << 1,
    MRFRobosapienScanOptionMask_FilterByDeviceName   = 1 << 2,
} RobosapienRobotFinderScanOptions;

#ifndef ROBOSAPIEN_SCAN_OPTIONS
//#define SNAPPET_SCAN_OPTIONS MRFScanOptionMask_ShowAllDevices | MRFScanOptionMask_FilterByProductId | MRFScanOptionMask_FilterByServices
#define ROBOSAPIEN_SCAN_OPTIONS MRFRobosapienScanOptionMask_ShowAllDevices | MRFRobosapienScanOptionMask_FilterByProductId
#endif

@interface RobosapienSDKConfig : NSObject
@end
