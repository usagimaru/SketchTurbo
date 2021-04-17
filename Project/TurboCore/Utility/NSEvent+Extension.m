//
//  NSEvent+Extension.m
//
//  Created by usagimaru on 2018.07.18.
//  Copyright © 2018年 usagimaru. All rights reserved.
//

#import "NSEvent+Extension.h"

@implementation NSEvent (Extension)

// https://stackoverflow.com/questions/13807616/mac-cocoa-how-to-differentiate-if-a-nsscrollwheel-event-is-from-a-mouse-or-trac

- (BOOL)isTrackpadEvent {
	if ([self momentumPhase] != NSEventPhaseNone || [self phase] != NSEventPhaseNone) {
		return YES;
	}
	else {
		return NO;
	}
}

@end
