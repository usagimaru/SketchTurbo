//
//  RuntimeInjector.h
//
//  Created by usagimaru on 2018.01.03.
//  Copyright © 2018年 usagimaru. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface NSObject (RuntimeInjection)

- (id)associatedObjectForKey:(const void*)key;
- (void)setAssociatedObject:(id)object key:(const void*)key;
- (id)instanceVariableForName:(NSString*)ivarName;

+ (BOOL)swizzleClassMethod:(NSString*)methodSelectorName proxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector;
+ (BOOL)swizzleInstanceMethod:(NSString*)methodSelectorName proxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector;

+ (BOOL)addClassMethodInProxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector;
+ (BOOL)addInstanceMethodInProxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector;
+ (BOOL)addProtocolWithName:(const void*)protocolName;

@end
