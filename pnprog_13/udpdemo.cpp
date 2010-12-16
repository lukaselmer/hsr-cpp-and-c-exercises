#include "UDPSocket.h"
#include "Datagram.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
const int maxlen=1000;

int main(int argc,char**argv)
{
	if (argc < 2) { 
		cerr << argv[0] << " port [server]" << endl;
	} else if (argc == 2) { //server
		UDPSocket udp(atoi(argv[1])); // Port
		if (!udp.PrepareUDPServerSocket()) {
			return 1;
		}
		do {
			Datagram *dgram = udp.receiveDatagram(60000); // Timeout
			if (dgram) {
				cout << "got:" << dgram->message << " from " << dgram->getPeerInfo() << endl;
				udp.sendDatagram(*dgram);
				delete dgram;
			} else {
				cerr << "too much silence. terminating..." << endl;
				break; // stop after 1 minute of silence
			}
		} while (1);
	} else { // client
		UDPSocket udp;
		if (!udp.PrepareUDPClientSocket()) {
			return 1;
		}
		char linebuf[maxlen];
		while(cin.getline(linebuf,maxlen).good()){
			Datagram dgram(string(linebuf,cin.gcount()),atoi(argv[1]),argv[2]);
			if (udp.sendDatagram(dgram)) {
				Datagram *reply=udp.receiveDatagram();
				if (reply) {
					cout << "got:" << reply->message << " from " << reply->getPeerInfo() << endl;
				} else {
					cout << "didn't receive anything" << endl;
				}
			} else {
				UDPSocket::reportError("sending failed",errno);
			}
		}
	}
	return 0;
}
