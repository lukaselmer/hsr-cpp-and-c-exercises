#include "UDPSocket.h"
#include "Datagram.h"
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/select.h>
#include <cerrno>
#include <iostream>
#include <string.h>
using namespace std;

void UDPSocket::reportError(string msg, int errornumber)
{
	cerr << msg <<":" << strerror(errornumber) << endl;
}
string UDPSocket::getHostIp(const char *host)
{
	struct hostent *he=gethostbyname(host);
	string result(host);
	if (he && he->h_addr_list)
		result = inet_ntoa(*(struct in_addr*)*(he->h_addr_list));
	return result;
}
struct sockaddr_in UDPSocket::MakeSocketAddr(const char *host,int port)
{
	struct sockaddr_in sa;
	sa.sin_family = AF_INET;
	sa.sin_port=htons(port);
	if (!inet_aton(getHostIp(host).c_str(),&sa.sin_addr))
		sa.sin_addr.s_addr=htonl(INADDR_ANY);
	return sa;
}
int	UDPSocket::MakeDgramSocket() {
	return socket(PF_INET,SOCK_DGRAM,0);
}

bool	UDPSocket::PrepareUDPServerSocket() {
	sockfd = MakeDgramSocket();
	if (sockfd <0){
		return false;
	}
	int opt=1;
	if (setsockopt(sockfd,SOL_SOCKET,SO_REUSEADDR,&opt,sizeof(opt))<0){
		return false;
	}
	struct sockaddr_in sa=MakeSocketAddr("0.0.0.0",serverport);
	return bind(sockfd,(struct sockaddr*)&sa,sizeof(sa)) > -1;
}
bool	UDPSocket::PrepareUDPClientSocket() {
	sockfd = MakeDgramSocket();
	return sockfd > -1;
}
bool	UDPSocket::dataAvailable(long msec) {
	fd_set rset;
	FD_ZERO(&rset);
	FD_SET(sockfd,&rset);
	struct timeval to;
	to.tv_sec = msec/1000;
	to.tv_usec = (msec%1000)*1000;
	int res = select(sockfd+1,&rset,0,0,&to);
	return (res == 1);
}
Datagram *UDPSocket::directReceiveDatagram(){
	char buf[Datagram::maxlen];
	struct sockaddr_in partner;
	memset(&partner,0,sizeof(partner));
	socklen_t addrlen=sizeof(partner);
	int len = recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&partner,&addrlen);
	if (len >= 0) return new Datagram(string(buf,len),partner);
	return 0;
}

Datagram *UDPSocket::receiveDatagram(long msec){
	if (dataAvailable(msec)) {
		return directReceiveDatagram();
	}
	return 0;
}
bool	UDPSocket::sendDatagram(Datagram dgram){
	return sendto(sockfd,dgram.message.data(),dgram.message.length(),0,(struct sockaddr*)&dgram.peer,sizeof(dgram.peer))==dgram.message.length();
}
bool	UDPSocket::sendMessageToConnected(std::string message){
	return send(sockfd,message.data(),message.length(),0) == message.length();
}
bool	UDPSocket::PrepareUDPClientSocket(std::string peerhostname, short peerport){
	sockfd = MakeDgramSocket();
	if (sockfd <0) return false;
	struct sockaddr_in sa=MakeSocketAddr(peerhostname.c_str(),peerport);
	return connect(sockfd,(struct sockaddr*)&sa,sizeof(sa)) > -1;
}
