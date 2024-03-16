///////////////////////////////////////////////////
// @deque_string_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <deque>

using namespace std;

int main() {

    // Obtain string from User
    string input{""};
    deque<string> strings;

    // Loop through input
    do {
        cout << "Please enter a string: (Enter '-1' to quit)\n";

        getline(cin, input);

        if (input != "-1") {
            strings.push_back(input);
        }
    } while(input != "-1");

    // Display the input
    cout << "Here is the vector of your strings:\n";
    for(int i = 0; i < strings.size(); ++i) {
        auto it = strings.begin();
        advance(it, i);
        cout << i + 1 << ": " << *it << endl;
    }

    return 0;
}