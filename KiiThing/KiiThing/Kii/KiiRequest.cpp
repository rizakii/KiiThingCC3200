//
//  KiiRequest.cpp
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//
#ifdef __arm__
#include <WString.h>
#include <WiFiClient.h>
#endif

#include "KiiRequest.h"
#include "Kii.h"


void KiiRequest::sendRequest(const String httpMethod, const String path, const String data){
    WiFiClient http;
    char buf[1025];
    int i;
    size_t total = 0;

    String host= Kii::instance()->get_host();
    String headerAppId = "X-Kii-AppID: " + Kii::instance()->get_appId();
    String headerAppKey = "X-Kii-AppKey: " + Kii::instance()->get_appKey();
    String connectionPath = httpMethod + " /api/apps/" + Kii::instance()->get_appId() +"/" + path + " HTTP/1.1";
    
    Serial.println("Attempting HTTPS request-");
    if (http.sslConnect(Kii::instance()->get_host().c_str(), 443)) {
        
        Serial.println(data.c_str());
        Serial.println("connected");
        http.println(connectionPath.c_str());
        http.println("User-Agent: curl/7.37.1");
        http.println("Host: api-development-jp.internal.kii.com");
        http.println("Connection:Keep-Alive");
        http.println("Cache-Control: max-age=0");
        http.println("Accept: */*");
        http.println(headerAppKey.c_str());
        http.println(headerAppId.c_str());
        http.println("Content-Type: application/vnd.kii.ThingRegistrationAndAuthorizationRequest+json");
        http.print("Content-Length: ");
        http.println(data.length());
        http.println("");
        http.println(data.c_str());
        Serial.println("Waiting for response...");
        while (http.connected()) {
            
            i = http.read((uint8_t *)buf, 1024);
            buf[i] = '\0';
            
            total += i;
            Serial.print(buf);
        }
        
        Serial.println("Disconnected by remote host.");
        
        
    } else {
        Serial.println("Error connecting ");
    }

}