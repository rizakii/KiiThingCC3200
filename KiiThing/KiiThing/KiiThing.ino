#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiServer.h>

#include "Kii.h"
#include "KiiRequest.h"

// your network name also called SSID
char ssid[] = "";
// your network password
char password[] = "";
// your network key Index number (needed only for WEP)
int keyIndex = 0;

void printWifiStatus();

void setup() {
    //Initialize serial and wait for port to open:
    Serial.begin(115200);
    char buf[1025];
    int i;
    size_t total = 0;
    // attempt to connect to Wifi network:
    Serial.print("Attempting to connect to Network named: ");
    // print the network name (SSID);
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    WiFi.begin(ssid, password);
    while ( WiFi.status() != WL_CONNECTED) {
        // print dots while we wait to connect
        Serial.print(".");
        delay(300);
    }
    
    Serial.println("\nYou're connected to the network");
    Serial.println("Waiting for an ip address");
    
    while (WiFi.localIP() == INADDR_NONE) {
        // print dots while we wait for an ip addresss
        Serial.print(".");
        delay(300);
    }
    
    Serial.println("\nIP Address obtained");
    printWifiStatus();
    
    Serial.println("\nStarting connection to server...");
    Kii::instance()->init("api-development-jp.internal.kii.com", "f25bd5bf", "3594109968d7adf522c9991c0be51137");
    KiiRequest request;
    request.set_contentType("application/vnd.kii.ThingRegistrationAndAuthorizationRequest+json");
    request.sendRequest("POST", "things", "{\"_password\":\"password\" , \"_vendorThingID\":\"NXX0QrBnvSPOXBDF9r29GJeGS\"}");
    
}

void loop()
{
    
}


void printWifiStatus() {
    // print the SSID of the network you're attached to:
    Serial.print("SSID: ");
    Serial.println(WiFi.SSID());
    
    // print your WiFi shield's IP address:
    IPAddress ip = WiFi.localIP();
    Serial.print("IP Address: ");
    Serial.println(ip);
    
    // print the received signal strength:
    long rssi = WiFi.RSSI();
    Serial.print("signal strength (RSSI):");
    Serial.print(rssi);
    Serial.println(" dBm");
}
