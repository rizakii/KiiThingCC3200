//
//  WiFiClient.h
//  KiiThing
//
//  Created by Syah Riza on 12/22/14.
//  Copyright (c) 2014 Kii. All rights reserved.
//

#ifndef __KiiThing__WiFiClient__
#define __KiiThing__WiFiClient__

#include <stdio.h>
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
class WiFiClient  {
    int connectedCount=0;
    int availableCount = 0;
    
public:
    WiFiClient();
    
    ~WiFiClient();
    
//    uint8_t status();
//    virtual int connect(const char *host, uint16_t port);
      virtual int sslConnect(const char *host, uint16_t port);
//    virtual size_t write(uint8_t);
//    virtual size_t write(const uint8_t *buffer, size_t size);
      virtual int available();
      virtual int read();
      virtual int read(uint8_t* buf, size_t size);
//    virtual int peek();
//    virtual void flush();
//    virtual void stop();
     virtual uint8_t connected();
//    virtual operator bool();
    
    //  friend class WiFiServer;
    
    void println(const char c[]);
    void println(const unsigned long c);
    void print(const char c[]);
    void print(const unsigned long c);
};

#endif /* defined(__KiiThing__WiFiClient__) */
