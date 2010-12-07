/*
 * File:   UploadFile.cpp
 * Author: Lukas Elmer
 *
 * Created on 7. Dezember 2010, 18:49
 */

#include <iosfwd>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <sstream>

#include "UploadFile.h"

using namespace std;

UploadFile::UploadFile() : file_upload_path(""), file_name(""), file_raw(""), file_with_header("") {
}

UploadFile::UploadFile(string _file_upload_path, string _file_with_header) : file_upload_path(_file_upload_path), file_name(""), file_raw(""), file_with_header(_file_with_header) {
    processFileWithHeader();
    saveFile();
}

UploadFile::~UploadFile() {
}

void UploadFile::processFileWithHeader() {
    //file_data_with_header;
    string double_seperator("\r\n\r\n");
    file_raw = string(file_with_header.begin() + file_with_header.find(double_seperator) + double_seperator.length(), file_with_header.end());
    //cout << "ZZZZZZZZZZZZZZ" << endl << file_with_header.find("\n") << endl << endl << file_raw << endl << endl << endl;
    file_name = "xxxx.png";
}

void UploadFile::saveFile() {
    ofstream f;
    f.open(string(file_upload_path + "/" + file_name).c_str());
    f << file_raw;
    f.close();
}
