/*!
 * @header AppConnectUIApplication.h
 *
 * @abstract UIApplication subclass used by AppConnect SDK.
 *
 * @copyright Copyright (c) 2015-2018 MobileIron. All rights reserved.
 * <p>YOUR USE AND DISTRIBUTION OF THIS SOFTWARE IS SUBJECT TO THE SOFTWARE DEVELOPMENT KIT (SDK) AGREEMENT BETWEEN
 * YOU AND MOBILE IRON, INC. (“MI”).  USE OR DISTRIBUTION NOT IN STRICT ACCORDANCE WITH THE AGREEMENT IS PROHIBITED.</p>
 */

#import <UIKit/UIKit.h>

/*!
 * @class AppConnectUIApplication
 *
 * UIApplication subclass used by AppConnect SDK. Client applications passing thier own subclass of UIApplication as
 * prinicpal class to UIApplicationMain() function should derive their subclass from AppConnectUIApplication instead
 * of UIApplication to be able to use AppConnect features.
 *
 * In case client applications do not subclass UIApplication, they should instead pass "AppConnectUIApplication" as
 * the principal class name to UIApplicationMain() function.
 */
@interface AppConnectUIApplication : UIApplication

/*!
 * @deprecated Use -[UIApplication delegate] instead
 */
@property(nonatomic, readonly) id<UIApplicationDelegate> originalDelegate DEPRECATED_ATTRIBUTE;

@end
