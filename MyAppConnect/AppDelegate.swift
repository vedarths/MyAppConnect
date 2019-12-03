//
//  AppDelegate.swift
//  MyAppConnect
//
//  Created by Vedarth Solutions on 12/3/19.
//  Copyright © 2019 Sky Plc. All rights reserved.
//

import UIKit
import AppConnect

class AppDelegate: UIResponder, UIApplicationDelegate,  AppConnectDelegate {
    func appConnectIsReady(_ appConnect: AppConnect) {
        print("app connect is ready")
    }
    
    func appConnect(_ appConnect: AppConnect, authStateChangedTo newAuthState: ACAuthState, withMessage message: String?) {
        print("appconnect auth state changed")
    }
    

    var appConnect: AppConnect?


    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        startAppConnect(launchOptions: launchOptions)
        return true
    }
    
    
    func stopAppConnect() {
        self.appConnect!.retire()
        self.appConnect!.stop()
        self.appConnect = nil
    }

    func startAppConnect(launchOptions: [AnyHashable : Any]? = [:]) {
        AppConnect.initWith(self)
        self.appConnect = AppConnect.sharedInstance()
        self.appConnect!.start(launchOptions: launchOptions)
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }


}

