//
//  TapUserRelationShip.h
//  TDSSDK
//
//  Created by Bottle K on 2021/3/12.
//

#import <Foundation/Foundation.h>
#import <TapFriendSDK/TapRichPresence.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapUserRelationShip : NSObject
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, copy, nullable) NSString *avatar;
@property (nonatomic, assign) long gender;
@property (nonatomic, assign) BOOL mutualAttention;
@property (nonatomic, assign) BOOL online;
@property (nonatomic, assign) long time;
@property (nonatomic, copy) NSString *relationship;
@property (nonatomic, copy) TapRichPresence *richPresence;

- (BOOL)isFollowing;
- (BOOL)isFollowed;
- (BOOL)isBlocked;
- (NSString *)toJsonString;
@end

NS_ASSUME_NONNULL_END
