//
//  RoboraptorRobotPrivate.h
//  WowWeeRoboraptorSDK
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

@import UIKit;
@import Foundation;
@import CoreBluetooth;

#import "BluetoothRobot.h"
#import "BluetoothRobotPrivate.h"
#import "RoboraptorRobot.h"

@interface RoboraptorRobot()

#pragma mark Private Api Calls
-(void) setRoboraptorProductActivated;
@end

@protocol RoboraptorRobotPrivateDelegate <RoboraptorRobotDelegate>
@optional
#pragma mark - Lower level bluetooth chip delegate calls
// If didReceiveRawCommandBytes is implemented then higher level MIP commands are not passed, this takes priority
-(void) RoboraptorRobotBluetooth:(RoboraptorRobot *)mip didReceiveRobotCommand:(RobotCommand *)command;
-(void) RoboraptorRobotBluetooth:(RoboraptorRobot *)mip didReceiveRawCommandData:(NSData *)data;

@end
