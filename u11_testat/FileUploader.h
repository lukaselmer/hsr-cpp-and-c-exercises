#ifndef FILEUPLOADER_H
#define	FILEUPLOADER_H

#include <string>
#include <vector>
#include <iosfwd>
#include <iterator>
#include <fstream>
#include <stdlib.h>
#include <sstream>
#include <dirent.h>
#include <errno.h>
#include <string.h>

#include "UploadFile.h"

class FileUploader {
public:
    FileUploader();
    virtual ~FileUploader();
    void upload(std::string request, int id);
    std::vector<std::string> getUploadedFilesList();
    std::string getUploadFile(std::string filename);
private:
    std::string file_upload_path;
    std::string decode_url(std::string real_url);
    //std::vector<UploadFile> uploadedFiles;
};

#endif	/* FILEUPLOADER_H */

