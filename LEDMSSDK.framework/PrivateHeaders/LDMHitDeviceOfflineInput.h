//
//  LDMHitDeviceOfflineInput.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/22.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

/****
 *
 * 请求强制关联设备下线参数
 *
 ****/
@interface LDMHitDeviceOfflineInput : NSObject

@property (nonatomic, copy, readwrite) NSString *appKey;            //appKey
@property (nonatomic, copy, readwrite) NSString *dmsUID;            //DMS UID
@property (nonatomic, copy, readwrite) NSString *deviceId;          //设备id
@property (nonatomic, copy, readwrite) NSString *dmsTK;             //DMS Token
@property (nonatomic, copy, readwrite) NSString *qDeviceId;         //下线设备id
@property (nonatomic, copy, readwrite) NSString *time;              //时间戳
@property (nonatomic, copy, readwrite) NSString *sign;              //sign

@end
