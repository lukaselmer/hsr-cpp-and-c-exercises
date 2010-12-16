SRC= Datagram.cpp UDPSocket.cpp udpdemo.cpp udpchatserver.cpp chatclient.cpp udpchatclient.cpp
OBJECTS= Datagram.o UDPSocket.o 

#only udpdemo is complete code. all others need your completion
#all: udpdemo
all: udpdemo udpchatserver udpchatclient 

udpdemo:  $(OBJECTS) udpdemo.o
	g++ -o $@ $+ 

udpchatserver:  $(OBJECTS) udpchatserver.o
	g++ -o $@ $+ 

udpchatclient:  $(OBJECTS) udpchatclient.o
	g++ -o $@ $+ 

chatclient:  $(OBJECTS) chatclient.o
	g++ -o $@ $+ 

clean:
	-rm $(OBJECTS) Makefile.bak udpdemo.o udpdemo udpdemo.exe \
	    udpchatserver.o udpchatserver udpchatserver.exe \
	    udpchatclient.o udpchatclient udpchatclient.exe \
	    chatclient.o chatclient chatclient.exe 2>/dev/null

depend: $(SRC) 
	makedepend $(SRC)  2>/dev/null # requires #DO NOT DELETE comment
	g++ -MM $(SRC) >./makedepends.incl

dist: $(SRC) Makefile makedepends.incl
	zip uebw13-vorgabe $+
	
#dependencies genereated with g++ -MM
-include ./makedepends.incl
#last comment for makedepend instead
