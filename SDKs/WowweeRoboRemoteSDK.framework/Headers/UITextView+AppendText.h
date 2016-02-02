//
//  UITextView+AppendText.h
//  BobiMipTester
//
//  Created by Andy on 2/12/13.
//  Copyright (c) 2013 Andy. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UITextView (AppendText)

-(void) appendText:(NSString *)text;
-(void) appendText:(NSString *)appendText withNewline:(bool)newline;
-(BOOL)sizeFontToFit:(NSString*)aString minSize:(float)aMinFontSize maxSize:(float)aMaxFontSize;

@end
