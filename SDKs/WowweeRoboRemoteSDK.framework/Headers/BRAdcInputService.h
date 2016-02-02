//
//  MIPAdcInputService.h
//  BobiMipTester
//
//  Created by Andy on 30/10/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef adcInputKVOContext
#define adcInputKVOContext "adcInputService"
#endif

// KeyPath
FOUNDATION_EXPORT NSString *const adcInputChannel0ValueKeyPathKVO;
FOUNDATION_EXPORT NSString *const adcInputChannel1ValueKeyPathKVO;
FOUNDATION_EXPORT NSString *const adcInputSamplePeriodKeyPathKVO;
FOUNDATION_EXPORT NSString *const adcInputChannel0EnabledKeyPathKVO;
FOUNDATION_EXPORT NSString *const adcInputChannel1EnabledKeyPathKVO;
FOUNDATION_EXPORT float const ADC_LOWER_REFERENCE_VOLTAGE;
FOUNDATION_EXPORT float const ADC_UPPER_REFERENCE_VOLTAGE;

typedef enum : NSInteger {
    kBluetoothRobotAdcInputChannel0 = 0,
    kBluetoothRobotAdcInputChannel1 = 1
} kBluetoothRobotAdcInputChannel;

@interface BRAdcInputService : BRBaseService

+(short)calculateAdcValueFromShort:(short)value;
@property (nonatomic, assign) NSInteger adcInput0;
@property (nonatomic, assign) NSInteger adcInput1;
@property (nonatomic, assign) NSUInteger inputSamplePeriod;
@property (nonatomic, assign) bool isNotifyingAdc0;
@property (nonatomic, assign) bool isNotifyingAdc1;
@property (nonatomic, assign) bool isAdcInput0Enabled;
@property (nonatomic, assign) bool isAdcInput1Enabled;

- (void) readAdcChannel0value;
- (void) readAdcChannel1value;
- (void) setAdcChannelEnabledDisabled:(bool)channel0 channel1:(bool)channel1;
- (void) readAdcChannelEnabledDisabled;
- (void) readAdcSamplePeriod;
- (void) setAdcSamplePeriod:(uint16_t)samplePeriod;
- (void) turnOnChannel0;
- (void) turnOnChannel1;
- (void) turnOffChannel0;
- (void) turnOffChannel1;
- (void) triggerUpdateWithCurrentValues;

@end
