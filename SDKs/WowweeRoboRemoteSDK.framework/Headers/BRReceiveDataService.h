//
//  MIPReceiveDataService.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"
#import "RobotCommand.h"
//#import "FirmwareUpdateResponse.h"

/** KVO **/
// Context
#ifndef receiveDataKVOContext
#define receiveDataKVOContext "receiveData"
#endif
// KeyPath
FOUNDATION_EXPORT NSString *const commandKeyPathKVO;
FOUNDATION_EXPORT NSString *const rawDataKeyPathKVO;
FOUNDATION_EXPORT NSString *const BRReceiveRobotCommandNotificationID;
FOUNDATION_EXPORT NSString *const BRReceiveDataRawNotificationID;

@interface BRReceiveDataService : BRBaseService

@property (nonatomic, assign) bool processRobotCommands;
@property (nonatomic, assign) bool firmwareUpdateMode;
@property (nonatomic, strong) RobotCommand *lastRobotCommand;
@property (nonatomic, strong) NSData *lastCommandData;
@property (nonatomic, assign) bool isNotifying;

- (void) turnOff;
- (void) turnOn;

@end
