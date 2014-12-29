//
//  KiiThing.cpp
//  KiiThing
//
//  Created by Syah Riza on 12/28/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#include "KiiThing.h"
#include "Kii.h"
#include "KiiRequest.h"
#include "KiiThingRequestObserver.h"

 KiiThing::KiiThing(){
    
}
void KiiThing::doRegister(String thingVendorID, String password){
    KiiRequest request;
    KiiThingRequestObserver observer(&request);
    String registerPayload = "{\"_password\":\""+ password
    +"\" , \"_vendorThingID\":\""+ thingVendorID
    +"\"}";
    
    request.set_contentType("application/vnd.kii.ThingRegistrationAndAuthorizationRequest+json");
    request.sendRequest("POST", "things", registerPayload);
    
    _thingID = observer._thingID;
    
    _thingVendorID=thingVendorID;
}