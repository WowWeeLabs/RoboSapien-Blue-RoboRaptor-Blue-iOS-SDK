//
//  RaptorRemoteController.m
//  roboremoteblueSample
//
//  Created by Alex Lam on 2/2/2016.
//  Copyright © 2016 Wowwee. All rights reserved.
//

#import "RaptorRemoteController.h"

@implementation RaptorRemoteController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    self.headClockwiseButton.tag = RoboraptorCommandsHeadClockwise;
    self.headCounterClockwiseButton.tag = RoboraptorCommandsHeadCounterClockwise;
    self.tailLeftButton.tag = RoboraptorCommandsTailLeft;
    self.tailRightButton.tag = RoboraptorCommandsTailRight;
    self.biteButton.tag = RoboraptorCommandsBite;
    self.moveUpButton.tag = RoboraptorCommandsUp;
    self.moveDownButton.tag = RoboraptorCommandsDown;
    self.moveLeftButton.tag = RoboraptorCommandsLeft;
    self.moveRightButton.tag = RoboraptorCommandsRight;
    self.stopButton.tag = RoboraptorCommandsStop;
    self.guardModeButton.tag = RoboraptorCommandsGuardMode;
    self.demoButton.tag = RoboraptorCommandsDemo;
    self.huntingModeButton.tag = RoboraptorCommandsHuntingMode;
    self.cautionsModeButton.tag = RoboraptorCommandsCautiousMode;
    self.roamButton.tag = RoboraptorCommandsRoam;
    self.playfulModeButton.tag = RoboraptorCommandsPlayfulMode;
    

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

- (IBAction)actionButtonPressed:(id)sender {
    UIButton* btn = sender;
    
    if(self.connectedRobot) {
        [self.connectedRobot roboraptorWithCommand:btn.tag];
    }
}


#pragma mark - RoboraptorRobotDelegate
-(void) RoboraptorDeviceReady:(RoboraptorRobot *)Roboraptor {
    self.connectedRobot = Roboraptor;
    [Roboraptor roboraptorWithCommand:RoboraptorCommandsStop];
}

-(void) RoboraptorDeviceDisconnected:(RoboraptorRobot *)Roboraptor error:(NSError *)error {
    UIAlertController* alert = [UIAlertController alertControllerWithTitle:@"Raptor has been disconnected" message:nil preferredStyle:UIAlertControllerStyleAlert];
    [alert addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        [self.navigationController popToRootViewControllerAnimated:YES];
    }]];
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

@end
