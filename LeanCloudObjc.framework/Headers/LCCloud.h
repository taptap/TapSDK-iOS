//
//  LCCloud.h
//  LeanCloud
//
//  Created by Zhu Zeng on 2/25/13.
//  Copyright (c) 2013 LeanCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "LCConstants.h"

NS_ASSUME_NONNULL_BEGIN

/**
 *  Call the cloud code from client
 */
@interface LCCloud : NSObject


/*!
 Calls the given cloud function with the parameters passed in.
 @param function The function name to call.
 @param parameters The parameters to send to the function.
 @return The response from the cloud function.
 */
+ (id)callFunction:(NSString *)function withParameters:(nullable NSDictionary *)parameters;

/*!
 Calls the given cloud function with the parameters passed in and sets the error if there is one.
 @param function The function name to call.
 @param parameters The parameters to send to the function.
 @param error Pointer to an NSError that will be set if necessary.
 @return The response from the cloud function.  This result could be a NSDictionary, an NSArray, NSInteger or NSString.
 */
+ (id)callFunction:(NSString *)function withParameters:(nullable NSDictionary *)parameters error:(NSError **)error;

/*!
 Calls the given cloud function with the parameters provided asynchronously and calls the given block when it is done.
 @param function The function name to call.
 @param parameters The parameters to send to the function.
 @param block The block to execute. The block should have the following argument signature:(id result, NSError *error).
 */
+ (void)callFunctionInBackground:(NSString *)function withParameters:(nullable NSDictionary *)parameters block:(LCIdResultBlock)block;

/*!
 Calls the given cloud function with the parameters passed in by RPC.
 @param function The function name to call.
 @param parameters The parameters to send to the function.
 @return The response from the cloud function.
 */
+ (id)rpcFunction:(NSString *)function withParameters:(nullable id)parameters;

/*!
 Calls the given cloud function with the parameters passed in by RPC and sets the error if there is one.
 @param function The function name to call.
 @param parameters The parameters to send to the function.
 @param error Pointer to an NSError that will be set if necessary.
 @return The response from the cloud function.  This result could be a NSDictionary, an NSArray, NSInteger or NSString.
 */
+ (id)rpcFunction:(NSString *)function withParameters:(nullable id)parameters error:(NSError **)error;

/*!
 Calls the given cloud function with the parameters provided by RPC asynchronously and calls the given block when it is done.
 @param function The function name to call.
 @param parameters The parameters to send to the function.
 @param block The block to execute. The block should have the following argument signature:(id result, NSError *error).
 */
+ (void)rpcFunctionInBackground:(NSString *)function withParameters:(nullable id)parameters block:(LCIdResultBlock)block;

/**
 *  Set call what production mode's cloud code
 *
 *  @param isProduction the production mode or test mode
 */
+ (void)setProductionMode:(BOOL)isProduction;

@end

NS_ASSUME_NONNULL_END
