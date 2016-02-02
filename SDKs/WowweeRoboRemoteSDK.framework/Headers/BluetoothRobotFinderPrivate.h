//
//  BluetoothRobotFinderPrivate.h
//  WowWeeMiPSDK
//
//  Created by Andy on 17/9/14.
//  Copyright (c) 2014 WowWee Group Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BluetoothRobotFinder.h"
#import "YMSCBCentralManager.h"

@interface BluetoothRobotFinder()
@property (nonatomic, strong) YMSCBCentralManager *btMgr;
@property (nonatomic, strong) NSMutableArray *peripheralsFound;

- (YMSCBPeripheral *)findPeripheral:(CBPeripheral *)peripheral;
-(void)handleFoundPeripheral:(CBPeripheral *)cbPeripheral advertisingData:(NSDictionary *)advertisingData rssi:(NSNumber *)rssi;
-(void) subscribeToNotifications;
-(void) unsubscribeFromNotifications;
@end
