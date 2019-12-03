/*!
 * @header AppConnectInterface.h
 *
 * @abstract Central class of AppConnect
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>
#import <AppConnect/ACSensitiveData.h>

#import <AppConnect/ACTypes.h>

NS_ASSUME_NONNULL_BEGIN

@protocol AppConnectDelegate;

/*! Name of the class provided by the AppConnect library to be used as the application's principal class */
extern NSString * const ACUIApplicationClassName;

/*!
 *  Name of an exception thrown if the properties of AppConnect singleton object
 *  are accessed before AppConnect is ready.
 */
extern NSString * const ACPropertyAccessException;

/*!
 * @class AppConnect
 * @abstract Central class of AppConnect
 */
@interface AppConnect : NSObject

/*! The version of the AppConnect library. */
+(NSString *)version;

/*!
 *  A Boolean flag to indicate whether the properties on the AppConnect singleton can now be accessed.
 *  The value is YES if the properties are valid and can now be accessed; NO, otherwise.
 *  When the value is NO, accessing the properties will throw ACPropertyAccessException.
 */
@property (nonatomic, readonly, getter=isReady) BOOL ready;

/*!
 *  The current managed policy.
 *  See the ACManagedPolicy enum for a description of possible states.
 */
@property (nonatomic, readonly) ACManagedPolicy managedPolicy;

/*!
 *  The current authorization state.
 *  See the ACAuthStates enum for a description of possible states.
 */
@property (nonatomic, readonly) ACAuthState authState;

/*! A message describing the current authorization state. */
@property (nonatomic, readonly, nullable) NSString *authMessage;

/*!
 *  The current pasteboard policy.
 *  See the ACPasteboardPolicy enum for a description of possible policies.
 */
@property (nonatomic, readonly) ACPasteboardPolicy pasteboardPolicy;

/*!
 *  The current open in policy.
 *  See the ACOpenInPolicy enum for a description of possible policies.
 */
@property (nonatomic, readonly) ACOpenInPolicy openInPolicy;

/*!
 *  The current open in whitelist.
 *  The set contains NSStrings. Each NSString is a bundleID of an app that is allowed to open documents from the app.
 */
@property (nonatomic, readonly) NSSet<NSString*> *openInWhitelist;

/*!
 *  The current open from policy.
 *  See the ACOpenFromPolicy enum for a description of possible policies.
 */
@property (nonatomic, readonly) ACOpenFromPolicy openFromPolicy;

/*!
 *  The current open from whitelist.
 *  The set contains NSStrings. Each NSString is a bundleID of an app that is allowed to send documents to this app.
 */
@property (nonatomic, readonly) NSSet<NSString*> *openFromWhitelist;

/*!
 *  The list of Apple activities that should be excluded from UIActivityViewController.
 *  The array contains NSStrings. These strings correspond to the string constants used by Apple.
 */
@property (nonatomic, readonly) NSArray *excludedAppleActivityTypes;

/*!
 *  The current print policy.
 *  See the ACPrintPolicy enum for a description of possible policies.
 */
@property (nonatomic, readonly) ACPrintPolicy printPolicy;

/*!
 *  The current secure file IO policy.
 *  See the ACSecureFileIOPolicy enum for a description of possible policies.
 */
@property (nonatomic, readonly) ACSecureFileIOPolicy secureFileIOPolicy;

/*!
 *  The current app-specific configuration.
 */
@property (nonatomic, readonly) NSDictionary *config;

/*!
 *  Whether secure services are currently available.
 *
 *  If this is ACSecureServicesAvailabilityAvailable, secure services are currently available. AppConnect secure file
 *  storage can access secure files.
 *
 *  If this is ACSecureServicesAvailabilityUnavailable, secure services are currently unavailable. AppConnect secure
 *  file storage is unable to access secure files.
 */
@property (nonatomic, readonly) ACSecureServicesAvailability secureServicesAvailability;

/*!
 *  Dual mode apps call this method to determine whether to start the AppConnect library. The method returns YES if:
 *  - The MobileIron client is installed or
 *  - The MobileIron client had been installed but is now deleted, and the app had previously run as an AppConnect app.
 *
 *  This method is necessary because users often launch an app before the MobileIron client is installed.
 *  When an app launches the first time, the app determines whether it is managed by MobileIron, and therefore determines
 *  whether to run as an AppConnect app (managed by MobileIron) or a regular app (not managed by MobileIron).
 *  Once an app has made this choice, it cannot change to the other choice without user actions, such as using an
 *  app-provided user interface, or re-installing the app.
 *
 *  Therefore, an app should call +shouldStartAppConnect: to determine whether to delay the choice until its next launch.
 *  If +shouldStartAppConnect: returns NO, the app delays the choice and runs as a regular app. On the app's next launch,
 *  if +shouldStartAppConnect: returns YES, it makes the choice to run as an AppConnect app without any user action.
 */
+(BOOL)shouldStartAppConnect;

/*!
 *  The current log level
 *
 *  See the -logAtLevel:format:... method for a description of the log level system. See the ACLogLevel enum for an
 *  explanation of the log levels.
 *
 *  This function is safe to call when AppConnect is stopped. If AppConnect is stopped, this returns ACLogLevelStatus.
 */
+(ACLogLevel)logLevel;

/*!
 *  A delegate that will receive AppConnect notifications. See the AppConnectDelegate protocol for details.
 *  WARNING: The delegate is not retained to avoid circular dependencies between this class and the delegate.
 */
@property (nonatomic, weak, nullable) id<AppConnectDelegate> appConnectDelegate;

/*!
 * The designated initializer for AppConnect.
 * Applications must call this method once before calling any other AppConnect methods.
 * @param appConnectDelegate An object conforming to AppConnectDelegate protocol. It must not be nil.
 */
+(void)initWithDelegate:(id<AppConnectDelegate>)appConnectDelegate;

/*!
 *  Get the shared instance of AppConnect. AppConnect is a singleton. Applications do not create their own instances of
 *  AppConnect. Instead applications must use this class method to get the one shared instance of AppConnect. You must
 *  call +initWithDelegate: before calling sharedInstance. Otherwise sharedInstance will return nil.
 */
+(nullable AppConnect *)sharedInstance;

/*!
 * Start the AppConnect system. This must be called in the UIApplicationDelegate's
 * -application:didFinishLaunchingWithOptions: method.
 * @param launchOptions Must be the value provided to -application:didFinishLaunchingWithOptions:
 */
-(void)startWithLaunchOptions:(nullable NSDictionary *)launchOptions;

/*!
 *  Retire the application. Most applications do not need to call this method; it is primarily for dual-mode
 *  applications. This method sets the authState to ACAuthStateRetired, and sets the authMessage to a message stating
 *  that the application has retired itself. This also sets all other policies to their defaults, which erases any secure
 *  information in the policies, such as certificates or passwords in the configuration.
 */
-(void)retire;

/*!
 *  Stop the AppConnect system. Only dual-mode applications should call this method, and only when switching from
 *  MobileIron mode to non-MobileIron mode. This stops all AppConnect functions, sets AppConnect delegate to nil
 *  and deallocs the shared instance. After calling this method, all other methods must not be called and will
 *  have undefined result, except for the following:
 *    -initWithDelegate:
 *    +logLevel
 *    +logAtLevel:format:...
 *    +logAtLevel:format:args:
 */
-(void)stop;

/*!
 * When the AppConnectDelegate receives the -appConnect:authStateChangedTo:withMessage: callback, it must call this
 * function some time later to acknowledge the new policy.
 *
 * @param policyState Indicates the new state. See the ACPolicyState enum for the possible acknowlegements.
 *  ACPolicyStateUnsupported is not permitted; all applications must support all auth states.
 * @param message An optional message describing the acknowledgement. This is primarily useful for describing the error
 *  when the policyState is ACPolicyStateError.
 */
-(void)authStateApplied:(ACPolicyState)policyState message:(nullable NSString *)message;

/*!
 * When the AppConnectDelegate receives the -appConnect:configChangedTo: callback, it must call this function some time
 * later to acknowledge the new config.
 *
 * If the AppConnectDelegate does not implement the -appConnect:configChangedTo: method, this is equivalent to
 * automatically calling this function with a policyState of ACPolicyStateUnsupported. In this case a standard message
 * is supplied.
 *
 * @param policyState Indicates the new state. See the ACPolicyState enum for the possible acknowledgements.
 * @param message An optional message describing the acknowledgement. This is primarily useful for describing the error
 *  when the policyState is ACPolicyStateError.
 */
-(void)configApplied:(ACPolicyState)policyState message:(nullable NSString *)message;

/*!
 * When the AppConnectDelegate receives the -appConnect:openInPolicyChangedTo:whitelist: callback, it must call this
 * function some time later to acknowledge the new policy.
 *
 * If the AppConnectDelegate does not implement the -appConnect:openInPolicyChangedTo: method, this is equivalent to
 * automatically calling this function with a policyState of ACPolicyStateUnsupported. In this case, a standard message
 * is supplied.
 *
 * @param policyState Indicates the new state. See the ACPolicyState enum for the possible acknowledgements.
 * @param message An optional message describing the acknowledgement. This is primarily useful for describing the error
 *  when the policyState is ACPolicyStateError.
 */
-(void)openInPolicyApplied:(ACPolicyState)policyState message:(nullable NSString *)message NS_SWIFT_NAME(openInPolicyApplied(_:message:));

/*!
 * When the AppConnectDelegate receives the -appConnect:openFromPolicyChangedTo:whitelist: callback, it must call this
 * function some time later to acknowledge the new policy.
 *
 * If the AppConnectDelegate does not implement the -appConnect:openFromPolicyChangedTo: method, this is equivalent to
 * automatically calling this function with a policyState of ACPolicyStateUnsupported. In this case, a standard message
 * is supplied.
 *
 * @param policyState Indicates the new state. See the ACPolicyState enum for the possible acknowledgements.
 * @param message An optional message describing the acknowledgement. This is primarily useful for describing the error
 *  when the policyState is ACPolicyStateError.
 */
-(void)openFromPolicyApplied:(ACPolicyState)policyState message:(nullable NSString *)message;
/*!
 * When the AppConnectDelegate receives the -appConnect:pasteboardPolicyChangedTo: callback, it must call this
 * function some time later to acknowledge the new policy.
 *
 * If the AppConnectDelegate does not implement the -appConnect:pasteboardPolicyChangedTo: method, this is equivalent to
 * automatically calling this function with a policyState of ACPolicyStateUnsupported. In this case, a standard message
 * is supplied.
 *
 * @param policyState Indicates the new state. See the ACPolicyState enum for the possible acknowledgements.
 * @param message An optional message describing the acknowledgement. This is primarily useful for describing the error
 *  when the policyState is ACPolicyStateError.
 */
-(void)pasteboardPolicyApplied:(ACPolicyState)policyState message:(nullable NSString *)message;

/*!
 * When the AppConnectDelegate receives the -appConnect:printPolicyChangedTo: callback, it must call this function some
 * time later to acknowledge the new policy.
 *
 * If the AppConnectDelegate does not implement the -appConnect:printPolicyChangedTo: method, this is equivalent to
 * automatically calling this function with a policyState of ACPolicyStateUnsupported. In this case, a standard message
 * is supplied.
 *
 * @param policyState Indicates the new state. See the ACPolicyState enum for the possible acknowledgements.
 * @param message An optional message describing the acknowledgement. This is primarily useful for describing the error
 * when the policyState is ACPolicyStateError.
 */
-(void)printPolicyApplied:(ACPolicyState)policyState message:(nullable NSString *)message;

/*!
 *  When the AppConnectDelegate receives the -appConnect:secureFileIOPolicyChangedTo: callback, it must call this
 *  function some time later to acknowledge the new policy.
 *
 *  If the AppConnectDelegate does not implement the -appConnect:secureFileIOPolicyChangedTo: method, this is equivalent
 *  to automatically calling this function with a policyState of ACPolicyStateUnsupported. In this case,
 *  a standard message is supplied.
 *
 * @param policyState Indicates the new state. See the ACPolicyState enum for the possible acknowledgements.
 * @param message An optional message describing the acknowledgement. This is primarily useful for describing the error
 * when the policyState is ACPolicyStateError.
 */
-(void)secureFileIOPolicyApplied:(ACPolicyState)policyState message:(nullable NSString *)message;

/*!
 * Display a message using the MobileIron client.
 *
 * This is a convenience method. When authState changes to ACAuthStateUnauthorized, the application must exit any
 * sensitive portion of the application. This may make it difficult to display the authMessage to the user. While it is
 * a better user experience for the application to display the authMessage, it can opt to have the MobileIron client
 * display the message instead by using this method.
 *
 * @param message A message to be displayed. If message is nil, this method does nothing.
 */
-(void)displayMessage:(nullable NSString *)message DEPRECATED_MSG_ATTRIBUTE("Use -displayMessage:withCompletion: instead");

/*!
 * Display a message using the MobileIron client.
 *
 * This is a convenience method. When authState changes to ACAuthStateUnauthorized, the application must exit any
 * sensitive portion of the application. This may make it difficult to display the authMessage to the user. While it is
 * a better user experience for the application to display the authMessage, it can opt to have the MobileIron client
 * display the message instead by using this method.
 *
 * @param message A message to be displayed. If message is nil, this method does nothing.
 * @param completion Completion block called on display message completion with success flag.
 */
- (void)displayMessage:(nullable NSString *)message withCompletion:(void(^ _Nullable)(BOOL success))completion;

/*!
 * Provides a key that can be used for custom cryptography purposes within the app.
 *
 * @param identifier The argument is used to derive a key for a specific purpose.
 * The app must select a different identifier for different encryption purposes.
 * Reusing an identifier for a different encryption purpose weakens the key and makes it
 * more vulnerable to brute force attacks.
 * For instance, the app should use different identifiers to derive different keys for AES, SHA-1, and HMAC.
 * @param error If secure services are not currently available, the error is set to an NSError with domain ACErrorDomain
 * and code ACErrorNoError. If identifier is nil or has zero length, the error is set to an NSError with domain
 * ACErrorDomain and code ACErrorInvalidArg.
 * @return ACSenstiveData filled with a 32 byte long key, or nil in case of failure.
 */
- (nullable ACSensitiveData *)derivedAppKeyWithIdentifier:(NSString *)identifier error:(NSError **)error;

/*!
 * Provides a key that can be used for custom cryptography purposes between AppConnect apps on the same device. Passing
 * the same arguments to this function in another app on the same device will derive the same shared key.
 *
 * @param identifier The argument is used to derive a key for a specific purpose.
 * The app must select a different identifier for different encryption purposes.
 * Reusing an identifier for a different encryption purpose weakens the key and makes it
 * more vulnerable to brute force attacks. For instance, the app should use different identifiers to
 * derive different keys for AES, SHA-1, and HMAC.
 * @param error If secure services are not currently available, the error is set to an NSError with domain ACErrorDomain
 * and code ACErrorNoError. If identifier is nil or has zero length, the error is set to an NSError with domain
 * ACErrorDomain and code ACErrorInvalidArg.
 * @return ACSenstiveData filled with a 32 byte long key, or nil in case of failure.
 */
- (nullable ACSensitiveData *)derivedSharedKeyWithIdentifier:(NSString *)identifier error:(NSError **)error;

/*!
 * @param pKey Must point to a writeable buffer of at least 32 bytes.
 * @param index An identifier for derived key.
 * @return If successful, returns nil and *pKey is filled with a 32 byte long key.
 * @deprecated Use @link derivedAppKeyWithIdentifier:error: @/link instead
 */
- (nullable NSError *)derivedAppKey:(uint8_t *)pKey withIndex:(NSString *)index DEPRECATED_MSG_ATTRIBUTE("Use -derivedAppKeyWithIdentifier:error: instead");

/*!
 * @param pKey Must point to a writeable buffer of at least 32 bytes.
 * @param index An identifier for derived key.
 * @return If successful, returns nil and *pKey is filled with a 32 byte long key.
 * @deprecated Use @link derivedSharedKeyWithIdentifier:error: @/link instead
 */
- (nullable NSError *)derivedSharedKey:(uint8_t *)pKey withIndex:(NSString *)index DEPRECATED_MSG_ATTRIBUTE("Use -derivedSharedKeyWithIdentifier:error: instead");

/*!
 * Generates log messages which are sent to the Apple System Log facility (console).
 *
 * If the current log level is at or above logLevel, this prepends the log level to the given message and then passes
 * the message to NSLog().
 *
 * This function is safe to call when AppConnect is stopped. If AppConnect is stopped, this behaves as if the current
 * log level is ACLogLevelError.
 *
 * @param logLevel A severity of the condition that caused the logging.
 * @param message A string to be logged
 */
+(void)logAtLevel:(ACLogLevel)logLevel message:(NSString *)message;

/*!
 * Generates log messages which are sent to the Apple System Log facility (console).
 *
 * If the current log level is at or above logLevel, this prepends the log level to the format and then passes the
 * format and variable argument list to NSLogv().
 *
 * This function is safe to call when AppConnect is stopped. If AppConnect is stopped, this behaves as if the current
 * log level is ACLogLevelError.
 *
 * @param logLevel A severity of the condition that caused the logging.
 * @param format A format string. This value must not be nil.
 * @param ... A comma-separated list of arguments to substitute into format.
 */
+(void)logAtLevel:(ACLogLevel)logLevel format:(NSString *)format, ... NS_FORMAT_FUNCTION(2,3);

/*!
 * Generates log messages which are sent to the Apple System Log facility (console).
 *
 * This is identical to +logAtLevel:format:... except with an explicit va_list
 *
 * @param logLevel A severity of the condition that caused the logging.
 * @param format A format string. This value must not be nil.
 * @param args A list of arguments to substitute into format.
 */
+(void)logAtLevel:(ACLogLevel)logLevel format:(NSString *)format args:(va_list)args NS_FORMAT_FUNCTION(2,0);

/*!
 *  Controls local caching for tunneled URL requests.
 *
 *  The default behavior in AppConnect tunneling is to disable caching for tunneled requests. This is to ensure
 *  that unauthorized apps will not have access to secure backend data. Caching should be left disabled
 *  unless the app has specific requirements to use a custom local cache that supplies data for and caches
 *  data from tunneled requests.
 *
 *  Disabling caching would clear the entire cache, including non-tunneled requests.
 *
 * @param flag Pass YES to enable caching and pass NO to disable it.
 */
-(void)allowLocalCachingForTunneledRequests:(BOOL)flag;

/*!
 *  Enable extension support for AppConnect.
 */
-(void)enableAppExtensionSupport;
@end

/*!
 * @protocol AppConnectDelegate
 * @abstract Delegate of AppConnect class
 */
@protocol AppConnectDelegate <NSObject>

@required

/*!
 *  Notification that the value of the 'ready' property has changed.
 *
 *  This notification is sent after the properties on the AppConnect singleton have
 *      been initialized and are ready for access.
 *
 *  This notification will be sent once after the app is launched.
 *  @param appConnect Instance of AppConnect sending the notification.
 */
- (void)appConnectIsReady:(AppConnect *)appConnect;

/*!
 *  Notification that the app's auth state and/or message has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newAuthState New ACAuthState value.
 *      If the state changes to ACAuthStateUnauthorized, the app must exit any sensitive portion of the application.
 *      If the state changes to ACAuthStateRetired, the app must exit any sensitive portion of the application
 *          and delete all sensitive data.
 *  @param message Textual explanation of authState changes.
 *  @note It is possible for newAuthState to be the same as the previous authState, but the message explaining the
 *      authState has changed.
 *  @note If policy wasn't applied or is unsupported then method -authStateApplied:message: with appropriate
 *      ACPolicyState and descriptive message must be called.
 *  @see ACAuthState
 */
- (void)appConnect:(AppConnect *)appConnect authStateChangedTo:(ACAuthState)newAuthState withMessage:(nullable NSString *)message;

@optional

/*!
 *  Notification that the app's managed policy has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newManagedPolicy New managed policy value. See ACManagedPolicy for more details.
 */
- (void)appConnect:(AppConnect *)appConnect managedPolicyChangedTo:(ACManagedPolicy)newManagedPolicy;

/*!
 *  Notification that the app's configuration has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newConfig New configuration represented as NSDictionary.
 *  @note If policy wasn't applied or is unsupported then method -configApplied:message: with appropriate
 *      ACPolicyState and descriptive message must be called.
 */
- (void)appConnect:(AppConnect *)appConnect configChangedTo:(NSDictionary *)newConfig;

/*!
 *  Notification that the app's Open In policy has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newOpenInPolicy New value for Open-In policy. See ACOpenInPolicy for more details.
 *  @param newWhitelist NSSet with the bundle IDs of applications that can receive documents
 *      if newOpenInPolicy is ACOpenInPolicyWhitelist.
 *  @note If policy wasn't applied or is unsupported then method -openInPolicyApplied:message: with appropriate
 *      ACPolicyState and descriptive message must be called.
 *  @see ACOpenInPolicy
 *  @see openInWhitelist
 */
- (void)appConnect:(AppConnect *)appConnect openInPolicyChangedTo:(ACOpenInPolicy)newOpenInPolicy whitelist:(NSSet<NSString *> *)newWhitelist;

/*!
 *  Notification that the app's Open From policy has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newOpenFromPolicy New value for Open-From policy. See ACOpenFromPolicy for more details.
 *  @param newWhitelist NSSet with the bundle IDs of applications that can receive documents
 *      if newOpenFromPolicy is ACOpenFromPolicyWhitelist.
 *  @note If policy wasn't applied or is unsupported then method -openFromPolicyApplied:message: with appropriate
 *      ACPolicyState and descriptive message must be called.
 *  @see ACOpenFromPolicy
 *  @see openInWhitelist
 */
- (void)appConnect:(AppConnect *)appConnect openFromPolicyChangedTo:(ACOpenFromPolicy)newOpenFromPolicy whitelist:(NSSet<NSString *> *)newWhitelist;

/*!
 *  Notification that the app's pasteboard policy has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newPasteboardPolicy New pasteboard policy value. See ACPasteboardPolicy for more details.
 *  @note If policy wasn't applied or is unsupported then method -pasteboardPolicyApplied:message: with appropriate
 *      ACPolicyState and descriptive message must be called.
 *  @see ACPasteboardPolicy
 */
- (void)appConnect:(AppConnect *)appConnect pasteboardPolicyChangedTo:(ACPasteboardPolicy)newPasteboardPolicy;

/*!
 *  Notification that the app's print policy has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newPrintPolicy New print policy value. See ACPrintPolicy for more details.
 *  @note If policy wasn't applied or is unsupported then method -printPolicyApplied:message: with appropriate
 *      ACPolicyState and descriptive message must be called.
 *  @see ACPrintPolicy
 */
- (void)appConnect:(AppConnect *)appConnect printPolicyChangedTo:(ACPrintPolicy)newPrintPolicy;

/*!
 *  Notification that the app's secure file policy has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newSecureFileIOPolicy New print policy value. See ACSecureFileIOPolicy for more details.
 *  @note If policy wasn't applied or is unsupported then method -secureFileIOPolicyApplied:message: with appropriate
 *      ACPolicyState and descriptive message must be called.
 *  @see ACSecureFileIOPolicy
 */
- (void)appConnect:(AppConnect *)appConnect secureFileIOPolicyChangedTo:(ACSecureFileIOPolicy)newSecureFileIOPolicy;

/*!
 *  Notification that the log level has changed.
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param newLogLevel New log level value. See ACLogLevel for more details.
 *  @see ACLogLevel
 */
- (void)appConnect:(AppConnect *)appConnect logLevelChangedTo:(ACLogLevel)newLogLevel;

/*!
 *  Notification that the availability of secure services has changed. Currently the only secure services are
 *      secure file IO and derived keys.
 *
 *  If secureServicesAvailability is ACSecureServicesAvailabilityAvailable, secure features are currently available.
 *      AppConnect secure file storage is able to open, read, and write secure files. -derivedAppKey:length:withIndex:
 *      and -derivedSharedKey:length:withIndex: are available.
 *
 *  If secureServicesAvailability is ACSecureServicesAvailabilityUnavailable, secure data is currently unavailable.
 *      AppConnect secure file storage is unable to open, read or write secure files. -derivedAppKey:length:withIndex:
 *      and -derivedSharedKey:length:withIndex: are unavailable and will return an error.
 *
 *  The secure services availability also impacts reading/writing data from/to the general pasteboard when the
 *      pasteboard policy is ACPasteboardPolicySecureCopy. When the secure services are available,
 *      the app will be able write data to the pasteboard securely so that only authorized AppConnect apps can read
 *      that data. Also an app can read secure pasteboard data written by another app only when the secure services are
 *      available. When secure services are not available, writing to the general pasteboard will fail and reading from
 *      it will read unsecured content, if any.
 *
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param secureServicesAvailability ACSecureServicesAvailability enum value that indicates whether secure services
 *      are available.
 */
- (void)appConnect:(AppConnect *)appConnect secureServicesAvailabilityChangedTo:(ACSecureServicesAvailability)secureServicesAvailability;

/*!
 *  Notification that the end user attempted to copy data to the pasteboard when copying to the pasteboard is
 *      unauthorized.
 *
 *  The notification is sent only when the status is ACPasteboardPolicyUnauthorized and the end user taps the "Copy"
 *      button. iOS behavior still causes the copy button to display. However, because the status is unauthorized,
 *      tapping "Copy" has no effect. This behavior can confuse the end user, who sometimes thinks that the selection
 *      was copied. Therefore, this notification tells the app that the end user attempted to copy data. The app is
 *      responsible for taking some action, such as displaying an alert to the end user that copy is not allowed.
 *
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param pasteboardPolicy Current pasteboardPolicy value. See ACPasteboardPolicy for more details.
 */
- (void)appConnect:(AppConnect *)appConnect copyAttemptedWhenUnauthorized:(ACPasteboardPolicy)pasteboardPolicy;

/*!
 *  Notification that the end user attempted to open URL with an external application when the URL scheme was
 *      not allowed.
 *
 *  The notification is sent when openInPolicy is ACOpenInPolicyUnauthorized or ACOpenInPolicyWhitelist and
 *      the whitelist does not contain the bundle ID of the app that will process the URL. The app is responsible for
 *      taking some action, such as displaying an alert to the end user that opening the native mail app from this app
 *      is not allowed.
 *
 *  @param appConnect Instance of AppConnect sending the notification.
 *  @param openURL URL that failed to be opened.
 */
- (void)appConnect:(AppConnect *)appConnect openURLAttemptedWhenUnauthorizedForURL:(NSURL *)openURL;

/*!
 * Notification that the end user attempted to share content with another application, when open-in is unauthorized
 * or only allowed between whitelisted apps.
 *
 * This notification is sent only when the status is ACOpenInPolicyUnauthorized or ACOpenInPolicyWhitelist.
 * The notification tells the app that the end user attempted to share content with another app
 * and the operation was blocked. The app is responsible for taking some action, such as displaying an alert to
 * the end user that Open-in is not allowed.
 *
 * @param appConnect Instance of AppConnect sending the notification.
 * @param openInPolicy Current openInPolicy value. See ACOpenInPolicy for more details.
 */
- (void)appConnect:(AppConnect *)appConnect openInAttemptedWhenACOpenInPolicyBlocked:(ACOpenInPolicy)openInPolicy;

/*!
 * Notification that the end user attempted to import content from another application, when open-from is unauthorized
 * or only allowed between whitelisted apps.
 *
 * This notification is sent only when the status is ACOpenFromPolicyUnauthorized or ACOpenFromPolicyWhitelist.
 * The notification tells the app that the end user attempted to import content with another app
 * and the operation was blocked. The app is responsible for taking some action, such as displaying an alert to
 * the end user that Open-From is not allowed.
 *
 * @param appConnect Instance of AppConnect sending the notification.
 * @param openFromPolicy Current openFromPolicy value. See ACOpenFromPolicy for more details.
 * @param sourceApplicationId bundle id of the source app that sent the file.
 */
- (void)appConnect:(AppConnect *)appConnect openFromAttemptedWhenACOpenFromPolicyBlocked:(ACOpenFromPolicy)openFromPolicy sourceApplication:(nullable NSString *)sourceApplicationId;

/*!
 * Notification that the end user attempted to share content using drag and drop to non-AppConnect apps when the policy
 * restricts sharing only to AppConnect apps.
 *
 * @param appConnect Instance of AppConnect sending the notification.
 */
- (void)appConnectAttemptedDragAndDropToNonAppConnectApp:(AppConnect *)appConnect NS_SWIFT_NAME(appConnectAttemptedDragAndDropToNonAppConnectApp(_:));

/*!
 *  Notification that the application is resigning active due to AppConnect event such as a flip to MobileIron client.
 *  @param appConnect Instance of AppConnect sending the notification.
 */
- (void)applicationWillResignActiveForAppConnect:(AppConnect *)appConnect NS_SWIFT_NAME(applicationWillResignActiveForAppConnect(_:));

/*!
 *  Notification that the application is becoming active again due to AppConnect event such as a flip from
 *      MobileIron client.
 *
 *  This notification only occurs after an AppConnect event such as a flip to the MobileIron client
 *      caused the app to resign active. Not every such event is followed by this notification. For instance, this
 *      notification does not occur if the user presses the home button to cancel the operation, and then returns to
 *      the app.
 *  @param appConnect Instance of AppConnect sending the notification.
 */
- (void)applicationDidBecomeActiveFromAppConnect:(AppConnect *)appConnect NS_SWIFT_NAME(applicationDidBecomeActiveFromAppConnect(_:));

@end

NS_ASSUME_NONNULL_END

