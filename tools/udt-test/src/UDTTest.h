//
//  UDTTest.h
//  tools/udt-test/src
//
//  Created by Stephen Birarda on 2015-07-30.
//  Copyright 2015 High Fidelity, Inc.
//
//  Distributed under the Apache License, Version 2.0.
//  See the accompanying file LICENSE or http://www.apache.org/licenses/LICENSE-2.0.html
//

#pragma once

#ifndef hifi_UDTTest_h
#define hifi_UDTTest_h

#include <QtCore/QCoreApplication>
#include <QtCore/QCommandLineParser>

#include <udt/Constants.h>
#include <udt/Socket.h>

class UDTTest : public QCoreApplication {
public:
    UDTTest(int& argc, char** argv);
private:
    void parseArguments();
    
    QCommandLineParser _argumentParser;
    udt::Socket _socket;
    
    HifiSockAddr _target; // the target for sent packets
    
    int _minPacketSize = udt::MAX_PACKET_SIZE_WITH_UDP_HEADER;
    int _maxPacketSize = udt::MAX_PACKET_SIZE_WITH_UDP_HEADER;
    int _maxSendBytes = -1; // the number of bytes to send to the target before stopping
    int _maxSendPackets = -1; // the number of packets to send to the target before stopping
    
    bool _sendReliable = true; // wether packets are sent reliably or unreliably
};

#endif // hifi_UDTTest_h
