#ifndef _SEVENSEGMENTLINE_H
#define	_SEVENSEGMENTLINE_H

#include "SevenSegmentDigit.h"
#include <iosfwd>

class SevenSegmentLine {
public:
    SevenSegmentLine(const int);
    SevenSegmentLine(const std::string);
    void print();
    void print(const int);
    void print(std::ostream&);
    void print(const int, std::ostream&);
    std::vector<std::string> getLine(const int);
private:
    std::vector<SevenSegmentDigit> digits;
    void init(std::string);
};

#endif	/* _SEVENSEGMENTLINE_H */
