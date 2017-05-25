//
//  NSMutableDictionary+SafeSetObject.h
//  DeviceManagement
//
//  Created by 魏琪 on 2016/11/29.
//  Copyright © 2016年 weiqi. All rights reserved.
//

#import <UIKit/UIKit.h>

@interface NSMutableDictionary (SafeSetObject)

-(void)safeSetObject:(nonnull id)value
              forKey:(nonnull id<NSCopying>)key
        defaultValue:(nonnull id)defaultValue;

@end
