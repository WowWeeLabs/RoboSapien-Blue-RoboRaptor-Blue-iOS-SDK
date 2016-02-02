//
//  BRSettingsService.h
//  BluetoothRobotControlLibrary
//
//  Created by Forrest Chan on 19/11/14.
//  Copyright (c) 2014 WOWWEE GROUP LIMITED. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef settingsKVOContext
#define settingsKVOContext "settingsService"
#endif

FOUNDATION_EXPORT NSString *const activationStatusKVO;

@interface BRSettingsService : BRBaseService

@property (nonatomic, assign) NSNumber *activationStatus;

#pragma mark - READ
- (void)readActivationStatus;

#pragma mark - WRITE
- (void)setActivationStatus:(uint8_t)activationStatus withCallback:(void (^)(NSError *))callback;

@end
