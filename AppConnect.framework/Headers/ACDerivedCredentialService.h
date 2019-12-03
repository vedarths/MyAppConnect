/*!
 * @header ACDerivedCredentialService.h
 *
 * @abstract Derived creadential handling.
 *
 * @copyright Copyright (c) 2017-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class ACDerivedCredential;

/*! */
extern NSString *const ACDerivedCredentialServiceErrorDomain;

/*!
 * @typedef ACDerivedCredentialServiceErrorCode
 * @brief Codes for errors occured during derived credentials processing.
 */
typedef NS_ENUM (NSInteger, ACDerivedCredentialServiceErrorCode) {
    /*! Error code for unknown error. */
    ACDerivedCredentialServiceErrorUnknown = -1000,
    /*! Error code for the case when one of ACDerivedCredential properties is not valid. */
    ACDerivedCredentialServiceErrorInvalid = -1001,
    /*! Error code for the case when secure services are not available making it impossible to send credential to the MobileIron client app. */
    ACDerivedCredentialServiceErrorServiceUnavailable = -1002,
    /*! Error code for the case when the MobileIron client app is not installed on the device. */
    ACDerivedCredentialServiceErrorMissingClient = -1003,
    /*! Error code for the case when the MobileIron client app is installed on the device, but does not support derived credentials. */
    ACDerivedCredentialServiceErrorOldClient = -1004,
    /*! Error code for the case when the underlying AppConnect SDK is not ready. Make sure -[AppConnect isReady] returns YES before trying again. */
    ACDerivedCredentialServiceErrorNotReady = -1005,
};

/*!
 * @typedef ACDerivedCredentialServiceSupport
 */
typedef NS_ENUM (NSInteger, ACDerivedCredentialServiceSupport) {
    /*! Indicates that derived credentials are supported by the agent application */
    ACDerivedCredentialServiceSupportPresent = 0,
    /*! Indicates that agent application is to old to suuport derived credentials */
    ACDerivedCredentialServiceSupportOldClient,
    /*! Indicates that agent application is not installed on the device */
    ACDerivedCredentialServiceSupportMissingClient,
};

/*!
 * @class ACDerivedCredentialService
 * @abstract ACDerivedCredentialService is responsible for communicating derived credentials to MAM agent application.
 */
@interface ACDerivedCredentialService : NSObject

@property (nonatomic, readonly) NSString *brand;
@property (nonatomic, readonly) NSString *callbackScheme;

// Default contructors are not available
// Use designated initializer defined below.
+ (instancetype)new NS_UNAVAILABLE;
- (instancetype)init NS_UNAVAILABLE;

/*!
 *  Check if the MobileIron client app is installed and supports receiving derived credentials.
 *  @discussion The app must add "appconnectdc" and "appconnect" to LSApplicationQueriesSchemes in its Info.plist for this method to return actual result.
 */
+ (ACDerivedCredentialServiceSupport)derivedCredentialSupport;

/*!
 *  Check if the credentials can be sent.
 *  @return YES if appropriate version of the MobileIron client app is installed and secure services are available, NO otherwise.
 */
+ (BOOL)canSendCredential;

/*!
 *  Creates ACDerivedCredentialService instance responsible for communicating with the MobileIron client app
 *  @param brand String to be used as the identifier of the derived credentials provider
 *  @param callbackScheme URL scheme to be used by the MobileIron client app to communicate with the app.
 *      The MobileIron client uses the scheme to ask the app to create a new derived credential.
 *      The URL for this request is <callbackScheme>://new
 *  @return ACDerivedCredentialService instance configured for communicating with the MobileIron client app or
 *      nil if the MobileIron client app doesn't support receiving derived credentials.
 *  @discussion The app must add "appconnectdc" to LSApplicationQueriesSchemes in its Info.plist to allow querying the MobileIron client app.
 */
- (nullable instancetype)initWithBrand:(NSString *)brand callbackScheme:(NSString *)callbackScheme NS_DESIGNATED_INITIALIZER;

/*!
 *  Sends derived credential to the MobileIron client app
 *  @param derivedCredential ACDerivedCredential instance
 *  @param error if sending credential fails will contain an error describing the reason of the failure.
 *  @return YES if the certificates were sent, NO otherwise.
 *  @discussion Secure services must be available for this to succeed.
 *  @note Calling this method results in -[UIApplication openURL:] and hence should be performed on the main thread.
 */
- (BOOL)sendDerivedCredential:(ACDerivedCredential *)derivedCredential withError:(NSError **)error;

@end

NS_ASSUME_NONNULL_END
