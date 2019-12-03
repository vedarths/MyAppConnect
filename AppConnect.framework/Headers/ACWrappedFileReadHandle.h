/*!
 * @header ACWrappedFileReadHandle.h
 *
 * @abstract File handle for reading wrapped files.
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>
#import <AppConnect/ACFileHandle.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @class ACWrappedFileReadHandle
 * @abstract This class provides a method for creating a file handle for a wrapped file.
 */
@interface ACWrappedFileReadHandle: ACFileHandle

/**
 * Actual file name. This can be different from the file name present in path.
 * Use this file name for all UI treatment.
 */
@property (nonatomic, strong) NSString * displayFileName;

/*!
 * Create a file handle for the file at the given path, with the keystore for decrypting the file.
 */
+(nullable instancetype)fileHandleForReadingAtPath:(NSString *)path
                                      withKeystore:(NSDictionary *)keystore;

// The following methods are not available for ACWrappedFileReadHandle
+ (nullable instancetype)fileHandleForReadingAtPath:(NSString *)path NS_UNAVAILABLE;
+ (nullable instancetype)fileHandleForWritingAtPath:(NSString *)path NS_UNAVAILABLE;
+ (nullable instancetype)fileHandleForUpdatingAtPath:(NSString *)path NS_UNAVAILABLE;

+ (nullable instancetype)fileHandleForReadingFromURL:(NSURL *)url error:(NSError **)error NS_UNAVAILABLE;
+ (nullable instancetype)fileHandleForWritingToURL:(NSURL *)url error:(NSError **)error NS_UNAVAILABLE;
+ (nullable instancetype)fileHandleForUpdatingURL:(NSURL *)url error:(NSError **)error NS_UNAVAILABLE;
@end
NS_ASSUME_NONNULL_END

