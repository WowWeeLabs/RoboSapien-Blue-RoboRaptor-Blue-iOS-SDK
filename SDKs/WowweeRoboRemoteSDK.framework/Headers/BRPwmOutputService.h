//
//  MIPPwmOutputService.h
//  BobiMipTester
//
//  Created by Andy on 30/10/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef pwmOutputKVOContext
#define pwmOutputKVOContext "pwmOutputService"
#endif

// KeyPath
FOUNDATION_EXPORT NSString *const pwmChannel1OutputPowerKeyPathKVO;
FOUNDATION_EXPORT NSString *const pwmChannel2OutputPowerKeyPathKVO;
FOUNDATION_EXPORT NSString *const pwmChannel3OutputPowerKeyPathKVO;
FOUNDATION_EXPORT NSString *const pwmChannel4OutputPowerKeyPathKVO;
FOUNDATION_EXPORT NSString *const pwmAllChannelsFrequencyKeyPathKVO;
FOUNDATION_EXPORT NSString *const pwmTransitionTimingMSKeyPathKVO;
FOUNDATION_EXPORT NSString *const pwmInitialChannelStateKeyPathKVO;

@interface BRPwmOutputService : BRBaseService

@property (nonatomic, assign) NSUInteger pwmChannel1OutputPower;
@property (nonatomic, assign) NSUInteger pwmChannel2OutputPower;
@property (nonatomic, assign) NSUInteger pwmChannel3OutputPower;
@property (nonatomic, assign) NSUInteger pwmChannel4OutputPower;

@property (nonatomic, assign) NSNumber *pwmAllChannelsFrequency;

@property (nonatomic, assign) NSUInteger pwmTransitionTimingMS;

@property (nonatomic, assign) kPwmInitialStateValues pwmInitialChannelState;

- (void) setAllPwmOutputChannel1Power:(uint8_t)channel1power channel2power:(uint8_t)channel2power channel3power:(uint8_t)channel3power channel4power:(uint8_t)channel4power;
- (void) readAllPwmOutputChannels;
- (void) readPwmChannelOutputFrequency;
- (void) setPwmChannelOutputFrequency:(float)pwmFrequency;
- (void) readPwmInitialOutputPower;
- (void) setPwmInitialOutputPower:(kPwmInitialStateValues)initialState;
- (void) readPwmTransitionTiming;
- (void) setPwmTransitionTiming:(NSUInteger)transitionTimingInMilliseconds;

@end
