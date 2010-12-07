#ifndef UPLOADFILE_H
#define	UPLOADFILE_H

#include <iosfwd>
#include <string>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdlib.h>
#include <sstream>
#include <stdlib.h>

class UploadFile {
public:
    UploadFile();
    UploadFile(std::string _file_upload_path, std::string _file_with_header, int id);
    virtual ~UploadFile();
private:
    std::string file_with_header;
    std::stringstream file_name;
    std::string file_raw;
    std::string file_upload_path;
    void processFileWithHeader();
    void saveFile();
};

#endif	/* UPLOADFILE_H */

