//
//  TapBootstrap.h
//  TapBootstrapSDK
//
//  Created by Bottle K on 2021/2/18.
//

#import <Foundation/Foundation.h>
#import <TapCommonSDK/TapCommonSDK.h>

#define TapSDK                @"TapSDK"
#define TapSDK_VERSION_NUMBER @"30000001"
#define TapSDK_VERSION        @"3.0.0"

NS_ASSUME_NONNULL_BEGIN

@interface TapBootstrap : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// 初始化
/// @param config 配置项
+ (void)initWithConfig:(TapConfig *)config;

/// 当前是否初始化
+ (BOOL)isInitialized;

/// 处理系统协议
/// @param url url
+ (BOOL)handleOpenURL:(NSURL *)url;
@end

NS_ASSUME_NONNULL_END
