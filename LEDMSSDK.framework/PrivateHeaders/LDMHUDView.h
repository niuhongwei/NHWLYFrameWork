//
//  LDMHUDView.h
//  DeviceManagement
//
//  Created by 王为 on 03/12/2016.
//  Copyright © 2016 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDMHUDView : UIView

/**
 模态显示一条信息

 @param title 信息内容，不超过20个字
 @param seconds 显示时间。如果传入参数小于等于0，使用默认2.0秒
 */
+(void)showTitle:(NSString *)title timeout:(NSTimeInterval)seconds;


@end
