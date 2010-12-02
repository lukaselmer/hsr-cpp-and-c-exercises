#include <iterator>
#include <string>
#include <streambuf>
#include <iostream>
#include <functional>
#include <boost/bind.hpp>

using namespace std;

/*using namespace boost;
using namespace boost::mpl;*/

struct IsOdd : unary_function<char,bool> {
  bool operator() (const char& x) const {return isupper(x);}
};


int main(int argc, char** argv) {
    string s("Aosdifoa isjfd");
    string s2("");
    copy(s.begin(), s.end(), ostream_iterator<char>(cout, "\n"));
    remove_copy_if(s.begin(), s.end(), back_inserter(s2), not1(IsOdd()));
    cout << s2 << endl;
    return 0;
}

