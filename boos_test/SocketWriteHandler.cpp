#include "SocketWriteHandler.h"
#include <poll.h>
#include <sys/socket.h>
#include <iostream>
#include "Reactor.h"
using namespace std;
SocketWriteHandler::SocketWriteHandler(int fildes, Reactor &theReactor,bool shutdownWr)
:WriteHandler(fildes,theReactor,false)
,shutdownWriting(shutdownWr)
{

}
SocketWriteHandler::~SocketWriteHandler()
{
	cerr << "Terminating SocketWriteHandler "<<getFd() << (shutdownWriting?"with shutdown":"")<< endl;
	if (shutdownWriting) shutdown(getFd(),SHUT_WR);
}
