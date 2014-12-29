//
//  Serial.h
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#ifndef __KiiThing__Serial__
#define __KiiThing__Serial__

#include <stdio.h>
#include <iostream>
class MockSerial{
public:
    MockSerial(){};
    ~MockSerial(){};
    
    void println(const char c[]){
        std::cout<< c << std::endl;
    };
    void print(const char c[]){
        std::cout<< c ;
    };
    void print(const int i){
        std::cout<< i ;
    };
    void println(const int i){
        std::cout<< i << std::endl;
    };
};
extern MockSerial Serial;
#endif /* defined(__KiiThing__Serial__) */
