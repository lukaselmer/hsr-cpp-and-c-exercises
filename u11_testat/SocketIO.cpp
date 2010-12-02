#include "SocketIO.h"

using namespace std;

SocketIO::SocketIO(int fd) : sock(fd), writePtr(buf), readPtr(buf), endPtr(buf + sizeof (buf)), eof_reached(false) {
}

SocketIO::~SocketIO() {

}

string SocketIO::readline() {
    // TODO: implement this
}

void SocketIO::writeN(const char *buf, int len) {
    write(sock, buf, len);
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
    // TODO: implement this
}

int SocketIO::getc() {
    // TODO: implement this
}