//
//  MIPPortTimedEvent.h
//  BobiMipTester
//
//  This class encapsulates a port timed event
//
//  Created by Andy on 17/11/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "BluetoothRobotConstants.h"

@interface BRPortTimedEvent : NSObject

@property (nonatomic, assign) NSUInteger eventIndex;
@property (nonatomic, assign) NSUInteger portChannel;
@property (nonatomic, assign) bool portState;
@property (nonatomic, strong) NSDate *dateTime;
@property (nonatomic, assign) kPortTimedEvent_EventActionValue actionType;

@property (nonatomic, assign) bool loopEverySecond;
@property (nonatomic, assign) bool loopEveryMinute;
@property (nonatomic, assign) bool loopEveryHour;
@property (nonatomic, assign) bool loopEveryDay;
@property (nonatomic, assign) bool loopEveryMonth;
@property (nonatomic, assign) bool loopEveryYear;

-(id) initEventWithEventIndex:(NSUInteger)anEventIndex
                     dateTime:(NSDate *)anEventDateTime
                   actionType:(kPortTimedEvent_EventActionValue)anActionType;
-(id) initEventWithData:(NSData *)eventData;
//-(void) setPortStateWithData:(NSData *)portStateData;
-(unsigned long long) dateTimeULongLong;
-(void) setDateTimeWithULongLong:(unsigned long long)longlongDateTime;

//+(kPortTimedEvent_EventActionValue) eventActionWithData:(NSData *)data;

@end
