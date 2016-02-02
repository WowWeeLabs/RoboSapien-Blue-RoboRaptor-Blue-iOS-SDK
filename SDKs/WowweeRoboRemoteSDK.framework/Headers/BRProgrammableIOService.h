//
//  MIPProgrammableIO.h
//  BobiMipTester
//
//  Created by Andy on 5/11/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef programmableIOKVOContext
#define programmableIOKVOContext "programmableIOService"
#endif

// KeyPath
FOUNDATION_EXPORT NSString *const programmableIO0StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO0ModeKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO1StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO1ModeKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO2StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO2ModeKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO3StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO3ModeKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO4StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO4ModeKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO5StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO5ModeKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO6StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO6ModeKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO7StateKeyPathKVO;
FOUNDATION_EXPORT NSString *const programmableIO7ModeKeyPathKVO;

typedef enum : uint8_t {
    kMipProgrammableIOPin0 = 0,
    kMipProgrammableIOPin1 = 1,
    kMipProgrammableIOPin2 = 2,
    kMipProgrammableIOPin3 = 3,
    kMipProgrammableIOPin4 = 4,
    kMipProgrammableIOPin5 = 5,
    kMipProgrammableIOPin6 = 6,
    kMipProgrammableIOPin7 = 7,
} kMipProgrammableIOPinValue;

typedef enum : uint8_t {
    kMipProgrammableIOState_Low = 0,
    kMipProgrammableIOState_High = 1,
} kMipProgrammableIOStateValue;

typedef enum : uint8_t {
    kMipProgrammableIOMode_Input = 0,
    kMipProgrammableIOMode_Output = 1,
} kMipProgrammableIOModeValue;

@interface BRProgrammableIOService : BRBaseService

@property (nonatomic, assign) kMipProgrammableIOStateValue io0state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io0mode;
@property (nonatomic, assign) kMipProgrammableIOStateValue io1state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io1mode;
@property (nonatomic, assign) kMipProgrammableIOStateValue io2state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io2mode;
@property (nonatomic, assign) kMipProgrammableIOStateValue io3state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io3mode;
@property (nonatomic, assign) kMipProgrammableIOStateValue io4state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io4mode;
@property (nonatomic, assign) kMipProgrammableIOStateValue io5state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io5mode;
@property (nonatomic, assign) kMipProgrammableIOStateValue io6state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io6mode;
@property (nonatomic, assign) kMipProgrammableIOStateValue io7state;
@property (nonatomic, assign) kMipProgrammableIOModeValue io7mode;
@property (nonatomic, assign) bool isNotifying;

-(void) turnOff;
-(void) turnOn;
-(void) readAllPinStates;
-(void) setAllPinStates:(kMipProgrammableIOStateValue)io0 io1:(kMipProgrammableIOStateValue)io1 io2:(kMipProgrammableIOStateValue)io2 io3:(kMipProgrammableIOStateValue)io3 io4:(kMipProgrammableIOStateValue)io4 io5:(kMipProgrammableIOStateValue)io5 io6:(kMipProgrammableIOStateValue)io6 io7:(kMipProgrammableIOStateValue)io7;
-(void) readAllPinModes;
-(void) setAllPinModes:(kMipProgrammableIOModeValue)io0 io1:(kMipProgrammableIOModeValue)io1 io2:(kMipProgrammableIOModeValue)io2 io3:(kMipProgrammableIOModeValue)io3 io4:(kMipProgrammableIOModeValue)io4 io5:(kMipProgrammableIOModeValue)io5 io6:(kMipProgrammableIOModeValue)io6 io7:(kMipProgrammableIOModeValue)io7;

@end
