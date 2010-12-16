#include "UDPSocket.h"
#include "Datagram.h"
#include <iostream>
#include <map>
#include <functional>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
const int maxlen=1000;

typedef map<struct sockaddr_in,string> ct;
ct clients;
typedef ct::iterator clientiter;
typedef ct::value_type ctvt;
int operator<(struct sockaddr_in left,struct sockaddr_in right) {
	return (left.sin_addr.s_addr < right.sin_addr.s_addr) ||
	       (left.sin_addr.s_addr == right.sin_addr.s_addr &&
		left.sin_port < right.sin_port);
}

struct sendTo{ // Funktor um for_each auf clients anzuwenden
	Datagram *dgram;
	UDPSocket &udp;
	sendTo(Datagram *dg,UDPSocket &udpref):dgram(dg),udp(udpref){}
	void operator()(ctvt client){
		dgram->peer = client.first;
		cout << "sending to peer:" << dgram->getPeerInfo() << endl;
		udp.sendDatagram(*dgram);
	}
};

int main(int argc,char**argv) {
	if (argc < 2) {
		cerr << argv[0] << " port" << endl;
	} else if (argc == 2) { //server
		cout << "creating server socket at " << argv[1]<< endl;
		// TODO: server socket anlegen und vorbereiten
		UDPSocket udp = UDPSocket(/*Parameter*/);
		do {
			Datagram *dgram = 0;// TODO: Datagram empfangen (0 durch methode ersetzen)
			if (dgram) { // ein Datagram wurde erfolgreich empfangen
				// TODO: testausgabe des Datagram Inhalts!

				// suchen ob neuer client, Datagram = key in map name=inhalt=value
				clientiter found = clients.find(dgram->peer);
				if (found == clients.end()) {
					ctvt p(dgram->peer,dgram->message);
					clients.insert(clients.end(),p);
					dgram->message += " enters";
				}
				else {
					// TODO: testen, ob client "." geschickt hat und gegebenenfalls vom chat abmelden

						// sonst
						dgram->message = (*found).second + ":" + dgram->message; // name voranstellen
				}
				for_each(clients.begin(),clients.end(),sendTo(dgram,udp));
				// Alternative Loesung mit Schleife:
/*				for(clientiter i=clients.begin(); i!=clients.end(); ++i) {
					dgram->peer = (*i).first;
					cout << "sending to peer:" << dgram->getPeerInfo() << endl;
					udp.sendDatagram(*dgram);
				}
*/				delete dgram;
			} else {
				cerr << "too much silence. terminating..." << endl;
				break; // stop after 1 minute of silence
			}
		} while (1);
	}
	return 0;
}
