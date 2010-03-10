/* 
 * File:   SevenSegmentLine.h
 * Author: Lukas Elmer
 *
 * Created on 10. März 2010, 12:46
 */

#ifndef _SEVENSEGMENTLINE_H
#define	_SEVENSEGMENTLINE_H

#include "SevenSegmentDigit.h"

class SevenSegmentLine {
public:
    SevenSegmentLine(std::string);
    void print();
    void print(int);
private:
    std::vector<SevenSegmentDigit> digits;
};

#endif	/* _SEVENSEGMENTLINE_H */

