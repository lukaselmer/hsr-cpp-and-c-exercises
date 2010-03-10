#include "cute.h"
#include "ide_listener.h"
#include "cute_runner.h"
//#include "ex2.h"
#include <iostream>
#include <algorithm>
using namespace std;

namespace {

    void cuteTest() {
        //Hello hello("Hello Cute");
        //ASSERT_EQUAL("Cu", hello.getHelloMessage());
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
    typedef char element;
    cout << "Ctrl-Z to stop" << endl;
    istream_iterator<element> eos;
    //cout << count(istream_iterator<element > (cin), eos, istream_iterator<element > (cin)) << endl;
    //cout << count(istream_iterator<element > (cin), istream_iterator<element> (), 'c') << endl;
    cout << distance(istream_iterator<element > (cin), istream_iterator<element> ()) << endl;
    //cout << count(istream_iterator<element > (cin), istream_iterator<element> (), 'c') << endl;
}

