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
#include <cstdlib>
#include <vector>
#include <string.h>

using namespace std;

string readFromSocket(int clinetfd) {
    char buf[1024]; // a bit stupid way to mimick an istream
    int received_count = recv(clinetfd, buf, 1024, MSG_DONTWAIT);
    if (received_count <= 0) return false;
    return string(buf, buf + received_count);
}

int main(int argc, char** argv) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    int port = 777;
    char x = 1;

    //set keep alive opt
    if (setsockopt(sockfd, SOL_SOCKET, SO_KEEPALIVE, (const char*) &x, sizeof (x)) == -1) {
        cerr << "failed to set socket option: SO_KEEPALIVE" << strerror(errno) << endl;
        close(sockfd);
        return 1;
    }
    //set reuse socket opt
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char*) &x, sizeof (x)) == -1) {
        cerr << "failed to set socket option: SO_REUSEADDR" << strerror(errno) << endl;
        close(sockfd);
        return 2;
    }

    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(port);
    sa.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(sockfd, (sockaddr *) & sa, sizeof (sa)) < 0) {
        cerr << "failed to bind:" << strerror(errno) << endl;
        close(sockfd);
        return 3;
    }
    if (listen(sockfd, 1) < 0) {
        cerr << "failed to listen:" << strerror(errno) << endl;
        close(sockfd);
        return 4;
    }

    while (true) {
        cout << "Server is listening and waiting for accept..." << endl;

        // TODO: This is blocking unless the current connection is closed! How can it be fixed???
        cout << "Before accept" << endl;
        int clientfd = accept(sockfd, 0, 0);
        cout << "After accept" << endl;
        if (clientfd < 0) {
            cerr << "failed to accept:" << strerror(errno) << endl;
            close(sockfd);
            return 5;
        }

        //pid_t parentId = getpid();
        if (fork() == 0) { // Child process
            close(sockfd);
            string request = readFromSocket(clientfd);
            cout << "Request:" << endl << "******" << endl << request << "******" << endl;
            string response(request + "BlaBlaBla" + "\r\n");
            cout << "Simulating long request processing time" << endl;
            for (int i = 0; i < 25; ++i) {
                cout << "-";
            }
            cout << endl;
            for (int i = 0; i < 25; ++i) {
                cout << "=" << flush;
                usleep(200000);
            }
            cout << endl << "Done!" << endl;

            cout << "Response:" << endl << "******" << endl << response << "******" << endl;
            write(clientfd, response.c_str(), response.length());
            cout << "*** Request done ***" << endl << endl;
            close(clientfd);
            exit(1);
        }
        close(clientfd);
    }

    close(sockfd);
    return 0;
}

