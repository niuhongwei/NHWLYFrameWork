//
//  LDMCapatchaVerifyView.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/12/2.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

@class LDMGetImageCaptchaInput;
@class LDMTextFieldWithoutPaste;

@protocol LDMCapatchaVerifyDelegate <NSObject>

- (void)TapCapatchaPic:(UITapGestureRecognizer *)gestureRecognizer;
- (void)TapCloseKeyBoard:(UITapGestureRecognizer *)gestureRecognizer;
- (void)ClickConfirmButton:(UIButton *)button;
- (void)ClickCancelButton:(UIButton *)button;
- (BOOL)textFieldShouldReturn:(UITextField *)textField;
- (BOOL)textField:(UITextField *)textField shouldChangeCharactersInRange:(NSRange)range replacementString:(NSString *)string;

@end

@class LDMGetImageCaptchaInput;

@interface LDMCapatchaVerifyView : UIView

@property (nonatomic, strong, readwrite) LDMTextFieldWithoutPaste *capatchaInput;

@property (nonatomic, strong, readwrite) LDMGetImageCaptchaInput *imageCodeInput;

@property (nonatomic, weak, readwrite) id<LDMCapatchaVerifyDelegate> delegate;

@property (nonatomic, strong, readwrite) UIImage *captchaImg;

- (instancetype)init NS_UNAVAILABLE;

- (instancetype)initWithImageRequestInput:(LDMGetImageCaptchaInput *)imageCaptchaInput;

- (void)initSubViews;

- (void)show;

@end
