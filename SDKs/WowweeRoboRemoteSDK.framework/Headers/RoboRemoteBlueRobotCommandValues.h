//
//  RoboRemoteBlueRobotCommandValues.h
//  RoboRemoteBlue
//
//  Created by David Chan on 8/4/15.
//  Copyright (c) 2015 wowwee. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_OPTIONS(NSUInteger, kRoboRemoteBlueRobotActivationStatus) {
    kRoboRemoteBlueRobotActivation_FactoryDefault               = 0,        // => 00000000
    kRoboRemoteBlueRobotActivation_Activate                     = (1 << 0), // => 00000001
    kRoboRemoteBlueRobotActivation_ActivationSentToFlurry       = (1 << 1), // => 00000010
    kRoboRemoteBlueRobotActivation_HackerUartUsed               = (1 << 2), // => 00000100
    kRoboRemoteBlueRobotActivation_HackerUartUsedSentToFlurry   = (1 << 3), // => 00001000
};

@interface RoboRemoteBlueRobotCommandValues : NSObject

@end
