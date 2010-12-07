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
#include "FileUploader.h"

using namespace std;

string getHeaders(int len) {
    stringstream ss;
    ss << "HTTP/1.1 200 OK\n";
    ss << "Server: LukesC++Server\n";
    ss << "Content-Length: " << len << "\n";
    ss << "Connection: close\n";
    ss << "Content-Type: text/html\n";
    ss << "\n";
    return ss.str();
}

bool quitRequested(string request) {
    return request.find("GET /quit HTTP/1.1\r\n", 0) == 0 || request.find("GET /quit HTTP/1.1\n", 0) == 0;
}

string generateResponse(string request, string clintinfo, int counter) {
    stringstream ss1, ss2;
    ss1 << "<html><head></head><body><h1>Hello <i>" << clintinfo << "</i></h1>" <<
            "<div>This is request <b>#" << counter << "</b>.</div>" <<
            "<div>This is your request:</div>" <<
            "<pre>" << request << "</pre>" <<
            "<form action=\"input_file.htm\" method=\"post\" enctype=\"multipart/form-data\">" <<
            "File upload test: <input name=\"Datei\" type=\"file\" /><input type=\"submit\" />" <<
            "</form>" << "</body></html>\n";
    ss2 << getHeaders(ss1.str().length()) << ss1.str();
    return ss2.str();
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
    int counter = 0;
    bool quit = false;
    while (!quit) {
        ++counter;
        cout << "Server is listening and waiting for accept..." << endl;

        // TODO: This is blocking unless the current connection is closed! How can it be fixed???
        int clientfd = ss.doAccept();

        cout << "Request started..." << endl;
        if (clientfd < 0) {
            cout << "connection failed!" << endl;
            exit(1);
        }

        pid_t parentId = getpid();
        if (!fork()) { // Child process
            ss.doClose();
            SocketIO sio(clientfd);
            cout << "Connected to " << sio.getPeerInfo() << endl;
            string lines_received = sio.readlines();
            sio.closeReadSocket();
            
            // Just for fun: Upload file
            FileUploader f(lines_received);

            if (quitRequested(lines_received)) {
                cout << endl << endl;
                quit = true;
            }
            string reply = generateResponse(lines_received, sio.getPeerInfo(), counter);
            //sleep(5);
            sio.writeN(reply.c_str(), reply.length());
            sio.doClose();

            cout << "*** Request done ***" << endl << endl;
            if (quit) {
                cout << "******************************" << endl;
                cout << "* SERVER IS SHUTTING DOWN!!! *" << endl;
                cout << "******************************" << endl << endl;
                kill(parentId, SIGINT);
            }
            exit(0);
        } else { // Main process
            close(clientfd);
            //sio.doClose();
        }
    }
    ss.doClose();
    return 0;
}

