//
//  LDMDefines.h
//  DeviceManagement
//
//  Created by 王为 on 03/12/2016.
//  Copyright © 2016 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString *LDMSTR_ERROR_DOMAIN;           // = @"LDMS error domain";
extern NSString *LDMSTR_ERROR_LOGIN_CHECKDEVICEAUTH; // = @"LDMS error login check device auth";

extern NSString *LDMSTR_LOAD_MORE_BY_CLICK;     // = @"点击加载更多";
extern NSString *LDMSTR_NO_MORE_DATA;           // = @"没有更多了";
extern NSString *LDMSTR_LOADING;                // = @"加载中";
extern NSString *LDMSTR_LOAD_FAILED_TRTRY;      // = @"加载失败，点击重试";


extern NSString *LDMSTR_NETWORK_FAILED;         // = @"网络不给力";
extern NSString *LDMSTR_UNKNOWN_ERROR;          // = @"未知错误";


extern NSString *LDMSTR_USERINFO_APPKEY;        
extern NSString *LDMSTR_USERINFO_DEVICEID;      
extern NSString *LDMSTR_USERINFO_DMSUID;        
extern NSString *LDMSTR_USERINFO_DMSTK;         
extern NSString *LDMSTR_USERINFO_SSOTK;         
extern NSString *LDMSTR_USERINFO_UID;           
extern NSString *LDMSTR_USERINFO_IMEI;          
extern NSString *LDMSTR_USERINFO_APPVER;
extern NSString *LDMSTR_USERINFO_LOGINFLAG;
extern NSString *LDMSTR_DIM_TOPIC_OLD_DEVICE_INFO;
extern NSString *LDMSTR_USERINFO_VIPFLAG;
extern NSString *LDMSTR_USERINFO_LONGITUDE;
extern NSString *LDMSTR_USERINFO_LATITUDE;
extern NSString *LDMSTR_USERINFO_CITYCODE;
extern NSString *LDMSTR_USERINFO_CITYNAME;
extern NSString *LDMSTR_HAVE_START_ONCE;
extern NSString *LDMSTR_USERINFO_TID;

extern NSString *LDMSRC_BUTTONBACK;             // = @"LEDMSBundle.bundle/button_back.png"
extern NSString *LDMSRC_BUTTONSTATENORMAL;
extern NSString *LDMSRC_BUTTONSTATEHIGHTLIGHT;
extern NSString *LDMSRC_BUTTONSTATEDISABLE;

extern NSString *LDMSRC_DEVICEAUTH_FORBIDDEN;
extern NSString *LDMSRC_DEVICEAUTH_WARNING;

extern NSString *LDMSTR_DIM_TOPIC_DEVICE_STATE_CHANGED; // = @"deviceUsingStateChange"
extern NSString *LDMSTR_DIM_TOPIC_COMMAND_NOTICE; // = @"deviceCommandNotice";
extern NSString *LDMSTR_DIM_TOPIC_DEVICE_INFO; // = @"deviceInfo";
extern NSString *LDMSTR_DIM_TOPIC_ERROR_LOG; // = @"dmsSdkErrorLog";

extern NSString *LDMSTR_NOTIFICATION_LOGIN_FINISHED; //= @"LEDMS_NOTIFICATION_LOGIN_FINISHED";
extern NSString *LDMSTR_NOTIFICATION_AUTH_CHANGED;
extern NSString *LDMSTR_NOTIFICATION_CANCEL_ALL_ALERT;

extern NSString *LDMSTR_USERINFO_VIPLEVEL;
extern NSString *LDMSTR_USERINFO_ISEXPIRED;

extern const int kLoginErrorCodeNetworkError;
extern const int kLoginErrorCodeUnknowError;
extern const int kLoginErrorCodeUserCancel;

extern const int kUserEventForwardLELoginPage;

BOOL isEmptyStringOrNil(NSString *str);

//typedef void(^LoginComletionHandler)(BOOL loginSucceeded);

@interface LDMDefines : NSObject

@end
