/*!
 * @header ACUnwrappedFile.h
 *
 * @abstract Reading wrapped files.
 *
 * @copyright Copyright (c) 2017-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

@class ACWrappedFileReadHandle;

extern NSString * const kACWrappedFileReadHandleErrorDomain;

/*!
 * @typedef ACWrappedFileReadError
 * @brief Enum providing error codes returned when read fails.
 */
typedef NS_ENUM(int, ACWrappedFileReadError) {
    /*! File does not exist at given path. */
    ACWrappedFileReadErrorFileDoesNotExist,
    /*! Provided file has a bad crypto block. */
    ACWrappedFileReadErrorBadCryptoBlock,
    /*! Provided file has an unknown key type specified. */
    ACWrappedFileReadErrorUnknowKeyType,
    /*! Provided file has unknown secure file type. */
    ACWrappedFileReadErrorUnknownSecureFileType,
    /*! Cannot determine if the file is wrapped or not. */
    ACWrappedFileReadErrorUnknownWrapperFormat,
    /*! Cannot create a read file handle */
    ACWrappedFileReadErrorUnableToCreateReadFileHandle
};

/*!
 * @class ACUnwrappedFile
 * @abstract This class provides method for reading a wrapped file.
 */
@interface ACUnwrappedFile : NSObject

/*!
 * Read wrapped file at path.
 * @param path Path to wrapped file.
 * @param groupID The original groupID used (shared group ID)
 * @param error In case of error, the error is set with appropriate NSError object.
 * @return ACWrappedFileReadHandle file handle, if operation was successful. Otherwise returns nil.
 */
+(ACWrappedFileReadHandle *)readWrappedFileAtPath:(NSString *)path
                                    sharedGroupID:(NSString *)groupID
                                            error:(NSError *__autoreleasing *)error;
@end
