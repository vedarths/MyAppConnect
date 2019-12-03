/*!
 * @header NSMutableDictionary+ACSecureFile.h
 *
 * @abstract Category of NSMutableDictionary adding AppConnect Secure File IO
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
@interface NSMutableDictionary (ACSecureFile)

/*! */
+ (nullable instancetype)dictionaryWithContentsOfSecureFile:(NSString *)path error:(NSError *__autoreleasing*)error;
/*! */
+ (nullable instancetype)dictionaryWithContentsOfSecureURL:(NSURL *)aURL error:(NSError *__autoreleasing*)error;

/*! */
- (nullable instancetype)initWithContentsOfSecureFile:(NSString *)path error:(NSError *__autoreleasing*)error;
/*! */
- (nullable instancetype)initWithContentsOfSecureURL:(NSURL *)aURL error:(NSError *__autoreleasing*)error;

/*! */
- (BOOL)writeToSecureFile:(NSString *)path atomically:(BOOL)flag error:(NSError *__autoreleasing*)error;
/*! */
- (BOOL)writeToSecureURL:(NSURL *)aURL atomically:(BOOL)flag error:(NSError *__autoreleasing*)error;

@end

NS_ASSUME_NONNULL_END
