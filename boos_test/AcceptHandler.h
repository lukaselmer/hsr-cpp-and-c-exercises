#include "Handler.h"
class AcceptHandler:public AHandler
{
protected:
	// factory method for handler after we accepted
	virtual Handler makeRWHandler(int fd);
public:
	AcceptHandler(int fildes, Reactor &theReactor);
	virtual bool handleEvent(int revents);
	virtual int  getEvents() ;
};
