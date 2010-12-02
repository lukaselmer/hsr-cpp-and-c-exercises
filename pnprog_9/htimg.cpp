#include <arpa/inet.h>
#include <iostream>
#include <string>
#include <cerrno>
#include <cstring>
#include <algorithm>

using namespace std;

bool writeHTTP(int sockfd, const char *path) {
    std::string s("GET ");
    s += path;
    s += " HTTP/0.9\r\n\r\n";
    //	s += " HTTP/1.0\r\n\r\n";
    //	s += " HTTP/1.1\r\nConnection: close\r\n\r\n";
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
    while (1 == read(sockfd, &c, 1) && '\n' != c) {
        s += c;
    }
    //	cout << s <<endl;
    return '\n' == c;
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
        ok200 = (s.substr(firstblank + 1, 3) == "200");
    }
    // read rest of header
    while (readline(sockfd, s)) {
        trimcr(s); // could save header here...
        if (s.length() == 0) return ok200;
    }
    return false; // some error occured
}

bool readHTTPBody(int sockfd, std::string &s) {
    s.erase();
    //char c = '\0';
    int bytesread;
    char buf[1024];
    // error handling missing here
    while ((bytesread = read(sockfd, buf, sizeof (buf))) > 0) {
        s.append(buf, bytesread);
    }
    return (bytesread == 0);
}

int countIMGtags(std::string s) {
    int counter = 0;
    std::transform(s.begin(), s.end(), s.begin(), (int(*)(int))tolower);
    std::string::size_type pos = 0;
    const std::string imgtag("<img");
    while ((pos = s.find(imgtag, pos)) != std::string::npos) {
        pos += imgtag.length();
        counter++;
    }
    return counter;
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
    cout << "htimg with " << argv[1] << " on " << path << endl;
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
                std::string body;
                if (readHTTPBody(sockfd, body)) {
                    cout << "Nr. of <img> Tags: " << countIMGtags(body) << endl;
                } else {
                    cerr << "error reading http reply body" << endl;
                    return 2;
                }
            }
        }
    } else {
        cerr << argv[1] << ":not a valid host address" << endl;
        return 3;
    }
    return 0;
}
