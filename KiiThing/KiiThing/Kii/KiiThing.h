//
//  KiiThing.h
//  KiiThing
//
//  Created by Syah Riza on 12/28/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//
#ifdef __arm__
#include <WString.h>
#endif

#ifndef __KiiThing__KiiThing__
#define __KiiThing__KiiThing__

class KiiThing {
    String _thingID;
    String _thingVendorID;
    String _accessToken;
    
    KiiThing();
    void doRegister(String thingVendorID, String password);
    
public:
    static KiiThing registerThing(String thingVendorID, String password){
        KiiThing thing;
        thing.doRegister(thingVendorID,password);
        return thing;
    }
    
    String get_thingVendorID(){return _thingVendorID;};
    String get_thingID(){return _thingID;};
    
};

#endif /* defined(__KiiThing__KiiThing__) */
