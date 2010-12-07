#include "ServerSocket.h"

using namespace std;

ServerSocket::ServerSocket(unsigned short p) : sockfd(0), port(p) {
}

ServerSocket::~ServerSocket() {
    doClose();
}

bool ServerSocket::setSocketOptions() {
    char x = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (const char*) &x, sizeof (x)) == -1) {
        return false;
    }
    //set reuse socket opt
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*) &x, sizeof (x)) == -1) {
        return false;
    }
    return true;
}

bool ServerSocket::prepareServerSocket() {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    char x = 1;
    if (!setSocketOptions()) {
        return false;
    }

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
}

void ServerSocket::doClose() {
    if (sockfd >= 0) {
        shutdown(sockfd, SHUT_RDWR);
        close(sockfd);
    }
    sockfd = -1;
}
