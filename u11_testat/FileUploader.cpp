/* 
 * File:   FileUploader.cpp
 * Author: Lukas Elmer
 * 
 * Created on 7. Dezember 2010, 17:17
 */

#include <iterator>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include "FileUploader.h"

using namespace std;

FileUploader::FileUploader() : file_upload_path("file_uploads") {
    system(string("mkdir " + file_upload_path).c_str());
}

FileUploader::~FileUploader() {
}

void FileUploader::upload(string request) {
    string file_upload_header("Content-Type: multipart/form-data; boundary=");
    int index = request.find(file_upload_header, 0);
    cout << index << endl << endl << endl;
    if (index > 0) {
        //cout << "File uploaded: " << index << endl;
        string seperator("\r\n");
        int begin_of_boundary_index = index + file_upload_header.size();
        string::iterator begin_of_boundary = request.begin() + begin_of_boundary_index;
        string boundary(begin_of_boundary, request.find(seperator, begin_of_boundary_index) - begin_of_boundary_index + begin_of_boundary);
        int begin_of_boundary_data = request.find(boundary, begin_of_boundary_index + boundary.length()) + boundary.length() + seperator.length();
        int end_of_boundary_data = request.find(boundary, begin_of_boundary_data + 1) - seperator.length() - seperator.length();
        string raw_file_with_header(request.begin() + begin_of_boundary_data, request.begin() + end_of_boundary_data);
        UploadFile(file_upload_path, raw_file_with_header); // uploadedFiles <<
    } else {
        //cout << "No file uploaded" << index << endl;
    }
}

