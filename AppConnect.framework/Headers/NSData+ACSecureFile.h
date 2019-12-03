/*!
 * @header NSData+ACSecureFile.h
 *
 * @abstract Category of NSData adding AppConnect Secure File IO
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
@interface NSData (ACSecureFile)

/*! */
+ (nullable instancetype)dataWithContentsOfSecureFile:(NSString *)path;
/*! */
+ (nullable instancetype)dataWithContentsOfSecureFile:(NSString *)path options:(NSDataReadingOptions)mask error:(NSError **)errorPtr;
/*! */
+ (nullable instancetype)dataWithContentsOfSecureURL:(NSURL *)url;
/*! */
+ (nullable instancetype)dataWithContentsOfSecureURL:(NSURL *)url options:(NSDataReadingOptions)mask error:(NSError **)errorPtr;

/*! */
- (nullable instancetype)initWithContentsOfSecureFile:(NSString *)path;
/*! */
- (nullable instancetype)initWithContentsOfSecureFile:(NSString *)path options:(NSDataReadingOptions)mask error:(NSError **)errorPtr;
/*! */
- (nullable instancetype)initWithContentsOfSecureURL:(NSURL *)url;
/*! */
- (nullable instancetype)initWithContentsOfSecureURL:(NSURL *)url options:(NSDataReadingOptions)mask error:(NSError **)errorPtr;

/*! */
- (BOOL)writeToSecureFile:(NSString *)path atomically:(BOOL)flag;
/*! */
- (BOOL)writeToSecureFile:(NSString *)path options:(NSDataWritingOptions)mask error:(NSError **)errorPtr;
/*! */
- (BOOL)writeToSecureURL:(NSURL *)aURL atomically:(BOOL)atomically;
/*! */
- (BOOL)writeToSecureURL:(NSURL *)aURL options:(NSDataWritingOptions)mask error:(NSError **)errorPtr;

@end

NS_ASSUME_NONNULL_END
