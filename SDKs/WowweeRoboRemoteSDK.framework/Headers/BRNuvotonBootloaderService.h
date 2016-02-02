//
//  BRNuvotonBootloaderService.h
//
//  Created by Forrest on 23/3/15.
//  Copyright (c) 2015 WowWee Group Limited. All rights reserved.
//

@import Foundation;
#import "BRBaseService.h"
#import "RobotCommand.h"

/** KVO **/
// Context
#ifndef nuvotonBootloaderKVOContext
#define nuvotonBootloaderKVOContext "nuvotonBootloader"
#endif
// KeyPath
FOUNDATION_EXPORT NSString *const nuvotonChipStatusKeyPathKVO;
FOUNDATION_EXPORT NSString *const firmwareDataStatusKeyPathKVO;
FOUNDATION_EXPORT NSString *const firmwareCompleteStatusKeyPathKVO;

typedef void (^FirmwareProgressCallback)(int sentByte);

@interface BRNuvotonBootloaderService : BRBaseService

@property (nonatomic, assign) bool isNotifying;
@property (nonatomic, strong) NSNumber *nuvotonChipStatus;
@property (nonatomic, strong) NSNumber *firmwareDataStatus;
@property (nonatomic, strong) NSNumber *firmwareCompleteStatus;

#pragma mark - public
- (void) turnOff;
- (void) turnOn;
- (void) readNuvotonChipStatus;
- (void) readFirmwareDataStatus;
- (void) restartNuvotonChipToMode:(NuvotonBootloaderMode)mode;
- (void) stopTransfer;
- (void) writeFirmwareToNuvoton;
- (void)sendFirmwareDataToCache:(NSData *)data
   withAppToBleProgressCallback:(void (^)(int sentByte))appToBleProgressCallback
   bleToNuvotonProgressCallback:(void (^)(int sentByte))bleToNuvotonProgressCallback;

@end
