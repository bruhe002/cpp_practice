///////////////////////////////////////////////////
// @string_function.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <string>
#include <cctype>

// Define exclaim function

/*
    Takes a string and returns the modified string with
    all punctuation switched with a '!'

    @param old_str: string to be modified
    @return old_str
*/

std::string exclaim(std::string& old_str) {
    // Loop through the string
    for(auto& c : old_str) {
        if(ispunct(c)) {
            c = '!';
        }
    }

    return old_str;
}
