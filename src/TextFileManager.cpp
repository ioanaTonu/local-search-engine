#include "../includes/TextFileManager.h"
#include <iostream>
#include <fstream>
#include <filesystem>
namespace fs = std::filesystem;

std::vector<std::string> TextFileManager::listTextFiles() {    
    std::vector<std::string> vector_of_file_path(NUMBER_OF_FILES);

    for (const auto & entry : fs::directory_iterator(path)) {
        if (entry.path().extension().string() == ".txt") {
            vector_of_file_path.push_back(entry.path().string());
        }
    }

    return vector_of_file_path; // inca nu stiu de ce, dar mi se salveaza niste path-uri vide; tb pus if (i.length() > 0)
}

void TextFileManager::readFiles(std::string path_to_file) {
    std::string line;
    std::ifstream myfile (path_to_file);
    if (myfile.is_open()) {
        while ( std::getline (myfile,line) ) {
            std::cout << line << '\n'; // va tb modificat in functie de cerinta
        }
            myfile.close();
    }

    else 
        std::cout << "Unable to open file"; 
}