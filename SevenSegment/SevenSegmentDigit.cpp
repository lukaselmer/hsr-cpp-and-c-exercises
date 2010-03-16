/*
 * Author: Lukas Elmer
 */

#define Ob(x)  ((unsigned)Ob_(0 ## x ## uL))
#define Ob_(x) (x & 1 | x >> 2 & 2 | x >> 4 & 4 | x >> 6 & 8 | x >> 8 & 16 | x >> 10 & 32 | x >> 12 & 64 | x >> 14 & 128)

#include "SevenSegmentDigit.h"
#include <iostream>
#include <boost/assign/list_of.hpp>
#include <boost/assign/std/vector.hpp>

using namespace std;
using namespace boost::assign;

SevenSegmentDigit::mapType SevenSegmentDigit::digitsMap = map_list_of(0, Ob(00111111))
(1, Ob(00000110))(2, Ob(01011011))(3, Ob(01001111))(4, Ob(01100110))(5, Ob(01101101))
(6, Ob(01111101))(7, Ob(00000111))(8, Ob(01111111))(9, Ob(01101111))(-1, Ob(01000000));

SevenSegmentDigit::SevenSegmentDigit(int d) : digit(d) {
    if (digit > 9 || digit < -1)
        throw "Illegal input. Digit must be [0-9]";
    this->initBinaryDigit();
}

void SevenSegmentDigit::initBinaryDigit() {
    mapType::iterator ditigIt = digitsMap.find(digit);
    if (ditigIt != digitsMap.end())
        binaryDigit = ditigIt->second;
    else
        throw "Illegal input";
}

/**
 * Source: http://upload.wikimedia.org/wikipedia/commons/0/02/7_segment_display_labeled.svg
 * Each Digit looks like this:
 *  A
 * F B         _
 *  G      =  |_|
 * E C        |_|
 *  D
 * Example: for nr. 8 is each letter (A,B,C,D,E,F,G) true
 * For -1, '-' will be printed
 **/
vector<string> SevenSegmentDigit::getStringVector(int scale) {
    if (scale <= 0)
        throw "Scale must be >= 1!";
    bool a = (binaryDigit & 1) > 0, b = (binaryDigit & 2) > 0, c = (binaryDigit & 4) > 0, d = (binaryDigit & 8) > 0,
            e = (binaryDigit & 16) > 0, f = (binaryDigit & 32) > 0, g = (binaryDigit & 64) > 0;
    vector<string> v;
    addHorizontal(a, scale, v);
    addVertical(f, b, scale, v);
    addHorizontal(g, scale, v);
    addVertical(e, c, scale, v);
    addHorizontal(d, scale, v);
    return v;
}

void SevenSegmentDigit::addHorizontal(bool draw_line, int scale, vector<string>& v) {
    v += " " + string(scale, (draw_line ? '-' : ' ')) + " ";
}

void SevenSegmentDigit::addVertical(bool left, bool right, int scale, vector<string>& v) {
    string s = (left ? '|' : ' ') + string(scale, ' ') + (right ? '|' : ' ');
    for (int i = 0; i < scale; ++i)
        v += s;
}
