//
//  KiiRequest.h
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//
#ifdef __arm__
#include <WString.h>
#endif

#ifndef __KiiThing__KiiRequest__
#define __KiiThing__KiiRequest__
#include "IRequestObserver.h"

class KiiRequest{
    String _contentType = "application/json";
    IRequestObserver* _observer = 0;
public:
    void sendRequest(const String httpMethod, const String path, const String data);
    void set_contentType (const String contentType) { _contentType = contentType;};
    void attach_observer(IRequestObserver* observer) {_observer = observer;};
};

#endif /* defined(__KiiThing__KiiRequest__) */
