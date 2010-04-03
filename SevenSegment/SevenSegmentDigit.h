/*
 * Author: Lukas Elmer
 */

#ifndef _SEVENSEGMENTDIGIT_H
#define	_SEVENSEGMENTDIGIT_H

#include <iosfwd>
#include <vector>
#include <map>
#include <string>

class SevenSegmentDigit {
public:
    typedef std::map<int, int> mapType;
    typedef mapType::const_iterator mapIter;
    static mapType digitsMap;
    SevenSegmentDigit(int);
    std::vector<std::string> getStringVector(int);
private:
    int digit;
    int binaryDigit;
    void initBinaryDigit();
    void addHorizontal(bool, int, std::vector<std::string>&);
    void addVertical(bool, bool, int, std::vector<std::string>&);
};

#endif	/* _SEVENSEGMENTDIGIT_H */
