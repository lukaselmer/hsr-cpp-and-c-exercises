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
#include "HttpRequest.h"

using namespace std;

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
    FileUploader file_uploader;
    while (true) {
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

            HttpRequest request(sio, file_uploader, counter);

            sio.writeResponse(request.getResponse(), request.wasNormalRequest());
            sio.doClose();

            cout << "*** Request done ***" << endl << endl;

            if (request.quitRequested()) {
                cout << endl << endl;
                cout << "******************************" << endl;
                cout << "* SERVER IS SHUTTING DOWN!!! *" << endl;
                cout << "******************************" << endl << endl << endl;
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

