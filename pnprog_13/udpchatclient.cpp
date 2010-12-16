#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <netdb.h>
#include <fcntl.h>
#include <iostream>
#include <cerrno>
#include <stdlib.h>
#include <string.h>
#include "UDPSocket.h"
#include "Datagram.h"

using namespace std;

const int MAXLINELEN=100;
bool handleInput(int in, UDPSocket &udp, string server, short port) {
	bool eofInput = false;
	char inbuf[MAXLINELEN];
	int readBytes=read(in,inbuf,MAXLINELEN);
	if (readBytes > 0) {
		// TODO: Testen ob user "." eingegeben hat und eofInput auf true setzen

		Datagram dg(string(inbuf,readBytes),port,server.data());
		udp.sendDatagram(dg);
	} else {
		if (readBytes < 0) {
			cerr << "error reading stdin:" << strerror(errno) << endl;
		}
		eofInput=true;
		//close(in);
		cerr << "eof on input" << endl;
	}
	return eofInput;
}

bool handleOutput(int out, UDPSocket &udp) {
	bool eofSocket = false;
	Datagram *dg = udp.directReceiveDatagram();

	if (dg) {
		cout << dg->message << endl;
	} else {
		cerr << "error receiving datagram:" << strerror(errno) << endl;
		eofSocket=true;
	}
	delete dg;
	return eofSocket;
}

void clientcomm(int in,string server, short port, string nickname) {
	UDPSocket udp;
	if (!udp.PrepareUDPClientSocket() || udp.getSocket() <0){
		cerr << "couldn't prepare client" << endl;
		return;
	}
	Datagram dg(nickname,port,server.data());
	udp.sendDatagram(dg);

	bool eofSocket=false;
	bool eofStdin=false;
	while(!eofSocket && !eofStdin) {
		//TODO: hier select einfuegen inkl. vorbereitung fuer select:
		// int res=select(...);
		if (res < 0) {
			cerr << "select failed:" << strerror(errno) << endl;
			continue;
		}
		//TODO: if (input auf stdin (in) verfuegbar)
			eofStdin = handleInput(in,udp,server,port);
		//
		//TODO: if (input auf socket verfuegbar)
			eofSocket = handleOutput(1,udp);
	}
}

int main(int argc,char**argv)
{
    if (argc < 4) {
    	cerr << "usage: " << argv[0] << " hostip port nickname" << endl;
		return 1;
    }
    string server = argv[1];
    short port = atoi(argv[2]);
    clientcomm(0,server,port,argv[3]);
    return 0;
}
