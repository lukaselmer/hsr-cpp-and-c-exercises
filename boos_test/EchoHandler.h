#include "Handler.h"
#include <string>
class EchoHandler: public AHandler
{
protected:
	static const int	READSIZE=1024;
	std::string	writebuf;
	bool eofInput;
	static bool islf(char c);
	virtual bool handleReadEvent();
	virtual bool handleWriteEvent();
public:
	// register this handler with the reactor
	EchoHandler(int fildes, Reactor &theReactor);
	// close socket descriptor
	~EchoHandler();
	virtual bool handleEvent(int revents);
	virtual int  getEvents();
	void	writen(const char *buf,std::string::size_type len);
};
