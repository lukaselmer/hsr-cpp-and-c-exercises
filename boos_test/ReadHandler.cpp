#include "ReadHandler.h"
#include "WriteHandler.h"
#include <poll.h>
#include <sys/socket.h>
#include <errno.h>
#include <iostream>
#include <string.h>
using namespace std;

ReadHandler::ReadHandler(int fildes, Reactor &theReactor, Handler wh, bool shouldClose) : AHandler(fildes, theReactor, shouldClose), writePartner(wh) {
}

bool ReadHandler::isEndOfInput(const char *buf, int len) {
    return len <= 0 || (buf[0] == '.' && islf(buf[1]));
}

bool ReadHandler::handleEvent(int revents) {
    bool eof = false;
    if (revents & (POLLIN | POLLERR | POLLHUP)) {
        char buf[READSIZE];
        int readBytes = read(getFd(), buf, READSIZE);
        if (readBytes > 0) {
            eof = consumeData(buf, readBytes);
        } else if (readBytes < 0) {
            cerr << "error reading:" << strerror(errno) << endl;
        } else {
            cerr << "detected eof" << endl;
            eof = true;
        }
        if (eof && getWritePartner()) getWritePartner()->setEofInput(true);
    }
    return eof;
}

ReadHandler::~ReadHandler() {
    cerr << "terminating ReadHandler " << getFd() << (mustClose ? " with closing" : "") << endl;
}

int ReadHandler::getEvents() {
    return POLLIN;
}

bool ReadHandler::islf(char c) {
    return '\n' == c || '\r' == c || '\0' == c;
}

WriteHandler *ReadHandler::getWritePartner() {
    WriteHandler *wh = dynamic_cast<WriteHandler*> (writePartner.get());
    return wh;
}

bool ReadHandler::consumeData(const char *buf, int len) {
    WriteHandler *wh = getWritePartner();
    if (wh) {
        wh->writen(buf, len);
    }
    return isEndOfInput(buf, len);
}
