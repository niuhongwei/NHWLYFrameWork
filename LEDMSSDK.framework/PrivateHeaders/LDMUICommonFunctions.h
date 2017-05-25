//
//  LDMUICommonFunctions.h
//  DeviceManagement
//
//  Created by 王为 on 03/12/2016.
//  Copyright © 2016 weiqi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NSDictionary *CheckErrorFlowForRequestWithData(NSData *data, NSError *error);

void ShowErrorMessage(NSString *errMsg);

UIImage * createImageWithColor(UIColor *color);

