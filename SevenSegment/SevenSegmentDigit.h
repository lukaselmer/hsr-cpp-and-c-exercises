#ifndef _SEVENSEGMENTDIGIT_H
#define	_SEVENSEGMENTDIGIT_H

#include <iosfwd>
#include <vector>
#include <map>
#include <string>
#include <boost/assign/list_of.hpp>
#include <boost/assign/std/vector.hpp>
#include <vector>
#include <map>
#include <string>
#include <iostream>

class SevenSegmentDigit {
public:
    typedef std::vector<bool> digitVectorType;
    typedef std::map<int, digitVectorType> mapType;
    typedef mapType::const_iterator mapIter;
    static mapType digitsMap;

    static bool defineDigitsMap() {
        using namespace std;
        using namespace boost::assign;
        insert(digitsMap)
                (0, list_of(true)(true)(true)(true)(true)(true)(false))
                (1, list_of(false)(true)(true)(false)(false)(false)(false))
                (2, list_of(true)(true)(false)(true)(true)(false)(true))
                (3, list_of(true)(true)(true)(true)(false)(false)(true))
                (4, list_of(false)(true)(true)(false)(false)(true)(true))
                (5, list_of(true)(false)(true)(true)(false)(true)(true))
                (6, list_of(true)(false)(true)(true)(true)(true)(true))
                (7, list_of(true)(true)(true)(false)(false)(false)(false))
                (8, list_of(true)(true)(true)(true)(true)(true)(true))
                (9, list_of(true)(true)(true)(true)(false)(true)(true))
                (-1, list_of(false)(false)(false)(false)(false)(false)(false));
        return true;
    }

    SevenSegmentDigit(int);
    std::vector<std::string> getStringVector(int);

private:
    int digit;
    std::vector<bool> getBoolVector();
    void addHorizontal(bool, int, std::vector<std::string>&);
    void addVertical(bool, bool, int, std::vector<std::string>&);

};

#endif	/* _SEVENSEGMENTDIGIT_H */
