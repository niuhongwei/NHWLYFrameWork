//
//  LDMCheckImageCaptchaInput.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/12/2.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface LDMCheckImageCaptchaInput : NSObject

@property (nonatomic, copy, readwrite) NSString *appKey;            //appKey
@property (nonatomic, copy, readwrite) NSString *deviceId;          //设备id
@property (nonatomic, copy, readwrite) NSString *dmsUID;            //DMS UID
@property (nonatomic, copy, readwrite) NSString *dmsTK;             //DMS Token
@property (nonatomic, copy, readwrite) NSString *captcha;           //验证码
@property (nonatomic, copy, readwrite) NSString *time;              //时间戳
@property (nonatomic, copy, readwrite) NSString *sign;              //sign

@end
