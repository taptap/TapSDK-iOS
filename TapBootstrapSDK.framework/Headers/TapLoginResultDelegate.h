//
//  TapLoginResultDelegate.h
//  TapBootstrapSDK
//
//  Created by Bottle K on 2021/2/19.
//

#import <Foundation/Foundation.h>
@class AccessToken;

NS_ASSUME_NONNULL_BEGIN

@protocol TapLoginResultDelegate <NSObject>

/// 登录成功回调
/// @param token token对象
- (void)onLoginSuccess:(AccessToken *)token;

/// 登录取消
- (void)onLoginCancel;

/// 登录失败
/// @param error 失败原因
- (void)onLoginError:(NSError *)error;

@end

NS_ASSUME_NONNULL_END
