/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 16. März 2010, 08:49
 */

#include <set>
#include <map>
#include <boost/assign.hpp>
#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std;
using namespace boost::assign;

template < class mapType >
void printPrices(const mapType & priceMap) {
    for (typename mapType::const_iterator it = priceMap.begin(); it != priceMap.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}

int main(int argc, char** argv) {
    typedef map<string, double > mapType;
    typedef mapType::const_iterator mapIter;
    mapType priceMap;
    mapType::iterator it;


    insert(priceMap)("Wein", 7.50)("Champagner", 14)("Kaffee", 2.5);

    cout << "extended contents:" << endl;
    printPrices<mapType > (priceMap);

    it = priceMap.find("Weinx");

    cout << "XXXXXXXX" << endl;
    if (it != priceMap.end()) {
        cout << it->second << endl;
    }else{
        cout << "key not found" << endl;
    }
    cout << "YYYYYYYYYYYY" << endl;

    return (EXIT_SUCCESS);
}

