package com.awesomeproject;

import androidx.appcompat.app.AppCompatActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

import com.razorpay.Checkout;

import org.json.JSONException;
import org.json.JSONObject;

public class PaymentActivity extends Activity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        requestWindowFeature(Window.FEATURE_NO_TITLE);
//        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
//                WindowManager.LayoutParams.FLAG_FULLSCREEN);
//        getWindow().setBackgroundDrawableResource(android.R.color.transparent);

        String jsonString = getIntent().getStringExtra("options");
        JSONObject optionsJson;
        try {
            optionsJson = new JSONObject(jsonString);
        } catch (JSONException e) {
            throw new RuntimeException(e); // Handle exception appropriately
        }

        Checkout checkout = new Checkout().upiTurbo(this);
        if (optionsJson.has("key")) {
            try {
                checkout.setKeyID(optionsJson.getString("key"));
            } catch (JSONException e) {
                throw new RuntimeException(e);
            }
            optionsJson.remove("key");
        }

        checkout.open(this, optionsJson);
//        finish();
    }
}