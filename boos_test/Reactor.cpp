#include "Reactor.h"
#include "Handler.h"
#include <cassert>
#include <algorithm>
#include <poll.h>
#include <sys/select.h>
#include <iostream>
#include <errno.h>
#include <boost/bind.hpp>
#include <string.h>
using namespace std;

Reactor::Reactor() {
}

#if defined(__APPLE__)
// Apple's Mac OS X 10.4 poll() doesn't work with devices (e.g. stdin from /dev/tty)
// replace it with a version based on select() that works with all filedescriptors
// BTW, Windows select() only works with sockets!
#define poll(a,b,c) mypoll(a,b,c)

int mypoll(struct pollfd *pfds, unsigned int countfd, int timeoutms) {
    int maxfd = 0;
    struct timeval *timeout = 0;
    struct timeval tv;
    if (timeoutms >= 0) {
        tv.tv_sec = timeoutms / 1000;
        tv.tv_usec = (timeoutms % 1000)*1000;
        timeout = &tv;
    }
    fd_set readfds, writefds;
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    for (struct pollfd *it = pfds; it < pfds + countfd; ++it) {
        maxfd = std::max(maxfd, it->fd);
        if (it->events & POLLIN) FD_SET(it->fd, &readfds);
        if (it->events & POLLOUT) FD_SET(it->fd, &writefds);
    }
    int retval = select(maxfd + 1, &readfds, &writefds, 0, timeout);
    for (struct pollfd *it = pfds; it < pfds + countfd; ++it) {
        it->revents = 0;
        if (FD_ISSET(it->fd, &readfds)) it->revents |= POLLIN;
        if (FD_ISSET(it->fd, &writefds)) it->revents |= POLLOUT;
    }
    return retval;
}
#endif /* macosx broken poll() replacement */

void Reactor::handleEvents() {
    bool someInterest = true;
    while (handlers.size() > 0 && someInterest) {
        someInterest = false;
        size_t handlerscount = handlers.size();
        struct pollfd pfds[handlerscount];
        for (int i = 0; i < handlerscount; i++) {
            Handler h = handlers[i];
            pfds[i].fd = h->getFd();
            pfds[i].events = h->getEvents();
            pfds[i].revents = 0;
            someInterest = someInterest || (pfds[i].events != 0);
        }
        if (someInterest) { // avoids polling forever
            int count = poll(pfds, handlerscount, -1);
            if (count < 0) {
                std::cerr << "poll in reactor failed: " << strerror(errno) << std::endl;
                continue;
            }
            for (int i = 0; i < handlerscount; i++) {
                if (pfds[i].revents & POLLNVAL) {
                    std::cerr << "poll() broken or fd " << pfds[i].fd << " closed" << std::endl;
                    removeHandler(handlers[i]);
                } else if (handlers[i] && pfds[i].revents && handlers[i]->handleEvent(pfds[i].revents))
                    removeHandler(handlers[i]);
            }
        }
        doRemoveHandlers();
    }
    if (handlers.size() == 0)
        std::cerr << "no more Handlers... ";
    else
        std::cerr << "no more interest from Handlers... ";
    std::cerr << "Reactor terminating" << std::endl;
}

void Reactor::registerHandler(Handler h) {
    if (h && !handlerIsRegistered(h))
        handlers.push_back(h);
}

bool Reactor::canBeRemoved(Handler h) {
    return (handlerIsRegistered(h) && findRemovedHandler(h) == handlersToRemove.end());
}

void Reactor::removeHandler(Handler h) {
    if (canBeRemoved(h))
        handlersToRemove.push_back(h);
}

Reactor::HandlersIterator Reactor::findRemovedHandler(Handler h) {
    return find(handlersToRemove.begin(), handlersToRemove.end(), h);
}

bool Reactor::handlerIsRegistered(Handler h) {
    return h && handlers.end() != findHandler(h);
}

Reactor::HandlersIterator Reactor::findHandler(Handler h) {
    return find(handlers.begin(), handlers.end(), h);
}

bool Reactor::needsRemoval(Handler h) {
    return find(handlersToRemove.begin(), handlersToRemove.end(), h) != handlersToRemove.end();
}

void Reactor::doRemoveHandlers() {
    handlers.erase(
            remove_if(handlers.begin(), handlers.end(), boost::bind(std::mem_fun(&Reactor::needsRemoval), this, _1))
            , handlers.end());
    handlersToRemove.clear();
}
