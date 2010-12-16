#include "TelnetConnectHandler.h"
#include "SocketWriteHandler.h"
#include "ReadHandler.h"
#include "Reactor.h"
TelnetConnectHandler::TelnetConnectHandler(int fildes, Reactor &theReactor,int in, int out)
:ConnectHandler(fildes,theReactor)
,stdinfd(in)
,stdoutfd(out)
{}
Handler TelnetConnectHandler::makeHandler(){
	Handler out(new WriteHandler(stdoutfd,myReactor));
	myReactor.registerHandler(out);
	Handler telout(new SocketWriteHandler(getFd(),myReactor));
	myReactor.registerHandler(telout);
	Handler telin(new ReadHandler(getFd(),myReactor,out));
	myReactor.registerHandler(telin);
	Handler in (new ReadHandler(stdinfd,myReactor,telout));
	return in;
}

