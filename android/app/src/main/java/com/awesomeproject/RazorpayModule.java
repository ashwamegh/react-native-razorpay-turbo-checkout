package com.awesomeproject;

import android.app.Activity;
import android.content.Intent;
import android.telecom.Call;
import android.util.Log;

import androidx.annotation.NonNull;
import androidx.annotation.Nullable;

import com.facebook.react.bridge.ActivityEventListener;
import com.facebook.react.bridge.NativeModule;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.ReadableMap;
import com.facebook.react.modules.core.DeviceEventManagerModule;
import com.facebook.react.bridge.WritableMap;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.Promise;
import com.razorpay.Checkout;
import com.razorpay.CheckoutActivity;
import com.razorpay.PaymentData;
import com.razorpay.PaymentResultWithDataListener;
import com.razorpay.ExternalWalletListener;

import android.os.Handler;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;

public class RazorpayModule extends ReactContextBaseJavaModule implements ActivityEventListener, PaymentResultWithDataListener, ExternalWalletListener {
    public static final String MAP_KEY_ERROR_CODE = "code";
    public static final String MAP_KEY_ERROR_DESC = "description";
    ReactApplicationContext reactContext;

    public RazorpayModule(ReactApplicationContext context) {
        super(context);
        this.reactContext = context;
        reactContext.addActivityEventListener(this);
    }

    @NonNull
    @Override
    public String getName() {
        return "RazorpayModule";
    }

    @ReactMethod
    public void printOrderAndAmount(String order_id, Float amount, Promise promise) {
        Log.d("RazorpayModule","=============================================");
        Log.d("RazorpayModule","Order ID: " + order_id + " Amount: " + amount);
        Log.d("RazorpayModule","=============================================");
//        Timeout for 2 seconds
//        Handler handler = new Handler();
//        handler.postDelayed(new Runnable() {
//            @Override
//            public void run() {
//                // Code to execute after 2 seconds
//                // Add your logic here
//                promise.resolve("Order ID: " + order_id + " Amount: " + amount);
//            }
//        }, 5000);
    }

    @ReactMethod
    public void open() {
        Activity currentActivity = getCurrentActivity();

        /**
         * Pass your payment options to the Razorpay Checkout as a JSONObject
         */
        try {
            JSONObject options = new JSONObject();
            options.put("key", "rzp_test_vacN5cmVqNIlhO");
            options.put("currency", "INR");
            options.put("amount", "10000");//pass amount in currency subunits
            JSONObject prefillObj = new JSONObject();
            options.put("prefill.email", "shashank@numadic.com");
            options.put("prefill.contact","8587099540");
            options.put("theme.color", "#FF7B05");
            options.put("send_sms_hash", true);
            JSONObject retryObj = new JSONObject();
            retryObj.put("enabled", true);
            retryObj.put("max_count", 4);
            options.put("retry", retryObj);
            options.put("disable_redesign_v15", false);
            options.put("experiments.upi_turbo", true);
            options.put("ep", "https://api-web-turbo-upi.ext.dev.razorpay.in/test/checkout.html");

            Checkout checkout = new Checkout().upiTurbo(currentActivity);
            if (options.has("key")) {
                checkout.setKeyID(options.getString("key"));
                options.remove("key");
            }

            checkout.open(currentActivity, options);

        } catch(Exception e) {
            Log.e("RazorpayModule", "Error in starting Razorpay Checkout", e);
        }
    }

    private void sendEvent(String eventName, WritableMap params) {
        reactContext
                .getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class)
                .emit(eventName, params);
    }

    public void onActivityResult(Activity activity, int requestCode, int resultCode, Intent data) {
        onActivityResult(requestCode, resultCode, data);
    }

    public void onActivityResult(int requestCode, int resultCode, Intent data){
        Checkout.handleActivityResult(getCurrentActivity(), requestCode, resultCode, data, this, this);
    }


    @Override
    public void onNewIntent(Intent intent) {

    }

    @Override
    public void onPaymentSuccess(String razorpayPaymentId, PaymentData paymentData) {
        sendEvent("Razorpay::PAYMENT_SUCCESS", Utils.jsonToWritableMap(paymentData.getData()));
    }

    @Override
    public void onPaymentError(int code, String description, PaymentData paymentData) {
        WritableMap errorParams = Arguments.createMap();
        JSONObject paymentDataJson = paymentData.getData();
        try{
            paymentDataJson.put(MAP_KEY_ERROR_CODE, code);
            paymentDataJson.put(MAP_KEY_ERROR_DESC, description);
        } catch(Exception e){
        }
        sendEvent("Razorpay::PAYMENT_ERROR", Utils.jsonToWritableMap(paymentDataJson));
    }

    @Override
    public void onExternalWalletSelected(String s, PaymentData paymentData) {
        sendEvent("Razorpay::EXTERNAL_WALLET_SELECTED", Utils.jsonToWritableMap(paymentData.getData()));
    }
}
