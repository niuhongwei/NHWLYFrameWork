//
//  LDMCreditDeviceToast.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/12/3.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

typedef NS_ENUM(NSInteger, LDMCreditDeviceResultType) {
    LDMCreditDeviceResultTypeSuccess,
    LDMCreditDeviceResultTypeFailure
};

@interface LDMCreditDeviceToast : UIView

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initSuccessTypeWithPhone:(NSString *)phoneNumber;

- (instancetype)initFailureType;

- (void)show;

@end
