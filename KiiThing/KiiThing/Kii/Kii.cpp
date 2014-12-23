//
//  Kii.cpp
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include "Kii.h"
Kii* Kii::s_instance=0;
void Kii::init(const String host, const String appId, const String appKey){
    
    this->host= host;
    this->appId= appId;
    this->appKey= appKey;
}