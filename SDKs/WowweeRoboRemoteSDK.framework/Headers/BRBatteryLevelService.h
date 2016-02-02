//
//  MIPBatteryLevelServiceUUID.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef batteryReadingKVOContext
#define batteryReadingKVOContext "batteryReading"
#endif
// KeyPath
FOUNDATION_EXPORT NSString *const batteryReadingKeyPathKVO;

@interface BRBatteryLevelService : BRBaseService

@property (nonatomic, strong) NSNumber *batteryReading;
@property (nonatomic, assign) bool isNotifying;

- (void) turnOff;
- (void) turnOn;
- (void) readBatteryLevel;

@end
