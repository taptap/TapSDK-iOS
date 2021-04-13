//
//  AccessToken.h
//  TapBootstrapSDK
//
//  Created by Bottle K on 2021/2/20.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface AccessToken : NSObject
@property (nonatomic, copy) NSString *kid;
@property (nonatomic, copy) NSString *accessToken;
@property (nonatomic, copy) NSString *macAlgorithm;
@property (nonatomic, copy) NSString *tokenType;
@property (nonatomic, copy) NSString *macKey;
@property (nonatomic, assign) long expireIn;

- (instancetype)initWithJsonString:(NSString *)json;

- (NSString *)toJsonString;
@end

NS_ASSUME_NONNULL_END
