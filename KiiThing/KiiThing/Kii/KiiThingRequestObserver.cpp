//
//  KiiThingRequestObserver.cpp
//  KiiThing
//
//  Created by Syah Riza on 12/29/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include "KiiThingRequestObserver.h"
#include "Serial.h"

void KiiThingRequestObserver::set_json_object(String key, String value){
    if (key == "_thingID") {
        _thingID=value;
    }else if (key == "_vendorThingID"){
        
    }else if (key == "_created"){
        
    }else if (key == "_disabled"){
        
    }else if (key == "_accessToken"){
        _accessToken = value;
    }
    Serial.print("Key :");
    Serial.println(key.c_str());
    Serial.print("Value :");
    Serial.println(value.c_str());
}