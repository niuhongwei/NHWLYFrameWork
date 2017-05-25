//
//  LDMDeviceCapatchaViewController.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/30.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, LDMDeviceCapatchaType) {
    LDMDeviceCapatchaBinding,
    LDMDeviceCapatchaNoBinding
};


@protocol LDMDeviceCapatchaProtocol <NSObject>

- (void)ClickButton:(UIButton *)button;
- (void)ClickCreditDeviceLabel;

@end

@interface LDMDeviceCapatchaViewController : UIViewController

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithBindingPhoneNumber:(NSString *)phoneNumber trustLimited:(int)trustLimited;

- (instancetype)initNoBindingPhoneNumberWithTrustLimited:(int)trustLimited;

@end
