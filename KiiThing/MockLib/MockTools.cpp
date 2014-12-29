//
//  MockTools.cpp
//  KiiThing
//
//  Created by Syah Riza on 12/29/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include "MockTools.h"

MockTools* MockTools::s_instance = NULL;
MockTools* MockTools::instance(){
    if (!s_instance)
        s_instance = new MockTools;
    return s_instance;
}