///////////////////////////////////////////////////
// @Files.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

// Implement struct necessary
struct language {
    std::string lang;
    std::string designer;
    int date;
};

const std::string FILENAME = "languages.txt";

int main() {
    // Read data from the languages.txt
    std::ifstream ifile{FILENAME};

    // Check if opened properly
    if (!ifile) {
        std::cerr << "File does not exist!" << std::endl;
        throw;
    }

    std::string line;
    // Loop through the lines of the file
    while(std::getline(ifile, line)) {
        std::istringstream iss(line);

        // Add words to struct
        int count = 0;
        language l;
        while(iss) {
            std::string word;
            int date;
            switch(count) {
                case 0:
                    iss >> word;
                    l.lang = word;
                    break;
                case 1:
                    l.designer = word;
                    break;
                case 2:
                    iss >> date;
                    l.date = date;
            }
        }
    }
}