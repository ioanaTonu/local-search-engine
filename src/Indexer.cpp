#include <iostream>
#include "../includes/Indexer.h"
#include "../includes/FileManager.h"

void Indexer::buildMap(FileManager* fileManager) {
    std::vector<std::string> vectorOfFilePath = fileManager->listTextFiles();
    std::string text;

    for(std::string i : vectorOfFilePath) {
        if (i.length() >0) {
            text = fileManager->readFiles(i);          

            if (!text.find(this->word)) {
                continue;
            } 

            int res = 0;
            int count = 0;
            while ((res = text.find(this->word, res + 1)) != std::string::npos) {
                ++count;
            }

            this->index[this->word][i] = count;
        }
        
    }
}

void Indexer::afis() {

     for (const auto& [cuvant, mapFisiere] : this->index) {
        std::cout << "Cuvant: " << cuvant << "\n";
        for (const auto& [fisier, frecventa] : mapFisiere) {
            std::cout << "  Fisier: " << fisier << ", Frecventa: " << frecventa << "\n";
        }
    }
}