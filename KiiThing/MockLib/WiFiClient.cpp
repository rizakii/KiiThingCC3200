//
//  WiFiClient.cpp
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include "WiFiClient.h"
#include <iostream>

WiFiClient::WiFiClient(){
    
}

WiFiClient::~WiFiClient(){
    
}

int WiFiClient::sslConnect(const char *host, uint16_t port){
    connectedCount=0;
    return 1;
}
void WiFiClient::println(const char c[])
{
    std::cout << c << std::endl;
}
void WiFiClient::println(const unsigned long c)
{
    std::cout << c << std::endl;
}
void WiFiClient::print(const char c[])
{
    std::cout << c ;
}

void WiFiClient::print(const unsigned long c)
{
    std::cout << c ;
}
uint8_t WiFiClient::connected(){
    
    return connectedCount<100;
}
int WiFiClient::available(){
    
    return connectedCount<100;
}

int WiFiClient::read(){
    char var[]= "payload";
    connectedCount=100;
    return *var;
}
int WiFiClient::read(uint8_t* buf, size_t size)
{
    std::string mock = "Cache-Control: max-age=0 \n";
mock +=    "Content-Type: application/vnd.kii.ThingRegistrationAndAuthorizationResponse+json;charset=UTF-8 \n";
mock +="Date: Mon, 22 Dec 2014 10:52:36 GMT \n";
mock +="Location: https://api-development-jp.internal.kii.com/api/apps/f25bd5bf/things/th.0267251d9d60-fada-4e11-8c98-04efb14a \n";
mock +="Server: Apache-Coyote/1.1 \n";
mock +="Via: 1.1 varnish\n";
mock +="    X-HTTP-Status-Code: 201\n";
mock +="    X-Varnish: 1438331003\n";
mock +="    Content-Length: 227\n";
mock +="Connection: keep-alive\n";
mock +="\n";
mock +="    {";
mock +="        \"_thingID\" : \"th.0267251d9d60-fada-4e11-8c98-04efb14a\",";
mock +="        \"_vendorThingID\" : \"NewrBnvSPOXBDF9r29GJeGS\",";
mock +="        \"_created\" : 1419245556773,";
mock +="        \"_disabled\" : false,";
mock +="        \"_accessToken\" : \"y8Na1FWR8j2bCyIsrMDq1wQm0ZcWtW9UwR70njoCsZU\"";
mock +="    }";
    
    memcpy(buf, mock.c_str(), mock.length());
    
    connectedCount=100;
    return (int)mock.length();
}