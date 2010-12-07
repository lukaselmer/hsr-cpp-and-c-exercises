#include <string>
#include <iostream>

#ifndef UPLOADFILE_H
#define	UPLOADFILE_H

class UploadFile {
public:
    UploadFile();
    UploadFile(std::string _file_upload_path, std::string _file_with_header);
    virtual ~UploadFile();
private:
    std::string file_with_header;
    std::string file_name;
    std::string file_raw;
    std::string file_upload_path;
    void processFileWithHeader();
    void saveFile();
};

#endif	/* UPLOADFILE_H */

