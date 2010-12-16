#include "EchoHandler.h"
#include <poll.h>
#include <sys/socket.h>
#include <errno.h>
#include <iostream>
#include <string.h>
using namespace std;

EchoHandler::EchoHandler(int fildes, Reactor &theReactor) : AHandler(fildes, theReactor), eofInput(false) {
}

bool EchoHandler::handleEvent(int revents) {
    bool result = false;
    if (revents & (POLLIN | POLLERR | POLLHUP)) result = handleReadEvent();
    if (revents & (POLLOUT | POLLHUP)) result |= handleWriteEvent();
    result |= (revents & POLLERR);
    return result;
}

bool EchoHandler::handleReadEvent() {
    char buf[READSIZE];
    int readBytes = read(getFd(), buf, READSIZE);
    if (readBytes < 0) {
        cerr << "error reading:" << strerror(errno) << endl;
        eofInput = true;
        return true;
    }
    if (readBytes == 0) {
        eofInput = true;
        shutdown(getFd(), SHUT_RD);
        cerr << "eof reached on read" << endl;
        writen("Good Bye\n", 9);
    } else if (buf[0] == '.' && islf(buf[1])) {
        shutdown(getFd(), SHUT_RD);
        cerr << ". reached on read" << endl;
        writen("Good Bye\n", 9);
        eofInput = true;
    } else
        writen(buf, readBytes);
    return false;
}

bool EchoHandler::handleWriteEvent() {
    int writecount = write(getFd(), writebuf.data(), writebuf.length());
    if (writecount < 0) {
        cerr << "error writing:" << strerror(errno) << endl;
        return true;
    }
    if (writecount == 0) {
        if (writebuf.length() > 0 || eofInput) {
            cerr << "eof writing" << endl;
            return true;
        }
    }
    writebuf.erase(0, writecount);
    return false;
}

EchoHandler::~EchoHandler() {
    cerr << "EchoHandler terminating and closing" << endl;
    close(getFd());
}

int EchoHandler::getEvents() {
    return (eofInput ? POLLOUT : POLLIN) | (writebuf.length() > 0 ? POLLOUT : 0);
}

void EchoHandler::writen(const char *buf, std::string::size_type len) {
    writebuf.append(buf, len);
}

bool EchoHandler::islf(char c) {
    return '\n' == c || '\r' == c;
}

