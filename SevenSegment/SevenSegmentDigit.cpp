/* 
 * File:   SevenSegmentDigit.cpp
 * Author: Lukas Elmer
 * 
 * Created on 10. März 2010, 12:45
 */
#include "SevenSegmentDigit.h"

using namespace std;
using namespace boost::assign;


SevenSegmentDigit::mapType SevenSegmentDigit::digitsMap;
bool b = SevenSegmentDigit::defineDigitsMap();

SevenSegmentDigit::SevenSegmentDigit(int d) : digit(d) {
    if (digit > 9 || digit < -1) {
        throw "Illegal input. Digit must be [0-9]";
    }
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
 * For -1 a space will be printed
 **/
vector<string> SevenSegmentDigit::getStringVector(int scale) {
    if (scale <= 0) {
        throw "Scale must be >= 1!";
    }
    vector<bool> ii = getBoolVector();
    vector<string> v;
    int a = 0, b = 1, c = 2, d = 3, e = 4, f = 5, g = 6;
    // Top line
    addHorizontal(ii[a], scale, v);
    // First vertical
    addVertical(ii[f], ii[b], scale, v);
    // Middle Line
    addHorizontal(ii[g], scale, v);
    //Second vertical
    addVertical(ii[e], ii[c], scale, v);
    // Bottom Line
    addHorizontal(ii[d], scale, v);
    return v;
}

void SevenSegmentDigit::addHorizontal(bool draw_line, int scale, vector<string>& v) {
    v += " " + string(scale, (draw_line ? '-' : ' ')) + " ";
}

void SevenSegmentDigit::addVertical(bool left, bool right, int scale, vector<string>& v) {
    string s = (left ? '|' : ' ') + string(scale, ' ') + (right ? '|' : ' ');
    for (int i = 0; i < scale; ++i) {
        v += s;
    }
}

vector<bool> SevenSegmentDigit::getBoolVector() {
    mapType::iterator ditigIt;
    ditigIt = digitsMap.find(digit);
    if (ditigIt != digitsMap.end()) {
        return ditigIt->second;
    } else {
        throw "Illegal input";
    }
}
