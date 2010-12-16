#include "Handler.h"
#include <poll.h>
#include "Reactor.h"

AHandler::AHandler(int fd, Reactor &theReactor, bool shouldClose)
: filedes(fd)
, myReactor(theReactor)
, mustClose(shouldClose) {
}

AHandler::~AHandler() {
    // auto deleted when removed
    if (mustClose) close(getFd());
}

// deliver poll Events I am interested in

int AHandler::getEvents() {
    return 0;
    /* default no interest */
}
