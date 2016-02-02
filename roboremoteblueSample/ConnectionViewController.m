//
//  ConnectionViewController.m
//  roboremoteblueSample
//
//  Created by Alex Lam on 1/2/2016.
//  Copyright © 2016 Wowwee. All rights reserved.
//

#import "ConnectionViewController.h"
#import "SapienRemoteController.h"
#import "RaptorRemoteController.h"

@implementation ConnectionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [[RoboRemoteBlueRobotFinder sharedInstance] clearFoundRobotList];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(onRoboRemoteBlueRobotFinderNotification:) name:RoboRemoteBlueRobotFinderNotificationID object:nil];
    [self startScan];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    
    [[NSNotificationCenter defaultCenter] removeObserver:self name:RoboRemoteBlueRobotFinderNotificationID object:nil];
    [self stopScan];
}

- (IBAction)refreshButtonPressed:(id)sender {
    [self startScan];
}

- (void)startScan {
    [[RoboRemoteBlueRobotFinder sharedInstance] scanForRobotsForDuration:10];
}

- (void)stopScan {
    [[RoboRemoteBlueRobotFinder sharedInstance] stopScanForRobots];
}

#pragma mark - RoboRemoteBlueRobotFinderNotification
- (void)onRoboRemoteBlueRobotFinderNotification: (NSNotification *)notification {
    NSDictionary *info = notification.userInfo;
    if(info){
        NSNumber *code = [info objectForKey: @"code"];
        //id data = [info objectForKey: @"data"];
        if (code.intValue == RoboRemoteBlueRobotFinderNote_RobotFound){
            [self.tableView reloadData];
        } else if (code.intValue == RoboRemoteBlueRobotFinderNote_RobotListCleared) {
            [self.tableView reloadData];
        } else if (code.intValue == RoboRemoteBlueRobotFinderNote_BluetoothError) {
            NSLog(@"Bluetooth error!");
        } else if (code.intValue == RoboRemoteBlueRobotFinderNote_BluetoothIsOff) {
            NSLog(@"Bluetooth is off!");
        } else if (code.intValue == RoboRemoteBlueRobotFinderNote_BluetoothIsAvailable) {
            NSLog(@"RoboRemoteBlueRobotFinderNote_BluetoothIsAvailable");
        }
    }
}


#pragma mark - UITableViewDelegate
- (void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath {
    [tableView deselectRowAtIndexPath:indexPath animated:YES];
    
    [self stopScan];
    if([[RoboRemoteBlueRobotFinder sharedInstance].robotsConnected count] == 0) {
        BluetoothRobot* robot = [[RoboRemoteBlueRobotFinder sharedInstance].robotsFound objectAtIndex:indexPath.row];
        if([robot isKindOfClass:[RobosapienRobot class]]) {
            RobosapienRobot *sapien = (RobosapienRobot*)robot;
            sapien.delegate = self;
        }
        else if([robot isKindOfClass:[RoboraptorRobot class]]) {
            RoboraptorRobot *raptor = (RoboraptorRobot*)robot;
            raptor.delegate = self;
        }
        [robot connect];
//        self.loadingIndicator.hidden = NO;
//        [self.loadingIndicator startAnimating];
    }
}

- (CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath {
    return 80;
}

#pragma mark - UITableViewDataSource
- (NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section {
    return [RoboRemoteBlueRobotFinder sharedInstance].robotsFound.count;
}

- (UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath {
    UITableViewCell* cell = [tableView dequeueReusableCellWithIdentifier:@"RobotCell"];
    if(!cell) {
        cell = [[UITableViewCell alloc] initWithStyle:UITableViewCellStyleDefault reuseIdentifier:@"RobotCell"];
    }
    
    UILabel* typeLabel = (UILabel*)[cell.contentView viewWithTag:100];
    UILabel* nameLabel = (UILabel*)[cell.contentView viewWithTag:101];
    
    BluetoothRobot* robot = [[RoboRemoteBlueRobotFinder sharedInstance].robotsFound objectAtIndex:indexPath.row];
    if([robot isKindOfClass:[RobosapienRobot class]]) {
        typeLabel.text = @"Sapien";
    }
    else if([robot isKindOfClass:[RoboraptorRobot class]]) {
        typeLabel.text = @"Raptor";
    }
    nameLabel.text = robot.name;
    
    [cell setAccessoryType:UITableViewCellAccessoryNone];
    
    if([[RoboRemoteBlueRobotFinder sharedInstance].robotsConnected count] > 0) {
        BluetoothRobot* connectedRobot = [[RoboRemoteBlueRobotFinder sharedInstance].robotsConnected objectAtIndex:0];
        if([connectedRobot.uuid.UUIDString isEqualToString:robot.uuid.UUIDString]) {
            [cell setAccessoryType:UITableViewCellAccessoryCheckmark];
        }
    }
    return cell;
}

#pragma mark - RoboraptorRobotDelegate
-(void) RoboraptorDeviceReady:(RoboraptorRobot *)Roboraptor {
    [Roboraptor roboraptorReadActivationStatus];
    [Roboraptor roboraptorWithCommand:RoboraptorCommandsStop];
    
    [self stopScan];
    
    // Go to raptor remotecontroller view
    RaptorRemoteController* controller = [self.storyboard instantiateViewControllerWithIdentifier:@"RoboRaptorRemoteController"];
    controller.connectedRobot = Roboraptor;
    [self.navigationController pushViewController:controller animated:YES];
}

-(void) RoboraptorDeviceDisconnected:(RoboraptorRobot *)Roboraptor error:(NSError *)error {
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Raptor has been disconnected" message:nil preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
    [self.navigationController presentViewController:alert animated:YES completion:nil];
}

-(void) RoboraptorDeviceFailedToConnect:(RoboraptorRobot *)Roboraptor error:(NSError *)error {
    
}

-(void) RoboraptorDeviceReconnecting:(RoboraptorRobot *)Roboraptor {
    
}

-(void) RoboraptorDeviceWentToSleep:(RoboraptorRobot *)roboraptor {
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Hint" message:@"Press stop button to wake up raptor again." preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
    [self.navigationController presentViewController:alert animated:YES completion:nil];
}

-(void) RoboraptorDeviceWokeUp:(RoboraptorRobot *)roboraptor {
    
}

-(void) Roboraptor:(RoboraptorRobot *)roboraptor didReceiveSettingsActivationStatus:(int)status {
    switch (status) {
        case 0:
            [roboraptor roboraptorSetProductActivated];
            break;
        case 1:
            [roboraptor roboraptorSetProductActivationUploaded];
            break;
    }
}

#pragma mark - RobosapienRobotDelegate
-(void) RobosapienDeviceReady:(RobosapienRobot *)robosapien {
    [robosapien robosapienReadActivationStatus];
    [robosapien robosapienWithCommand:RSCommandsStop];
    
    [self stopScan];
    
    // Go to Sapien remotecontroller view
    SapienRemoteController* controller = [self.storyboard instantiateViewControllerWithIdentifier:@"RoboSapienRemoteController"];
    controller.connectedRobot = robosapien;
    [self.navigationController pushViewController:controller animated:YES];
}

-(void) RobosapienDeviceDisconnected:(RobosapienRobot *)robosapien error:(NSError *)error {
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"RoboSapien has been disconnected" message:nil preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
    [self.navigationController presentViewController:alert animated:YES completion:nil];

}

-(void) RobosapienDeviceFailedToConnect:(RobosapienRobot *)robosapien error:(NSError *)error {
    
}

-(void) RobosapienDeviceReconnecting:(RobosapienRobot *)robosapien {
    
}

-(void) RobosapienDeviceWentToSleep:(RobosapienRobot *)robosapien {
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Hint" message:@"Press stop button to wake up RoboSapien again." preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:nil]];
    [self.navigationController presentViewController:alert animated:YES completion:nil];
}

-(void) RobosapienDeviceWokeUp:(RobosapienRobot *)robosapien {
    
}

-(void) Robosapien:(RobosapienRobot *)robosapien didReceiveSettingsActivationStatus:(int)status {
    switch (status) {
        case 0:
            [robosapien robosapienSetProductActivated];
            break;
        case 1:
            [robosapien robosapienSetProductActivationUploaded];
            break;
    }
}


@end
