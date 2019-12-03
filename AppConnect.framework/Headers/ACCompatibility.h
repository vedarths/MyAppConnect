/*!
 * @header ACCompatibility.h
 *
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#ifndef ACCompatibility_h
#define ACCompatibility_h

#define ACLOGLEVEL_ERROR ACLogLevelError
#define ACLOGLEVEL_WARNING ACLogLevelWarning
#define ACLOGLEVEL_STATUS ACLogLevelStatus
#define ACLOGLEVEL_INFO ACLogLevelInfo
#define ACLOGLEVEL_VERBOSE ACLogLevelVerbose
#define ACLOGLEVEL_DEBUG ACLogLevelDebug

#define ACPOLICY_UNSUPPORTED  ACPolicyStateUnsupported
#define ACPOLICY_APPLIED ACPolicyStateApplied
#define ACPOLICY_ERROR ACPolicyStateError

#define ACMANAGEDPOLICY_UNKNOWN ACManagedPolicyUnknown
#define ACMANAGEDPOLICY_UNMANAGED ACManagedPolicyUnmanaged
#define ACMANAGEDPOLICY_MANAGED ACManagedPolicyManaged

#define ACAUTHSTATE_UNAUTHORIZED ACAuthStateUnauthorized
#define ACAUTHSTATE_AUTHORIZED ACAuthStateAuthorized
#define ACAUTHSTATE_RETIRED ACAuthStateRetired

#define ACPASTEBOARDPOLICY_UNAUTHORIZED ACPasteboardPolicyUnauthorized
#define ACPASTEBOARDPOLICY_AUTHORIZED ACPasteboardPolicyAuthorized
#define ACPASTEBOARDPOLICY_SECURECOPY ACPasteboardPolicySecureCopy

#define ACOPENINPOLICY_UNAUTHORIZED ACOpenInPolicyUnauthorized
#define ACOPENINPOLICY_AUTHORIZED ACOpenInPolicyAuthorized
#define ACOPENINPOLICY_WHITELIST ACOpenInPolicyWhitelist

#define ACOPENFROMPOLICY_UNAUTHORIZED ACOpenFromPolicyUnauthorized
#define ACOPENFROMPOLICY_AUTHORIZED ACOpenFromPolicyAuthorized
#define ACOPENFROMPOLICY_WHITELIST ACOpenFromPolicyWhitelist

#define ACPRINTPOLICY_UNAUTHORIZED ACPrintPolicyUnauthorized
#define ACPRINTPOLICY_AUTHORIZED ACPrintPolicyAuthorized

#define ACSECUREFILEIOPOLICY_OPTIONAL ACSecureFileIOPolicyOptional
#define ACSECUREFILEIOPOLICY_REQUIRED ACSecureFileIOPolicyRequired

#define ACSECURESERVICESAVAILABILITY_UNAVAILABLE ACSecureServicesAvailabilityUnavailable
#define ACSECURESERVICESAVAILABILITY_AVAILABLE ACSecureServicesAvailabilityAvailable

#define ACTDR_RUN_STARTED ACTunnelingDiagnosticResultCodeStarted
#define ACTDR_REDIRECT ACTunnelingDiagnosticResultCodeRedirect
#define ACTDR_COMPLETED ACTunnelingDiagnosticResultCodeCompleted
#define ACTDR_ABORT_UNSUPPORTED_AUTH ACTunnelingDiagnosticResultCodeAborted
#define ACTDR_RULE_MATCH ACTunnelingDiagnosticResultCodeRuleMatch
#define ACTDR_POLICY_SERVER_CERT ACTunnelingDiagnosticResultCodePolicyServerCert
#define ACTDR_POLICY_CLIENT_IDENTITY ACTunnelingDiagnosticResultCodePolicyClientId
#define ACTDR_SEND_CLIENT_CERT ACTunnelingDiagnosticResultCodeSendClientCert
#define ACTDR_EVALUATE_SENTRY_CERT ACTunnelingDiagnosticResultCodeEvaluateSentryCert
#define ACTDR_DNSLOOKUP_SENTRY ACTunnelingDiagnosticResultCodeDNSLookupSentry
#define ACTDR_RESPONSE ACTunnelingDiagnosticResultCodeResponse
#define ACTDR_RECEIVED_DATA ACTunnelingDiagnosticResultCodeReceivedData

#define ACE_NO_ERROR ACErrorNoError
#define ACE_NO_KEYS_ERROR ACErrorNoKeys
#define ACE_FILE_TOO_BIG_ERROR ACErrorFileTooBig
#define ACE_NEGATIVE_FILE_LEN_ERROR ACErrorNegativeFileLen
#define ACE_LOW_MEMORY_ERROR ACErrorLowMemory
#define ACE_BAD_KEY_OR_CORRUPT_DATA_ERROR ACErrorBadKeyOrCorruptData
#define ACE_INVALID_ARG ACErrorInvalidArg
#define ACE_REGULAR_FILE_ONLY_ERROR ACErrorRegularFileOnly
#define ACE_INTERNAL_ERROR ACErrorInternal

#define kACDerivedCredentialPayloadTagKey ACDerivedCredentialPayloadKeyTag
#define kACDerivedCredentialPayloadCertKey ACDerivedCredentialPayloadKeyCert
#define kACDerivedCredentialPayloadPrivateKeyKey ACDerivedCredentialPayloadKeyPrivateKey

#define kACDerivedCredentialAuthenticationTag ACDerivedCredentialTagAuthentication
#define kACDerivedCredentialSigningTag ACDerivedCredentialTagSigning
#define kACDerivedCredentialEncryptionTag ACDerivedCredentialTagEncryption

#define kACUIApplicationClassName ACUIApplicationClassName

#endif /* ACCompatibility_h */