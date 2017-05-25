//
//  LDMDeviceLoginInput.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/23.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

/****
 *
 * 请求设备登陆参数
 *
 ****/
@interface LDMDeviceLoginInput : NSObject

@property (nonatomic, copy, readwrite) NSString *appKey;            //appKey
@property (nonatomic, copy, readwrite) NSString *uid;                //用户id
@property (nonatomic, copy, readwrite) NSString *deviceId;          //设备id
@property (nonatomic, copy, readwrite) NSString *ssoTK;             //SSO Token
@property (nonatomic, copy, readwrite) NSString *deviceName;        //设备名称
@property (nonatomic, copy, readwrite) NSString *deviceModel;       //设备型号
@property (nonatomic, copy, readwrite) NSString *appVersionCode;        //app版本信息(eg:230)
@property (nonatomic, copy, readwrite) NSString *appVersionName;        //app版本信息(eg:1.2.1)
@property (nonatomic, copy, readwrite) NSString *imei;              //imei
@property (nonatomic, copy, readwrite) NSString *platform;           //平台
@property (nonatomic, copy, readwrite) NSString *lat;                //纬度
@property (nonatomic, copy, readwrite) NSString *longitude;          //经度
@property (nonatomic, copy, readwrite) NSString *time;               //时间戳
@property (nonatomic, copy, readwrite) NSString *sign;              //sign

@end
