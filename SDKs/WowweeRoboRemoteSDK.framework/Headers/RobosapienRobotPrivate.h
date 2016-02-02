//
//  RobosapienRobotPrivate.h
//  WowWeeRobosapienSDK
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

@import UIKit;
@import Foundation;
@import CoreBluetooth;

#import "BluetoothRobot.h"
#import "BluetoothRobotPrivate.h"
#import "RobosapienRobot.h"

@interface RobosapienRobot()

#pragma mark Private Api Calls
-(void) setRobosapienProductActivated;
@end

@protocol RobosapienRobotPrivateDelegate <RobosapienRobotDelegate>
@optional
#pragma mark - Lower level bluetooth chip delegate calls
// If didReceiveRawCommandBytes is implemented then higher level MIP commands are not passed, this takes priority
-(void) RobosapienRobotBluetooth:(RobosapienRobot *)mip didReceiveRobotCommand:(RobotCommand *)command;
-(void) RobosapienRobotBluetooth:(RobosapienRobot *)mip didReceiveRawCommandData:(NSData *)data;

@end
