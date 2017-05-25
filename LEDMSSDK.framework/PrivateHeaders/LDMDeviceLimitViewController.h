//
//  LDMDeviceLimitViewController.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/30.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

@protocol LDMDeviceLimitDelegate <NSObject>

- (void)ClickButton:(UIButton *)button;
- (void)ClickAccountLabel;
- (void)ClickCreditDeviceLabel;

@end

@class LDMDeviceLimitModel;

typedef NS_ENUM(NSInteger, LDMDeviceLimitType) {
    LDMDeviceLimitAuthLimited,
    LDMDeviceLimitUsedLimited,
    LDMDeviceLimitForbidden
};


@interface LDMDeviceLimitViewController : UIViewController

@property (nonatomic, strong, readwrite) UILabel *errorMessageLabel;
@property (nonatomic, strong, readwrite) UIButton *deviceManagementBtn;
@property (nonatomic, strong, readwrite) UILabel *todoMessageLabel;

@property (nonatomic, strong, readwrite) LDMDeviceLimitModel *data;

@property (nonatomic, weak, readwrite) id<LDMDeviceLimitDelegate> delegate;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithType:(LDMDeviceLimitType)type;

- (instancetype)initWithType:(LDMDeviceLimitType)type withUserPhoneAccount:(NSString *)phoneNumber;

@end
