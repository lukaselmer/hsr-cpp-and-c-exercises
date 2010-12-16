#include "WriteHandler.h"
class SocketWriteHandler: public WriteHandler
{
protected:
	bool	shutdownWriting;
public:
	// register this handler with the reactor
	SocketWriteHandler(int fildes, Reactor &theReactor,bool shutdownWr=true);
	// don't socket descriptor, only shutdown
	~SocketWriteHandler();
};
