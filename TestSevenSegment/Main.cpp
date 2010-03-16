/* 
 * File:   Main.cpp
 * Author: Lukas Elmer
 *
 * Created on 11. März 2010, 10:21
 */

#include "cute.h"
#include "cute_runner.h"
#include "ide_listener.h"
#include "SevenSegmentDigit.h"
#include "SevenSegmentLine.h"
#include <boost/assign/std/vector.hpp>
#include <boost/assert.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;
using namespace boost::assign;


using namespace std;


namespace {

    ostream & operator<<(ostream&in, const vector<string>&vec) {
        copy(vec.begin(), vec.end(), ostream_iterator<string > (in, "\n"));
        return in;
    }

    void sevenSegmentDigitTest() {
        SevenSegmentDigit d(2);
        vector<string> expected;
        expected +=
                " - ",
                "  |",
                " - ",
                "|  ",
                " - ";
        ASSERT_EQUAL(expected, d.getStringVector(1));
        //ASSERT(expected == d.getStringVector(1));
    }

    void sevenSegmentDigitScaleTest() {
        SevenSegmentDigit d(2);
        vector<string> expected;
        expected +=
                " -- ",
                "   |",
                "   |",
                " -- ",
                "|   ",
                "|   ",
                " -- ";
        ASSERT_EQUAL(expected, d.getStringVector(2));
        //ASSERT(expected == d.getStringVector(2));
    }

    void sevenSegmentListTest() {
        SevenSegmentLine l("784");
        l.print(1);
        //ASSERT(expected == d.getStringVector(2));
    }

    void runSuite() {
        cute::suite s;
        //TODO add your test here
        s.push_back(CUTE(sevenSegmentDigitTest));
        s.push_back(CUTE(sevenSegmentDigitScaleTest));
        s.push_back(CUTE(sevenSegmentListTest));
        cute::ide_listener lis;
        cute::makeRunner(lis)(s, "The Suite");
    }
}

int main(int argc, char** argv) {
    runSuite();

    SevenSegmentLine l("784");
    l.print(5);
    l.print(2);
    l = SevenSegmentLine(123);
    l.print();
    l = SevenSegmentLine("079 666 55 77");
    l.print(3);
    l.print(1);
    l = SevenSegmentLine("098 7654321");
    l.print(2);
    l.print(6);

    l = SevenSegmentLine(0);
    l.print(1);
    l = SevenSegmentLine(1);
    l.print(3);
    l = SevenSegmentLine(2);
    l.print(5);
    l = SevenSegmentLine(3);
    l.print(7);
    l = SevenSegmentLine(4);
    l.print(9);
    l = SevenSegmentLine(5);
    l.print(11);
    l = SevenSegmentLine(6);
    l.print(13);
    l = SevenSegmentLine(7);
    l.print(15);
    l = SevenSegmentLine(8);
    l.print(17);
    l = SevenSegmentLine(9);
    l.print(20);
    return (EXIT_SUCCESS);
}

