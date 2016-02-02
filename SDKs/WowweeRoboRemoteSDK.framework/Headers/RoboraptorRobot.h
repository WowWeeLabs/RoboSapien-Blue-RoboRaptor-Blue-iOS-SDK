//
//  RoboraptorRobot.h
//  BluetoothRobotControlLibrary
//
//  Created by Forrest Chan on 17/11/14.
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
// 

@import UIKit;
@import Foundation;
@import CoreBluetooth;

#import "BluetoothRobot.h"
#import "RoboraptorCommandValues.h"
#import "RoboraptorRobotConstants.h"
#import "BluetoothRobotPrivate.h"

@protocol RoboraptorRobotDelegate;

FOUNDATION_EXPORT NSString *const ROBORAPTOR_CONNECTED_NOTIFICATION_NAME;
FOUNDATION_EXPORT NSString *const ROBORAPTOR_DISCONNECTED_NOTIFICATION_NAME;

typedef NS_ENUM(NSInteger, RoboraptorLogLevel) {
    RoboraptorLogLevelDebug,
    RoboraptorLogLevelErrors,
    RoboraptorLogLevelNone
};

@interface RoboraptorRobot : BluetoothRobot

/** Event manager handles handling basic events which do not require app interaction **/
@property (nonatomic, strong) NSDate *RoboraptorFirmwareVersionDate;
@property (nonatomic, assign) NSUInteger RoboraptorFirmwareVersionId;
@property (nonatomic, strong) NSNumber *RoboraptorHardwareVersion;
@property (nonatomic, assign) NSInteger batteryLevel;
@property (nonatomic, readonly, assign) kRoboraptorActivationStatus toyActivationStatus;

@property (nonatomic, assign) bool disableReceivedCommandProcessing;

@property (nonatomic, assign) RoboraptorLogLevel logLevel;

/** Delegate for receiving callbacks */
@property (nonatomic, weak) id<RoboraptorRobotDelegate> delegate;
@property (readwrite) BOOL isConnect;

#pragma mark - Roboraptor Protocal Methods
- (void)roboraptorWithCommand:(NSInteger)commandID;
- (void)roboraptorWriteDisplayName:(NSString*)displayName;
- (void)roboraptorIsSleep;

- (void)roboraptorReadActivationStatus;
- (void)roboraptorSetProductActivated;
- (void)roboraptorResetProductActivation;
- (void)roboraptorSetProductActivationUploaded;
- (void)roboraptorSetProductionActivationHackerActivated;
- (void)robosapienSetProductionActivationHackerUploaded;

@end

#pragma mark - Delegate Callbacks
@protocol RoboraptorRobotDelegate <NSObject>
@optional
/** Connection Methods **/
-(void) RoboraptorDeviceReady:(RoboraptorRobot *)Roboraptor;
-(void) RoboraptorDeviceDisconnected:(RoboraptorRobot *)Roboraptor error:(NSError *)error;
-(void) RoboraptorDeviceFailedToConnect:(RoboraptorRobot *)Roboraptor error:(NSError *)error;
-(void) RoboraptorDeviceReconnecting:(RoboraptorRobot *)Roboraptor;
-(void) RoboraptorDeviceWentToSleep:(RoboraptorRobot *)roboraptor;
-(void) RoboraptorDeviceWokeUp:(RoboraptorRobot *)roboraptor;
-(void) Roboraptor:(RoboraptorRobot *)roboraptor didReceiveSettingsActivationStatus:(int)status;

@end




