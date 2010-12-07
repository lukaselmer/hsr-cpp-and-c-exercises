#include "HttpRequest.h"
#include "FileUploader.h"
#include "SocketIO.h"

using namespace std;

HttpRequest::HttpRequest(const SocketIO & _sio, const FileUploader & _file_uploader, int _counter) :
request(""), sio(_sio), file_uploader(_file_uploader), counter(_counter), response(""), normal_request(false) {
    request = sio.readlines();
    sio.closeReadSocket();

    if (quitRequested()) return;
    file_uploader.upload(request, counter);
    if (!fileRequest()) normalRequest();
}

HttpRequest::~HttpRequest() {
}

bool HttpRequest::quitRequested() {
    return request.find("GET /quit HTTP/1.1\r\n", 0) == 0;
}

bool HttpRequest::fileRequest() {
    string start_pattern("GET /files/");
    int filename_start = request.find(start_pattern, 0), filename_end = request.find(" HTTP/1.1", 0);
    string ret;
    if (filename_start == 0 && filename_end > 0) {
        ret = file_uploader.getUploadFile(string(request.begin() + filename_start + start_pattern.length(), request.begin() + filename_end));
        if (ret != string("")) {
            response = getHeaders(ret.length(), false) + ret;
            return true;
        }
    }
    return false;
}

void HttpRequest::normalRequest() {
    stringstream ss1, ss2;
    ss1 << "<html><head></head><body><a href='/'>Reload</a><br/><h1>Hello <i>" << sio.getPeerInfo() << "</i></h1>" <<
            "<div>This is request <b>#" << counter << "</b>.</div>" <<
            "<div>This is your request:</div>" <<
            "<pre>" << filterFileUpload() << "</pre>" <<
            "<form action=\"/\" method=\"post\" enctype=\"multipart/form-data\">" <<
            "File upload: <input name=\"Datei\" type=\"file\" /><input type=\"submit\" value=\"Upload!\" />" <<
            "</form>" << "<br/>" << generateUploadedFilesList() << "<br/>" <<
            "<a href='/quit'>Quit server</a><br/>" << "</body></html>\r\n";
    ss2 << getHeaders(ss1.str().length(), true) << ss1.str();
    normal_request = true;
    response = ss2.str();
}

bool HttpRequest::wasNormalRequest() {
    return normal_request;
}

string HttpRequest::getResponse() {
    return response;
}

string HttpRequest::getHeaders(int len, bool add_content_type) {
    stringstream ss;
    ss << "HTTP/1.1 200 OK\r\n";
    ss << "Server: LukesC++Server\r\n";
    ss << "Content-Length: " << len << "\r\n";
    ss << "Connection: close\r\n";
    if (add_content_type) ss << "Content-Type: text/html\r\n";
    ss << "\r\n";
    return ss.str();
}

string HttpRequest::filterFileUpload() {
    string double_seperator("\r\n\r\n");
    int header_end = request.find(double_seperator) - double_seperator.length();
    if (header_end > 0) {
        return string(request.begin(), request.begin() + header_end);
    }
    return request;
}

string HttpRequest::generateUploadedFilesList() {
    vector<string> files = file_uploader.getUploadedFilesList();
    vector<string>::iterator it(files.begin());
    stringstream ss;
    while (it != files.end()) {
        ss << "<a href='/files/" << (*it) << "'>" << (*it) << "</a><br/>" << endl;
        ++it;
    }
    return ss.str();
}

//string HttpRequest::generateResponse(string request, string clintinfo, int counter, FileUploader file_uploader) {
//
//}
