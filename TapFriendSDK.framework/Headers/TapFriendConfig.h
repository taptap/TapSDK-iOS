//
//  TapFriendConfig.h
//  TapFriendSDK
//
//  Created by Bottle K on 2021/4/2.
//

#import <Foundation/Foundation.h>
#import <TapFriendSDK/TapFriendClientInfo.h>
#import <TapCommonSDK/TapCommonSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapFriendConfig : NSObject
@property (nonatomic, assign) BOOL isCN;
@property (nonatomic, strong) NSString *clientId;
@property (nonatomic, strong) TapFriendClientInfo *clientInfo;
@property (nonatomic, weak) id<TDSAccountProvider>provider;
@property (nonatomic, weak) id<ComponentMessageDelegate>messageDelegate;

+ (nonnull instancetype)sharedInstance;
@end

NS_ASSUME_NONNULL_END
