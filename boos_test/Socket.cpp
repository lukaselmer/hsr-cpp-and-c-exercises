#include "Socket.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <iostream>
#include <string.h>
using namespace std;

int Socket::MakeTCPSocket() {
    return socket(PF_INET, SOCK_STREAM, 0);
}

bool Socket::SetNonBlocking(int fd, bool how) {
    int flags = fcntl(fd, F_GETFL, 0);
    int newflags = how ? (flags | O_NONBLOCK) : (flags&~O_NONBLOCK);
    if (flags < 0 || fcntl(fd, F_SETFL, newflags) < 0) {
        cerr << "couldn't get/set non-blocking flag" << strerror(errno) << endl;
        return false;
    }
    return true;
}

bool Socket::SetReuseAddr(int fd) {
    int opt = 1;
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, (const char *) &opt, sizeof (opt)) != 0) {
        cerr << "couldn't set reuseaddr option:" << strerror(errno) << endl;
        return false;
    }
    return true;
}

struct sockaddr_in Socket::MakeSocketAddr(const char *host, int port) {
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    if (!inet_aton(getHostIp(host).c_str(), &sa.sin_addr))
        sa.sin_addr.s_addr = htonl(INADDR_ANY);
    return sa;
}

std::string Socket::getHostIp(const char *host) {
    struct hostent *he = gethostbyname(host);
    string result(host);
    if (he && he->h_addr_list)
        result = inet_ntoa(*(struct in_addr*) *(he->h_addr_list));
    return result;
};

bool Socket::Connect(int sockfd, struct sockaddr_in sa) {
    if (connect(sockfd, (struct sockaddr*) &sa, sizeof (sa)) < 0) {
        if (errno != EINPROGRESS) {
            cerr << "couldn't connect" << strerror(errno) << endl;
            return false;
        }
    }
    return true;
}

bool Socket::Bind(int sockfd, struct sockaddr_in sa) {
    if (bind(sockfd, (struct sockaddr*) &sa, sizeof (sa)) < 0) {
        cerr << "couldn't bind" << strerror(errno) << endl;
        return false;
    }
    return true;
}

bool Socket::Listen(int sockfd) {
    if (listen(sockfd, 10) < 0) {
        cerr << "couldn't set passive mode" << strerror(errno) << endl;
        return false;
    }
    return true;
}
