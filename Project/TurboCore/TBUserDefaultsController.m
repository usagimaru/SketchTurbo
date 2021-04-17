//
//  TBUserDefaultsController.m
//
//  Created by usagimaru on 2018.07.18.
//  Copyright © 2018年 usagimaru. All rights reserved.
//

#import "TBUserDefaultsController.h"

@implementation TBUserDefaultsController

static NSString *kTrackPadScrollDeltaKey = @"SketchTurbo_TrackPadScrollDelta";
static NSString *kMouseWheelScrollDeltaXKey = @"SketchTurbo_MouseWheelScrollDeltaX";
static NSString *kMouseWheelScrollDeltaYKey = @"SketchTurbo_MouseWheelScrollDeltaY";
static CGFloat trackPadScrollDeltaDefault = 1.5;
static CGFloat mouseWheelScrollDeltaXDefault = 5.0;
static CGFloat mouseWheelScrollDeltaYDefault = 6.0;

+ (void)setTrackPadScrollDelta:(CGFloat)delta {
	NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
	[ud setDouble:delta forKey:kTrackPadScrollDeltaKey];
}
+ (CGFloat)trackPadScrollDelta {
	NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
	double v = [ud doubleForKey:kTrackPadScrollDeltaKey];
	if (v == 0.0) {
		return trackPadScrollDeltaDefault;
	}
	return v;
}
+ (void)setMouseWheelScrollDeltaX:(CGFloat)delta {
	NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
	[ud setDouble:delta forKey:kMouseWheelScrollDeltaXKey];
}
+ (void)setMouseWheelScrollDeltaY:(CGFloat)delta {
	NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
	[ud setDouble:delta forKey:kMouseWheelScrollDeltaYKey];
}
+ (CGFloat)mouseWheelScrollDeltaX {
	NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
	double v = [ud doubleForKey:kMouseWheelScrollDeltaXKey];
	if (v == 0.0) {
		return mouseWheelScrollDeltaXDefault;
	}
	return v;
}
+ (CGFloat)mouseWheelScrollDeltaY {
	NSUserDefaults *ud = [NSUserDefaults standardUserDefaults];
	double v = [ud doubleForKey:kMouseWheelScrollDeltaYKey];
	if (v == 0.0) {
		return mouseWheelScrollDeltaYDefault;
	}
	return v;
}

+ (void)synchronized {
	[[NSUserDefaults standardUserDefaults] synchronize];
}

@end
