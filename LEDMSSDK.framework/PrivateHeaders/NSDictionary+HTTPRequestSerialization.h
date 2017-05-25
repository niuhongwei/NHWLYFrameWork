//
//  NSDictionary+HTTPRequestSerialization.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/22.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface NSDictionary (HTTPRequestSerialization)

+ (NSString *)LDMHTTPBody:(NSDictionary *)dict;

@end
