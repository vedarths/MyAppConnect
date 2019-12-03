/*!
 * @header ACDerivedCredential.h
 *
 * @abstract Derived creadential model.
 *
 * @copyright Copyright (c) 2017-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>
#import <AppConnect/ACCompatibility.h>

// Certificate sending constants
/*! */
typedef NSString * const ACDerivedCredentialPayloadKey NS_STRING_ENUM;
/*! */
extern ACDerivedCredentialPayloadKey ACDerivedCredentialPayloadKeyTag;
/*! */
extern ACDerivedCredentialPayloadKey ACDerivedCredentialPayloadKeyCert;
/*! */
extern ACDerivedCredentialPayloadKey ACDerivedCredentialPayloadKeyPrivateKey;
/*! */
extern ACDerivedCredentialPayloadKey ACDerivedCredentialPayloadKeyCredentialArray;

// Certificate tags
/*! */
typedef NSString * const ACDerivedCredentialTag NS_STRING_ENUM;
/*! */
extern ACDerivedCredentialTag ACDerivedCredentialTagAuthentication;
/*! */
extern ACDerivedCredentialTag ACDerivedCredentialTagSigning;
/*! */
extern ACDerivedCredentialTag ACDerivedCredentialTagEncryption;
/*! */
extern ACDerivedCredentialTag ACDerivedCredentialTagEscrow;

/*!
 * @class ACDerivedCredential
 * @abstract Represents derived credential
 */
@interface ACDerivedCredential : NSObject

@property (nonatomic, readonly) NSString *name;
@property (nonatomic, readonly) NSString *serialNumber;
@property (nonatomic, readonly) NSDate *expirationDate;
@property (nonatomic, readonly) NSArray *certificates;

// Default contructors are not available
// Use designated initializer defined below.
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*!
 *  Creates ACDerivedCredential suitable for sending to the MobileIron client app
 *
 *  @param name String to be used as the human readable name for this derived credentials payload.
 *  @param serialNumber String to be used as the identifier for this derived credentials payload.
 *  @param expirationDate Expiration date for this derived credentials payload.
 *  @param certificates array of dictionaries representing certificates associated with this derived credentials payload.
 *          Each dictionary MUST have values for all keys defined in Certificate sending constants:
 *          ACDerivedCredentialPayloadKeyTag - value is typically one of the predefined constants from Certificate tags,
 *              but can be any string if you have other uses for certificates.
 *          ACDerivedCredentialPayloadKeyCert - value MUST be DER encoded certificate data.
 *          ACDerivedCredentialPayloadKeyPrivateKey - value MUST be DER encoded private key data.
 *          In case there are multiple certificates, dictionary MUST have values for following keys.
 *          ACDerivedCredentialPayloadKeyCredentialArray - value is array of dictionaries that MUST contain
 *              ACDerivedCredentialPayloadKeyCert - value MUST be DER encoded certificate data.
 *              ACDerivedCredentialPayloadKeyPrivateKey - value MUST be DER encoded private key data.
 *                  In case of type ACDerivedCredentialTagDecryption, dictionary MUST have values for following keys.
 *  @return ACDerivedCredential suitable for sending to the MobileIron client app or nil if any parameter is nil or empty.
 */
- (instancetype)initWithName:(NSString *)name
                serialNumber:(NSString *)serialNumber
              expirationDate:(NSDate *)expirationDate
                certificates:(NSArray *)certificates NS_DESIGNATED_INITIALIZER;

@end
