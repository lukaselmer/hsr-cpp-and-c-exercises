/* 
 * File:   SevenSegmentDigit.h
 * Author: Lukas Elmer
 *
 * Created on 10. März 2010, 12:45
 */

#ifndef _SEVENSEGMENTDIGIT_H
#define	_SEVENSEGMENTDIGIT_H

#include <vector>
#include <string>

class SevenSegmentDigit {
public:
    SevenSegmentDigit(int);
    std::vector<std::string> getStringVector(int);
private:
    int digit;
    std::vector<bool> getBoolVector();
    void addHorizontal(bool, int, std::vector<std::string>&);
    void addVertical(bool, bool, int, std::vector<std::string>&);
};

#endif	/* _SEVENSEGMENTDIGIT_H */

