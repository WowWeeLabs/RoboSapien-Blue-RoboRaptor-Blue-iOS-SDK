//
//  PerformBlockAfterDelay.h
//  BobiMipTester
//
//  Created by Andy on 23/1/14.
//  Copyright (c) 2014 Andy. All rights reserved.
//

@import Foundation;

@interface NSObject (PerformBlockAfterDelay)

- (void)performBlock:(void (^)(void))block
          afterDelay:(NSTimeInterval)delay;

@end
