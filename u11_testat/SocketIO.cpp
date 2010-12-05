#include "SocketIO.h"

using namespace std;

SocketIO::SocketIO(int fd) : sock(fd), /*writePtr(buf), readPtr(buf), endPtr(buf + sizeof (buf)),*/ eof_reached(true) {
}

SocketIO::~SocketIO() {
    this->doClose();
}

string SocketIO::readlines() {
    fillbuf();
    if (eof_reached) {
        return "";
    }
    eof_reached = true;
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
    int i = recv(sock, buf, BUF_SIZE, 0);
    if (i < 0) {
        lines = "";
        return false;
    }
    eof_reached = (i == 0);
    lines = string(buf, buf + i);
    return true;
}
