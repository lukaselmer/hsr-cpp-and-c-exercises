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

#include "ServerSocket.h"
#include "SocketIO.h"

using namespace std;

string getHeaders(int len) {
    return "";
    stringstream ss;
    ss << "HTTP/1.1 200 OK\r\n";
    ss << "Date: Mon, 23 May 2005 22:38:34 GMT\r\n";
    ss << "Server: Apache/1.3.3.7 (Unix) (Red-Hat/Linux)\r\n";
    ss << "Last-Modified: Wed, 08 Jan 2003 23:11:55 GMT\r\n";
    ss << "Etag: \"3f80f-1b6-3e1cb03b\"\r\n";
    ss << "Accept-Ranges: bytes\r\n";
    ss << "Content-Length: " << len << "\r\n";
    ss << "Connection: close\r\n";
    ss << "Content-Type: text/html; charset=UTF-8\r\n";
    return ss.str();
}

int main(int argc, char**argv) {
    if (argc < 2) {
        cerr << argv[0] << ": port" << endl;
        return 1;
    }
    cout << "Setting server up on port " << argv[1] << endl;
    ServerSocket ss(atoi(argv[1]));
    if (!ss.prepareServerSocket()) {
        cerr << "ss.prepareServerSocket() failed!" << endl;
        return 2;
    }
    bool quit = false;
    int counter = 0;
    while (!quit) {
        ++counter;
        int clientfd = ss.doAccept();
        cout << "Starting request...";
        if (clientfd < 0) continue; // retry
        SocketIO sio(clientfd);

        stringstream ss1, ss2;
        ss1 << "<html><head></head><body><h1>Huuuhuuu</h1><pre>yeah yeah, this is request #" << counter << "!</pre></body></html>\r\n";
        ss2 << getHeaders(ss1.str().length()) << ss1.str();
        string reply = ss2.str();
        sio.writeN(reply.c_str(), reply.length());
        sio.doClose();

        cout << " done!" << endl;
    }
    ss.doClose();
    return 0;
}
