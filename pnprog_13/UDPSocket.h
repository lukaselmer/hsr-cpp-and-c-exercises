#ifndef UDPSocket_H
#define UDPSocket_H
#include <netinet/in.h>
#include <cstddef>
#include <cerrno>
#include <arpa/inet.h>
#include <string>
class Datagram;
class UDPSocket {
	public:
	UDPSocket():serverport(0),sockfd(-1){}
	UDPSocket(short port):serverport(port),sockfd(-1){}
	~UDPSocket(){ if (sockfd >-1)close(sockfd); }
	static std::string getHostIp(const char *host);
	static struct sockaddr_in MakeSocketAddr(const char *host,int port);
	static int	MakeDgramSocket() ;
	bool	PrepareUDPServerSocket() ;
	bool	PrepareUDPClientSocket() ;
	bool	PrepareUDPClientSocket(std::string peerhostname, short peerport) ;
	bool	dataAvailable(long msec) ;
	Datagram *receiveDatagram(long timeoutmsec=1000);
	Datagram *directReceiveDatagram();
	bool	sendDatagram(Datagram dgram);
	bool 	sendMessageToConnected(std::string msg);
static	void	reportError(std::string msg, int errornumber);
	int 	getSocket()const {return sockfd;}
	private:
	short	serverport;
	int	sockfd;
};
#endif
