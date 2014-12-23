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

class KiiRequest{
public:
    void sendRequest(const String httpMethod, const String path, const String data);
};

#endif /* defined(__KiiThing__KiiRequest__) */
