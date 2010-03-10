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
    SevenSegmentLine l = SevenSegmentLine("1");
    //l.print();
    //l.print(5);
    l.print(5);
    l.print(1);
    //    l = SevenSegmentLine("123");
    //    l.print();
    //    l = SevenSegmentLine("88");
    //    l.print();
    //    l = SevenSegmentLine("0987654321");
    //    l.print();

    return (EXIT_SUCCESS);
}

