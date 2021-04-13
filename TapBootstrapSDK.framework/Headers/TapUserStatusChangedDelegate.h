//
//  TapUserStatusChangedDelegate.h
//  TapBootstrapSDK
//
//  Created by Bottle K on 2021/2/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TapUserStatusChangedDelegate <NSObject>

/// 退出登录
/// @param error 如果是因为出错导致的退登，则返回错误信息
- (void)onLogout:(NSError *_Nullable)error;

/// 绑定回调
/// @param error 如果是因为出错导致的退登，则返回错误信息
@optional
- (void)onBind:(NSError *_Nullable)error;

@end

NS_ASSUME_NONNULL_END
