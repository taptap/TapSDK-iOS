//
//  TapUserDetails.h
//  TapBootstrapSDK
//
//  Created by Bottle K on 2021/2/19.
//

#import <Foundation/Foundation.h>
#import <TapBootstrapSDK/TapUserCenterEntry.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapUserDetails : NSObject
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, copy, nullable) NSString *avatar;
@property (nonatomic, assign) BOOL isGuest;
@property (nonatomic, assign) long gender;

@property (nonatomic, strong) TapUserCenterEntry *userCenterEntry;

- (NSString *)toJsonString;
@end

NS_ASSUME_NONNULL_END
