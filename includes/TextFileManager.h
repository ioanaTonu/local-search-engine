#ifndef TEXT_FILE_MANAGER
#define TEXT_FILE_MANAGER

#include <vector>
#include <string>
#include "FileManager.h"

class TextFileManager : public FileManager{
    public:
    TextFileManager(const std::string path):FileManager(path){}
    std::vector<std::string> listTextFiles();
    std::string readFiles(std::string pathToFile);
    //~TextFileManager();
};

#endif