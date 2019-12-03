/*!
 * @header AppConnect+Networking.h
 *
 * @abstract AppConnect networking functions
 *
 * @copyright Copyright (c) 2015-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <AppConnect/AppConnectInterface.h>

NS_ASSUME_NONNULL_BEGIN

/*! Constants for reporting TLS validation errors as NSError. */
/*! Error Domain */
extern NSString * const kACTLSValidationErrorDomain;
/*! Status code */
extern NSInteger const kACTLSValidationFailedStatusCode;
/*! Key to access Failure reason in NSError's userInfo dictionary. */
extern NSString * const kACTLSValidationFailureReason;

/*!
 * @protocol AppConnectNetworkingDelegate
 *
 * AppConnectNetworkingDelegate protocol defines a protocol for an optional delegate that allows the AppConnect SDK to
 * notify the app of networking events when using the AppTunnel feature.
 *
 * If your app implements the NSURLConnectionDataDelegate method
 * connection:didSendBodyData:totalBytesWritten:totalBytesExpectedToWrite: implement this delegate.
 *
 * Use the setNetworkingDelegate: method to set the delegate that will receive these notifications.
 */
@protocol AppConnectNetworkingDelegate <NSObject>

/*!
 * Notification of progress as the body of a request is sent when a connection is tunneled using the AppTunnel feature.
 *
 * When a connection is tunneled, iOS will not call the NSURLConnectionDataDelegate method
 * connection:didSendBodyData:totalBytesWritten:totalBytesExpectedToWrite: to notify the app of upload progress.
 * Instead, AppConnect will call this method on the networking delegate. If your app implements the
 * connection:didSendBodyData:totalBytesWritten:totalBytesExpectedToWrite: method, implement this method
 * for upload updates.
 *
 * @param request NSURLRequest object that caused the upload.
 * @param bytesWritten The number of bytes written in the latest write.
 * @param totalBytesWritten The total number of bytes written for the request.
 * @param totalBytesExpectedToWrite The number of bytes URL loading system expects to write for the request.
 */
-(void) uploadProgressForConnectionWithURLRequest:(NSURLRequest *)request
                                     bytesWritten:(NSInteger)bytesWritten
                                totalBytesWritten:(NSInteger)totalBytesWritten
                        totalBytesExpectedToWrite:(NSInteger)totalBytesExpectedToWrite;
@end


/*!
 *  @typedef ACTunnelingDiagnosticResultCode
 *  @brief Codes describing different tunneling diagnostic result types.
 */
typedef NS_ENUM(NSUInteger, ACTunnelingDiagnosticResultCode) {
    // Run life cycle
    /*! The run started properly. Always succeeds. */
    ACTunnelingDiagnosticResultCodeStarted              = 0,
    /*! The server redirected to a new URL. Always succeeds. */
    ACTunnelingDiagnosticResultCodeRedirect             = 1,
    /*! Fails if the session completed with an error, succeeds otherwise. */
    ACTunnelingDiagnosticResultCodeCompleted            = 2,
    /*! 
     * The diagnostic is aborted because the server issued an auth challenge that the diagnostic does not support. 
     * Always succeeds. 
     */
    ACTunnelingDiagnosticResultCodeAborted              = 3,

    // Policy integrity
    /*! Succeeds if an initial or redirected request matched a tunneling rule, fails otherwise. */
    ACTunnelingDiagnosticResultCodeRuleMatch            = 100,
    /*! Succeeds if the policy contains a valid server certificate, fails otherwise. */
    ACTunnelingDiagnosticResultCodePolicyServerCert     = 101,
    /*! Succeeds if the policy contains a valid client identity, fails otherwise. */
    ACTunnelingDiagnosticResultCodePolicyClientId       = 102,

    // Certificate challenges
    /*! Succeeds if the client-side authenticated with the identity, fails otherwise. */
    ACTunnelingDiagnosticResultCodeSendClientCert       = 200,
    /*! Succeeds if the sentry's server-side certificate matches the pinned Sentry cert, fails otherwise. */
    ACTunnelingDiagnosticResultCodeEvaluateSentryCert   = 201,

    // Networking
    /*! Succeeds if DNS lookup for the Sentry host succeeded, fails otherwise */
    ACTunnelingDiagnosticResultCodeDNSLookupSentry      = 300,

    // Connection result
    /*!
     *  Received a response. Succeeds if the server returned HTTP status code 1xx, 2xx or 3xx.
     *  Fails if the AppTunnel is blocked, or the server returned HTTP status code 4xx or 5xx.
     */
    ACTunnelingDiagnosticResultCodeResponse             = 400,
    /*! Received data. Always succeeds. */
    ACTunnelingDiagnosticResultCodeReceivedData         = 401,
};

/*!
 * @class ACTunnelingDiagnosticResult
 * A result of a tunneling diagnostic test performed by diagnoseTunnelingForURL:delegate:
 */
@interface ACTunnelingDiagnosticResult : NSObject

/*! 
 * Code identifying the type of result. See the ACTunnelingDiagnosticResultCode for descriptions of the individual codes 
 */
@property (nonatomic, readonly) ACTunnelingDiagnosticResultCode resultCode;

/*! Indicates whether the diagnostic result was successful or failed */
@property (nonatomic, readonly, getter=isSuccessful) BOOL successful;

/*! Timestamp for when the result occurred */
@property (nonatomic, readonly) NSDate *timestamp;

/*! Human-readable description of the result */
@property (nonatomic, readonly) NSString *resultDescription;

@end

/*! Additional methods on the AppConnect object for networking */
@interface AppConnect (Networking)

/*! 
 * Sets the optional networking delegate.
 * @param delegate An object that will receive the notifications described in the AppConnectNetworkingDelegate protocol.
 */
-(void)setNetworkingDelegate:(nullable id<AppConnectNetworkingDelegate>)delegate;

/*!
 * Starts a diagnostic run for a tunneled request.
 *
 * This makes a request for url, gathers diagnostic information until the request completes, compiles the results in
 * a human-readable form, calls resultHandler for each result as it occurs, and calls resultHandler with a nil result to
 * indicate that the run has completed. See ACTunnelingDiagnosticResultCode for a list of results that may be generated.
 * Only applicable result codes are generated for a diagnostic run.
 *
 * If the request is successful, the destination server will receive the request, but the app will not receive the
 * response. testURL should be a URL that has no unintended side-effects, such as modifying user data.
 *
 * @param url A URL that will be loaded during the diagnostic.
 * @param resultHandler A block that will be called to handle diagnostic results.
 * @returns A unique runID that matches the second parameter to the resultHandler. Multiple simultaneous diagnostic runs
 *  are supported, and the runID distinguishes which result corresponds to a diagnostic run.
 */
-(NSInteger)diagnoseTunnelingForURL:(NSURL *)url
                      resultHandler:(void (^)(ACTunnelingDiagnosticResult * _Nullable result, NSInteger runID))resultHandler;
@end

NS_ASSUME_NONNULL_END
