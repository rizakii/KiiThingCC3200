//
//  main.cpp
//  MockingTools
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include <iostream>
#include "Kii.h"
#include "KiiRequest.h"
//        client.println("X-Kii-AppKey: 3594109968d7adf522c9991c0be51137");
//        client.println("X-Kii-AppID: f25bd5bf");
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Hello, World!\n";
    String a = "a";
    
    Kii::instance()->init("api-development-jp.internal.kii.com", "f25bd5bf", "3594109968d7adf522c9991c0be51137");
    KiiRequest request;
    
    request.sendRequest("POST", "things", "{\"_password\":\"password\" , \"_vendorThingID\":\"DDrBnvSPOXBDF9r29GJeGS\"}");
    
    return 0;
}
