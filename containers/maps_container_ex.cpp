///////////////////////////////////////////////////
// @maps_container_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <map>
#include <utility>
#include <vector>

using namespace std;

int main() {

    // Create a container map
    map<string, int> m;
    // Create a container vector
    vector<pair<string, int>> v;
    // Ask for user input
    string input{""};
    do {
        cout << "Please Enter a word(-1 to exit):\n";
        cin >> input;

        if(input != "-1"){
            m.insert(pair<string, int>(input, input.size()));
            v.push_back(pair<string, int>(input, input.size()));
        }
    } while(input != "-1");

    // Print the words
    cout << "The words list for MAP:\n";
    for(auto p : m) {
        cout << "\t\"" << p.first << "\"" << " has a size of " << p.second << endl;
    }

    // Print the words
    cout << "The words list for VECTOR:\n";
    for(auto p : v) {
        cout << "\t\"" << p.first << "\"" << " has a size of " << p.second << endl;
    }

    return 0;
}