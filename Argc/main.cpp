#include <iostream>
#include <cmath>
#include <boost/lexical_cast.hpp>

using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "usage: kreis Gleitkommazahl" << endl;
        return 1;
    }
    try {
        double d = boost::lexical_cast<double>(argv[1]);
        cout << "radius: " << d << endl;
        cout << "flaeche: " << d * d * M_PI << endl;
    } catch (boost::bad_lexical_cast ex) {
        cout << "usage: kreis Gleitkommazahl" << endl;
    }
    return 0;
}

