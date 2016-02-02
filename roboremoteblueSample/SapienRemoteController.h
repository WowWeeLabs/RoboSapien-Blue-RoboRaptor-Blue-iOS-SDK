//
//  SapienRemoteController.h
//  roboremoteblueSample
//
//  Created by Alex Lam on 2/2/2016.
//  Copyright © 2016 Wowwee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <WowweeRoboRemoteSDK/WowweeRoboRemoteSDK.h>
#import "ConstantsDefinition.h"

@interface SapienRemoteController : UIViewController <RobosapienRobotDelegate>

- (IBAction)leftArmActionButtonPressed:(id)sender;
- (IBAction)rightArmActionButtonPressed:(id)sender;
- (IBAction)movementActionButtonPressed:(id)sender;
- (IBAction)otherActionButtonPressed:(id)sender;

@property(nonatomic, weak) IBOutlet UIButton* leftArmUpActionButton;
@property(nonatomic, weak) IBOutlet UIButton* leftArmDownActionButton;
@property(nonatomic, weak) IBOutlet UIButton* leftArmLeftActionButton;
@property(nonatomic, weak) IBOutlet UIButton* leftArmRightActionButton;

@property(nonatomic, weak) IBOutlet UIButton* rightArmUpActionButton;
@property(nonatomic, weak) IBOutlet UIButton* rightArmDownActionButton;
@property(nonatomic, weak) IBOutlet UIButton* rightArmLeftActionButton;
@property(nonatomic, weak) IBOutlet UIButton* rightArmRightActionButton;

@property(nonatomic, weak) IBOutlet UIButton* changeArmActionLeftButton;
@property(nonatomic, weak) IBOutlet UIButton* changeArmActionRightButton;

@property(nonatomic, weak) IBOutlet UIButton* stopButton;
@property(nonatomic, weak) IBOutlet UIButton* moveForwardButton;
@property(nonatomic, weak) IBOutlet UIButton* moveBackwardButton;
@property(nonatomic, weak) IBOutlet UIButton* moveLeftButton;
@property(nonatomic, weak) IBOutlet UIButton* moveRightButton;
@property(nonatomic, weak) IBOutlet UIButton* tiltLeftButton;
@property(nonatomic, weak) IBOutlet UIButton* tiltRightButton;
@property(nonatomic, weak) IBOutlet UIButton* leanForwardButton;
@property(nonatomic, weak) IBOutlet UIButton* leanBackwardButton;

@property(nonatomic, weak) IBOutlet UIButton* sfxWhistleButton;
@property(nonatomic, weak) IBOutlet UIButton* demoButton;
@property(nonatomic, weak) IBOutlet UIButton* demo2Button;
@property(nonatomic, weak) IBOutlet UIButton* sfxBurpButton;
@property(nonatomic, weak) IBOutlet UIButton* sfxRoarButton;
@property(nonatomic, weak) IBOutlet UIButton* listenButton;
@property(nonatomic, weak) IBOutlet UIButton* sleepButton;
@property(nonatomic, weak) IBOutlet UIButton* sfxOopsButton;

@property(nonatomic, strong) RobosapienRobot* connectedRobot;
@property(nonatomic, assign)int currentArmActionMode;

@end
