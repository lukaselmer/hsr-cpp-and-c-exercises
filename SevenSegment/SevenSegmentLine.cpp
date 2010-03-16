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

SevenSegmentLine::SevenSegmentLine(int inputNum) {
    if (inputNum < 0)
        throw "Inupt number must be >= 0";
    init(boost::lexical_cast< string > (inputNum));
}

SevenSegmentLine::SevenSegmentLine(string inputString) {
    init(inputString);
}

void SevenSegmentLine::init(string inputString) {
    this->digits = vector<SevenSegmentDigit > ();
    for (string::iterator it = inputString.begin(); it != inputString.end(); ++it) {
        try {
            if (*it == ' ')
                this->digits += SevenSegmentDigit(-1);
            else
                this->digits += SevenSegmentDigit(boost::lexical_cast< int >(*it));
        } catch (const boost::bad_lexical_cast &) {
            throw "Illegal input string";
        }
    }
}

void SevenSegmentLine::print() {
    print(1, cout);
}

void SevenSegmentLine::print(const int scale) {
    print(scale, cout);
}

void SevenSegmentLine::print(ostream &out) {
    print(1, out);
}

void SevenSegmentLine::print(const int scale, ostream &out) {
    if (scale <= 0)
        throw "Scale must be >= 1";
    if (digits.size() <= 0)
        throw "No digits given";

    vector<string> all((scale * 2) + 3, ""); // Three horizonal lines and (scale)-times the vertical lines
    for (vector<SevenSegmentDigit>::const_iterator i = digits.begin(); i != digits.end(); ++i) {
        const vector<string> v = ((SevenSegmentDigit) * i).getStringVector(scale);
        for (int k = 0; k < v.size(); ++k) {
            all[k] += " " + v[k];
        }
    }

    cout << endl;
    copy(all.begin(), all.end(), ostream_iterator<string > (cout, "\n"));
    cout << endl;
}
