//
//  WiFiClient.cpp
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include "WiFiClient.h"
#include <iostream>
#include "MockTools.h"


WiFiClient::WiFiClient(){
    
    
}

WiFiClient::~WiFiClient(){
    
}

int WiFiClient::sslConnect(const char *host, uint16_t port){
    connectedCount=0;
    responseMock = MockTools::instance()->_responseMock;
    
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
    
    return responseMock.size();
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
    std::string mock = responseMock[0];

    
    memcpy(buf, mock.c_str(), mock.length());
    
    responseMock.pop_front();
    return (int)mock.length();
}
void WiFiClient::stop(){
    std::cout<<"Stop Connection"<<std::endl;
    
}