//
//  MIPDeviceInformationService.h
//  bttester
//
//  Created by Andy on 12/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"

/** KVO **/
// Context
#ifndef deviceInfoKVOContext
#define deviceInfoKVOContext "deviceInfo"
#endif
// KeyPath
FOUNDATION_EXPORT NSString *const systemIdKeyPathKVO;
FOUNDATION_EXPORT NSString *const softwareVersionKeyPathKVO;

@interface BRDeviceInformationService : BRBaseService

@property (nonatomic, strong) NSString *systemId;
@property (nonatomic, strong) NSString *moduleSoftwareVersion;

- (void) readSystemId;
- (void) readModuleSoftwareVersion;

@end
