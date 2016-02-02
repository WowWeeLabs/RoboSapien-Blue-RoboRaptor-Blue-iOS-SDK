//
//  MIPRSSIReportService.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef rssiReportKVOContext
#define rssiReportKVOContext "rssiReport"
#endif
// KeyPaths
FOUNDATION_EXPORT NSString *const rssiLevelKVO;
//NSString *const notificationPeriodKVO;

@interface BRRSSIReportService : BRBaseService
@property (nonatomic, strong) NSNumber *rssiLevel;
@property (nonatomic, strong) NSNumber *notificationPeriod;
@property (nonatomic, assign) bool isNotifying;

- (void) turnOff;
- (void) turnOnWithPeriod:(uint16_t)period;
- (void) readRSSI;
- (void) readConfigPeriod;
- (void) setConfigPeriod:(uint16_t)value;

@end
