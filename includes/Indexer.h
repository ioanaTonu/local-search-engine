#ifndef INDEXER_HEADER
#define INDEXER_HEADER

#include <map>
#include <string>
#include "FileManager.h"

class Indexer{
    private:
    std::map<std::string, std::map<std::string, int>> index; // <word , <path, frequency>>
    std::string word;

    public:
    Indexer(std::string word) {this->word = word;};
    void buildMap(FileManager* fileManager);
    void afis(); // created to be used just if it is needed to print the map values
};

#endif