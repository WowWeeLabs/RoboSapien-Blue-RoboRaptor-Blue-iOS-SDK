//
//  MIPPortTimedPWMEvent.h
//  BobiMipTester
//
//  Created by Andy on 17/11/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "BRPortTimedEvent.h"

@interface BRPortTimedPWMEvent : BRPortTimedEvent

@property (nonatomic, assign) NSUInteger pwmPower;
@property (nonatomic, assign) NSUInteger pwmGradient;

-(NSData *) eventBytes;

@end
