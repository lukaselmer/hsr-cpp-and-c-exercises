#include <arpa/inet.h>
#include <iostream>
#include <cerrno> // needed for errno
#include <cstring>

using namespace std;

int main(int argc, char**argv) {
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " hostip [path]" << endl;
        return 1;
    }
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &sa.sin_addr)) {
        int connerr = connect(sockfd, (const sockaddr*) &sa, sizeof (sa));
        if (!connerr) {
            const char *path = argv[2];
            if (!path || !*path) path = "/";
            write(sockfd, "GET ", 4);
            write(sockfd, path, strlen(path));
            write(sockfd, "\r\n\r\n", 4);
            shutdown(sockfd, SHUT_WR); //close writing side
            char c;
            while (read(sockfd, &c, 1)) {
                cout << c;
            }
        }
    } else {
        cerr << argv[1] << ":not a valid host address" << endl;
        return 2;
    }
    return 0;
}
