//
// Created by vanya on 02.06.15.
//

#ifndef HWW2_MYCLIENT_H
#define HWW2_MYCLIENT_H


#include <array>
#include <vector>
#include <iostream>
#include <memory>
#include <bits/stdc++.h>
#include "MyEpoll.h"

using namespace std;

const int BACK_LOG = 100;
const int TEMP_SIZE = 1000;

class MyEpoll;

class MyClient {
private:

    MyClient(int port, int socketDescriptor, int epollDescriptor, MyEpoll *);

    int port;
    int socketDescriptor;
    int epollDescriptor;
    u_int32_t flagMask;

//    vector<char> buffer;
//    int bufferCursor;
    deque < char > buffer;
    bool closed;
    MyEpoll * myEpoll;


public:
    friend class MyEpoll;

    void setRead(int flag);

    void setWrite(int flag);

    int readyToWrite();

    void closeClient();

    int getSocketDescriptor();


    void write(string s);

    int read(string &buffer);

    void writeFromEpoll();
};

void makeSocketNonBlocking(int socketDescriptor);

#endif //HWW2_MYCLIENT_H
