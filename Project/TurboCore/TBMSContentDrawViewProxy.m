//
//  TBMSContentDrawViewProxy.m
//
//  Created by usagimaru on 2018.07.18.
//  Copyright © 2018年 usagimaru. All rights reserved.
//

#import "TBMSContentDrawViewProxy.h"
#import "TBUserDefaultsController.h"
#import "SketchRuntime.h"
#import "RuntimeInjector.h"
#import "NSEvent+Extension.h"
#import "Logging.h"

@interface TBMSContentDrawViewProxy ()

@end

@implementation TBMSContentDrawViewProxy


Class _Nullable MSContentDrawViewClass() {
	return NSClassFromString(@"MSContentDrawView");
}

+ (void)initialize {
	[super initialize];
	
	Class MSContentDrawView = MSContentDrawViewClass();
	[MSContentDrawView swizzleInstanceMethod:@"scrollWheelScroll:"
								  proxyClass:self
							   proxySelector:@selector(navigatorCore_scrollWheelScroll:)];
}

+ (void)injection {
	MyLog(@"");
}

- (void)navigatorCore_scrollWheelScroll:(NSEvent*)event {
	id <TurboCoreMSContentDrawView> contentDrawView = (id <TurboCoreMSContentDrawView>)self;
	if (![contentDrawView isKindOfClass:MSContentDrawViewClass()]) {
		[self navigatorCore_scrollWheelScroll:event];
		return;
	}
	
	CGPoint p = contentDrawView.scrollOrigin;
	CGFloat deltaX = 1.0;
	CGFloat deltaY = 1.0;
	
	if ([event isTrackpadEvent]) {
		deltaX = [TBUserDefaultsController trackPadScrollDelta];
		deltaY = deltaX;
	}
	else {
		deltaX = [TBUserDefaultsController mouseWheelScrollDeltaX];
		deltaY = [TBUserDefaultsController mouseWheelScrollDeltaY];
	}

	// shift 押下中はYがXに切り替わるため、それに対応する
	if (NSEvent.modifierFlags & NSEventModifierFlagShift) {
		p.x += event.scrollingDeltaX * deltaY;
		p.y += event.scrollingDeltaY * deltaY;
		//MyLog(@"shift")
	}
	else {
		p.x += event.scrollingDeltaX * deltaX;
		p.y += event.scrollingDeltaY * deltaY;
		//MyLog(@"normal")
	}
	MyLog(@"%.1f : %.1f", p.x, p.y)

	[contentDrawView scrollToScrollOrigin:p];
}

@end
