#include "ConnectHandler.h"
class TelnetConnectHandler:public ConnectHandler
{
protected:
	int stdinfd;
	int stdoutfd;
	// factory method for handler after we connected
	virtual Handler makeHandler();
public:
	TelnetConnectHandler(int fildes, Reactor &theReactor, int in, int out);
};
