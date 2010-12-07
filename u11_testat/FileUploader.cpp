#include "FileUploader.h"

using namespace std;

FileUploader::FileUploader() : file_upload_path("file_uploads") {
    system(string("mkdir " + file_upload_path).c_str());
}

FileUploader::~FileUploader() {
}

string FileUploader::getUploadFile(string filename) {
    filename = decode_url(filename);
    string line;
    ifstream file((file_upload_path + "/" + filename).c_str());
    stringstream ss;
    if (file.is_open()) {
        bool first_time = true;
        while (file.good()) {
            if (first_time) {
                first_time = false;
            } else {
                ss << endl;
            }
            getline(file, line);
            ss << line;
        }
        file.close();
    }
    return ss.str();
}

string FileUploader::decode_url(string real_url) {
    std::string s2;
    s2.reserve(real_url.size());
    for (size_t i = 0; i < real_url.size(); i++) {
        if (real_url[i] == '%') {
            if (!strncmp(&real_url[i], "%3A", 3))
                s2 += ':';
            else if (!strncmp(&real_url[i], "%20", 3))
                s2 += ' ';
            else if (!strncmp(&real_url[i], "%2F", 3))
                s2 += '/';
            else if (!strncmp(&real_url[i], "%3F", 3))
                s2 += '?';
            else if (!strncmp(&real_url[i], "%3D", 3))
                s2 += '=';
            else if (!strncmp(&real_url[i], "%26", 3))
                s2 += '&';
            else if (!strncmp(&real_url[i], "%25", 3))
                s2 += '%';
            i += 2;
        } else
            s2 += real_url[i];
    }
    return s2;
}

vector<string> FileUploader::getUploadedFilesList() {
    string dir(file_upload_path);
    vector<string> files;
    DIR *dp;
    struct dirent *dirp;
    if ((dp = opendir(dir.c_str())) == NULL) {
        cout << "Error(" << errno << ") opening " << dir << endl;
        return files;
    }
    while ((dirp = readdir(dp)) != NULL) {
        if (dirp->d_type == DT_REG) {
            files.push_back(string(dirp->d_name));
        }
    }
    closedir(dp);
    return files;
}

void FileUploader::upload(string request, int id) {
    string file_upload_header("Content-Type: multipart/form-data; boundary=");
    int index = request.find(file_upload_header, 0);
    if (index > 0) {
        string seperator("\r\n");
        int begin_of_boundary_index = index + file_upload_header.size();
        string::iterator begin_of_boundary = request.begin() + begin_of_boundary_index;
        string boundary(begin_of_boundary, request.find(seperator, begin_of_boundary_index) - begin_of_boundary_index + begin_of_boundary);
        int begin_of_boundary_data = request.find(boundary, begin_of_boundary_index + boundary.length()) + boundary.length() + seperator.length();
        int end_of_boundary_data = request.find(boundary, begin_of_boundary_data + 1) - seperator.length() - seperator.length();
        string raw_file_with_header(request.begin() + begin_of_boundary_data, request.begin() + end_of_boundary_data);
        UploadFile(file_upload_path, raw_file_with_header, id);
    } else {
        // No file uploaded
    }
}

