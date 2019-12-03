//
//  AppConnectHandler.h
//  MyAppConnect
//
//  Created by Vedarth Solutions on 12/3/19.
//  Copyright © 2019 Sky Plc. All rights reserved.
//

#ifndef AppConnectHandler_h
#define AppConnectHandler_h

#ifndef AppConnectHandler_h
#define AppConnectHandler_h

#import <AppConnect/AppConnect.h>

/** Defines methods and properties to be implemented by class responsible for AppConnect interaction */
@protocol AppConnectHandler <AppConnectDelegate>

@property (nonatomic, strong, nullable) AppConnect *appConnect;
/** Display message in the M@W client */
- (void) displayMessage;
/**
 *  @brief Start AppConnect instance on user's request
 *  @discussion The method is called automatically on launch of the application
 *  or on user's request after AppConnect was stopped
 *  @param launchOptions options that were passed in applicationDidFinishLaunching:withOptions: method or nil
 *  when called later in the application's lifecycle
 */
- (void) startAppConnectWithLaunchOptions:(nullable NSDictionary *)launchOptions;
/** Stop AppConnect instance on user's request */
- (void) stopAppConnect;

@end

#endif /* AppConnectHandler_h */


#endif /* AppConnectHandler_h */
