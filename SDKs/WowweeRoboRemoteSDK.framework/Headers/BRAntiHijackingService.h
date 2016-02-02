//
//  MIPAntiHijackingService.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef antiHijackingKVOContext
#define antiHijackingKVOContext "antiHijacking"
#endif
// KeyPath
FOUNDATION_EXPORT NSString *const isPasswordErrorKeyPathKVO;
FOUNDATION_EXPORT NSString *const passwordKeyPathKVO;

@interface BRAntiHijackingService : BRBaseService

@property (nonatomic, assign) bool isNotifying;
@property (nonatomic, strong) NSString *password;
@property (nonatomic, assign) kAntiHijackingReceiveSecurityInfoValues securityInfo;
@property (nonatomic, assign) bool isPasswordError;

- (void) turnOff;
- (void) turnOn;
- (void) setNewPassword:(NSString *)password oldPassword:(NSString *)oldPassword;
- (void) setNewPassword:(NSString *)password;
- (void) removePassword:(NSString *)oldPassword;

@end
