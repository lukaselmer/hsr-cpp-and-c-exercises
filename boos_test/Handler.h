#ifndef _Handler_H
#define _Handler_H
#include <boost/shared_ptr.hpp>
class AHandler;
typedef boost::shared_ptr<AHandler> Handler;

class AHandler
{
protected:
	int filedes;
	bool	mustClose;
	class Reactor	&myReactor;
public:
	AHandler(int fildes,Reactor &theReactor,bool shouldClose=false);
	virtual ~AHandler();
	// return true on EOF
	virtual bool handleEvent(int revents)=0;
	// deliver poll Events I am interested in
	virtual int  getEvents();
	int getFd() { return filedes;}
};
#endif
