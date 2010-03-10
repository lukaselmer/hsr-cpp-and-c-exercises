/* 
 * File:   SevenSegmentDigit.cpp
 * Author: Lukas Elmer
 * 
 * Created on 10. März 2010, 12:45
 */
#include "SevenSegmentDigit.h"

#include <boost/assign/std/vector.hpp> // for 'operator+=()'
#include <boost/assert.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace boost::assign;

SevenSegmentDigit::SevenSegmentDigit(int digit) {
    if (digit > 9 || digit < 0) {
        throw "Illegal input. Digit must be [0-9]";
    }
    this->digit = digit;
}

/**
 * Source: http://upload.wikimedia.org/wikipedia/commons/0/02/7_segment_display_labeled.svg
 *
 * Each Digit looks like this:
 *  A
 * F B         _
 *  G      =  |_|
 * E C        |_|
 *  D
 *
 * Example: for nr. 8 is each letter (A,B,C,D,E,F,G) true
 **/
vector<string> SevenSegmentDigit::getStringVector(int scale) {
    vector<bool> ii; // this is an array of (A,B,C,D,E,F,G)
    switch (digit) {
        case 0:
            ii += true, true, true, true, true, true, false;
            break;
        case 1:
            ii += false, true, true, false, false, false, false;
            break;
        case 2:
            ii += true, true, false, true, true, false, true;
            break;
        case 3:
            ii += true, true, true, true, false, false, true;
            break;
        case 4:
            ii += false, true, true, false, false, true, true;
            break;
        case 5:
            ii += true, false, true, true, false, true, true;
            break;
        case 6:
            ii += true, false, true, true, true, true, true;
            break;
        case 7:
            ii += true, true, true, false, false, false, false;
            break;
        case 8:
            ii += true, true, true, true, true, true, true;
            break;
        case 9:
            ii += true, true, true, true, false, true, true;
            break;
    }
    vector<string> v;
    int a = 0;
    int b = 1;
    int c = 2;
    int d = 3;
    int e = 4;
    int f = 5;
    int g = 6;
    // Top line
    v += digit[a] ? " - " : "   ";

    // First vertical
    if (digit[b] && digit[f]) {
        v += "| |";
    } else if (digit[b]) {
        v += "  |";
    } else if (digit[f]) {
        v += "|  ";
    } else {
        throw "Illegal state";
    }

    // Middle Line
    v += digit[g] ? " - " : "   ";

    //Second vertical
    if (digit[c] && digit[e]) {
        v += "| |";
    } else if (digit[c]) {
        v += "  |";
    } else if (digit[e]) {
        v += "|  ";
    } else {
        throw "Illegal state";
    }

    // Bottom Line
    v += digit[d] ? " - " : "   ";

    return v;
}

string SevenSegmentDigit::getHorizontal(bool val, int scale) {

}

string SevenSegmentDigit::getVertical(bool, bool, int scale) {

}

