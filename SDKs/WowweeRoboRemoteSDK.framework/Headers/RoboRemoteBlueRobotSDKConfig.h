//
//  RoboRemoteBlueRobotSDKConfig.h
//  RoboBlue
//
//  Created by David Chan on 16/3/15.
//  Copyright (c) 2015 wowwee. All rights reserved.
//

#import <Foundation/Foundation.h>
// These can be overridden by defining them before importing the SDK

typedef enum {
    MRFRoboRemoteBlueRobotScanOptionMask_ShowAllDevices       = 0,
    MRFRoboRemoteBlueRobotScanOptionMask_FilterByProductId    = 1 << 0,
    MRFRoboRemoteBlueRobotScanOptionMask_FilterByServices     = 1 << 1,
    MRFRoboRemoteBlueRobotScanOptionMask_FilterByDeviceName   = 1 << 2,
} RoboRemoteBlueRobotFinderScanOptions;

#ifndef ROBOREMOTEBLUEROBOT_SCAN_OPTIONS
//#define SNAPPET_SCAN_OPTIONS MRFScanOptionMask_ShowAllDevices | MRFScanOptionMask_FilterByProductId | MRFScanOptionMask_FilterByServices
#define ROBOREMOTEBLUEROBOT_SCAN_OPTIONS MRFRoboRemoteBlueRobotScanOptionMask_ShowAllDevices | MRFRoboRemoteBlueRobotScanOptionMask_FilterByProductId
#endif

typedef NS_ENUM(NSInteger, RoboRemoteBlueRobotLogLevel) {
    RoboRemoteBlueRobotLogLevelDebug,
    RoboRemoteBlueRobotLogLevelErrors,
    RoboRemoteBlueRobotLogLevelNone
};

@interface RoboRemoteBlueRobotSDKConfig : NSObject
@end
