//
//  LDMDeviceLimitModel.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/30.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDMDeviceLimitModel : NSObject

@property (nonatomic, copy, readwrite) NSString *title;
@property (nonatomic, copy, readwrite) NSString *errorMessage;
@property (nonatomic, copy, readwrite) NSString *todoMessage;
@property (nonatomic, copy, readwrite) NSString *buttonText;

@end
