package siabl.retrofit;

import android.content.Intent;

import org.json.simple.JSONArray;
import org.json.simple.JSONObject;

import okhttp3.OkHttpClient;
import okhttp3.logging.HttpLoggingInterceptor;
import retrofit2.Call;
import retrofit2.Callback;
import retrofit2.Response;
import retrofit2.Retrofit;
import retrofit2.converter.gson.GsonConverterFactory;
import retrofit2.http.Body;
import retrofit2.http.Headers;
import retrofit2.http.POST;

//package com.example.kahye.common.models;

import com.google.gson.annotations.Expose;
import com.google.gson.annotations.SerializedName;

public class PostTest {
    public interface CommonService {
        @Headers("Content-Type: application/json")
        @POST("api/login/")
        Call<User> sendPost(@Body JSONObject userEmail);
    }

    class User {
        @Expose
        public String userEmail;
        @SerializedName("userName")
        @Expose
        public String userName;
        public String accountType;
        public boolean isLecturer;
    }

    public static void main(String[] args) {
        System.out.println("program start\n================================\n");
        OkHttpClient client;

        HttpLoggingInterceptor interceptor = new HttpLoggingInterceptor();
        interceptor.setLevel(HttpLoggingInterceptor.Level.BODY);
        client = new OkHttpClient.Builder().addInterceptor(interceptor).build();

        Retrofit retrofit = new Retrofit.Builder()
                .baseUrl("http://52.8.187.167:8000/")
                .client(client)
                .addConverterFactory(GsonConverterFactory.create())
                .build();

        //JSONArray array = new JSONArray();
        JSONObject email = new JSONObject();
        email.put("userEmail","jmj@kookmin.ac.kr");
        //array.add(email);

        CommonService service = retrofit.create(CommonService.class);

        //Call<JSONArray> request = service.sendPost(email);
        Call<User> request = service.sendPost(email);

        request.enqueue(new Callback<User>() {
            @Override
            public void onResponse(Call<User> call, Response<User> response) {
                //Log.d("test","responses");
                System.out.println("sibal");
                //JSONArray user = response.body();
                //System.out.print(user);
                //Intent UserTest = new Intent(PostTest.this, UserTest.class)
                // Intent
                System.out.println("Call : "+call);
                System.out.println("Response : "+response);
//                System.out.println(response.body());
                User r = response.body();
                System.out.println("r: " + r.userName);
            }

            @Override
            public void onFailure(Call<User> call, Throwable t) {
                System.out.println("SSSSSSibal");
                //JSONArray user = t.getCause()
                //System.out.print(user);
                System.out.println("Cause : "+t);
                System.out.println("JSON : "+call);
            }
        });
        System.out.println("progarm finished");
    }


}