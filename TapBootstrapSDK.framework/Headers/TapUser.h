//
//  TapUser.h
//  TapBootstrapSDK
//
//  Created by Bottle K on 2021/2/19.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TapUser : NSObject
@property (nonatomic, copy) NSString *userId;
@property (nonatomic, copy, nullable) NSString *name;
@property (nonatomic, copy, nullable) NSString *avatar;
@property (nonatomic, copy, nullable) NSString *taptapUserId;
@property (nonatomic, assign) BOOL isGuest;
@property (nonatomic, assign) long gender;

- (instancetype)initWithJsonString:(NSString *)json;

- (NSString *)toJsonString;
@end

NS_ASSUME_NONNULL_END
