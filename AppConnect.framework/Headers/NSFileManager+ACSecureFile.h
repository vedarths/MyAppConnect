/*!
 * @header NSFileManager+ACSecureFile.h
 *
 * @abstract Category of NSFileManager adding AppConnect Secure File IO
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @abstract AppConnect Secure File IO additions
 */
@interface NSFileManager (ACSecureFile)

/*! */
- (BOOL)createSecureFileAtPath:(NSString *)path
                      contents:(nullable NSData *)contents
                    attributes:(nullable NSDictionary *)attributes
                         error:(NSError *__autoreleasing*)error;

/*! */
- (BOOL)moveSecureFileAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError *__autoreleasing*)error;
/*! */
- (BOOL)moveSecureFileAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError *__autoreleasing*)error;

/*! */
- (BOOL)copySecureFileAtPath:(NSString *)srcPath toPath:(NSString *)dstPath error:(NSError *__autoreleasing*)error;
/*! */
- (BOOL)copySecureFileAtURL:(NSURL *)srcURL toURL:(NSURL *)dstURL error:(NSError *__autoreleasing*)error;

/*! */
- (nullable NSData *)secureContentsAtPath:(NSString *)path error:(NSError *__autoreleasing*)error;
/*! */
- (BOOL)secureContentsEqualAtPath:(NSString *)path1 andPath:(NSString *)path2 error:(NSError *__autoreleasing*)error;

/*! */
- (nullable NSDictionary *)attributesOfSecureFileAtPath:(NSString *)path error:(NSError *__autoreleasing*)error;

@end

NS_ASSUME_NONNULL_END
