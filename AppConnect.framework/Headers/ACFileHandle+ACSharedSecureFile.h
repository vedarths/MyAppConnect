/*!
 * @header ACFileHandle+ACSharedSecureFile.h
 *
 * @abstract Extension of ACFileHandle adding AppConnect Shared Secure File IO
 *
 * @copyright Copyright (c) 2017-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <AppConnect/ACFileHandle.h>

// ACFileHandle Category to open file handle for read/write of files, that need use encryption group ID.
@interface ACFileHandle (ACSharedSecureFile)

+ (id)fileHandleForReadingAtPath:(NSString *)path
           withEncryptionGroupId:(NSString *)groupId;

+ (id)fileHandleForReadingAtPath:(NSString *)path
           withEncryptionGroupId:(NSString *)groupId
                           error:(NSError *__autoreleasing *)error;

+ (id)fileHandleForReadingFromURL:(NSURL *)url
            withEncryptionGroupId:(NSString *)groupId
                            error:(NSError *__autoreleasing *)error;

+ (id)fileHandleForUpdatingAtPath:(NSString *)path
            withEncryptionGroupId:(NSString *)groupId;

+ (id)fileHandleForUpdatingAtPath:(NSString *)path
            withEncryptionGroupId:(NSString *)groupId
                            error:(NSError *__autoreleasing *)error;

+ (id)fileHandleForUpdatingURL:(NSURL *)url
         withEncryptionGroupId:(NSString *)groupId
                         error:(NSError *__autoreleasing *)error;

+ (id)fileHandleForWritingAtPath:(NSString *)path
           withEncryptionGroupId:(NSString *)groupId;

+ (id)fileHandleForWritingAtPath:(NSString *)path
           withEncryptionGroupId:(NSString *)groupId
                           error:(NSError *__autoreleasing *)error;

+ (id)fileHandleForWritingToURL:(NSURL *)url
          withEncryptionGroupId:(NSString *)groupId
                          error:(NSError *__autoreleasing *)error;

@end
