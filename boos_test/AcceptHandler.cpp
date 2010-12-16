#include "AcceptHandler.h"
#include "Reactor.h"
#include <poll.h>
#include <sys/socket.h>
#include <errno.h>
#include <iostream>
#include <string.h>
#include "EchoHandler.h"
using namespace std;

AcceptHandler::AcceptHandler(int fildes, Reactor &theReactor) : AHandler(fildes, theReactor) {
}

bool AcceptHandler::handleEvent(int revents) {
    if (revents & (POLLIN | POLLERR | POLLHUP)) {
        int fd = accept(getFd(), 0, 0);
        if (fd >= 0) {
            cerr << "accepting with connected fd = " << fd << endl;
            Handler h = makeRWHandler(fd);
            myReactor.registerHandler(h);
            return false;
        } else {
            cerr << "failure in accept" << strerror(errno) << endl;
        }
    }
    cerr << "no more accepts? revents=" << oct << revents << endl;
    return true; // eof
}

Handler AcceptHandler::makeRWHandler(int fd) {
    return Handler(new EchoHandler(fd, myReactor));
}

int AcceptHandler::getEvents() {
    return POLLIN;
}
