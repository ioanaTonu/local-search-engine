#ifndef FILE_MANAGER
#define FILE_MANAGER

#include <vector>
#include <string>

#define NUMBER_OF_FILES 10

class FileManager {
    protected:
    std::string path;

    public:
        FileManager(const std::string path) {this->path = path;}
        virtual std::vector<std::string> listTextFiles() = 0;
        virtual void readFiles(std::string path_to_file) = 0;
        //~FileManager();
};

#endif