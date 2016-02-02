//
//  MIPBaseService.h
//  bttester
//
//  Created by Andy on 13/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import "YMSCBService.h"
#import "BluetoothRobotConstants.h"
#import "YMSCBCharacteristic+fixBluetoothBugIOS7.h"

@class BluetoothRobot;

@interface BRBaseService : YMSCBService

@property (nonatomic, strong) NSArray *kvoKeyPaths;
@property (nonatomic, weak, readonly) BluetoothRobot *parentBluetoothRobot;
@property (nonatomic, assign) BOOL isOptional;

- (id)initWithName:(NSString *)oName
            parent:(YMSCBPeripheral *)pObj
            serviceOffset:(int)serviceOffset;
- (id)initWithName:(NSString *)oName
            parent:(YMSCBPeripheral *)pObj
              UUID:(NSString *)uuidString;
-(id)initWithBluetoothRobot:(BluetoothRobot *)robot andPeripheral:(YMSCBPeripheral *)peripheral;
-(id)initWithParent:(YMSCBPeripheral *)pObj;

@end
