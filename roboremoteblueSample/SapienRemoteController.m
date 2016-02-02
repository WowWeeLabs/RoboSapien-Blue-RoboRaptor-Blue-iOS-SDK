//
//  SapienRemoteController.m
//  roboremoteblueSample
//
//  Created by Alex Lam on 2/2/2016.
//  Copyright © 2016 Wowwee. All rights reserved.
//

#import "SapienRemoteController.h"

@implementation SapienRemoteController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    [self.leftArmDownActionButton.titleLabel setNumberOfLines:2];
    [self.leftArmLeftActionButton.titleLabel setNumberOfLines:2];
    [self.leftArmRightActionButton.titleLabel setNumberOfLines:2];
    [self.leftArmUpActionButton.titleLabel setNumberOfLines:2];
    [self.rightArmDownActionButton.titleLabel setNumberOfLines:2];
    [self.rightArmLeftActionButton.titleLabel setNumberOfLines:2];
    [self.rightArmRightActionButton.titleLabel setNumberOfLines:2];
    [self.rightArmUpActionButton.titleLabel setNumberOfLines:2];
    
    self.tiltLeftButton.tag = RSCommandsWaistLeft;
    self.tiltRightButton.tag = RSCommandsWaistRight;
    self.leanForwardButton.tag = RSCommandsLeanForward;
    self.leanBackwardButton.tag = RSCommandsLeanBackward;
    self.moveBackwardButton.tag = RSCommandsDown;
    self.moveForwardButton.tag = RSCommandsUp;
    self.moveLeftButton.tag = RSCommandsLeft;
    self.moveRightButton.tag = RSCommandsRight;
    self.stopButton.tag = RSCommandsStop;
    self.sfxWhistleButton.tag = RSCommandsSFXWhistle;
    self.demoButton.tag = RSCommandsDemo1;
    self.demo2Button.tag = RSCommandsDemo2;
    self.sfxBurpButton.tag = RSCommandsSFXBurp;
    self.sfxRoarButton.tag = RSCommandsSFXRoar;
    self.sleepButton.tag = RSCommandsSleep;
    self.listenButton.tag = RSCommandsListen;
    self.sfxOopsButton.tag = RSCommandsSFXOops;
    
    [self setArmActionMode:RoboSapienArmActionModeNormal];
}

- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    
    if(self.connectedRobot) {
        self.connectedRobot.delegate = self;
    }
    else {
        [self.navigationController popToRootViewControllerAnimated:YES];
    }
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    if(self.connectedRobot) {
        self.connectedRobot.delegate = nil;
        [self.connectedRobot disconnect];
    }
}

#pragma mark -
- (void)setArmActionMode:(int)mode {
    self.currentArmActionMode = mode;
    switch (self.currentArmActionMode) {
        case RoboSapienArmActionModeNormal:
            self.changeArmActionLeftButton.hidden = YES;
            self.changeArmActionRightButton.hidden = NO;
            
            self.leftArmLeftActionButton.tag = RSCommandsLeftHandForward;
            [self.leftArmLeftActionButton setTitle:@"Arm In" forState:UIControlStateNormal];
            self.leftArmRightActionButton.tag = RSCommandsLeftHandBackward;
            [self.leftArmRightActionButton setTitle:@"Arm Out" forState:UIControlStateNormal];
            self.leftArmUpActionButton.tag = RSCommandsLeftShoulderForward;
            [self.leftArmUpActionButton setTitle:@"Arm Up" forState:UIControlStateNormal];
            self.leftArmDownActionButton.tag = RSCommandsLeftShoulderBackward;
            [self.leftArmDownActionButton setTitle:@"Arm Down" forState:UIControlStateNormal];

            self.rightArmLeftActionButton.tag = RSCommandsRightHandForward;
            [self.rightArmLeftActionButton setTitle:@"Arm In" forState:UIControlStateNormal];
            self.rightArmRightActionButton.tag = RSCommandsRightHandBackward;
            [self.rightArmRightActionButton setTitle:@"Arm Out" forState:UIControlStateNormal];
            self.rightArmUpActionButton.tag = RSCommandsRightShoulderForward;
            [self.rightArmUpActionButton setTitle:@"Arm Up" forState:UIControlStateNormal];
            self.rightArmDownActionButton.tag = RSCommandsRightShoulderBackward;
            [self.rightArmDownActionButton setTitle:@"Arm Down" forState:UIControlStateNormal];

            break;
        case RoboSapienArmActionModePick:
            self.changeArmActionLeftButton.hidden = NO;
            self.changeArmActionRightButton.hidden = NO;
            
            self.leftArmLeftActionButton.tag = RSCommandsLeftArmThump;
            [self.leftArmLeftActionButton setTitle:@"Thump" forState:UIControlStateNormal];
            self.leftArmRightActionButton.tag = RSCommandsLeftArmSweep;
            [self.leftArmRightActionButton setTitle:@"Sweep" forState:UIControlStateNormal];
            self.leftArmUpActionButton.tag = RSCommandsLeftArmPickUp;
            [self.leftArmUpActionButton setTitle:@"Pick Up" forState:UIControlStateNormal];
            self.leftArmDownActionButton.tag = RSCommandsLeftArmThrow;
            [self.leftArmDownActionButton setTitle:@"Throw" forState:UIControlStateNormal];
            
            self.rightArmLeftActionButton.tag = RSCommandsRightArmThump;
            [self.rightArmLeftActionButton setTitle:@"Thump" forState:UIControlStateNormal];
            self.rightArmRightActionButton.tag = RSCommandsRightArmSweep;
            [self.rightArmRightActionButton setTitle:@"Sweep" forState:UIControlStateNormal];
            self.rightArmUpActionButton.tag = RSCommandsRightArmPickUp;
            [self.rightArmUpActionButton setTitle:@"Pick Up" forState:UIControlStateNormal];
            self.rightArmDownActionButton.tag = RSCommandsRightArmThrow;
            [self.rightArmDownActionButton setTitle:@"Throw" forState:UIControlStateNormal];
            
            break;
        case RoboSapienArmActionModeStrike:
            self.changeArmActionLeftButton.hidden = NO;
            self.changeArmActionRightButton.hidden = YES;
            
            self.leftArmLeftActionButton.tag = RSCommandsLeftArmStrike2;
            [self.leftArmLeftActionButton setTitle:@"Strike 2" forState:UIControlStateNormal];
            self.leftArmRightActionButton.tag = RSCommandsTalkBack;
            [self.leftArmRightActionButton setTitle:@"Talk Back" forState:UIControlStateNormal];
            self.leftArmUpActionButton.tag = RSCommandsLeftArmStrike1;
            [self.leftArmUpActionButton setTitle:@"Strike 1" forState:UIControlStateNormal];
            self.leftArmDownActionButton.tag = RSCommandsLeftArmStrike3;
            [self.leftArmDownActionButton setTitle:@"Strike 3" forState:UIControlStateNormal];
            
            self.rightArmLeftActionButton.tag = RSCommandsRightArmStrike2;
            [self.rightArmLeftActionButton setTitle:@"Strike 2" forState:UIControlStateNormal];
            self.rightArmRightActionButton.tag = RSCommandsRightArmHigh5;
            [self.rightArmRightActionButton setTitle:@"High 5" forState:UIControlStateNormal];
            self.rightArmUpActionButton.tag = RSCommandsRightArmStrike1;
            [self.rightArmUpActionButton setTitle:@"Strike 1" forState:UIControlStateNormal];
            self.rightArmDownActionButton.tag = RSCommandsRightArmStrike3;
            [self.rightArmDownActionButton setTitle:@"Strike 3" forState:UIControlStateNormal];
            
            break;
    }
}

#pragma mark -

- (IBAction)leftArmActionButtonPressed:(id)sender {
    UIButton* btn = sender;
    
    if(self.connectedRobot) {
        [self.connectedRobot robosapienWithCommand:btn.tag];
    }
}

- (IBAction)rightArmActionButtonPressed:(id)sender {
    UIButton* btn = sender;
    
    if(self.connectedRobot) {
        [self.connectedRobot robosapienWithCommand:btn.tag];
    }
}

- (IBAction)movementActionButtonPressed:(id)sender {
    UIButton* btn = sender;
    
    if(self.connectedRobot) {
        [self.connectedRobot robosapienWithCommand:btn.tag];
    }
}

- (IBAction)otherActionButtonPressed:(id)sender {
    UIButton* btn = sender;
    
    if(btn == self.changeArmActionRightButton) {
        [self setArmActionMode:MIN(self.currentArmActionMode+1, RoboSapienArmActionModeStrike)];
    }
    else if(btn == self.changeArmActionLeftButton) {
        [self setArmActionMode:MAX(self.currentArmActionMode-1, RoboSapienArmActionModeNormal)];
    }
    else {
        if(self.connectedRobot) {
            [self.connectedRobot robosapienWithCommand:btn.tag];
        }
    }
}

#pragma mark - RobosapienRobotDelegate
-(void) RobosapienDeviceReady:(RobosapienRobot *)robosapien {
    self.connectedRobot = robosapien;
    [self.connectedRobot robosapienWithCommand:RSCommandsStop];
}

-(void) RobosapienDeviceDisconnected:(RobosapienRobot *)robosapien error:(NSError *)error {
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"RoboSapien has been disconnected" message:nil preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self.navigationController popToRootViewControllerAnimated:YES];
    }]];
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
