=Problem fuer alle Services=
	Wenn boost nicht gefunden wird Kommentar im Makefile beachten!

+------------+
| chatserver |
+------------+
Der Chat-Server ist noch nicht implementiert.
F�r die Implementierung braucht es folgende Files:
	chatserver.cpp
		enth�lt die main Methode
	AcceptChatHandler
		abgeleitet von AcceptHandler
	ChatHandler
		abgeleitet von EchoHandler

Im Makefile m�ssen noch die jeweiligen Stellen auskommentiert und die jeweils davor stehende Linien geloescht werden (3x).

Compilieren:
	make depend
	make

Starten:
	./chatserver <port>

Clients:
	telnet <host> <port>
	# zuerst Namen eingeben, dann chaten

+-----------------+
| reactorechoserv |
+-----------------+
Echo Server der mittels Reactor Pattern implementiert ist.
Mehrere Clients koennen ueber z.B. ueber Telnet verbinden

Compilieren:
	make depend
	make

Starten:
	./reactorechoserv <port>

Clients:
	telnet <host> <port>	
	
+---------+
| rtelnet |
+---------+
Telnet mittels Reactor Pattern implementiert.
Handling analog zum reactorechoserv.

