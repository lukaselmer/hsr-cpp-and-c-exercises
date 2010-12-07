#include <string>
#include <iostream>

#include "UploadFile.h"

#ifndef FILEUPLOADER_H
#define	FILEUPLOADER_H

class FileUploader {
public:
    FileUploader(std::string request);
    virtual ~FileUploader();
private:
    UploadFile file;
};

#endif	/* FILEUPLOADER_H */

