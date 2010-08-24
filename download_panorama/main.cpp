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

void download_panorama(ostream & os, string const & foldername, string const & url, string const & filename) {
    os << url << endl;
    os << "Retrieving " << url << endl;
    string command("start /LOW /B curl --silent -o " + foldername + "/" + filename + " " + url);
    os << "Executing: " << command << endl;
    system(command.c_str());
}

bool file_exists(string filename) {
    ifstream f(filename.c_str());
    if (f.is_open() == true) {
        f.close();
        return true;
    } else {
        return false;
    }

}

int main(int argc, char** argv) {
    cout << "Bitte Log-Datei angeben (e.g. c:/panorama.log.txt): ";
    string logname, foldername;
    cin >> logname;
    if (logname == string("x")) logname = "c:/panorama.log.txt";
    while (file_exists(logname)) {
        cout << "Datei existiert bereits! ";
        cout << "Bitte Output-Datei angeben (e.g. c:/output.txt): ";
        cin >> logname;
    }
    cout << "Bitte einen leeren, existierender Ordner angeben (default c:/panorama): ";
    cin >> foldername;
    if (foldername == string("x")) foldername = "c:/panorama";
    cout << "Bitte warten, es wird nach " << foldername << " heruntergeladen (Log-Datei: " << logname << ")..." << endl;
    ofstream file(logname.c_str());
    for (int i = 0; i <= 1504; ++i) {
        for (int k = 0; k <= 314; ++k) {
            stringstream filename;
            filename << i << "_tile_" << k << ".jpg";
            stringstream ss;
            ss << "http://www.hdviewpano.com/HdView/Panos/P006061/l_9/c_" << i << "/tile_" << k << ".jpg";
            download_panorama(file, foldername, ss.str(), filename.str());
        }
    }
    file.close();
    cout << "...fertig! " << logname << " wurde generiert!" << endl << endl;
    return 0;
}

