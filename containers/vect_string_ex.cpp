///////////////////////////////////////////////////
// @vector_string_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

int main() {

    // Obtain string from User
    string input{""};
    vector<string> strings;

    // Loop through input
    do {
        cout << "Please enter a string: (Enter '-1' to quit)\n";

        getline(cin, input);

        if (input != "-1") {
            strings.push_back(input);
        }
    } while(input != "-1");

    // Display the input
    cout << "Here is the a list of your strings:\n";
    for(int i = 0; i < strings.size(); ++i) {
        cout << i + 1 << ": " << strings[i] << endl;
    }

    return 0;
}