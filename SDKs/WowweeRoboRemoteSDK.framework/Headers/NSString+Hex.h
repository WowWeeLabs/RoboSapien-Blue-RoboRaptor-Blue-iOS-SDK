//
//  NSString+Hex.h
//  Bluetooth Library Tester
//
//  Created by Andy on 24/9/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

@import Foundation;

@interface NSString (Hex)

-(NSUInteger) hexFromString;
-(unsigned long long) longLongHexFromString;
+(NSString *) EightBitStringWithUInt8:(uint8_t)number;

@end
