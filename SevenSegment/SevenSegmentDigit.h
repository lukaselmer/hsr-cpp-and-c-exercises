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
    std::vector<std::string> getStringVector();
private:
    int digit;
    std::string getHorizontal(bool, int);
    std::string getVertical(bool, bool, int);
};

#endif	/* _SEVENSEGMENTDIGIT_H */

