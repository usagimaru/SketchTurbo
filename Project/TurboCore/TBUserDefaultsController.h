//
//  TBUserDefaultsController.h
//
//  Created by usagimaru on 2018.07.18.
//  Copyright © 2018年 usagimaru. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TBUserDefaultsController : NSObject

+ (void)setTrackPadScrollDelta:(CGFloat)delta;
+ (CGFloat)trackPadScrollDelta;
+ (void)setMouseWheelScrollDeltaX:(CGFloat)delta;
+ (void)setMouseWheelScrollDeltaY:(CGFloat)delta;
+ (CGFloat)mouseWheelScrollDeltaX;
+ (CGFloat)mouseWheelScrollDeltaY;

+ (void)synchronized;

@end
