//
//  BRDFUService.h
//
//  Created by Forrest Chan on 17/3/15.
//  Copyright (c) 2015 WowWee Group Limited. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

@interface BRDFUService : BRBaseService

- (void)rebootToMode:(uint8_t)mode withCallback:(void (^)(NSError *))callback;

@end
