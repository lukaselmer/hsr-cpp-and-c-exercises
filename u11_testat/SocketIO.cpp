#include "SocketIO.h"

using namespace std;

SocketIO::SocketIO(int fd) : sock(fd), writePtr(buf), readPtr(buf), endPtr(buf + sizeof (buf)), eof_reached(true) {
}

SocketIO::~SocketIO() {
    this->doClose();
}

string SocketIO::readline() {
    return "";
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
    cout << " write: " << write(sock, buf, len) << " chars of " << len << ": " << endl << buf << "...";
}

void SocketIO::doClose() {
    if (sock >= 0) {
        close(sock);
    }
    sock = -1;
}

string SocketIO::getPeerInfo() {
    // TODO: implement this
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

int SocketIO::getc() {
    return 0;
}