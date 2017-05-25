//
//  LEDeviecAuthViewController.h
//  DeviceManagement
//
//  Created by 王为 on 01/12/2016.
//  Copyright © 2016 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface LDMDeviceAuthViewController : UIViewController

@property (nonatomic, copy) NSString *appKey;
@property (nonatomic, copy) NSString *currentDeviceId;
@property (nonatomic, copy) NSString *dmsUID;
@property (nonatomic, copy) NSString *dmsTK;

@property (nonatomic, copy) NSDictionary *deviceDataDict;
@property (nonatomic, copy) NSDictionary *generalInfoDict;

@property (nonatomic) void(^dataChangedHandler)(BOOL dataChanged);

@end
