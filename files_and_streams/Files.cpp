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
#include <vector>
#include <limits>

// Implement struct necessary
struct language {
    std::string lang;
    std::string designer;
    int date;
};

std::string to_string(const language& l) {
    std::ostringstream oss;
    oss << l.lang << ", " << l.designer << ", " << l.date << std::endl;

    return oss.str();     
}

int main() {
    // Read data from the languages.txt
    std::ifstream ifile{"languages.txt"};

    // Check if opened properly
    if (!ifile) {
        std::cerr << "File does not exist!" << std::endl;
        throw;
    }

    std::string line;
    std::vector<language> vect;
    // Loop through the lines of the file
    while(std::getline(ifile, line)) {
        std::istringstream iss(line);
        // Add words to struct
        int count = 0;
        language l;
        std::string word;
        int date;
        while(!iss.eof()) {
            switch(count) {
                case 0:
                    iss >> word;
                    l.lang = word;
                    break;
                case 1:
                    iss >> word;
                    l.designer = word;
                    break;
                case 2:
                    iss >> date;
                    l.date = date;
                    break;
            }

            count++;
        }

        // push language to vector
        vect.push_back(l);
    }

    // Close file 
    ifile.close();

    // Print the vector
    for (auto l : vect) {
        std::cout << to_string(l);
    }
}