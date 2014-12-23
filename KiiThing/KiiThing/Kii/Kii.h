//
//  Kii.h
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#ifdef __arm__
#include <WString.h>
#endif


#ifndef __KiiThing__Kii__
#define __KiiThing__Kii__

class Kii {
    static Kii *s_instance;
    Kii(){};
    String host;
    String appId;
    String appKey;
    
public:
    void init(const String host, const String appId, const String appKey);
    String get_host(){ return host;};
    String get_appId(){ return appId;};
    String get_appKey(){ return appKey;};
    static Kii *instance()
    {
        if (!s_instance)
            s_instance = new Kii;
        return s_instance;
    }
};


#endif /* defined(__KiiThing__Kii__) */
