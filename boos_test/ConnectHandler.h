#include "Handler.h"
class ConnectHandler:public AHandler
{
protected:
	// factory method for handler after we connected
	virtual Handler makeHandler();
public:
	ConnectHandler(int fildes, Reactor &theReactor);
	virtual int  getEvents() ;
	// return true on EOF
	virtual bool handleEvent(int revents);
};
