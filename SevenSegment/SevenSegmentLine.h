/* 
 * File:   SevenSegmentLine.h
 * Author: Lukas Elmer
 *
 * Created on 10. März 2010, 12:46
 */

#ifndef _SEVENSEGMENTLINE_H
#define	_SEVENSEGMENTLINE_H

#include "SevenSegmentDigit.h"
#include <iosfwd>

class SevenSegmentLine {
public:
    SevenSegmentLine(int);
    SevenSegmentLine(std::string);
    void print();
    void print(int);
private:
    std::vector<SevenSegmentDigit> digits;
    void init(std::string);
};

#endif	/* _SEVENSEGMENTLINE_H */
