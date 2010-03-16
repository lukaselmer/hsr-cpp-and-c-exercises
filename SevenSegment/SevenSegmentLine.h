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
    void print(std::ostream &out);
    void print(int, std::ostream &out);
private:
    std::vector<SevenSegmentDigit> digits;
    void init(std::string);
};

#endif	/* _SEVENSEGMENTLINE_H */
