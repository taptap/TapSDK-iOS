//
//  LCFile.h
//  LeanCloud
//

#import <Foundation/Foundation.h>
#import "LCConstants.h"
#import "LCACL.h"

@class LCFileQuery;

NS_ASSUME_NONNULL_BEGIN

typedef NS_OPTIONS(NSUInteger, LCFileUploadOption) {
    
    /// default option. Data or File will be persistent cached after successfully uploading.
    /// Note: Remote URL not be cached after successfully uploading.
    LCFileUploadOptionCachingData = 0,
    
    /// Data or File will not be persistent cached after successfully uploading.
    LCFileUploadOptionIgnoringCachingData = 1 << 0
};

typedef NS_OPTIONS(NSUInteger, LCFileDownloadOption) {
    
    /// default option. When start downloading, if cached file exist, then return the cached file directly; else downloading from URL.
    LCFileDownloadOptionCachedData = 0,
    
    /// Always downloading from URL.
    LCFileDownloadOptionIgnoringCachedData = 1 << 0
};

/*!
 A file of binary data stored on the LeanCloud servers. This can be a image, video, or anything else
 that an application needs to reference in a non-relational way.
 */
@interface LCFile : NSObject <NSCoding>

// MARK: - Create

/**
 Create file from NSData.
 
 @param data Data
 @return Instance
 */
+ (instancetype)fileWithData:(NSData *)data;

/**
 Create file with a name from NSData.
 
 @param data Data
 @param name Name
 @return Instance
 */
+ (instancetype)fileWithData:(NSData *)data
                        name:(NSString * _Nullable)name;

/**
 Create file from Local Path
 
 @param localPath Path
 @return Instance
 */
+ (instancetype _Nullable)fileWithLocalPath:(NSString *)localPath
                                      error:(NSError * __autoreleasing *)error;

/**
 Create file from Remote URL
 
 @param remoteURL URL
 @return Instance
 */
+ (instancetype)fileWithRemoteURL:(NSURL *)remoteURL;

/**
 Create file from LCObject
 
 @param object LCObject
 @return Instance
 */
+ (instancetype)fileWithObject:(LCObject *)object;

/// Create file from `objectId` and `url`
/// @param objectId The ID of the File.
/// @param url The url of the File.
+ (instancetype)fileWithObjectId:(NSString *)objectId
                             url:(NSString *)url;

// MARK: - Property

/*!
 The name of the file.
 */
- (NSString * _Nullable)name;

/*!
 The id of the file.
 */
- (NSString * _Nullable)objectId;

/*!
 The url of the file.
 */
- (NSString * _Nullable)url;

/*!
 File metadata, caller is able to store additional values here.
 */
@property (nonatomic, strong, nullable) NSDictionary *metaData;

/**
 Owner ID of file, Customizable.
 */
@property (nonatomic, strong, nullable) NSString *ownerId;

/**
 Checksum of file, Customizable.
 */
@property (nonatomic, strong, nullable) NSString *checksum;

/**
 Size of file.
 */
- (NSUInteger)size;

/**
 Path Extension of file.
 */
- (NSString * _Nullable)pathExtension;

/**
 MIME Type of file.
 */
- (NSString * _Nullable)mimeType;

/*!
 *  The access control list for this file.
 */
@property (nonatomic, strong, nullable) LCACL *ACL;

/// Created date.
@property (nonatomic, strong, readonly, nullable) NSDate *createdAt;

/// Updated date.
@property (nonatomic, strong, readonly, nullable) NSDate *updatedAt;

/*!
 Request headers for file uploading.
 
 Some file hosting services allow you set custom headers in uploading request.
 Currently, it only supports files in US node, aka. the files hosted on AmazonS3.
 See https://docs.aws.amazon.com/AmazonS3/latest/API/RESTObjectPUT.html for all request headers.
 */
@property (nonatomic, strong, nullable) NSDictionary<NSString *, NSString *> *uploadingHeaders;

/**
 Returns the value associated with a given key.
 
 @param key Key.
 @return Value.
 */
- (id _Nullable)objectForKey:(id)key;

// MARK: - Upload

/**
 Upload Method. Use default option `LCFileUploadOptionCachingData`.
 
 @param completionHandler Completion Handler.
 */
- (void)uploadWithCompletionHandler:(void (^)(BOOL succeeded, NSError * _Nullable error))completionHandler;

/**
 Upload Method. Use default option `LCFileUploadOptionCachingData`.

 @param uploadProgressBlock Upload Progress Block.
 @param completionHandler Completion Handler.
 */
- (void)uploadWithProgress:(void (^ _Nullable)(NSInteger number))uploadProgressBlock
         completionHandler:(void (^)(BOOL succeeded, NSError * _Nullable error))completionHandler;

/**
 Upload Method.

 @param uploadOption See `LCFileUploadOption`
 @param uploadProgressBlock Upload Progress Block.
 @param completionHandler Completion Handler.
 */
- (void)uploadWithOption:(LCFileUploadOption)uploadOption
                progress:(void (^ _Nullable)(NSInteger number))uploadProgressBlock
       completionHandler:(void (^)(BOOL succeeded, NSError * _Nullable error))completionHandler;

// MARK: - Download

/**
 Download Method. Use default option `LCFileDownloadOptionCachedData`.

 @param completionHandler Completion Handler.
 */
- (void)downloadWithCompletionHandler:(void (^)(NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;

/**
 Download Method. Use default option `LCFileDownloadOptionCachedData`.

 @param downloadProgressBlock Download Progress Block.
 @param completionHandler Completion Handler.
 */
- (void)downloadWithProgress:(void (^ _Nullable)(NSInteger number))downloadProgressBlock
           completionHandler:(void (^)(NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;

/**
 Download Method.

 @param downloadOption See `LCFileDownloadOption`.
 @param downloadProgressBlock Download Progress Block.
 @param completionHandler Completion Handler.
 */
- (void)downloadWithOption:(LCFileDownloadOption)downloadOption
                  progress:(void (^ _Nullable)(NSInteger number))downloadProgressBlock
         completionHandler:(void (^)(NSURL * _Nullable filePath, NSError * _Nullable error))completionHandler;

// MARK: - Cancel

/**
 Cancel Uploading Task.
 */
- (void)cancelUploading;

/**
 Cancel Downloading Task.
 */
- (void)cancelDownloading;

// MARK: - Cache

/**
 Set a Custom Persistent Cache Directory for files.
 if not set, LCFile will use a default Persistent Cache Directory.
 
 @param directory Custom Persistent Cache Directory.
 */
+ (void)setCustomPersistentCacheDirectory:(NSString *)directory;

/**
 Clear This file's Persistent Cache.
 */
- (void)clearPersistentCache;

/**
 Clear All file's Persistent Cache.
 */
+ (void)clearAllPersistentCache;

/**
 Path of This file's Persistent Cache.

 @return Path.
 */
- (NSString * _Nullable)persistentCachePath;

// MARK: - Delete

/**
 Delete This File Object from server.
 
 @param completionHandler Completion Handler.
 */
- (void)deleteWithCompletionHandler:(void (^)(BOOL succeeded, NSError * _Nullable error))completionHandler;

/**
 Delete File Object List from server.
 
 @param files File Object List
 @param completionHandler Completion Handler.
 */
+ (void)deleteWithFiles:(NSArray<LCFile *> *)files
      completionHandler:(void (^)(BOOL succeeded, NSError * _Nullable error))completionHandler;

// MARK: - Get

/**
 Get File Object from server.
 
 @param objectId Object ID.
 @param completionHandler Completion Handler.
 */
+ (void)getFileWithObjectId:(NSString *)objectId
          completionHandler:(void (^)(LCFile * _Nullable file, NSError * _Nullable error))completionHandler;

// MARK: - Thumbnail

/*!
 Get a thumbnail URL for image saved on Qiniu.

 @param scaleToFit Scale the thumbnail and keep aspect ratio.
 @param width The thumbnail width.
 @param height The thumbnail height.
 @param quality The thumbnail image quality in 1 - 100.
 @param format The thumbnail image format such as 'jpg', 'gif', 'png', 'tif' etc.
 */
- (nullable NSString *)getThumbnailURLWithScaleToFit:(BOOL)scaleToFit
                                               width:(int)width
                                              height:(int)height
                                             quality:(int)quality
                                              format:(nullable NSString *)format;

/*!
 Get a thumbnail URL for image saved on Qiniu.
 @see -getThumbnailURLWithScaleToFit:width:height:quality:format

 @param scaleToFit Scale the thumbnail and keep aspect ratio.
 @param width The thumbnail width.
 @param height The thumbnail height.
 */
- (nullable NSString *)getThumbnailURLWithScaleToFit:(BOOL)scaleToFit
                                               width:(int)width
                                              height:(int)height;

/*!
 Gets a thumbnail asynchronously and calls the given block with the result.
 
 @param scaleToFit Scale the thumbnail and keep aspect ratio.
 @param width The desired width.
 @param height The desired height.
 @param block The block to execute. The block should have the following argument signature: (UIImage *image, NSError *error)
 */
- (void)getThumbnail:(BOOL)scaleToFit
               width:(int)width
              height:(int)height
           withBlock:(LCImageResultBlock)block;

// MARK: - Query

/*!
 Create an LCFileQuery which returns files.
 */
+ (LCFileQuery *)query;

// MARK: Compatibility

- (void)saveInBackgroundWithBlock:(void (^)(BOOL succeeded, NSError * _Nullable error))block;

- (void)saveInBackgroundWithBlock:(void (^)(BOOL succeeded, NSError * _Nullable error))block
                    progressBlock:(void (^ _Nullable)(NSInteger number))progressBlock;

@end

NS_ASSUME_NONNULL_END
