//
//  MIPWriteDataService.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

@interface BRSendDataService : BRBaseService

@property (assign, nonatomic) BOOL writeWithResponse;

- (void)sendData:(NSData *)data;
- (void)sendData:(NSData *)data withCallback:(void (^)(NSError *))writeCallback;

@end
