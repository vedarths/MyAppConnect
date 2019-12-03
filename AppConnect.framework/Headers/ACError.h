/*!
 * @header ACError.h
 *
 * @abstract Error codes used by AppConnect
 *
 * @copyright Copyright (c) 2013-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <Foundation/Foundation.h>
#import <AppConnect/ACCompatibility.h>

/*! */
extern NSString * const ACErrorDomain;

NS_ENUM(NSInteger) {
    /*! */
    ACErrorNoError = 0,
    /*! */
    ACErrorNoKeys,
    /*! */
    ACErrorFileTooBig,
    /*! */
    ACErrorNegativeFileLen,
    /*! */
    ACErrorLowMemory,
    /*! */
    ACErrorBadKeyOrCorruptData,
    /*! */
    ACErrorInvalidArg,
    /*! */
    ACErrorRegularFileOnly,
    /*! */
    ACErrorInternal = 444,
};
