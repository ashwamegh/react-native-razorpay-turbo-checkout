//
//  RazorpayEventEmitter.h
//  AwesomeProject
//
//  Created by Shashank Shekhar on 05/08/24.
//

#import <React/RCTEventEmitter.h>



@interface RazorpayEventEmitter : RCTEventEmitter

+ (void)onPaymentSuccess:(NSString *)payment_id
                 andData:(NSDictionary *)response;
+ (void)onPaymentError:(int)code
           description:(NSString *)str
               andData:(NSDictionary *)response;
+ (void)onExternalWalletSelected:(NSString *)walletName
                         andData:(NSDictionary *)paymentData;
@end
