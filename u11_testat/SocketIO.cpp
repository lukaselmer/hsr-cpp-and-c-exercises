#include "SocketIO.h"

using namespace std;

SocketIO::SocketIO(int fd) : sock(fd), lines("") {
}

SocketIO::~SocketIO() {
    this->doClose();
}

string SocketIO::readlines() {
    while (fillbuf());
    return lines;
}

void SocketIO::writeN(const char *buf, int len) {
    cout << endl << "Writing: " << write(sock, buf, len) << " chars of " << len << ": " << endl << "******" << endl << buf << endl << "******" << endl;
}

void SocketIO::doClose() {
    if (sock >= 0) {
        shutdown(sock, SHUT_RDWR);
        close(sock);
    }
    sock = -1;
}

void SocketIO::closeReadSocket() {
    shutdown(sock, SHUT_RD);
}

string SocketIO::getPeerInfo() {
    struct sockaddr_in peerInfo;
    socklen_t len = sizeof (peerInfo);
    if (getpeername(sock, (struct sockaddr*) &peerInfo, &len) != 0) {
        return "Error";
    }
    stringstream ss;
    ss << inet_ntoa(peerInfo.sin_addr) << ":";
    ss << ntohs(peerInfo.sin_port);
    return ss.str();
}

bool SocketIO::fillbuf() { // corresponds to streambuf::underflow()
    int i = recv(sock, buf, BUF_SIZE, MSG_DONTWAIT);
    if (i <= 0) {
        return false;
    }
    lines += string(buf, buf + i);
    return true;
}
