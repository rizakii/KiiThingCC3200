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
#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "KiiRequest.h"
#include "Kii.h"

#include "http.h"
#include "jsmn.h"
#define TOKEN_STRING(js, t, s) \
(strncmp(js+(t).start, s, (t).end - (t).start) == 0 \
&& strlen(s) == (t).end - (t).start)

#define TOKEN_PRINT(t) \
printf("start: %d, end: %d, type: %d, size: %d\n", \
(t).start, (t).end, (t).type, (t).size)

// Response data/funcs
struct HttpResponse {
    String body;
    int code;
};

static void* response_realloc(void* opaque, void* ptr, int size)
{
    return realloc(ptr, size);
}

static void response_body(void* opaque, const char* data, int size)
{
    HttpResponse* response = (HttpResponse*)opaque;
    response->body += data;
    
}

static void response_header(void* opaque, const char* ckey, int nkey, const char* cvalue, int nvalue)
{ /* example doesn't care about headers */ }

static void response_code(void* opaque, int code)
{
    HttpResponse* response = (HttpResponse*)opaque;
    response->code = code;
}

static const http_funcs responseFuncs = {
    response_realloc,
    response_body,
    response_header,
    response_code,
};

void KiiRequest::sendRequest(const String httpMethod, const String path, const String data){
    WiFiClient http;
    char buf[1025];
    int i;
    size_t total = 0;
    HttpResponse response;
    response.code = 0;
    
    http_roundtripper rt;
    http_init(&rt, responseFuncs, &response);
    
    String hostHeader ="Host: "+ Kii::instance()->get_host();
    String headerAppId = "X-Kii-AppID: " + Kii::instance()->get_appId();
    String headerAppKey = "X-Kii-AppKey: " + Kii::instance()->get_appKey();
    String connectionPath = httpMethod + " /api/apps/" + Kii::instance()->get_appId() +"/" + path + " HTTP/1.1";
    String headerContentType = "Content-Type: "+ _contentType;
    Serial.println("Attempting HTTPS request-");
    if (http.sslConnect(Kii::instance()->get_host().c_str(), 443)) {
        
        Serial.println(data.c_str());
        Serial.println("connected");
        http.println(connectionPath.c_str());
        http.println("User-Agent: curl/7.37.1");
        http.println(hostHeader.c_str());
        http.println("Connection: Close");
        http.println("Accept: */*");
        http.println(headerAppKey.c_str());
        http.println(headerAppId.c_str());
        http.println(headerContentType.c_str());
        http.print("Content-Length: ");
        http.println(data.length());
        http.println("");
        http.println(data.c_str());
        String resp = "";
        Serial.println("Waiting for response...");
        while (http.connected()) {
            
            i = http.read((uint8_t *)buf, 1024);
            buf[i] = '\0';
            
            total += i;
            resp+=buf;
            int read;
            http_data(&rt, buf, i, &read);
        }
        
        http_free(&rt);
        Serial.println("--------------------");
        String status = "Status " ;
        Serial.print(status.c_str());
        Serial.println(response.code);
        Serial.println("Body:");
        Serial.println(response.body.c_str());
        Serial.println("--------------------");
        Serial.println("Disconnected by remote host.");
        
        if (!_observer) {
            return;
        }
        
        jsmn_parser parser;
        
        jsmn_init(&parser);
        jsmntok_t tokens[256];
        const char *js;
        jsmnerr_t r;
        
        js = response.body.c_str();
        r = jsmn_parse(&parser, js, strlen(js), tokens, 256);
        String key ="";
        
        for (i = 1; tokens[i].end < tokens[0].end; i++) {
            if (tokens[i].type == JSMN_STRING || tokens[i].type == JSMN_PRIMITIVE) {
                
                int ln = tokens[i].end - tokens[i].start;
                char subbuff[ln];
                
                memcpy( subbuff, &js[tokens[i].start], ln );
                subbuff[ln] = '\0';
                if (key=="") {
                    key = subbuff;
                    
                }else{
                    _observer->set_json_object(key, subbuff);
                    key = "";
                }
                
                
            } else if (tokens[i].type == JSMN_ARRAY) {
                printf("[%d elems]\n", tokens[i].size);
            } else if (tokens[i].type == JSMN_OBJECT) {
                printf("{%d elems}\n", tokens[i].size);
            } else {
                //TOKEN_PRINT(tokens[i]);
            }
        }
        
    } else {
        Serial.println("Error connecting ");
    }

}