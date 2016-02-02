/*
 * Copyright 2010-2014 WowWee Group Ltd, All Rights Reserved.
 *
 * Licensed under the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

@import CoreBluetooth;

#import "RobosapienRobot.h"
#import "RoboraptorRobot.h"
#import "BluetoothRobotFinder.h"
#import "RoboRemoteBlueRobotSDKConfig.h"

FOUNDATION_EXPORT NSString *const RoboRemoteBlueRobotFinderNotificationID;

#ifndef EARLYLIGHT_TESTING_BUILD
//#define EARLYLIGHT_TESTING_BUILD
#endif

/**
 These are the values that can be sent from RoboRemoteBlueRobotFinder
 */
typedef enum : NSUInteger {
    RoboRemoteBlueRobotFinderNote_RobotFound = 1,
    RoboRemoteBlueRobotFinderNote_RobotListCleared,
    RoboRemoteBlueRobotFinderNote_BluetoothError,
    RoboRemoteBlueRobotFinderNote_BluetoothIsOff,
    RoboRemoteBlueRobotFinderNote_BluetoothIsAvailable,
} RoboRemoteBlueRobotFinderNote;

typedef enum _RobotType {
    RobotTypeRobosapien = 0,
    RobotTypeRoboraptor = 1,
}RobotType;

@interface RoboRemoteBlueRobotFinder : BluetoothRobotFinder <CBCentralManagerDelegate>

/**
 
 */
@property (nonatomic, strong, readonly) NSMutableArray *robotsFound;
@property (nonatomic, strong, readonly) NSMutableArray *robotsConnected;
@property (nonatomic, assign, readonly) CBCentralManagerState cbCentralManagerState;

#ifdef EARLYLIGHT_TESTING_BUILD
@property (readwrite) RobotType robotType;
#endif

//// Log level
@property (nonatomic, assign) RoboRemoteBlueRobotLogLevel logLevel;

/**
 Starts the BLE scanning
 */
-(void)scanForRobots;

/**
 Starts the BLE scanning for a specified number of seconds. Normally you should use this method because endlessly scanning is very battery intensive.
 */
-(void)scanForRobotsForDuration:(NSUInteger)seconds;
-(void)stopScanForRobots;
-(void)clearFoundRobotList;

/**
 Quick access to first connected Robot in RobotsConnected list
 @return RobotsConnected[0] or nil if RobotsConnected is empty
 */
-(BluetoothRobot *)firstConnectedRobot;

@end