//
//  RobosapienRobot.h
//  BluetoothRobotControlLibrary
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
// 

@import UIKit;
@import Foundation;
@import CoreBluetooth;

#import "BluetoothRobot.h"
#import "RobosapienCommandValues.h"
#import "RobosapienRobotConstants.h"
#import "BluetoothRobotPrivate.h"

@protocol RobosapienRobotDelegate;

FOUNDATION_EXPORT NSString *const ROBOSAPIEN_CONNECTED_NOTIFICATION_NAME;
FOUNDATION_EXPORT NSString *const ROBOSAPIEN_DISCONNECTED_NOTIFICATION_NAME;

typedef NS_ENUM(NSInteger, RobosapienLogLevel) {
    RobosapienLogLevelDebug,
    RobosapienLogLevelErrors,
    RobosapienLogLevelNone
};

@interface RobosapienRobot : BluetoothRobot

/** Event manager handles handling basic events which do not require app interaction **/
@property (nonatomic, strong) NSDate *robosapienFirmwareVersionDate;
@property (nonatomic, assign) NSUInteger robosapienFirmwareVersionId;
@property (nonatomic, strong) NSNumber *robosapienHardwareVersion;
@property (nonatomic, assign) NSInteger batteryLevel;
@property (nonatomic, readonly, assign) kRobosapienActivationStatus toyActivationStatus;

@property (nonatomic, assign) bool disableReceivedCommandProcessing;

@property (nonatomic, assign) RobosapienLogLevel logLevel;

/** Delegate for receiving callbacks */
@property (nonatomic, weak) id<RobosapienRobotDelegate> delegate;
@property (readwrite) BOOL isConnect;

#pragma mark - Robosapien Protocal Methods
- (void)robosapienWithCommand:(NSInteger)commandID;
- (void)robosapienWriteDisplayName:(NSString*)displayName;
- (void)robosapienIsSleep;

- (void)robosapienReadActivationStatus;
- (void)robosapienSetProductActivated;
- (void)robosapienResetProductActivation;
- (void)robosapienSetProductActivationUploaded;
- (void)robosapienSetProductionActivationHackerActivated;
- (void)robosapienSetProductionActivationHackerUploaded;

@end

#pragma mark - Delegate Callbacks
@protocol RobosapienRobotDelegate <NSObject>
@optional
/** Connection Methods **/
-(void) RobosapienDeviceReady:(RobosapienRobot *)robosapien;
-(void) RobosapienDeviceDisconnected:(RobosapienRobot *)robosapien error:(NSError *)error;
-(void) RobosapienDeviceFailedToConnect:(RobosapienRobot *)robosapien error:(NSError *)error;
-(void) RobosapienDeviceReconnecting:(RobosapienRobot *)robosapien;
-(void) RobosapienDeviceWentToSleep:(RobosapienRobot *)robosapien;
-(void) RobosapienDeviceWokeUp:(RobosapienRobot *)robosapien;
-(void) Robosapien:(RobosapienRobot *)robosapien didReceiveSettingsActivationStatus:(int)status;

@end




