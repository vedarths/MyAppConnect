/*!
 * @header ACWrappedAppKey.h
 *
 * @abstract Retrieving the crypto keys used for AppConnect File encryption.
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

/*! Error domain associated with retrieving crypto keys. */
extern NSString * const kACWrappedKeyErrorDomain;

/*!
 * @typedef ACWrappedAppKeyErrorType
 * @brief Enum providing error codes returned when operation fails.
 */
typedef NS_ENUM(int, ACWrappedAppKeyErrorType) {
    /*! Wrapped key format is incorrect or not supported. */
    ACWrappedAppKeyErrorTypeFormatError,
    /*! Group ID is invalid. */
    ACWrappedAppKeyErrorTypeInvalidGroupID,
    /*! Keystore is not valid. */
    ACWrappedAppKeyErrorTypeInvalidKeystore,
    /*! Operation to encrypt keystore failed. */
    ACWrappedAppKeyErrorTypeEncryptionFailed,
    /*! Operation to decrypt keystore failed. */
    ACWrappedAppKeyErrorTypeDecryptionFailed,
    /*! Operation to serialize keystore failed. */
    ACWrappedAppKeyErrorTypeSerializationFailed,
    /*! Operation to deserialize keystore failed. */
    ACWrappedAppKeyErrorTypeDeserializationFailed
};


/*!
 * @class ACWrappedAppKey
 * @abstract This class provides a method for getting the crypto block used for encrypting files.
 */
@interface ACWrappedAppKey : NSObject

/*!
 * Get crypto keys. The resulting data is encrypted using "groupID".
 * If groupID is nil, then data is encrypted with shared key.
 * @param groupID String used as index for encrypting crypto keys.
 * @param error If there is an error, error is set with appropriate NSError object.
 * @return NSData representation of crypto keys used for AppConnect file encryption.
 */
+(NSData *)getCryptoKeysForACFileEncryptionWithSharedGroupID:(NSString *)groupID
                                                       error:(NSError *__autoreleasing *)error;
@end
