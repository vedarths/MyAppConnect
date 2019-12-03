/*!
 * @header AppConnect.h
 *
 * @abstract AppConnect framework umbrella header
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>

//! Project version number for AppConnect.
FOUNDATION_EXPORT double AppConnectVersionNumber;

//! Project version string for AppConnect.
FOUNDATION_EXPORT const unsigned char AppConnectVersionString[];

#import <AppConnect/AppConnectInterface.h>
#import <AppConnect/ACError.h>
#import <AppConnect/ACFileHandle.h>
#import <AppConnect/ACSecureFile.h>
#import <AppConnect/AppConnect+Networking.h>
#import <AppConnect/AppConnectUIApplication.h>
#import <AppConnect/ACDerivedCredential.h>
#import <AppConnect/ACDerivedCredentialService.h>
#import <AppConnect/NSArray+ACSecureFile.h>
#import <AppConnect/NSData+ACSecureFile.h>
#import <AppConnect/NSData+ACSharedSecureFile.h>
#import <AppConnect/NSDictionary+ACSecureFile.h>
#import <AppConnect/NSFileManager+ACSecureFile.h>
#import <AppConnect/NSKeyedArchiver+ACSecureFile.h>
#import <AppConnect/NSKeyedUnarchiver+ACSecureFile.h>
#import <AppConnect/NSMutableArray+ACSecureFile.h>
#import <AppConnect/NSMutableDictionary+ACSecureFile.h>
#import <AppConnect/ACCompatibility.h>
#import <AppConnect/ACTypes.h>
#import <AppConnect/ACFileHandle+ACSharedSecureFile.h>
#import <AppConnect/ACUnwrappedFile.h>
#import <AppConnect/ACWrappedAppKey.h>
#import <AppConnect/ACWrappedFileReadHandle.h>
