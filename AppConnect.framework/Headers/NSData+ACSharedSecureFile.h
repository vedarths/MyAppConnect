/*!
 * @header NSData+ACSharedSecureFile.h
 *
 * @abstract Category of NSData adding AppConnect Shared Secure File IO
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @abstract AppConnect Shared Secure File IO additions
 */
@interface NSData (ACSharedSecureFile)

/*! */
+ (nullable instancetype)dataWithContentsOfSecureFile:(NSString *)path
                                    encryptionGroupId:(nullable NSString *)groupId;

/*! */
+ (nullable instancetype)dataWithContentsOfSecureFile:(NSString *)path
                                    encryptionGroupId:(nullable NSString *)groupId
                                              options:(NSDataReadingOptions)mask
                                                error:(NSError **)errorPtr;

/*! */
+ (nullable instancetype)dataWithContentsOfSecureURL:(NSURL *)url
                                   encryptionGroupId:(nullable NSString *)groupId;

/*! */
+ (nullable instancetype)dataWithContentsOfSecureURL:(NSURL *)url
                                   encryptionGroupId:(nullable NSString *)groupId
                                             options:(NSDataReadingOptions)mask
                                               error:(NSError **)errorPtr;

/*! */
- (nullable instancetype)initWithContentsOfSecureFile:(NSString *)path
                                    encryptionGroupId:(nullable NSString *)groupId;

/*! */
- (nullable instancetype)initWithContentsOfSecureFile:(NSString *)path
                                    encryptionGroupId:(nullable NSString *)groupId
                                              options:(NSDataReadingOptions)mask
                                                error:(NSError **)errorPtr;

/*! */
- (nullable instancetype)initWithContentsOfSecureURL:(NSURL *)url
                                   encryptionGroupId:(nullable NSString *)groupId;

/*! */
- (nullable instancetype)initWithContentsOfSecureURL:(NSURL *)url
                                   encryptionGroupId:(nullable NSString *)groupId
                                             options:(NSDataReadingOptions)mask
                                               error:(NSError **)errorPtr;

/*! */
- (BOOL)writeToSecureFile:(NSString *)path
        encryptionGroupId:(nullable NSString *)groupId
               atomically:(BOOL)flag;

/*! */
- (BOOL)writeToSecureFile:(NSString *)path encryptionGroupId:(nullable NSString *)groupId
                  options:(NSDataWritingOptions)mask
                    error:(NSError **)errorPtr;

/*! */
- (BOOL)writeToSecureURL:(NSURL *)aURL
       encryptionGroupId:(nullable NSString *)groupId
              atomically:(BOOL)atomically;

/*! */
- (BOOL)writeToSecureURL:(NSURL *)aURL
       encryptionGroupId:(nullable NSString *)groupId
                 options:(NSDataWritingOptions)mask
                   error:(NSError **)errorPtr;

@end

NS_ASSUME_NONNULL_END
