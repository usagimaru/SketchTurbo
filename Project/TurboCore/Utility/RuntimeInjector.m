//
//  RuntimeInjector.m
//
//  Created by usagimaru on 2018.01.03.
//  Copyright © 2018年 usagimaru. All rights reserved.
//

#import "RuntimeInjector.h"
#import <objc/runtime.h>
#import "JRSwizzle.h"

@implementation NSObject (RuntimeInjection)

- (id)associatedObjectForKey:(const void*)key {
	return objc_getAssociatedObject(self, key);
}

- (void)setAssociatedObject:(id)object key:(const void*)key {
	objc_setAssociatedObject(self, key, object, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
}

- (id)instanceVariableForName:(NSString*)ivarName {
	Ivar ivar = class_getInstanceVariable([self class], [ivarName cStringUsingEncoding:NSUTF8StringEncoding]);
	return object_getIvar(self, ivar);
}

+ (BOOL)swizzleClassMethod:(NSString*)methodSelectorName proxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector {
	Method proxyMethod = class_getInstanceMethod(proxyClass, proxySelector);
	class_addMethod(self,
					method_getName(proxyMethod),
					method_getImplementation(proxyMethod),
					method_getTypeEncoding(proxyMethod));

	return [self jr_swizzleClassMethod:NSSelectorFromString(methodSelectorName)
				withClassMethod:proxySelector
						  error:nil];
}

+ (BOOL)swizzleInstanceMethod:(NSString*)methodSelectorName proxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector {
	Method proxyMethod = class_getInstanceMethod(proxyClass, proxySelector);
	class_addMethod(self,
					method_getName(proxyMethod),
					method_getImplementation(proxyMethod),
					method_getTypeEncoding(proxyMethod));
	
	return [self jr_swizzleMethod:NSSelectorFromString(methodSelectorName)
					   withMethod:proxySelector
							error:nil];
}

+ (BOOL)addClassMethodInProxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector {
	Method proxyMethod = class_getClassMethod(proxyClass, proxySelector);
	return class_addMethod(self,
						   method_getName(proxyMethod),
						   method_getImplementation(proxyMethod),
						   method_getTypeEncoding(proxyMethod));
}

+ (BOOL)addInstanceMethodInProxyClass:(Class)proxyClass proxySelector:(SEL)proxySelector {
	Method proxyMethod = class_getInstanceMethod(proxyClass, proxySelector);
	return class_addMethod(self,
						   method_getName(proxyMethod),
						   method_getImplementation(proxyMethod),
						   method_getTypeEncoding(proxyMethod));
}

+ (BOOL)addProtocolWithName:(const void*)protocolName {
	Protocol *protocol = objc_allocateProtocol(protocolName);
	return class_addProtocol(self, protocol);
}

@end
