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
    do {
        cout << "Please enter a string: (Enter '-1' to quit)\n";

        getline(cin, input);

        if (input != "-1") {
            strings.push_back(input);
        }
    } while(input != "-1");

    cout << "Here is the a list of your strings:\n";
    for(int i = 0; i < strings.size();) {
        cout << ++i << ": " << strings[i] << endl;
    }

    return 0;
}