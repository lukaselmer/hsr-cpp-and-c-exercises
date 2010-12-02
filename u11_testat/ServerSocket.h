#ifndef SERVERSOCKET_H
#define	SERVERSOCKET_H

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
#include <fcntl.h>
#include <poll.h>

class ServerSocket {
public:
    ServerSocket(unsigned short p);
    virtual ~ServerSocket();
    bool prepareServerSocket();
    int doAccept();
    void doClose();
private:
    int sockfd;
    unsigned short port;

};

#endif	/* SERVERSOCKET_H */

