#ifndef FACTORY_FILE_MANAGER
#define FACTORY_FILE_MANAGER

#include "TextFileManager.h"
#include "FileManager.h"
#include <stdexcept>
#include <memory>

enum class FileManagerTypes {
    HTML, TXT
};

class FactoryFileManager {
    std::string path;

    public:
    FactoryFileManager(std::string newPath): path(newPath) {}; 
    std::shared_ptr<FileManager> build(FileManagerTypes type) {
        switch (type)
        {
        case FileManagerTypes::HTML:
            return nullptr;
            break;
        
        case FileManagerTypes::TXT:
            return std::shared_ptr<FileManager> (new TextFileManager(this->path));
            break;
        
        default:
            throw std::invalid_argument("This file type is not supported.");
            break;
        }
    };
};

#endif