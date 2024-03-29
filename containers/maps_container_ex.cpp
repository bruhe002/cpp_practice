///////////////////////////////////////////////////
// @maps_container_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <utility>

using namespace std;

int main() {

    // Create a container map
    map<string, int> m;
    // Ask for user input
    string input{""};
    do {
        cout << "Please Enter a word:\n";
        cin >> input;

        if(input != "-1"){
            m.insert(pair<string, int>(input, input.size()));
        }
    } while(input != "-1");

    for(auto p : m) {
        cout << "The words you entered:\n";
        cout << p.first << " has a size of " << p.second << endl;
    }

    return 0;
}