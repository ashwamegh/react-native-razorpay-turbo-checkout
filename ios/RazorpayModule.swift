//
//  RazorpayModule.swift
//  AwesomeProject
//
//  Created by Shashank Shekhar on 13/02/24.
//

import Foundation
import AVFoundation
import UIKit
import Razorpay
import WebKit
import TurboUpiPluginMock

@objc(RazorpayModule)
class RazorpayModule: NSObject, RazorpayPaymentCompletionProtocolWithData {
  func onPaymentError(_ code: Int32, description str: String, andData response: [AnyHashable : Any]?) {    
    do {
      let jsonData = try JSONSerialization.data(withJSONObject: response as Any, options: .prettyPrinted)
        let decoded = try JSONSerialization.jsonObject(with: jsonData, options: [])
        print(decoded)
    } catch (let e) {
        print(e)
    }
//    let alertController = UIAlertController(title: "FAILURE", message: str, preferredStyle: UIAlertController.Style.alert)
//    let cancelAction = UIAlertAction(title: "OK", style: UIAlertAction.Style.cancel, handler: nil)
//    alertController.addAction(cancelAction)
//    self.present(alertController, animated: true, completion: nil)
    
    
  }
  
  func onPaymentSuccess(_ payment_id: String, andData response: [AnyHashable : Any]?) {
    let alertController = UIAlertController(title: "SUCCESS", message: "Payment Id \(payment_id)", preferredStyle: UIAlertController.Style.alert)
    let cancelAction = UIAlertAction(title: "OK", style: UIAlertAction.Style.cancel, handler: nil)
    alertController.addAction(cancelAction)
//    self.present(alertController, animated: true, completion: nil)
    print(#function,payment_id, response as Any)
    
    
  }
  
  
  var razorpay: RazorpayCheckout?
  var webView: WKWebView?
  var phoneNumber: String!
  var merchantKey: String!
  
  @IBOutlet var statusLabel: UILabel!
  @IBOutlet var upiLable: UILabel!

     
 @IBAction func linkNewAccounts(_ sender: Any) {
     self.razorpay?.upiTurbo?.linkNewUpiAccount(mobileNumber: self.phoneNumber, color: "#0000FF", completionHandler: { upiAccounts, error in
         print(upiAccounts ?? "")
     })
 }
  
  @IBAction func mangeUpiAccountAction(_ sender: Any) {
      self.razorpay?.upiTurbo?.manageUpiAccount(mobileNumber: self.phoneNumber, color: "#0000FF")
  }
  
 @IBAction func makePayment() {
     let checkoutPayload: [AnyHashable: Any] = [
      "key": "rzp_test_vacN5cmVqNIlhO",
      "prefill": [
          "contact": "+918587099540",
          "email": "shashank@numadic.com"
      ],
      "image": "https://spaceplace.nasa.gov/templates/featured/sun/sunburn300.png",
      "amount": 100,
      "currency": "INR",
      "disable_redesign_v15": false,
      "experiments.upi_turbo": true,
     "ep":"https://api-web-turbo-upi.ext.dev.razorpay.in/test/checkout.html",
     "theme":  [
         "color": "#F3FF54"
     ],
     "environment_url": "https://api-web-turbo-upi.ext.dev.razorpay.in/test/checkout.html?platform=ios"
     ]
   self.razorpay?.open(checkoutPayload, arrExternalPaymentEntities: [RazorpayTurboUPI.turboUIPaymentPlugin()])
 }
  
  @objc
  func open() -> Void {
//    self.statusLabel.text = "Status : None"
//    self.razorpay = RazorpayCheckout.initWithKey("rzp_test_0wFRWIZnH65uny", andDelegateWithData: self)
    
    self.razorpay = RazorpayCheckout.initWithKey("rzp_test_vacN5cmVqNIlhO", andDelegateWithData: self, plugin: RazorpayTurboUPI.UIPluginInstance())
    self.makePayment()
    print("Called iOS Bridged Module")
  }
  
  @objc
  static func requiresMainQueueSetup() -> Bool {
    return true
  }
}
