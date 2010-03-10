/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 10. März 2010, 11:25
 */

#include "SevenSegmentDigit.h"
#include "SevenSegmentLine.h"
#include <stdlib.h>

/*
 * 
 */
int main(int argc, char** argv) {
    SevenSegmentLine l = SevenSegmentLine("784");
    l.print(5);
    l.print(2);
    l = SevenSegmentLine("123");
    l.print();
    l = SevenSegmentLine("079 666 55 77");
    l.print(3);
    l = SevenSegmentLine("0987654321");
    l.print(2);
    l.print(6);

    return (EXIT_SUCCESS);
}
