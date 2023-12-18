//
//  AppDelegate.swift
//  HomeTemperatureApp
//
//  Created by Gabriel Ivan on 15.12.2023.
//

import UIKit
import RowebUtilities

@main
class AppDelegate: BaseAppDelegate {

    override func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        
        self.applicationLanguageCodes = ["ro", "en"]
        
        FirebaseConfig.initializeFirebaseProject()
        
        self.window = UIWindow.init(frame: UIScreen.main.bounds)
        self.navigationController = UINavigationController()
        
        self.setupColorsAndImageForLoader()
        self.setupLiveAndStagingURLs(_live: "",
                                     _staging: "")
        self.setupEnviroment(_rowebAppServiceFactory: RowebAppServiceFactory(environment: .production))
        
        AppConfig.initializeAppConfig(_window: self.window!,
                                      _navigationController: self.navigationController,
                                      _firstViewController: ViewController())
        
        return true
    }
}

