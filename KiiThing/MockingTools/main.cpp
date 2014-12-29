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
#include "KiiThing.h"
#include <deque>
#include "MockTools.h"

//        client.println("X-Kii-AppKey: 3594109968d7adf522c9991c0be51137");
//        client.println("X-Kii-AppID: f25bd5bf");
int main(int argc, const char * argv[]) {
    
    std::deque<std::string > responseMock;
    responseMock.push_back("HTTP/1.1 200 OK \n");
    responseMock.push_back("Content-Type: application/vnd.kii.ThingRegistrationAndAuthorizationResponse+json;charset=UTF-8 \n");
    responseMock.push_back("Date: Mon, 22 Dec 2014 10:52:36 GMT \n");
    responseMock.push_back("Location: https://api-development-jp.internal.kii.com/api/apps/f25bd5bf/things/th.0267251d9d60-fada-4e11-8c98-04efb14a \n");
    responseMock.push_back("Server: Apache-Coyote/1.1 \n");
    responseMock.push_back("Via: 1.1 varnish\n");
    responseMock.push_back("X-HTTP-Status-Code: 201\n");
    responseMock.push_back("X-Varnish: 1438331003\n");
    responseMock.push_back("Content-Length: 227\n");
    responseMock.push_back("Connection: keep-alive\n");
    responseMock.push_back("\n");
    responseMock.push_back("{");
    responseMock.push_back("\"_thingID\" : \"th.0267251d9d60-fada-4e11-8c98-04efb14a\",");
    responseMock.push_back("\"_vendorThingID\" : \"NewrBnvSPOXBDF9r29GJeGS\",");
    responseMock.push_back("\"_created\" : 1419245556773,");
    responseMock.push_back("\"_disabled\" : false,");
    responseMock.push_back("\"_accessToken\" : \"y8Na1FWR8j2bCyIsrMDq1wQm0ZcWtW9UwR70njoCsZU\"");
    responseMock.push_back("}");
    MockTools::instance()->setResponseMock(responseMock);
    Kii::instance()->init("api-development-jp.internal.kii.com", "f25bd5bf", "3594109968d7adf522c9991c0be51137");
    KiiThing aThing = KiiThing::registerThing("NewrBnvSPOXBDF9r29GJeGS", "password");
    
    Serial.println(aThing.get_thingID().c_str());
    return 0;
}
