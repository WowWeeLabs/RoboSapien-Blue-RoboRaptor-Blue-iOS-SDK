//
//  ConnectionViewController.h
//  roboremoteblueSample
//
//  Created by Alex Lam on 1/2/2016.
//  Copyright © 2016 Wowwee. All rights reserved.
//

#import <WowweeRoboRemoteSDK/WowweeRoboRemoteSDK.h>
#import "ConstantsDefinition.h"

@interface ConnectionViewController : UIViewController <UITableViewDataSource, UITableViewDelegate, RoboraptorRobotDelegate, RobosapienRobotDelegate>
{
}

- (IBAction)refreshButtonPressed:(id)sender;

@property (nonatomic, weak) IBOutlet UITableView* tableView;

@end
