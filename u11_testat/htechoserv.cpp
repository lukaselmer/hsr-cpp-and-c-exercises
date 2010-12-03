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
#include <signal.h>
#include <sys/wait.h>

#include "ServerSocket.h"
#include "SocketIO.h"

using namespace std;

//void childTerminated(int sig_num) {
//    int child_status;
//    wait(&child_status);
//    if (child_status > 0) exit(0);
//}

static bool quit = false;

string getHeaders(int len) {
    //return "";
    stringstream ss;
    ss << "HTTP/1.1 200 OK\n";
    //ss << "Date: Mon, 23 May 2005 22:38:34 GMT\n";
    ss << "Server: LukesServer/0.0.0.1 (Unix) (Windows/NT6.1)\n";
    //ss << "Last-Modified: Wed, 08 Jan 2003 23:11:55 GMT\n";
    //ss << "Etag: \"3f80f-1b6-3e1cb03b\"\n";
    //ss << "Accept-Ranges: bytes\n";
    ss << "Content-Length: " << len << "\n";
    ss << "Connection: close\n";
    ss << "Content-Type: text/html\n";
    //ss << "Content-Type: text/html; charset=UTF-8\n";
    ss << "\n";
    return ss.str();
}

bool quitRequested(string request) {
    return request.find("GET /quit HTTP/1.1\r\n", 0) == 0 || request.find("GET /quit HTTP/1.1\n", 0) == 0;
}

string generateResponse(string request, int counter) {
    stringstream ss1, ss2;
    ss1 << "<html><head></head><body><h1>Dum di dum</h1>This is request #" << counter << "." <<
            "<br/>The request was:" <<
            "<pre>" << request << "</pre>" <<
            "</body></html>\n";
    ss2 << getHeaders(ss1.str().length()) << ss1.str();
    return ss2.str();
}

int main(int argc, char**argv) {
    //signal(SIGCHLD, childTerminated);
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
    int counter = 0;
    while (!quit) {
        ++counter;
        cout << "Server is listening and waiting for accept..." << endl;
        int clientfd = ss.doAccept();
        cout << "Request started..." << endl;
        if (clientfd < 0) {
            cout << "connection failed!" << endl;
            exit(1);
            //continue; // retry
        }

        pid_t parentId = getpid();
        if (!fork()) {
            SocketIO sio(clientfd);
            string lines_received = sio.readlines();
            if (quitRequested(lines_received)) {
                cout << endl << endl;
                quit = true;
            }
            //cout << lines_received << endl;
            string reply = generateResponse(lines_received, counter);
            sleep(5);
            sio.writeN(reply.c_str(), reply.length());
            sio.doClose();

            cout << "Request done!" << endl << endl;
            if (quit) {
                cout << "******************************" << endl;
                cout << "* SERVER IS SHUTTING DOWN!!! *" << endl;
                cout << "******************************" << endl << endl;
                kill(parentId, SIGINT);
            }
            exit(0);
        } else {
            close(clientfd);
        }
    }
    ss.doClose();
    return 0;
}

