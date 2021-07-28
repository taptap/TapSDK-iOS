//
//  TDSUser.h
//  TapBootstrapSDK
//
//  Created by pzheng on 2021/07/06.
//

#import <LeanCloudObjc/LeanCloudObjc.h>

NS_ASSUME_NONNULL_BEGIN

@interface TDSUser : LCUser

/// Login or register by taptap.
/// @param permissions permissions.
/// @param callback callback.
+ (void)loginByTapTapWithPermissions:(NSArray * _Nullable)permissions callback:(void (^)(TDSUser * _Nullable user, NSError * _Nullable error))callback;

/// Login anonymously.
/// @param callback callback.
+ (void)loginAnonymously:(void (^)(TDSUser * _Nullable user, NSError * _Nullable error))callback;

// MARK: Unavailable

- (nullable NSString *)username NS_UNAVAILABLE;
- (void)setUsername:(nullable NSString *)username NS_UNAVAILABLE;
- (nullable NSString *)password NS_UNAVAILABLE;
- (void)setPassword:(nullable NSString *)password NS_UNAVAILABLE;
- (nullable NSString *)email NS_UNAVAILABLE;
- (void)setEmail:(nullable NSString *)email NS_UNAVAILABLE;
- (nullable NSString *)mobilePhoneNumber NS_UNAVAILABLE;
- (void)setMobilePhoneNumber:(nullable NSString *)mobilePhoneNumber NS_UNAVAILABLE;
- (BOOL)mobilePhoneVerified NS_UNAVAILABLE;

+ (void)requestEmailVerify:(NSString *)email withBlock:(LCBooleanResultBlock)block NS_UNAVAILABLE;
- (BOOL)signUp:(NSError *__autoreleasing  _Nullable *)error NS_UNAVAILABLE;
- (BOOL)signUpAndThrowsWithError:(NSError *__autoreleasing  _Nullable *)error NS_UNAVAILABLE;
- (void)signUpInBackgroundWithBlock:(LCBooleanResultBlock)block NS_UNAVAILABLE;
- (void)updatePassword:(NSString *)oldPassword newPassword:(NSString *)newPassword block:(LCIdResultBlock)block NS_UNAVAILABLE;
+ (instancetype)logInWithUsername:(NSString *)username password:(NSString *)password error:(NSError *__autoreleasing  _Nullable *)error NS_UNAVAILABLE;
+ (void)logInWithUsernameInBackground:(NSString *)username password:(NSString *)password block:(LCUserResultBlock)block NS_UNAVAILABLE;
+ (void)loginWithEmail:(NSString *)email password:(NSString *)password block:(LCUserResultBlock)block NS_UNAVAILABLE;
+ (void)logInWithMobilePhoneNumberInBackground:(NSString *)phoneNumber password:(NSString *)password block:(LCUserResultBlock)block NS_UNAVAILABLE;
+ (instancetype)logInWithMobilePhoneNumber:(NSString *)phoneNumber password:(NSString *)password error:(NSError *__autoreleasing  _Nullable *)error NS_UNAVAILABLE;
+ (void)logInWithMobilePhoneNumberInBackground:(NSString *)phoneNumber smsCode:(NSString *)code block:(LCUserResultBlock)block NS_UNAVAILABLE;
+ (instancetype)logInWithMobilePhoneNumber:(NSString *)phoneNumber smsCode:(NSString *)code error:(NSError *__autoreleasing  _Nullable *)error NS_UNAVAILABLE;
+ (void)requestLoginSmsCode:(NSString *)phoneNumber withBlock:(LCBooleanResultBlock)block NS_UNAVAILABLE;
+ (void)requestLoginCodeForPhoneNumber:(NSString *)phoneNumber options:(nullable LCUserShortMessageRequestOptions *)options callback:(LCBooleanResultBlock)callback NS_UNAVAILABLE;
+ (void)signUpOrLoginWithMobilePhoneNumberInBackground:(NSString *)phoneNumber smsCode:(NSString *)code block:(LCUserResultBlock)block NS_UNAVAILABLE;
+ (void)signUpOrLoginWithMobilePhoneNumberInBackground:(NSString *)phoneNumber smsCode:(NSString *)smsCode password:(NSString *)password block:(LCUserResultBlock)block NS_UNAVAILABLE;
+ (instancetype)signUpOrLoginWithMobilePhoneNumber:(NSString *)phoneNumber smsCode:(NSString *)code error:(NSError *__autoreleasing  _Nullable *)error NS_UNAVAILABLE;
+ (BOOL)requestPasswordResetForEmail:(NSString *)email error:(NSError *__autoreleasing  _Nullable *)error NS_UNAVAILABLE;
+ (void)requestPasswordResetForEmailInBackground:(NSString *)email block:(LCBooleanResultBlock)block NS_UNAVAILABLE;
+ (void)requestPasswordResetWithPhoneNumber:(NSString *)phoneNumber block:(LCBooleanResultBlock)block NS_UNAVAILABLE;
+ (void)requestPasswordResetCodeForPhoneNumber:(NSString *)phoneNumber options:(nullable LCUserShortMessageRequestOptions *)options callback:(LCBooleanResultBlock)callback NS_UNAVAILABLE;
+ (void)resetPasswordWithSmsCode:(NSString *)code newPassword:(NSString *)password block:(LCBooleanResultBlock)block NS_UNAVAILABLE;
+ (void)requestMobilePhoneVerify:(NSString *)phoneNumber withBlock:(void (^)(BOOL, NSError * _Nullable))block NS_UNAVAILABLE;
+ (void)requestVerificationCodeForPhoneNumber:(NSString *)phoneNumber options:(nullable LCUserShortMessageRequestOptions *)options callback:(void (^)(BOOL, NSError * _Nullable))callback NS_UNAVAILABLE;
+ (void)verifyCodeForPhoneNumber:(NSString *)phoneNumber code:(NSString *)code block:(void (^)(BOOL, NSError * _Nullable))block NS_UNAVAILABLE;
+ (void)requestVerificationCodeForUpdatingPhoneNumber:(NSString *)phoneNumber options:(nullable LCUserShortMessageRequestOptions *)options block:(void (^)(BOOL, NSError * _Nullable))block NS_UNAVAILABLE;
+ (void)verifyCodeToUpdatePhoneNumber:(NSString *)phoneNumber code:(NSString *)code block:(void (^)(BOOL, NSError * _Nullable))block NS_UNAVAILABLE;
+ (void)loginAnonymouslyWithCallback:(void (^)(LCUser * _Nullable, NSError * _Nullable))callback NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
