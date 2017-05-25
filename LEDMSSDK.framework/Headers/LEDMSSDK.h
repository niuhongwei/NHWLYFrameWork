//
//  LEDMSSDK.h
//  LEDMSSDK
//
//  Created by 王为 on 06/12/2016.
//  Copyright © 2016 王为. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for LEDMSSDK.
FOUNDATION_EXPORT double LEDMSSDKVersionNumber;

//! Project version string for LEDMSSDK.
FOUNDATION_EXPORT const unsigned char LEDMSSDKVersionString[];


/**
 设备下线通知
 收到这个通知后，App应该logout，原因有三种，在通知的userInfo中指出。
 通知在主线程发送
 */
extern NSString *LEDMS_NOTIFICATION_OFFLINE;


/**
 设备上线失败通知
 
 设备在由inactive变成active过程中，如果权限发生变化造成了不能上线，
 会收到这个通知。原因有三种，在通知的userInfo中指出。
 收到这个通知后，App应该logout，
 通知在主线程发送
 */
extern NSString *LEDMS_NOTIFICATION_ONLINE_FAILED;


/**
 对于LEDMS发出的通知，
 使用LEDMS_NOTIFICATION_SUBTYPE_KEY从userInfo中获取通知的子类型(需要拆包)。
 使用LEDMS_COMMAND_DESCRIPTION_KEY从userInfo中获取通知的描述。
 */
extern NSString *LEDMS_NOTIFICATION_SUBTYPE_KEY;
extern NSString *LEDMS_NOTIFICATION_TITLE_KEY;
extern NSString *LEDMS_NOTIFICATION_DESCRIPTION_KEY;



/**
 设备下线通知的子类型
 */
typedef NS_ENUM(NSInteger, LDMSOfflineSubtype) {
    LDMSOfflineSubtypeTrustDeviceLogin,         //被挤下线
    LDMSOfflineSubtypeTrustDeviceKicked,        //被踢下线
    LDMSOfflineSubtypeTrustDeviceForbiddened,   //被禁用下线
};


/**
 设备上线失败通知的子类型
 */
typedef NS_ENUM(NSInteger, LDMSOnlineFailedSubtype) {
    LDMSOnlineFailedSubtypeNotAuthorized,           //设备未授权
    LDMSOnlineFailedSubtypeMaxOnlineDeviceReached,  //在线设备已满
    LDMSOnlineFailedSubtypeForbidden,               //设备被禁用
    LDMSOnlineFailedSubtypeUnknown,                 //其他
    LDMSOnlineFailedSubtypeDMSTKInvalid,            //DMSTK失效

};


/**
 设备登录返回的错误代码
 */
typedef NS_ENUM(NSInteger, LDMSLoginErrorCode) {
    LDMSLoginErrorCodeNetworkError,             //网络错误
    LDMSLoginErrorCodeUserCanceled,             //用户点击了回退，可能是取消了进一步的验证过程，也可能是设备不能使用。
    LDMSLoginErrorCodeGotoAccountPage,          //需要到平台账户流程去登录。
    LDMSLoginErrorCodeServerError,              //服务端错误。
    LDMSLoginErrorCodeUnknownError              //未知错误。
};


/**
 设备管理返回的错误代码
 */
typedef NS_ENUM(NSInteger, LDMSDeviceManagerErrorCode) {
    LDMSDeviceManagerErrorCodeNotLogin,         //设备未登录
    LDMSDeviceManagerErrorCodeNetworkError,     //网络错误，无法判断设备权限
    LDMSDeviceManagerErrorCodeUnknown,          //未知错误，一般是服务端错误。
};



/**
 登录函数的回调。

 @param dmsTk 如果登录成功，返回设备的dms token，失败返回nil
 @param dmsUID 如果登录成功，返回设备的dmsUID，失败返回nil
 @param error 如果登录成功，error为nil，否则errorCode表明失败原因。参见LDMSLoginErrorCode
 */
typedef void(^LoginComletionHandler)(NSString *dmsTk, NSString *dmsUID, NSError *error);



/**
 登录函数的回调。

 在进入SDK流程的时候会发生回调
 @param userInfo 一些额外的信息，作为扩展用，目前没有使用，为nil

 */
typedef void(^LoginWillProcessHandler)(NSDictionary *userInfo);



/**
 加载设备管理界面的回调，

 @param viewController nil或者一个恰当的viewController
 */
typedef void(^LoadDeviceManagementViewComletionHandler) (UIViewController* viewController, NSError *error);



@interface LEDMSSDK : NSObject
-(id)init NS_UNAVAILABLE;


/**
 必须一开始就调用SDK的setupSDKWithAppKey:，否者不能使用SDK其他方法。
 应该在应用程序启动的时候立即调用。

 @param appKey appKey
 */
+(void)setupSDKWithAppKey:(NSString *)appKey deviceID:(NSString *)deviceID isDebug:(BOOL)isDebug;



/**
 同步登录信息，验证登录权限。
 如果completionHanlder的返回中有错误，应该登出平台账号。
 如果completionHanlder的返回没有错误，应该保存成功登录状态。
 在平台账号登录成功之后调用，
 
 rootViewController是界面的根VC，用于展示各种登录流程的中的界面

 */
+(void)loginWithUID:(NSString *)uid
              ssoTK:(NSString *)ssoTK
               idfa:(NSString *)idfa
         appVersion:(NSString *)appVersion
 rootViewController:(UIViewController *)rootViewController
  willProcessHandler:(LoginWillProcessHandler)willProcessHandler
  completionHanlder:(LoginComletionHandler)completionHanlder;



/**
 账号登出的时候需要调用logout同步设备信息。
 在平台账号登出成功后调用。

 */
+(void)logout;



/**
 根据设备的不同权限和状态，返回设备管理页面或者是申请设备管理页面，或者nil，规则如下：
 1.如果设备没有登录，返回nil。
 2.如果设备登录，且设备有信任权限，返回设备管理页面的rootViewController
 3.如果设备登录，且设备有普通权限且信任设备未达上限，返回申请信任权限的页面。
 4.如果设备登录，且设备有普通权限且信任设备已经达到上限，返回告知用户不能申请信任的页面。

 注：一般情况下，设备的权限会在loginWithUID:ssoTK:deviceID:imei:comletionHandler这个接口调用之后自动获取，
 所以这个接口会很快的确定并在comletion中返回恰当的viewController。
 特殊情况下，如果设备的权限信息没有获取到（恰好那次网络请求失败），则调用这个接口会重新发送设备权限信息的请求，
 这样的话comletion的返回可能会需要一个网络请求的时间。如果返回值为nil，可以根据需要调用loadDeviceAuthority:来判断
 是否设备确实有权限管理。

 */
+(void)loadDeviceManagementViewWithCompletion:(LoadDeviceManagementViewComletionHandler)completion;



/**
 用户VIP状态设置，如果不调用，默认为非VIP。

 @param vipType VIP会员类型，如果取消VIP设置，传空字符串
 */
+(void)setVIPType:(NSString *)vipType;


///用户的VIP状态
/**
 NSString *vipLevel;               //vip级别
 BOOL isExpired;                   //是否过期
 keys:@[@"vipLevel",@"isExpired"]
 */
+(void)setVIPLevel:(NSDictionary *)vipLevelDic;


/**
 设置设备的地理位置，有助于设备管理。

 @param longitude 经度
 @param latitude 纬度
 @param cityCode 额外信息，城市代码，可为空。
 @param cityName 额外信息，城市名称，可为空。

 */
+(void)setDeviceLocation:(NSString *)longitude
                latitude:(NSString *)latitude
                cityCode:(NSString *)cityCode
                cityName:(NSString *)cityName;


/**
 确认设备在线状态，这个接口调用之后，会发送一个上线请求，如果设备已经被禁用则客户端会收到一个上线失败的通知。

 */
+(void)checkOnlineState;


/**
 销毁所有的弹出窗口。

 */
+(void)dismissAllPopupViews;


@end


