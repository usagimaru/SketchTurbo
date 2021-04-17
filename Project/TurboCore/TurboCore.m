//
//  TurboCore.m
//  SketchTurbo
//
//  Created by Satori Maru on 2018/07/18.
//Copyright © 2018年 usagimaru. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TurboCore.h"
#import "TBMSContentDrawViewProxy.h"


@interface TurboCore : NSObject

@end


@implementation TurboCore

+ (void)initialize {
	[super initialize];
	[TBMSContentDrawViewProxy injection];
}

@end

