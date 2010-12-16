#include "Handler.h"
#include <string>

class WriteHandler : public AHandler {
protected:
    static const int READSIZE = 1024;
    std::string writebuf;
    bool eofInput;
public:
    // register this handler with the reactor
    WriteHandler(int fildes, Reactor &theReactor, bool shouldClose = true);
    // close socket descriptor if mustClose
    ~WriteHandler();
    virtual int getEvents();
    virtual bool handleEvent(int revents);
    virtual void writen(const char *buf, std::string::size_type len);

    void setEofInput(bool isEof = true) {
        eofInput = isEof;
    }
};
