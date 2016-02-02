//
//  RaptorRemoteController.h
//  roboremoteblueSample
//
//  Created by Alex Lam on 2/2/2016.
//  Copyright © 2016 Wowwee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WowweeRoboRemoteSDK/WowweeRoboRemoteSDK.h>
#import "ConstantsDefinition.h"

@interface RaptorRemoteController : UIViewController <RoboraptorRobotDelegate>

- (IBAction)actionButtonPressed:(id)sender;

@property(nonatomic, weak) IBOutlet UIButton* headClockwiseButton;
@property(nonatomic, weak) IBOutlet UIButton* headCounterClockwiseButton;
@property(nonatomic, weak) IBOutlet UIButton* tailRightButton;
@property(nonatomic, weak) IBOutlet UIButton* tailLeftButton;
@property(nonatomic, weak) IBOutlet UIButton* biteButton;
@property(nonatomic, weak) IBOutlet UIButton* moveUpButton;
@property(nonatomic, weak) IBOutlet UIButton* moveDownButton;
@property(nonatomic, weak) IBOutlet UIButton* moveLeftButton;
@property(nonatomic, weak) IBOutlet UIButton* moveRightButton;
@property(nonatomic, weak) IBOutlet UIButton* stopButton;
@property(nonatomic, weak) IBOutlet UIButton* guardModeButton;
@property(nonatomic, weak) IBOutlet UIButton* demoButton;
@property(nonatomic, weak) IBOutlet UIButton* huntingModeButton;
@property(nonatomic, weak) IBOutlet UIButton* cautionsModeButton;
@property(nonatomic, weak) IBOutlet UIButton* roamButton;
@property(nonatomic, weak) IBOutlet UIButton* playfulModeButton;

@property(nonatomic, strong) RoboraptorRobot* connectedRobot;

@end
