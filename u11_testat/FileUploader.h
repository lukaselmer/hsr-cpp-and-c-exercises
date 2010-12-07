#include <string>
#include <iostream>

#include "UploadFile.h"

#ifndef FILEUPLOADER_H
#define	FILEUPLOADER_H

class FileUploader {
public:
    FileUploader();
    virtual ~FileUploader();
    void upload(std::string request);
private:
    std::string file_upload_path;
    //std::vector<UploadFile> uploadedFiles;
};

#endif	/* FILEUPLOADER_H */

