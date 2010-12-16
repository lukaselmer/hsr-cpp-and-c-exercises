#include "Handler.h"
#include <string>
class ReadHandler: public AHandler
{
protected:
	Handler writePartner;
	static const int	READSIZE=1024;
	virtual bool islf(char c);
	virtual bool consumeData(const char *buf,int len);
	virtual bool isEndOfInput(const char *buf,int len);
public:
	// register this handler with the reactor
	ReadHandler(int fildes, Reactor &theReactor, Handler wh=Handler(),bool shouldClose=false);
	// close descriptor
	~ReadHandler();
	// return true on EOF
	virtual bool handleEvent(int revents);
	virtual int  getEvents();
private:
    class WriteHandler *getWritePartner();
};
