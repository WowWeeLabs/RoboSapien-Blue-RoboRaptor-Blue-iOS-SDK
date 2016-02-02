//
//  MIPTimingTurnoverOutput.h
//  BobiMipTester
//
//  Created by Andy on 5/11/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "BRBaseService.h"

@interface BRTimingTurnoverOutputService : BRBaseService

@property (nonatomic, assign) NSUInteger io6firstTiming;
@property (nonatomic, assign) NSUInteger io6secondTiming;
@property (nonatomic, assign) NSUInteger io7firstTiming;
@property (nonatomic, assign) NSUInteger io7secondTiming;

@end
