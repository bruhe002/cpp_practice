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
    // Read File
        std::ifstream ifile{"languages2.txt"};

    // Check if opened properly
    if (!ifile) {
        std::cerr << "File does not exist!" << std::endl;
        throw;
    }

    std::string line;
    std::vector<language> vect;
    // Loop through the lines of the file
    while(std::getline(ifile, line)) {
        // Make iss
        std::istringstream iss(line);
        language l;
        // Lets go over the words one at a time
        while(iss) {
            
            // First, the language name
            std::string lang;
            iss >> lang;
            l.lang = lang;

            // Second, designers
            // Designers can have more than one word
            // so we need to place every character in
            // an oss until we reach a number
            // that will be the date
            std::ostringstream out;
            while(!std::isdigit(iss.peek())) {
                out << iss.get();
            }

            // Insert oss string into language designer
            l.designer = out.str();

            // Third read the integer
            int date;
            iss >> date;

            l.date = date;

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