#include "Reactor.h"
#include "AcceptHandler.h"
#include "Socket.h"
#include <iostream>
using namespace std;

int main(int argc, const char *argv[]) {
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " port" << endl;
        return 1;
    }
    int sockfd = Socket::MakeTCPSocket();
    if (sockfd < 0) return 1;
    if (Socket::SetReuseAddr(sockfd)
            && Socket::Bind(sockfd, Socket::MakeSocketAddr("0.0.0.0", atoi(argv[1])))
            && Socket::Listen(sockfd)) {
        Reactor theReactor;
        theReactor.registerHandler(Handler(new AcceptHandler(sockfd, theReactor)));
        theReactor.handleEvents();
    }
}
