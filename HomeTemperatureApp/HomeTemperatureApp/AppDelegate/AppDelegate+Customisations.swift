//
//  AppDelegate+Customisations.swift
//  HomeTemperatureApp
//
//  Created by Gabriel Ivan on 15.12.2023.
//

import UIKit
import RowebUtilities

extension AppDelegate {
    
    override func setupColorsAndImageForLoader() {
        
    }
    
    override func setupEnviroment(_rowebAppServiceFactory: RowebAppServiceFactory?) {
        self.rowebAppServiceFactory = _rowebAppServiceFactory
    }
    
    override func setupLiveAndStagingURLs(_live: String?, _staging: String?) {
        self.baseLiveURL = _live
        self.baseStagingURL = _staging
    }
    
    override func defineKeysForToken(_accessKeyToken: String?, _refreshKeyToken: String?, _firebaseKeyToken: String?) {
        self.accessTokenKey = _accessKeyToken
        self.refreshTokenKey = _refreshKeyToken
        self.firebaseTokenKey = _firebaseKeyToken
    }
    
    override func defineKeysForMultilanguage(_noInternetConnectionKey: String?, _languageCodeKey: String?, _alertTitleKey: String?, _defaultActionKey: String?) {
        self.noInternetConnectionKey = _noInternetConnectionKey
        self.languageCodeKey = _languageCodeKey
        self.alertTitleKey = _alertTitleKey
        self.defaultActionKey = _defaultActionKey
    }
    
    override func defineKeysForIsLoggedIn(_isLoggedInKey: String?) {
        self.isLoggedInKey = _isLoggedInKey
    }
    
    override func defineKeysForSocialMediaErrors(_loginGoogleFirebaseErrorKey: String?, _loginAppleFirebaseErrorKey: String?) {
        self.loginAppleFireabseErrorKey = _loginAppleFirebaseErrorKey
        self.loginGoogleFirebaseErrorKey = _loginGoogleFirebaseErrorKey
    }
}
