#ifndef HTTPREQUEST_H
#define	HTTPREQUEST_H

#include <string>

#include "FileUploader.h"
#include "SocketIO.h"

class HttpRequest {
public:
    HttpRequest(const SocketIO & _sio, const FileUploader & _file_uploader, int _counter);
    virtual ~HttpRequest();
    bool quitRequested();
    std::string getResponse();
    bool wasNormalRequest();
private:
    std::string request;
    std::string response;
    SocketIO sio;
    FileUploader file_uploader;
    int counter;
    bool normal_request;

    bool fileRequest();
    void normalRequest();
    std::string filterFileUpload();
    std::string getHeaders(int len, bool add_content_type);
    std::string generateUploadedFilesList();
};

#endif	/* HTTPREQUEST_H */

