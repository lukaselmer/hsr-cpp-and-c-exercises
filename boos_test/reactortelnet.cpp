#include "Reactor.h"
#include "TelnetConnectHandler.h"
#include "Socket.h"
#include <iostream>
#include <errno.h>
using namespace std;

int main(int argc, const char *argv[]) {
    if (argc < 3) {
        cerr << "usage: " << argv[0] << "host port" << endl;
        return 1;
    }
    int sockfd = Socket::MakeTCPSocket();
    if (sockfd < 0) return 1;
    if (!Socket::SetNonBlocking(sockfd)) {
        return 1;
    }
    Reactor theReactor;
    if (Socket::Connect(sockfd,
            Socket::MakeSocketAddr(argv[1], atoi(argv[2])))
            || (errno == EINPROGRESS)) {
        theReactor.registerHandler(Handler(new TelnetConnectHandler(sockfd, theReactor, 0, 1)));
    } else {
        cerr << "couldn't connect to " << argv[1] << " at " << argv[2] << endl;
        return 2;
    }
    theReactor.handleEvents();
}
