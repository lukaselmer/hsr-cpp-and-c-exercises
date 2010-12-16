#include "WriteHandler.h"
#include <poll.h>
#include <sys/socket.h>
#include <errno.h>
#include <iostream>
#include <string.h>
#include "Reactor.h"
using namespace std;

WriteHandler::WriteHandler(int fildes, Reactor &theReactor, bool shouldClose) : AHandler(fildes, theReactor, shouldClose), eofInput(false) {
}

bool WriteHandler::handleEvent(int revents) {
    if (revents & (POLLOUT | POLLHUP)) {
        int writecount = write(getFd(), writebuf.data(), writebuf.length());
        if (writecount < 0) {
            cerr << "error writing:" << strerror(errno) << endl;
            return true;
        }
        if (writecount == 0) {
            if (writebuf.length() > 0 || eofInput) {
                return true;
            }
        }
        writebuf.erase(0, writecount);
        return false;
    }
    return (revents & POLLERR);
}

WriteHandler::~WriteHandler() {
    cerr << "Terminating WriteHandler " << getFd() << (mustClose ? " with closing" : "") << endl;
}

int WriteHandler::getEvents() {
    return (eofInput || writebuf.length() > 0) ? POLLOUT : 0;
}

void WriteHandler::writen(const char *buf, std::string::size_type len) {
    writebuf.append(buf, len);
}

