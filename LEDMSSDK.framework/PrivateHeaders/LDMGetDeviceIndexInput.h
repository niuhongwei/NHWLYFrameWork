//
//  LDMGetDeviceIndexInput.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/22.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

/****
 *
 * 请求获取设备管理首页信息参数
 *
 ****/
@interface LDMGetDeviceIndexInput : NSObject

@property (nonatomic, copy, readwrite) NSString *appKey;            //appKey
@property (nonatomic, copy, readwrite) NSString *dmsUID;            //DMS UID
@property (nonatomic, copy, readwrite) NSString *ssoTK;            //ssoTK(必传)
@property (nonatomic, copy, readwrite) NSString *deviceId;          //设备id
@property (nonatomic, copy, readwrite) NSString *dmsTK;             //DMS Token
@property (nonatomic, copy, readwrite) NSString *lat;               //纬度
@property (nonatomic, copy, readwrite) NSString *longitude;         //经度
@property (nonatomic, copy, readwrite) NSString *time;              //时间戳
@property (nonatomic, copy, readwrite) NSString *sign;              //sign
@property (nonatomic, copy, readwrite) NSString *uid;               //用户id

@end
