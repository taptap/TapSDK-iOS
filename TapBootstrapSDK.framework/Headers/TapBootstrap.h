//
//  TapBootstrap.h
//  TapBootstrapSDK
//
//  Created by Bottle K on 2021/2/18.
//

#import <Foundation/Foundation.h>
#import <TapBootstrapSDK/TapLoginResultDelegate.h>
#import <TapBootstrapSDK/TapUserStatusChangedDelegate.h>
#import <TapBootstrapSDK/TapUser.h>
#import <TapBootstrapSDK/TapUserDetails.h>
#import <TapBootstrapSDK/AccessToken.h>

#import <TapCommonSDK/TapCommonSDK.h>

#define TapSDK                @"TapSDK"
#define TapSDK_VERSION_NUMBER @"20102001"
#define TapSDK_VERSION        @"2.1.2"

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM (NSInteger, TapBootstrapLoginType) {
    TapBootstrapLoginTypeTapTap = 0,
};

typedef NS_ENUM (NSInteger, TapBootstrapBindType) {
    TapBootstrapBindTypeTapTap
};

typedef void (^TapUserHandler)(TapUser *_Nullable userInfo, NSError *_Nullable error);
typedef void (^TapUserDetailsHandler)(TapUserDetails *_Nullable userDetail, NSError *_Nullable error);

@interface TapBootstrap : NSObject

+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/// 初始化
/// @param config 配置项
+ (void)initWithConfig:(TapConfig *)config;

/// 当前是否初始化
+ (BOOL)isInitialized;

/// 注册登录回调
/// @param delegate 回调
+ (void)registerLoginResultDelegate:(id <TapLoginResultDelegate>)delegate;

/// 注册用户状态变化回调
/// @param delegate 回调
+ (void)registerUserStatusChangedDelegate:(id <TapUserStatusChangedDelegate>)delegate;

/// TapTap 登录
/// @param permissions 权限列表
+ (void)loginWithPermissions:(NSArray *_Nullable)permissions;

/// 登录
/// @param type 登录类型
/// @param permissions 权限列表 (仅在taptap登录时需要)
+ (void)login:(TapBootstrapLoginType)type permissions:(NSArray *_Nullable)permissions;

/// 获取用户基本信息
+ (void)getUser:(TapUserHandler)handler;

/// 获取用户详细信息
+ (void)getUserDetails:(TapUserDetailsHandler)handler;

/// 获取当前 token
+ (AccessToken *)getCurrentToken;

/// 退出登录
+ (void)logout;

/// 获取用户是否有测试资格
/// @param handler 回调
+ (void)getTestQualification:(void (^)(BOOL isQualified, NSError *_Nullable error))handler;

/// 设定游戏倾向语言
/// @param lang TapLanguageType 0-自动 1-简中 2-英文
+ (void)setPreferredLanguage:(TapLanguageType)lang;

/// 处理系统协议
/// @param url url
+ (BOOL)handleOpenURL:(NSURL *)url;
@end

NS_ASSUME_NONNULL_END
