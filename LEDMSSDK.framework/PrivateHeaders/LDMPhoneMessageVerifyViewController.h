//
//  LDMPhoneMessageVerifyViewController.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/12/1.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>


@interface LDMPhoneMessageVerifyViewController : UIViewController

@property(nonatomic, assign) BOOL shouldDismiss;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithPhoneNumber:(NSString *)phoneNumber;

@end
