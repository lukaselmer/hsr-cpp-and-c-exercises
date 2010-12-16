#ifndef Datagram_H
#define Datagram_H
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string>

class Datagram {
public:
	static const long maxlen=65507L;//= 2**16 - IP-Headersize(20) -UDP-Headersize(8) -1
	std::string	message;
	struct sockaddr_in	peer;
	Datagram(std::string msg,short peerport,const char *peerhost);
	Datagram(std::string msg,struct sockaddr_in partner);
	std::string getPeerInfo();
};
#endif
