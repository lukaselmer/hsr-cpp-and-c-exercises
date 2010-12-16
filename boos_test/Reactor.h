#ifndef _Reactor_H
#define _Reactor_H
#include <vector>
#include <boost/shared_ptr.hpp>
class AHandler;
typedef boost::shared_ptr<AHandler> Handler;

class Reactor {
protected:
    typedef std::vector<Handler> Handlers;
    typedef Handlers::iterator HandlersIterator;
    Handlers handlers;
    Handlers handlersToRemove;
    bool canBeRemoved(Handler h);
    void doRemoveHandlers();
    bool handlerIsRegistered(Handler h);
    HandlersIterator findHandler(Handler h);
    HandlersIterator findRemovedHandler(Handler h);
    bool needsRemoval(Handler h);
public:
    Reactor();
    void handleEvents();
    void registerHandler(Handler h);
    void removeHandler(Handler h);
};
#endif
