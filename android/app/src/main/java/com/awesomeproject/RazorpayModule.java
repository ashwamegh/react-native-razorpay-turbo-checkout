package com.awesomeproject;

import static android.app.Activity.RESULT_CANCELED;
import static android.app.Activity.RESULT_OK;

import static androidx.core.content.ContextCompat.startActivity;

import android.app.Activity;
import android.content.Intent;
import android.os.Bundle;
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
        return "RNRazorpayModule";
    }

    @ReactMethod
    public void open(ReadableMap options) {
        try {
            Log.d("RazorpayCheckout","=============================================");
            JSONObject payload = Utils.readableMapToJson(options);
            Activity currentActivity = getCurrentActivity();
            Log.d("RazorpayCheckout", "Options JSON: " + payload.toString());

            Intent intent = new Intent(currentActivity, PaymentActivity.class);
            intent.putExtra("options", payload.toString());
            if (currentActivity != null) {
                currentActivity.startActivityForResult(intent, Checkout.RZP_REQUEST_CODE);
            }

        } catch(Exception e) {
            Log.e("RazorpayCheckout", "Error in starting Razorpay Checkout", e);
        }
    }

    public interface CheckoutCallback {
        void onCheckoutCompleted(boolean success, String paymentId, String errorMessage);
    }

    private void sendEvent(String eventName, WritableMap params) {
        reactContext.getJSModule(DeviceEventManagerModule.RCTDeviceEventEmitter.class).emit(eventName, params);
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
