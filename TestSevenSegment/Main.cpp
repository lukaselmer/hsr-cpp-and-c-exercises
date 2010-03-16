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
    }

    void sevenSegmentListTest1() {
        SevenSegmentLine l("2");
        vector<string> expected;
        expected +=
                "  - ",
                "   |",
                "  - ",
                " |  ",
                "  - ";
        ASSERT_EQUAL(expected, l.getLine(1));
    }

    void sevenSegmentListTest2() {
        SevenSegmentLine l("1 234567890");
        vector<string> expected;
        expected +=
                "            --   --        --   --   --   --   --   -- ",
                "    |         |    | |  | |    |       | |  | |  | |  |",
                "    |         |    | |  | |    |       | |  | |  | |  |",
                "       --   --   --   --   --   --        --   --      ",
                "    |      |       |    |    | |  |    | |  |    | |  |",
                "    |      |       |    |    | |  |    | |  |    | |  |",
                "            --   --        --   --        --   --   -- ";
        ASSERT_EQUAL(expected, l.getLine(2));
    }

    void runSuite() {
        cute::suite s;
        s.push_back(CUTE(sevenSegmentDigitTest));
        s.push_back(CUTE(sevenSegmentDigitScaleTest));
        s.push_back(CUTE(sevenSegmentListTest1));
        s.push_back(CUTE(sevenSegmentListTest2));
        cute::ide_listener lis;
        cute::makeRunner(lis)(s, "The Suite");
    }
}

int main(int argc, char** argv) {
    runSuite();
    return (EXIT_SUCCESS);
}

