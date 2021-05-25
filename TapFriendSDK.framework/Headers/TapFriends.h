//
//  TapFriends.h
//  TapFriends
//
//  Created by Bottle K on 2021/3/16.
//

#import <Foundation/Foundation.h>
#import <TapFriendSDK/TapUserRelationShip.h>
#import <TapFriendSDK/TapFriendConstants.h>
#import <TapCommonSDK/TapCommonSDK.h>

NS_ASSUME_NONNULL_BEGIN

#define TapFriendSDK                @"TapFriend"
#define TapFriendSDK_VERSION_NUMBER @"20102001"
#define TapFriendSDK_VERSION        @"2.1.2"

typedef void (^TapSimpleHandler)(NSError *_Nullable error);
typedef void (^TapFriendRelationHandler)(NSArray<TapUserRelationShip *> *_Nullable userList, NSError *_Nullable error);
typedef void (^TapFriendSearchHandler)(TapUserRelationShip *_Nullable user, NSError *_Nullable error);
typedef void (^TapFriendSendFriendInvitationHandler)(BOOL success, NSError *_Nullable error);

@interface TapFriends : NSObject

/// 初始化
/// @param config config
/// @param provider provider
+ (void)initWithConfig:(TapConfig *)config accountProvider:(id<TDSAccountProvider>)provider;

/// 注册消息接收器
/// @param delegate delegate
+ (void)registerMessageDelegate:(id<ComponentMessageDelegate>)delegate;

/// 添加好友
/// @param userId 用户tds_id
/// @param handler 回调
+ (void)addFriend:(NSString *)userId
          handler:(TapSimpleHandler)handler;

/// 删除好友
/// @param userId 用户tds_id
/// @param handler 回调
+ (void)deleteFriend:(NSString *)userId
             handler:(TapSimpleHandler)handler;

/// 获取关注列表
/// @param from 起始index，从0开始
/// @param mutualAttention 是否互相关注 false:不是互相关注 true: 互相关注
/// @param limit 单页个数限制，最大200
/// @param handler 回调
+ (void)getFollowingList:(NSInteger)from
         mutualAttention:(BOOL)mutualAttention
                   limit:(NSInteger)limit
                 handler:(TapFriendRelationHandler)handler;

/// 获取粉丝列表
/// @param from 起始index，从0开始
/// @param limit 单页个数限制，最大200
/// @param handler 回调
+ (void)getFollowerList:(NSInteger)from
                  limit:(NSInteger)limit
                handler:(TapFriendRelationHandler)handler;

/// 拉黑用户
/// @param userId 用户tds_id
/// @param handler 回调
+ (void)blockUser:(NSString *)userId
          handler:(TapSimpleHandler)handler;

/// 取消拉黑用户
/// @param userId 用户tds_id
/// @param handler 回调
+ (void)unblockUser:(NSString *)userId
            handler:(TapSimpleHandler)handler;

/// 黑名单列表
/// @param from 起始index，从0开始
/// @param limit 单页个数限制，最大200
/// @param handler 回调
+ (void)getBlockList:(NSInteger)from
               limit:(NSInteger)limit
             handler:(TapFriendRelationHandler)handler;

/// 搜索用户
/// @param userId 用户tds_id
/// @param handler 回调
+ (void)searchUserWithUserId:(NSString *)userId
                     handler:(TapFriendSearchHandler)handler;

/// 获取好友邀请链接
/// @param handler handler
+ (void)generateFriendInvitationWithHandler:(void (^)(NSString *_Nullable invitationString, NSError *_Nullable error))handler;

/// 分享好友邀请
/// @param handler handler
+ (void)sendFriendInvitationWithHandler:(TapFriendSendFriendInvitationHandler)handler;

/// 处理回调
/// @param url url
+ (BOOL)handleOpenURL:(NSURL *)url;
@end

NS_ASSUME_NONNULL_END
