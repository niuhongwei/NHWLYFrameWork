//
//  LEMyDeviceTableViewCell.h
//  DeviceManagement
//
//  Created by 王为 on 30/11/2016.
//  Copyright © 2016 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

extern const int kTrustDeviceType;
extern const int kOrdinaryDeviceType;
extern const int kForbiddenDeviceType;
extern const int kOnlineDeviceType;

@protocol LEMyDeviceTableViewCellDelegate;
@interface LDMMyDeviceTableViewCell : UITableViewCell

@property (nonatomic, weak)id<LEMyDeviceTableViewCellDelegate> delegate;
@property (nonatomic, strong) NSDictionary *dataDict;
@property (nonatomic)BOOL hideSeperatorLine;

-(void)updateCellWithData:(NSDictionary *)dataDict
               deviceType:(int)type
          isCurrentDevice:(BOOL)isCurrentDevice;

@end



@protocol LEMyDeviceTableViewCellDelegate <NSObject>

@optional
-(void)rightButtonTouchedWithData:(NSDictionary *)data;

@end
