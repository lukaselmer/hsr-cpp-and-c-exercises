#ifndef HELLO_H_
#define HELLO_H_

#include <iostream>
#include <string>

class Hello {
public:
    Hello(std::string message);
    std::string getHelloMessage();
private:
    std::string message;
};

#endif /*HELLO_H_*/
