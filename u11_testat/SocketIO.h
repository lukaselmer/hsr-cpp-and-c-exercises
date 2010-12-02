#ifndef SOCKETIO_H
#define	SOCKETIO_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <cerrno>
#include <stdlib.h>
#include <vector>

class SocketIO {
public:
    const static int BUF_SIZE = 1024;
    bool eof_reached;

    SocketIO(int fd);
    virtual ~SocketIO();
    std::string readline();
    std::string readlines();
    void writeN(const char *buf, int len);
    void doClose();
    std::string getPeerInfo();
private:
    int sock; // socket file descriptor
    char buf[BUF_SIZE]; // a bit stupid way to mimick an istream
    std::string lines;
        char *writePtr;
        char *readPtr;
        char *endPtr;
        //const char *endPtr;

        bool fillbuf();
        int getc();
};

#endif	/* SOCKETIO_H */

