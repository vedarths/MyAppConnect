/*!
 * @header ACFileHandle.h
 *
 * @abstract Subclass of NSFileHandle adding AppConnect Secure File IO
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/*!
 * @class ACFileHandle
 * @abstract NSFileHandle implementation compatible with AppConnect Secure File IO
 */
@interface ACFileHandle : NSFileHandle {
@private
    int fd;
    int type;
}

/*! */
+ (nullable instancetype)fileHandleForReadingAtPath:(NSString *)path;
/*! */
+ (nullable instancetype)fileHandleForReadingAtPath:(NSString *)path error:(NSError *__autoreleasing *)error;
/*! */
+ (nullable instancetype)fileHandleForReadingFromURL:(NSURL *)url error:(NSError *__autoreleasing *)error;
/*! */
+ (nullable instancetype)fileHandleForUpdatingAtPath:(NSString *)path;
/*! */
+ (nullable instancetype)fileHandleForUpdatingAtPath:(NSString *)path error:(NSError *__autoreleasing *)error;
/*! */
+ (nullable instancetype)fileHandleForUpdatingURL:(NSURL *)url error:(NSError *__autoreleasing *)error;
/*! */
+ (nullable instancetype)fileHandleForWritingAtPath:(NSString *)path;
/*! */
+ (nullable instancetype)fileHandleForWritingAtPath:(NSString *)path error:(NSError *__autoreleasing *)error;
/*! */
+ (nullable instancetype)fileHandleForWritingToURL:(NSURL *)url error:(NSError *__autoreleasing *)error;

/*! */
- (NSData *)availableData;
/*! */
- (nullable NSData *)availableDataWithError:(NSError *__autoreleasing *)error;

/*! */
- (NSData *)readDataToEndOfFile;
/*! */
- (nullable NSData *)readDataToEndOfFileWithError:(NSError *__autoreleasing *)error;
/*! */
- (NSData *)readDataOfLength:(NSUInteger)length;
/*! */
- (nullable NSData *)readDataOfLength:(NSUInteger)length error:(NSError *__autoreleasing *)error;

/*! */
- (void)writeData:(NSData *)data;
/*! */
- (BOOL)writeData:(NSData *)data error:(NSError *__autoreleasing *)error;

/*! */
- (unsigned long long)offsetInFile;
/*! */
- (unsigned long long)seekToEndOfFile;
/*! */
- (void)seekToFileOffset:(unsigned long long)offset;

/*! */
- (void)truncateFileAtOffset:(unsigned long long)offset;
/*! */
- (void)synchronizeFile;
/*! */
- (void)closeFile;

@end

NS_ASSUME_NONNULL_END

