/* 
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 29. April 2010, 10:25
 */

#include <fstream>
#include <iostream>
#include <boost/smart_ptr.hpp>

using namespace std;
using namespace boost;

typedef shared_ptr<std::ostream> FstrPtr;

FstrPtr createFile() {
    FstrPtr file(new ofstream("dudu.txt", ios::app));
    if (!*file) throw "file unwritable";
    // don't return unusable file
    return file;
}

int main() {
    try {
        FstrPtr file1 = createFile();
        (*file1) << "Hello world\n";
    } catch (char const *&e) {
        cerr << e << endl;
    }
}
