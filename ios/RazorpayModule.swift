//
//  RazorpayModule.swift
//  AwesomeProject
//
//  Created by Shashank Shekhar on 13/02/24.
//

import Foundation
import AVFoundation

@objc(RazorpayModule)
class RazorpayModule: NSObject {
  
  @objc
  func open() -> Void {
    print("Called iOS Bridged Module")
  }
  
  @objc
  static func requiresMainQueueSetup() -> Bool {
    return true
  }
}
