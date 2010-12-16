#include "ConnectHandler.h"
#include "Reactor.h"
#include <poll.h>
#include <iostream>
using namespace std;
ConnectHandler::ConnectHandler(int fildes, Reactor &theReactor)
:AHandler(fildes,theReactor)
{}

bool ConnectHandler::handleEvent(int revents)
{
	if (revents & POLLOUT) {
		cerr << "connected" << endl;
		Handler h = makeHandler();	
		myReactor.registerHandler(h);
	}
	return true; //will be deleted later
}

Handler ConnectHandler::makeHandler(){return Handler();}

int ConnectHandler::getEvents() 
{ 
	return POLLOUT;
}
