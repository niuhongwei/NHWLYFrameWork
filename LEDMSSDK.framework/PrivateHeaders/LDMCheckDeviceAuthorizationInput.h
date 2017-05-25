//
//  LDMCheckDeviceAuthorizationInput.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/22.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

/****
 *
 * 请求设备管理权限验证(进入设备管理时触发)参数
 *
 ****/
@interface LDMCheckDeviceAuthorizationInput : NSObject

@property (nonatomic, copy, readwrite) NSString *appKey;            //appKey
@property (nonatomic, copy, readwrite) NSString *uid;               //用户id
@property (nonatomic, copy, readwrite) NSString *dmsUID;            //DMS UID
@property (nonatomic, copy, readwrite) NSString *deviceId;          //设备id
@property (nonatomic, copy, readwrite) NSString *ssoTK;             //SSO Token
@property (nonatomic, copy, readwrite) NSString *dmsTK;             //DMS Token
@property (nonatomic, copy, readwrite) NSString *time;              //时间戳
@property (nonatomic, copy, readwrite) NSString *sign;              //sign


@end
