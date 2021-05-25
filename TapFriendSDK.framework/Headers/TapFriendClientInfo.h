//
//  TapFriendClientInfo.h
//  TapFriendSDK
//
//  Created by Bottle K on 2021/4/28.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapFriendClientInfo : NSObject
@property (nonatomic, assign) BOOL enable;
@property (nonatomic, copy) NSString *clientId;
@property (nonatomic, copy) NSString *followUrl;
@end

NS_ASSUME_NONNULL_END
