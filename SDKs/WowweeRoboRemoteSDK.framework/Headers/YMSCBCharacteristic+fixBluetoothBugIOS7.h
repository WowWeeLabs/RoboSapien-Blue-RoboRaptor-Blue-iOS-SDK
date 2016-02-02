//
//  YMSCBCharacteristic+fixBluetoothBugIOS7.h
//  MIP
//
//  Created by Andy on 23/9/13.
//  Copyright (c) 2013 WowWee Group Limited. All rights reserved.
//

#import "YMSCBCharacteristic.h"

@interface YMSCBCharacteristic (fixBluetoothBugIOS7)

-(void)writeValueAndFixBug:(NSData *)data withBlock:(void (^)(NSError *))writeCallback;
-(void)writeValueAndFixBug:(NSData *)data;

@end
