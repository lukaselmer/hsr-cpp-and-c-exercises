#include "Datagram.h"
#include "UDPSocket.h"
#include <sstream>
using namespace std;

Datagram::Datagram(string msg,short peerport,const char *peerhost)
:message(msg),
peer(UDPSocket::MakeSocketAddr(peerhost,peerport))
{}
Datagram::Datagram(string msg,struct sockaddr_in partner)
:message(msg),peer(partner) {}
string Datagram::getPeerInfo() {
		ostringstream result; 
		result << inet_ntoa(peer.sin_addr);
		result << ":" << peer.sin_port;
		return result.str();
}
