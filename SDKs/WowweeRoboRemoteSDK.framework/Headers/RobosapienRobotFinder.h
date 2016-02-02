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
#import "BluetoothRobotFinder.h"

FOUNDATION_EXPORT NSString *const RobosapienRobotFinderNotificationID;
FOUNDATION_EXPORT bool const ROBOSAPIEN_ROBOT_FINDER_DEBUG_MODE;

/**
 These are the values that can be sent from RobosapienRobotFinder
 */
typedef enum : NSUInteger {
    RobosapienRobotFinderNote_RobosapienFound = 1,
    RobosapienRobotFinderNote_RobosapienListCleared,
    RobosapienRobotFinderNote_BluetoothError,
    RobosapienRobotFinderNote_BluetoothIsOff,
    RobosapienRobotFinderNote_BluetoothIsAvailable,
} RobosapienRobotFinderNote;

@interface RobosapienRobotFinder : BluetoothRobotFinder <CBCentralManagerDelegate>

/**

 */
@property (nonatomic, strong, readonly) NSMutableArray *robosapiensFound;
@property (nonatomic, strong, readonly) NSMutableArray *robosapiensConnected;
@property (nonatomic, assign, readonly) CBCentralManagerState cbCentralManagerState;

// Log level
@property (nonatomic, assign) RobosapienLogLevel logLevel;

/**
 Starts the BLE scanning
 */
-(void)scanForRobosapiens;

/**
 Starts the BLE scanning for a specified number of seconds. Normally you should use this method because endlessly scanning is very battery intensive.
 */
-(void)scanForRobosapiensForDuration:(NSUInteger)seconds;
-(void)stopScanForRobosapiens;
-(void)clearFoundRobosapienList;

/**
 Quick access to first connected Robosapien in RobosapiensConnected list
 @return RobosapiensConnected[0] or nil if RobosapiensConnected is empty
 */
-(RobosapienRobot *)firstConnectedRobosapien;

@end