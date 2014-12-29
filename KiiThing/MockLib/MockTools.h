//
//  MockTools.h
//  KiiThing
//
//  Created by Syah Riza on 12/29/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#ifndef __KiiThing__MockTools__
#define __KiiThing__MockTools__
#include "WiFiClient.h"
#include <deque>
#include <string>
class MockTools {
    
    MockTools(){};
    static MockTools *s_instance;
    std::deque<std::string> _responseMock;
    
public:
    void setResponseMock(std::deque<std::string> responseMock){
        _responseMock= responseMock;
    };
    static MockTools *instance();
    friend class WiFiClient;
};

#endif /* defined(__KiiThing__MockTools__) */
