//
//  NSData+Sha256.h
//  MIP
//
//  Created by Andy on 20/1/14.
//  Copyright (c) 2014 WowWee Group Limited. All rights reserved.
//

@import Foundation;

@interface NSData (Sha256)

- (NSString *) sha256Hash;
- (NSString *) sha256HashHumanReadable:(bool)humanReadable;

@end
