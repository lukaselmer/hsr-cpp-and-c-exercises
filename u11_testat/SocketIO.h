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
    SocketIO(int fd, int buffer_size = 1024);
    virtual ~SocketIO();
    std::string readlines();
    void writeResponse(const std::string & response, bool normal_request);
    void doClose();
    const std::string getPeerInfo();
    void closeReadSocket();
private:
    int sock; // socket file descriptor
    int buffer_size;
    std::string buffer;
    bool fill_buffer();
};

#endif	/* SOCKETIO_H */

