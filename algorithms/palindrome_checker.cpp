///////////////////////////////////////////////////
// @palindrome_checker.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string normalize(const string& s) {
    string retval{""};

    // Remove any space/punctuation/digits
    copy_if(cbegin(s), cend(s), back_inserter(retval),
        [](char c) { return isalpha(c); }
    );
    // convert all remaining characters to the same case
    transform(begin(retval), end(retval), begin(retval),
        [](char c) { return tolower(c); }
    );

    return retval;
}

int main() {
    string s{""};
    cout << "Please enter your palindrome: ";
    getline(cin, s);
    
    // First we normalize the string
    string pal{normalize(s)};

    // call std::mismatch to compare the string to the reversed string
    // use a reverse iterator
    // return value is a pair of iterators
    auto p = mismatch(cbegin(pal), cend(pal), crbegin(pal));

    // If both are equal to their respective ends, then no mismatch
    if(p.first == cend(pal) && p.second == crend(pal)) {
        cout << "\"" << s << "\"" << " is a palindrome!" << endl;
    }
    else {
        // There is a mismatch
        cout << "\"" << s << "\"" << " is not a palindrome..." << endl;

        // Make a copy of the string up to mismatch in the reverse string
        string outstr;
        copy(cbegin(pal), p.second.base(), back_inserter(outstr));
        cout << "'" << *p.first << "'" << " does not match " << "'" << *p.second << "'";
        cout << " at \"" << outstr << "\"" << endl;
    }
}