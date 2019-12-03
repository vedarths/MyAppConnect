/*!
 * @header ACTypes.h
 *
 * @abstract Enumerations used by AppConnect
 *
 * @copyright Copyright (c) 2017-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#ifndef ACTypes_h
#define ACTypes_h

#import <AppConnect/ACCompatibility.h>

/*!
  *  @typedef ACLogLevel
  *  @brief An enum classifying log messages into different levels.
  */
typedef NS_ENUM(NSInteger, ACLogLevel) {
    /*! Error messages */
    ACLogLevelError   = 0,
    /*! Warning messages */
    ACLogLevelWarning = 1,
    /*! Significant status messages such as app launch and major user actions. */
    ACLogLevelStatus  = 2,
    /*! Additional informational messages */
    ACLogLevelInfo    = 3,
    /*! Verbose messages which may include sensitive information */
    ACLogLevelVerbose = 4,
    /*! Debug messages which may include sensitive information */
    ACLogLevelDebug   = 5,
};

/*!
  *  @typedef ACPolicyState
  *  @brief An enum listing the states of policies.
  *  @discussion When an application receives notification that a policy has changed, it MUST call
  *  the corresponding acknowledgement function and provide one of these values. If the application does not implement
  *  the notification callback (one of the AppConnectDelegate functions), AppConnect will set the policy's state
  *  to ACPolicyStateUnsupported.
  */
typedef NS_ENUM(NSInteger, ACPolicyState) {
    /*! The policy is not supported by this application */
    ACPolicyStateUnsupported = 0,
    /*! The policy was applied successfully */
    ACPolicyStateApplied     = 1,
    /*! An error occurred applying the policy */
    ACPolicyStateError       = 2,
};

/*!
  *  @typedef ACManagedPolicy
  *  @brief An enum listing all possible managed policies
  */
typedef NS_ENUM(NSInteger, ACManagedPolicy) {
    /*! The AppConnect library has not yet determined whether the app is managed by MobileIron */
    ACManagedPolicyUnknown      =  0,
    /*! The application is not currently managed by MobileIron */
    ACManagedPolicyUnmanaged    =  1,
    /*! The application is currently managed by MobileIron */
    ACManagedPolicyManaged      =  2,
};

/*!
  *  @typedef ACAuthState
  *  @brief An enum listing all possible authorization states
  */
typedef NS_ENUM(NSInteger, ACAuthState) {
    /*! The user is not authorized to access sensitive data or views in this app. */
    ACAuthStateUnauthorized  =  0,
    /*! This is the only state in which the user is authorized to access sensitive data or views. */
    ACAuthStateAuthorized   =  1,
    /*! The app must erase all sensitive data. The user is not authorized to access sensitive data or views in this app. */
    ACAuthStateRetired      =  2,
};

/*!
  *  @typedef ACPasteboardPolicy
  *  @brief An enum listing all possible pasteboard policies
  */
typedef NS_ENUM(NSInteger, ACPasteboardPolicy) {
    /*!
      *  The application cannot write data to the pasteboard. The AppConnect library
      *  enforces this status and ensures that the app cannot modify the pasteboard contents.
      */
    ACPasteboardPolicyUnauthorized =  0,
    /*!
      *  The application may write data to the pasteboard which gets shared among
      *  all apps (Both AppConnect and non-AppConnect apps can read this data).
      */
    ACPasteboardPolicyAuthorized   =  1,
    /*!
      *  The application may write data to the general pasteboard which is shared
      *  with authorized AppConnect apps. The AppConnect library implements
      *  the underlying technology so that the data written to the general pasteboard
      *  by one AppConnect app is only readable by authorized AppConnect apps.
      */
    ACPasteboardPolicySecureCopy   =  2,
};

/*!
 * @typedef ACOpenInPolicy
 * @brief An enum listing all possible open in policies
 */
typedef NS_ENUM(NSInteger, ACOpenInPolicy) {
    /*!
     * The application may not use Open In.
     * 
     * Sharing content with other apps is not allowed.
     * The end user is displayed the "open-in" options, but selecting any of the apps
     * has no effect. This behavior can confuse the end user, who sometimes thinks
     * that content was shared with another app.
     */
    ACOpenInPolicyUnauthorized =  0,
    /*!
     * The application may use Open In.
     *
     * Sharing content with all other apps is allowed. 
     */
    ACOpenInPolicyAuthorized   =  1,
    /*!
     * The application may only use Open In to send documents to applications in the whitelist
     *
     * Sharing content with only whitelisted apps is allowed. The end user is displayed
     * the "open-in" options, but selecting an app that is not on
     * the whitelist has no effect. This behavior maight confuse the end user,
     * who sometimes thinks that content was shared with another app.
     */
    ACOpenInPolicyWhitelist    =  2,
};

/*!
 * @typedef ACOpenFromPolicy
 * @brief An enum listing all possible open from policies
 */
typedef NS_ENUM(NSInteger, ACOpenFromPolicy) {
    /*!
     * The application may not use Open In.
     *
     * Sharing content from other apps is not allowed.
     */
    ACOpenFromPolicyUnauthorized =  0,
    /*!
     * The application may use Open from.
     *
     * Sharing content with all other apps is allowed.
     */
    ACOpenFromPolicyAuthorized   =  1,
    /*!
     * The application may only use Open from to receive documents from applications in the whitelist
     *
     * Sharing content with only whitelisted apps is allowed. The end user is displayed
     * the "open-from" options, but selecting an app that is not on
     * the whitelist has no effect. This behavior maight confuse the end user,
     * who sometimes thinks that content was shared with another app.
     */
    ACOpenFromPolicyWhitelist    =  2,
};

/*!
  *  @typedef ACPrintPolicy
  *  @brief An enum listing all possible print policies
  */
typedef NS_ENUM(NSInteger, ACPrintPolicy) {
    /*! The application may not use Print. */
    ACPrintPolicyUnauthorized =  0,
    /*! The application may use Print. */
    ACPrintPolicyAuthorized   =  1,
};

/*!
 * @typedef ACSecureFileIOPolicy
 * @brief An enum listing all possible secure file policies.
 * @see //apple_ref/doc/header/ACSecureFile.h ACSecureFile.h
 */
typedef NS_ENUM(NSInteger, ACSecureFileIOPolicy) {
    /*! The application may store sensitive files using iOS filessytem APIs or AppConnect secure file storage */
    ACSecureFileIOPolicyOptional =  0,
    /*! The application must store sensitive files using only AppConnect secure file storage. */
    ACSecureFileIOPolicyRequired =  1,
};

/*!
  *  @typedef ACSecureServicesAvailability
  *  @brief An enum describing the availability of AppConnect secure services, such as secure file IO.
  */
typedef NS_ENUM(NSInteger, ACSecureServicesAvailability) {
    /*! Secure services are currently unavailable. */
    ACSecureServicesAvailabilityUnavailable = 0,
    /*! Secure services are currently available. */
    ACSecureServicesAvailabilityAvailable   = 1,
};

#endif /* ACTypes_h */
