#include "SocketIO.h"

using namespace std;

SocketIO::SocketIO(int fd, int _buffer_size) : sock(fd), buffer(""), buffer_size(_buffer_size) {
}

SocketIO::~SocketIO() {
    this->doClose();
}

string SocketIO::readlines() {
    while (fill_buffer());
    return buffer;
}

void SocketIO::writeResponse(const string & response, bool normal_request) {
    cout << endl << "Writing: " << write(sock, response.c_str(), response.length()) << " chars of " << response.length() << endl << "******" << endl;
    cout << (normal_request ? response.c_str() : "[file transfer]");
    cout << endl << "******" << endl;
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

const string SocketIO::getPeerInfo() {
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

bool SocketIO::fill_buffer() {
    char buf[buffer_size]; // a bit stupid way to mimick an istream
    int received_count = recv(sock, buf, buffer_size, MSG_DONTWAIT);
    if (received_count <= 0) return false;
    buffer += string(buf, buf + received_count);
    return true;
}
