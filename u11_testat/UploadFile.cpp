#include "UploadFile.h"

using namespace std;

UploadFile::UploadFile() : file_upload_path(""), file_name(""), file_raw(""), file_with_header("") {
}

UploadFile::UploadFile(string _file_upload_path, string _file_with_header, int id) : file_upload_path(_file_upload_path), file_name(""), file_raw(""), file_with_header(_file_with_header) {
    file_name << id << "_";
    processFileWithHeader();
    saveFile();
}

UploadFile::~UploadFile() {
}

void UploadFile::processFileWithHeader() {
    string double_seperator("\r\n\r\n");
    string header(file_with_header.begin(), file_with_header.begin() + file_with_header.find(double_seperator));
    string filename_pattern_start("filename=\"");
    int index_of_filename_begin = header.find(filename_pattern_start) + filename_pattern_start.length();
    string filename_pattern_end("\"");
    string original_file_name(header.begin() + index_of_filename_begin, header.begin() + header.find(filename_pattern_end, index_of_filename_begin + 1));
    file_raw = string(file_with_header.begin() + file_with_header.find(double_seperator) + double_seperator.length(), file_with_header.end());
    file_name << original_file_name;
}

void UploadFile::saveFile() {
    ofstream f;
    f.open(string(file_upload_path + "/" + file_name.str()).c_str());
    f << file_raw;
    f.close();
}
