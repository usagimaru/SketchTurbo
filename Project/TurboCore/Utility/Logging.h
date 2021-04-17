//
//  Logging.h
//
//  Created by usagimaru on 2018.07.17.
//  Copyright © 2018年 usagimaru. All rights reserved.
//

#define MyLog(...) NSLog(@"🐰 %s %@", __PRETTY_FUNCTION__, [NSString stringWithFormat:__VA_ARGS__]);
