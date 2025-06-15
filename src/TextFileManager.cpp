#include "../includes/TextFileManager.h"
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

std::vector<std::string> TextFileManager::listTextFiles() {    
    std::vector<std::string> vectorOfFilePath(NUMBER_OF_FILES);

    for (const auto & entry : fs::directory_iterator(path)) {
        if (entry.path().extension().string() == ".txt") {
            vectorOfFilePath.push_back(entry.path().string());
        }
    }

    return vectorOfFilePath; // inca nu stiu de ce, dar mi se salveaza niste path-uri vide; tb pus if (i.length() > 0)
}

std::string TextFileManager::readFiles(std::string pathToFile) {
    std::string line;
    std::string text = "";
    std::ifstream myfile (pathToFile);
    if (myfile.is_open()) {
        while ( std::getline (myfile,line) ) {
            text += " ";
            text += line;
        }
            myfile.close();
            return text;
    }

    else {
        std::cout << "Unable to open file"; 
        return 0;}
}