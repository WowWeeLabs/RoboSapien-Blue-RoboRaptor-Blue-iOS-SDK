//
//  MIPPortTimedEventService.h
//  BobiMipTester
//
//  Created by Andy on 17/11/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "BRBaseService.h"

@interface BRPortTimedEventService : BRBaseService

@property (nonatomic, assign) NSDate *rtcDateTime;
@property (nonatomic, strong) NSMutableDictionary *events;

-(void) readPortTimedRealTimeClock;
-(void) setPortTimedRealTimeClockWithCurrentDate;
-(void) setPortTimedRealTimeClockWithDate:(NSDate *)clockDate;
//-(void) readTimedEventChannelByEventIndex:(NSUInteger)eventIndex;

@end
