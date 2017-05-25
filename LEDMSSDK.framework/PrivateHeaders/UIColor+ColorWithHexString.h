//
//  UIColor+ColorWithHexString.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/29.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface UIColor (ColorWithHexString)

+ (UIColor *)colorFromHexString:(NSString *)hexString;

+ (UIColor *)colorFromHexString:(NSString *)hexString alpha:(CGFloat)alpha;
@end
