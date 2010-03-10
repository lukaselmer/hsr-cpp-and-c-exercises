/* 
 * File:   SevenSegmentLine.cpp
 * Author: Lukas Elmer
 * 
 * Created on 10. März 2010, 12:46
 */

#include <boost/lexical_cast.hpp>
#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include <boost/assert.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "SevenSegmentLine.h"
#include "SevenSegmentDigit.h"


using namespace std;
using namespace boost::assign;

SevenSegmentLine::SevenSegmentLine(string s) {
    this->digits = vector<SevenSegmentDigit > ();




    try {
        std::string str = "123";
        int number = boost::lexical_cast< int >(str);
    } catch (const boost::bad_lexical_cast &) {
        throw "Invalid input";
    }

    this->digits +=
            SevenSegmentDigit(0),
            SevenSegmentDigit(1),
            SevenSegmentDigit(2),
            SevenSegmentDigit(3),
            SevenSegmentDigit(4),
            SevenSegmentDigit(5),
            SevenSegmentDigit(6),
            SevenSegmentDigit(7),
            SevenSegmentDigit(8),
            SevenSegmentDigit(9);
}

void SevenSegmentLine::print() {
    print(1);
}

void SevenSegmentLine::print(const int scale) {
    cout << endl;
    if (scale <= 0) {
        throw "Illegal scale";
    }
    if (digits.size() <= 0) {
        cout << "No digits given" << endl;
        return;
    }
    //copy(digits.begin(), digits.end(), ostream_iterator<SevenSegmentDigit > (cout, "\n"));

    vector<string> all(3 + (scale * 2), "");

    for (vector<SevenSegmentDigit>::const_iterator i = digits.begin(); i != digits.end(); ++i) {
        SevenSegmentDigit s = *i;
        vector<string> v = s.getStringVector(scale);
        //copy(v.begin(), v.end(), ostream_iterator<string > (cout, "\n"));
        //cout << endl << endl;

        for (int k = 0; k < v.size(); k++) {
            all[k] += v[k];
        }
    }
    copy(all.begin(), all.end(), ostream_iterator<string > (cout, "\n"));
    cout << endl;
}



