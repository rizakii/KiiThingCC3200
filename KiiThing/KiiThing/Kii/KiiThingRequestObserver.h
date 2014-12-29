//
//  KiiThingRequestObserver.h
//  KiiThing
//
//  Created by Syah Riza on 12/29/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//
#include "IRequestObserver.h"
#ifndef __KiiThing__KiiThingRequestObserver__
#define __KiiThing__KiiThingRequestObserver__

#include "KiiRequest.h"
#include "KiiThing.h"

class KiiThingRequestObserver : public IRequestObserver {
    KiiRequest* _request;
    String _thingID;
    String _accessToken;
    bool _disabled;
    
public:
    KiiThingRequestObserver(KiiRequest* request){
        _request=request;
        _request->attach_observer(this);
    }
    void set_json_object(String key, String value);
    friend class KiiThing;
};
#endif /* defined(__KiiThing__KiiThingRequestObserver__) */
