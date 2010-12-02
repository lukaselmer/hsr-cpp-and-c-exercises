#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>

using namespace std;

bool writeHTTP(int sockfd, const char *path) {
    std::string s("GET ");
    s += path;
    s += " HTTP/0.9\r\n\r\n";
    //	s += " HTTP/1.0\r\n\r\n";
    size_t towrite = s.length();
    const char *request = s.c_str();
    int written = 0;
    while (towrite > 0 && (written = write(sockfd, request, towrite)) >= 0) {
        towrite -= written;
        request += written;
    }
    if (written < 0) {
        cerr << "couldn't complete request: " << strerror(errno);
        return false;
    }
    shutdown(sockfd, SHUT_WR); //close writing side, no error checking yet
    return true;
}

// too silly implementation of reading loop without buffering

bool readline(int sockfd, std::string &s) {
    s.erase();
    char c = '\0';
    while (read(sockfd, &c, 1) == 1 && c != '\n') {
        s += c;
    }
    //cout << s << endl;
    return c == '\n';
}

void trimcr(std::string &s) {
    size_t lastchar = s.length() - 1;
    if (s[lastchar] == '\r') {
        s.erase(lastchar);
    }
}

// returns true if 200 OK, false otherwise, consumes header

bool readHTTPReplyHeader(int sockfd) {
    std::string s;
    bool ok200 = false;
    if (readline(sockfd, s)) {
        std::string::size_type firstblank = s.find_first_of(" ");
        //cout << s.substr(firstblank+1,3) << endl;
        ok200 = (s.substr(firstblank + 1, 3) == "200");
    }
    // read rest of header
    while (readline(sockfd, s)) {
        trimcr(s); // could save header here...
        if (s.length() == 0) {
            return ok200;
        }
    }
    return false; // some error occured
}

int main(int argc, char**argv) {
    if (argc < 2) {
        cerr << "usage: " << argv[0] << " hostip [path]" << endl;
        return 4;
    }
    const char *path = argv[2];
    if (!path || !*path) {
        path = "/";
    }
    cout << "htangle with " << argv[1] << " on " << path << endl;
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in sa;
    sa.sin_family = AF_INET;
    sa.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &sa.sin_addr)) {
        int connerr = connect(sockfd, (const sockaddr*) &sa, sizeof (sa));
        if (!connerr) {
            if (writeHTTP(sockfd, path)) {
                if (!readHTTPReplyHeader(sockfd)) {
                    cerr << "couldn't retrieve " << path << endl;
                    return 2;
                }
                char c;
                int lcounter = 0, rcounter = 0;
                while (read(sockfd, &c, 1)) {
                    //			cout << c;
                    if (c == '<') lcounter++;
                    if (c == '>') rcounter++;
                    if (rcounter > lcounter) {
                        cerr << "too many closing >" << endl;
                        return 1;
                    }
                }
                if (lcounter == rcounter) {
                    cout << "i.O" << endl;
                    return 0;
                } else {
                    cerr << "mismatch: <:" << lcounter << " >:" << rcounter << endl;
                    return 1;
                }
            }
        }
    } else {
        cerr << argv[1] << ":not a valid host address" << endl;
        return 3;
    }
    return 0;
}
