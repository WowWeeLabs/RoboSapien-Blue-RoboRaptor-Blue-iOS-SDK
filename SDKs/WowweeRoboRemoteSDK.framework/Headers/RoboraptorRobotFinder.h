/*
 * Copyright 2010-2014 WowWee Group Ltd, All Rights Reserved.
 *
 * Licensed under the "license" file accompanying this file. This file is distributed
 * on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
 * express or implied. See the License for the specific language governing
 * permissions and limitations under the License.
 */

@import CoreBluetooth;

#import "RoboraptorRobot.h"
#import "BluetoothRobotFinder.h"

FOUNDATION_EXPORT NSString *const RoboraptorRobotFinderNotificationID;
FOUNDATION_EXPORT bool const Roboraptor_ROBOT_FINDER_DEBUG_MODE;

/**
 These are the values that can be sent from RoboraptorRobotFinder
 */
typedef enum : NSUInteger {
    RoboraptorRobotFinderNote_RoboraptorFound = 1,
    RoboraptorRobotFinderNote_RoboraptorListCleared,
    RoboraptorRobotFinderNote_BluetoothError,
    RoboraptorRobotFinderNote_BluetoothIsOff,
    RoboraptorRobotFinderNote_BluetoothIsAvailable,
} RoboraptorRobotFinderNote;

@interface RoboraptorRobotFinder : BluetoothRobotFinder <CBCentralManagerDelegate>

/**

 */
@property (nonatomic, strong, readonly) NSMutableArray *roboraptorsFound;
@property (nonatomic, strong, readonly) NSMutableArray *roboraptorsConnected;
@property (nonatomic, assign, readonly) CBCentralManagerState cbCentralManagerState;

// Log level
@property (nonatomic, assign) RoboraptorLogLevel logLevel;

/**
 Starts the BLE scanning
 */
-(void)scanForRoboraptors;

/**
 Starts the BLE scanning for a specified number of seconds. Normally you should use this method because endlessly scanning is very battery intensive.
 */
-(void)scanForRoboraptorsForDuration:(NSUInteger)seconds;
-(void)stopScanForRoboraptors;
-(void)clearFoundRoboraptorList;

/**
 Quick access to first connected Roboraptor in RoboraptorsConnected list
 @return RoboraptorsConnected[0] or nil if RoboraptorsConnected is empty
 */
-(RoboraptorRobot *)firstConnectedRoboraptor;

@end