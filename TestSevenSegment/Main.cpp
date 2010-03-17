/* 
 * Author: Lukas Elmer
 */

#include "cute.h"
#include "cute_runner.h"
#include "ide_listener.h"
#include "SevenSegmentDigit.h"
#include "SevenSegmentLine.h"
#include <boost/assign/std/vector.hpp>
#include <boost/lexical_cast.hpp>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <time.h>

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

int nextPrimeRek(int lastPrime, int prime) {
    for (int i = 2; i < prime; ++i) {
        if ((prime % i) == 0) {
            return nextPrimeRek(lastPrime, prime + 1);
        }
    }
    return prime;
}

int nextPrime(int p) {
    return nextPrimeRek(p, p + 1);
}

void randHexString(char* buffer, int prime) {
    char nums[] = "1234567890abcdef";
    char a = nums[rand() % 15];
    char b = nums[rand() % 15];
    
    string("color ").insert(6, boost::lexical_cast< string > (a)).copy(buffer, 8, 0);
    int length = string(buffer).insert(6, boost::lexical_cast< string > (b)).copy(buffer, 8, 0);
    buffer[length] = '\0';
}

int main(int argc, char** argv) {
    char buffer[7];

    srand(time(NULL));

    system("color 2f");
    //system(string("color f").insert(6, "2"));
    runSuite();

    int prime = 1;
    while (true) {
        prime = nextPrime(prime);

        SevenSegmentLine s(prime);
        s.print((rand() % 5)+1);

        system("sleep 0.6");
        randHexString(buffer, prime);
        system(buffer);
        //cout << string("color f").insert(6, "3") << endl;
    }

    return (EXIT_SUCCESS);
}

