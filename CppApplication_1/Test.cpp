#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
#include "Hello.h"
#include <iostream>

namespace {

    void cuteTest() {
        Hello hello("Hello Cute");
        ASSERT_EQUAL("Cu", hello.getHelloMessage());
    }

    void runSuite() {
        cute::suite s;
        //TODO add your test here
        s.push_back(CUTE(cuteTest));
        cute::ide_listener lis;
        cute::makeRunner(lis)(s, "The Suite");
    }

}
//   runSuite();

int main() {
    runSuite();
    //    std::string s = "Hello world 1";
    //    size_t pos = s.find(' ');
    //    if (pos != std::string::npos)
    //        std::cout << s.substr(pos + 1, 2) << std::endl;
    //    else
    //        std::cout << "Not two words!" << std::endl;
    //    return 0;
}
