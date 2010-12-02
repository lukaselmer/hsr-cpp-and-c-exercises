#include <string.h>

#include "ServerSocket.h"

using namespace std;

ServerSocket::ServerSocket(unsigned short p) : sockfd(socket(AF_INET, SOCK_STREAM, 0)), port(p) {
}

ServerSocket::~ServerSocket() {
    doClose();
}

bool ServerSocket::prepareServerSocket() {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    string errmsg;
    if (bind(sockfd, (sockaddr *) & sa, sizeof (sa)) < 0) {
        errmsg = strerror(errno);
        cerr << "failed to bind:" << errmsg << endl;
        return false;
    }
    if (listen(sockfd, 1) < 0) {
        errmsg = strerror(errno);
        cerr << "failed to listen:" << errmsg << endl;
        return false;
    }
    return true;
}

int ServerSocket::doAccept() {
    int clientfd = -1;
    if ((clientfd = accept(sockfd, 0, 0)) < 0) {
        cerr << "failed to accept:" << strerror(errno) << endl;
        return -1;
    }
    return clientfd;
    //int theport = 0;
    //    string ip = getSa(clientfd, theport, getpeername);
    //    cout << "client on fd = " << clientfd << " from = " << ip << " at port = " << theport << endl;
    //    ip = getSa(clientfd, theport, getsockname);
    //    cout << "myself at = " << ip << " at port = " << theport << endl;
    //    ip = getSa(sockfd, theport, getsockname);
    //    cout << "myself accepting on fd=" << sockfd << " at = " << ip << " at port = " << theport << endl;
    //close(clientfd);
}

void ServerSocket::doClose() {
    if (sockfd >= 0) {
        close(sockfd);
    }
    sockfd = -1;
}
