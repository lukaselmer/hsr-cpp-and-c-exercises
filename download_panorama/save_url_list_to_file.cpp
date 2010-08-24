/*
 * File:   main.cpp
 * Author: Lukas Elmer
 *
 * Created on 24. August 2010, 16:51
 */

#include <string>
#include <sstream>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <iosfwd>

using namespace std;
//using namespace boost;

//void download_panorama(ostream & os, string url) {
//    os << url << endl;
//}
//
//bool file_exists(string filename) {
//    ifstream f(filename.c_str());
//    if (f.is_open() == true) {
//        f.close();
//        return true;
//    } else {
//        return false;
//    }
//
//}
//
//int main(int argc, char** argv) {
//    cout << "Bitte Output-Datei angeben (bsp c:/output.txt): ";
//    string name;
//    cin >> name;
//    while (file_exists(name)) {
//        cout << "Datei existiert bereits! ";
//        cout << "Bitte Output-Datei angeben (bsp c:/output.txt): ";
//        cin >> name;
//    }
//    cout << "Bitte warten, " << name << " wird generiert..." << endl;
//    ofstream file(name.c_str());
//    for (int i = 0; i <= 1504; ++i) {
//        for (int k = 0; k <= 314; ++k) {
//            stringstream ss;
//            ss << "http://www.hdviewpano.com/HdView/Panos/P006061/l_9/c_" << i << "/tile_" << k << ".jpg";
//            download_panorama(file, ss.str());
//        }
//    }
//    file.close();
//    cout << "...fertig! " << name << " wurde generiert!" << endl << endl;
//    return 0;
//}


