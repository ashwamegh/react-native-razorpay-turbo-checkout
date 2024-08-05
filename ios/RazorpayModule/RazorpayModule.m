//
//  RazorpayModule.m
//  AwesomeProject
//
//  Created by Shashank Shekhar on 05/08/24.
//
#import <Razorpay/Razorpay-Swift.h>
#import "RazorpayModule.h"
#import "RazorpayEventEmitter.h"

#import <React/RCTLog.h>

typedef RazorpayCheckout Razorpay;

@interface RNRazorpayModule () <RazorpayPaymentCompletionProtocolWithData,
ExternalWalletSelectionProtocol>

@end

@implementation RNRazorpayModule

// Register the module with React Native
RCT_EXPORT_MODULE();

// Method that logs a message
RCT_EXPORT_METHOD(printLog:(NSString *)message)
{
  RCTLogInfo(@"%@", message);
}

RCT_EXPORT_METHOD(open : (NSDictionary *)options) {

    NSString *keyID = (NSString *)[options objectForKey:@"key"];
    dispatch_sync(dispatch_get_main_queue(), ^{
        Razorpay *razorpay = [Razorpay initWithKey:keyID
                               andDelegateWithData:self];
        [razorpay setExternalWalletSelectionDelegate:self];
        NSMutableDictionary * tempOptions = [[NSMutableDictionary alloc] initWithDictionary:options];
        //tempOptions[@"integration_version"] = [self findReactNativeVersion];
        tempOptions[@"integration"] = @"react_native";
        tempOptions[@"FRAMEWORK"] = @"react_native";

        //get root view to present razorpay vc
        id<UIApplicationDelegate> app = [[UIApplication sharedApplication] delegate];
        UINavigationController *rootViewController = ((UINavigationController*) app.window.rootViewController);

        if (rootViewController.presentedViewController) {
            [razorpay open:tempOptions displayController:rootViewController.presentedViewController];
            return;
        }

        //Use 'open' method with displayController parameter
        [razorpay open:tempOptions displayController:rootViewController];
    });
}

- (void)onPaymentSuccess:(nonnull NSString *)payment_id
                 andData:(nullable NSDictionary *)response {
    [RazorpayEventEmitter onPaymentSuccess:payment_id andData:response];
}

- (void)onPaymentError:(int)code
           description:(nonnull NSString *)str
               andData:(nullable NSDictionary *)response {
    [RazorpayEventEmitter onPaymentError:code description:str andData:response];
}

- (void)onExternalWalletSelected:(nonnull NSString *)walletName
                 WithPaymentData:(nullable NSDictionary *)paymentData {
    [RazorpayEventEmitter onExternalWalletSelected:walletName
                                           andData:paymentData];
}

@end
