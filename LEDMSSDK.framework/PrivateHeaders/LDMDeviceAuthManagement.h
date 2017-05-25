//
//  LDMDeviceAuthManagement.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/22.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

#include "NSDate+CurrentTimeInterval.h"

#import "LDMDeviceLoginInput.h"
#import "LDMDeviceLogoutInput.h"
#import "LDMGetDeviceDetailInfoInput.h"
#import "LDMCheckDeviceAuthorizationInput.h"
#import "LDMGetDeviceIndexInput.h"
#import "LDMHitDeviceOfflineInput.h"
#import "LDMModifyDeviceNicknameInput.h"
#import "LDMGetLoginLogInput.h"
#import "LDMModifyDeviceAuthorizationInput.h"
#import "LDMSendDeviceCaptchaInput.h"
#import "LDMCheckDeviceCaptchaInput.h"
#import "LDMCheckImageCaptchaInput.h"
#import "LDMGetImageCaptchaInput.h"

@interface LDMDeviceAuthManagement : NSObject

NS_ASSUME_NONNULL_BEGIN
@property (nonatomic, copy, readwrite) NSString *deviceId;              // 设备
@property (nonatomic, copy, readwrite) NSString *uid;                   // 用户id
@property (nonatomic, copy, readwrite) NSString *ssoTK;                 // SSO Token;
@property (nonatomic, copy, readwrite) NSString *dmsUID;                // DMS UID
@property (nonatomic, copy, readwrite) NSString *dmsTK;                 // DMS Token
@property (nonatomic, copy, readwrite) NSString *appKey;                // appKey
@property (nonatomic, assign) BOOL isDebug;                             // 是否使用Debug环境

/****
 *
 * 单例类
 *
 ****/
+ (LDMDeviceAuthManagement * _Nullable)shareInstance;

- (instancetype)init NS_UNAVAILABLE;

/****
 *
 * 存储基本信息
 *
 ****/
- (void)setUserInfoValue:(NSString * _Nonnull)value forKey:(NSString *_Nonnull)key;

/****
 *
 * 加载基本信息
 *
 ****/
- (NSString * _Nullable)loadUserInfoByKey:(NSString * _Nonnull)key;

/****
 *
 * 删除基本信息
 *
 ****/
- (void)removeUserInfoByKey:(NSString * _Nonnull)key;

/****
 *
 * 开始计时
 *
 ****/
- (void)timerStart;

/****
 *
 * 完成计时
 *
 ****/
- (void)timerFinish;

/****
 *
 * 重置计时器
 *
 ****/
- (void)timerReset;

/****
 *
 * 获取计时器时间
 *
 ****/
- (CGFloat)timerCurrentTime;

/****
 *
 * 计时器是否运行
 *
 ****/
- (BOOL)timerIsRunning;

/****
 *
 * 计时器是否结束
 *
 ****/
- (BOOL)timerIsFinish;

/****
 *
 *  功能: 设备登陆
 *
 *  参数: deviceLoginData
 *       completion
 *
 *  返回值: code:      int     //返回结果, 0:成功
 *         errorMsg:  string  //错误信息
 *         errorDesc: string  //错误详细信息
 *         dmsTK:     string  //DMS Token
 *         dmsUID:    bigint  //
 *
 *         {
 *             "code":      0,
 *             "errorMsg":  "",
 *             "errorDesc": "",
 *             "data":
 *             [
 *                 "dmsTK":         "123abc"
 *                 "dmsUID":        112233
 *             ]
 *         }
 *
 ****/
- (void)login:(LDMDeviceLoginInput * _Nonnull)deviceLoginInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 设备注销
 *
 * 参数: deviceLogoutData
 *      completion
 *
 * 返回参数: code:      int     //返回结果, 0:成功
 *          errorMsg:  string  //错误信息
 *          errorDesc: string  //错误详细信息
 *
 *         {
 *              "code":      0,
 *              "errorMsg":  "",
 *              "errorDesc": ""
 *         }
 ****/
- (void)logout:(LDMDeviceLogoutInput * _Nonnull)deviceLogoutInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 获取设备详细信息
 * 参数: getDeviceDetailInfo
 *      completion
 *
 * 返回参数: code:                int     //返回结果, 0:成功
 *          errorMsg:            string  //错误信息
 *          errorDesc:           string  //错误详细信息
 *          deviceId:            string  //设备id
 *          deviceName:          string  //设备型号
 *          deviceNickname:      string  //设备别名
 *          authorization:       int     //设备权限, 0:未授权, 1:普通, 2:信任, 3:禁用
 *          isOnline:            int     //是否在线, 0:否, 1:是
 *          city:                string  //常用登录城市
 *          currentCity:         string  //当前登录城市（下线设备该项为空）
 *          lastLoginTime:       string  //最近登录时间
 *          isSyncPassword:      int     //是否同步密码, 0:否, 1:是
 *          isOnlineNotice:      int     //是否在线通知, 0:否, 1:是
 *          maxOnlineDevice:     int     //允许在线设备数
 *          currentOnlineDevice: int     //当前在线设备数
 *          maxLoginDevice:      int     //允许登录设备数
 *          currentLoginDevice:  int     //当前登录设备数
 *
 *         {
 *             "code":      0,
 *             "errorMsg":  "",
 *             "errorDesc": "",
 *             "data":
 *                 [
 *                     "deviceId": "111",
 *                     "deviceName": "iPhone 7",
 *                     "deviceNickname": "李白的iPhone 7",
 *                     "authorization": 2,
 *                     "isOnline": 1,
 *                     "city": "北京",
 *                     "currentCity": "北京",
 *                     "lastLoginTime": "2016-11-11 11:11",
 *                     "isSyncPassword": 1,
 *                     "isOnlineNotice": 1,
 *                     "maxOnlineDevice": 2,
 *                     "currentOnlineDevice": 1,
 *                     "maxLoginDevice": 5,
 *                     "currentLoginDevice": 3
 *                 ]
 *         }
 *
 ****/
- (void)getDeviceDetailInfo:(LDMGetDeviceDetailInfoInput * _Nonnull)getDeviceDetailInfoInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 设备管理权限验证（进入设备管理时触发）
 *
 * 参数: checkDeviceAuthorization
 *      completion
 *
 * 返回参数: code:      int     //返回结果, 0:成功
 *          errorMsg:  string  //错误信息
 *          errorDesc: string  //错误详细信息
 *          ok:        int     //是否有设备管理权限，0:无(需要进行短信验证), 1:有(可以直接进入)
 *          mobile:    string  //账号绑定的手机号(ok为0时返回该值，ok为1时该值为空)
 *          {
 *              "code":      0,
 *              "errorMsg":  "",
 *              "errorDesc": "",
 *              "data":
 *              [
 *                  "ok":     0,
 *                  "mobile": "138****1001"
 *              ]
 *          }
 ****/
- (void)checkDeviceAuthorization:(LDMCheckDeviceAuthorizationInput * _Nonnull)checkDeviceAuthorizationInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 获取设备管理首页信息
 *
 * 参数: getDeviceIndexInput
 *      completion
 *
 * 返回参数:    code:                int     //返回结果, 0:成功
 *             errorMsg:            string  //错误信息
 *             errorDesc:           string  //错误详细信息
 *             nickname:            string  //昵称
 *             mobile:              string  //绑定手机号
 *             vip:                 int     //0:非会员, 1:会员
 *             maxOnlineDevice:     int     //允许在线设备数
 *             currentOnlineDevice: int     //当前在线设备数
 *             maxLoginDevice:      int     //允许登录设备数
 *             currentLoginDevice:  int     //当前登录设备数
 *             deviceList:                  //设备列表
 *             deviceId:            string  //设备id
 *             deviceName:          string  //设备型号
 *             deviceNickname:      string  //设备别名
 *             tipType:             string  //提示信息: 本机，信任，普通
 *             authorization:       int     //设备权限, 0:未授权, 1:普通, 2:信任, 3:禁用
 *             isOnline:            int     //是否在线, 0:否, 1:是
 *             city:                string  //常用登录城市（一期返回上次登录城市）
 *             currentCity:         string  //当前登录城市（下线设备该项为空）
 *             lastLoginTime:       string  //最近登录时间
 *             isSyncPassword:      int     //是否同步密码, 0:否, 1:是
 *             isOnlineNotice:      int     //是否在线通知, 0:否, 1:是
 *
 *            {
 *                "code":      0,
 *                "errorMsg":  "",
 *                "errorDesc": "",
 *                "data":
 *                    [
 *                        "nickname": "",
 *                        "mobile": "139****1822",
 *                        "vip": 0,
 *                        "maxOnlineDevice": 2,
 *                        "currentOnlineDevice": 1,
 *                        "maxLoginDevice": 5,
 *                        "currentLoginDevice": 3,
 *                        "deviceList":{
 *                                         [
 *                                             "deviceId": "111",
 *                                             "deviceName": "iPhone 6",
                                               "deviceModel": "iPhone 6 Plus",
 *                                             "deviceNickname": "李白的iPhone 6",
 *                                             "tipType": "本机",
 *                                             "authorization": 2,
 *                                             "isOnline": 1,
 *                                             "city": "北京",
 *                                             "currentCity": "北京",
 *                                             "lastLoginTime": "2016-11-11 11:11",
 *                                             "isSyncPassword": 1,
 *                                             "isOnlineNotice": 1
 *                                         ],
 *                                         [
 *                                             "deviceId": "222",
 *                                             "deviceName": "iPhone 7",
                                               "deviceModel": "iPhone 6 Plus",
 *                                             "deviceNickname": "李白的iPhone 7",
 *                                             "tipType": "信任",
 *                                             "authorization": 1,
 *                                             "isOnline": 0,
 *                                             "city": "上海",
 *                                             "currentCity": "",
 *                                             "lastLoginTime": "2016-11-10 11:11",
 *                                             "isSyncPassword": 0,
 *                                             "isOnlineNotice": 0
 *                                         ]
 *                                      }
 *                    ]
 *           }
 *
 ****/
- (void)getDeviceIndex:(LDMGetDeviceIndexInput * _Nonnull)getDeviceIndexInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 强制关联设备下线
 *
 * 参数: getDeviceIndexInput
 *      completion
 *
 * 返回参数:
 *            code:      int     //返回结果, 0:成功, -1:失败
 *            errorMsg:  string  //错误信息
 *            errorDesc: string  //错误详细信息
 *
 *            {
 *                "code":      0,
 *                "errorMsg":  "",
 *                "errorDesc": ""
 *            }
 *
 ****/
- (void)hitDeviceOffline:(LDMHitDeviceOfflineInput * _Nonnull)hitDeviceOffline completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 修改设备别名
 *
 * 参数: modifyDeviceNicknameInput
 *       completion
 *
 * 返回参数: code:      int     //返回结果, 0:成功, -1:失败
 *          errorMsg:  string  //错误信息
 *          errorDesc: string  //错误详细信息
 *
 *          {
 *              "code":      0,
 *              "errorMsg":  "",
 *              "errorDesc": ""
 *          }
 *
 ****/
- (void)modifyDeviceNickname:(LDMModifyDeviceNicknameInput * _Nonnull)modifyDeviceNicknameInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 获取登录记录
 *
 * 参数: getLoginLogInput
 *       completion
 *
 * 返回参数: code:         int     //返回结果, 0:成功
 *          errorMsg:     string  //错误信息
 *          errorDesc:    string  //错误详细信息
 *          page:         int     //当前页码
 *          cnt:          int     //共多少条
 *          pageCnt:      int     //共多少页
 *          loginLogList:         //登录记录列表
 *          loginTime:    string  //登录时间
 *          ip:           string  //登录ip
 *          city:         string  //登录城市
 *
 *          {
 *              "code":      0,
 *              "errorMsg":  "",
 *              "errorDesc": "",
 *              "data":
 *              [
 *                  "page":         1,
 *                  "cnt":          134,
 *                  "pageCnt":      3,
 *                  "loginLogList": {
 *                      [
 *                          "loginTime": "2016-11-11 11:11",
 *                          "ip":        "123.12.12.***",
 *                          "city":      "北京"
 *                      ],
 *                      [
 *                          "loginTime": "2016-11-10 11:11",
 *                          "ip":        "123.12.14.***",
 *                          "city":      "上海"
 *                      ]
 *                  }
 *              ]
 *          }
 *
 ****/
- (void)getLoginLog:(LDMGetLoginLogInput * _Nonnull)getLoginLogInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 修改设备权限
 *
 * 参数: modifyDeviceAuthorizationInput
 *       completion
 *
 * 返回参数: code:      int     //返回结果, 0:成功, -1:失败
 *          errorMsg:  string  //错误信息
 *          errorDesc: string  //错误详细信息
 *
 *          {
 *              "code":      0,
 *              "errorMsg":  "",
 *              "errorDesc": ""
 *          }
 *
 ****/
- (void)modifyDeviceAuthorization:(LDMModifyDeviceAuthorizationInput * _Nonnull)modifyDeviceAuthorizationInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 下发设备管理短信验证码
 *
 * 参数: sendDeviceCaptchaInput
 *       completion
 *
 * 返回参数: code:      int     //返回结果, 0:成功, -1:失败
 *          errorMsg:  string  //错误信息
 *          errorDesc: string  //错误详细信息
 *
 *          {
 *              "code":      0,
 *              "errorMsg":  "",
 *              "errorDesc": ""
 *          }
 *
 ****/
- (void)sendDeviceCaptcha:(LDMSendDeviceCaptchaInput * _Nonnull)sendDeviceCaptchaInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 上送设备管理短信验证码
 *
 * 参数:
 *
 ****/
- (void)checkDeviceCaptcha:(LDMCheckDeviceCaptchaInput * _Nonnull)checkDeviceCaptchaInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 获取图片验证码
 *
 * 参数: LDMGetImageCaptchaInput
 *       completionHandler
 *
 * 返回参数: body:      byte  //图片的二进制文件
 *
 ****/
- (void)getImageCaptcha:(LDMGetImageCaptchaInput * _Nonnull)getImageCaptchaInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

/****
 *
 * 功能: 上送图片验证码
 *
 * 参数: LDMCheckImageCaptchaInput
 *       completionHandler
 *
 * 返回参数: code:      int     //返回结果, 0:成功, -1:失败
 *          errorMsg:  string  //错误信息
 *          errorDesc: string  //错误详细信息
 *          返回示例:
 *          {
 *               "code":      0,
 *               "errorMsg":  "",
 *               "errorDesc": ""
 *          }
 *
 ****/
- (void)checkImageCaptcha:(LDMCheckImageCaptchaInput * _Nonnull)checkImageCaptchaInput completionHandler:(void (^ _Nonnull)(NSData * _Nullable data, NSURLResponse * _Nullable response, NSError * _Nullable error))completion;

NS_ASSUME_NONNULL_END

@end
