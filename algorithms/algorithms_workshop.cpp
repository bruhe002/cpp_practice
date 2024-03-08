///////////////////////////////////////////////////
// @algorithm_workshop.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <random>
#include <iterator>
#include <ctime>
#include <vector>

using namespace std;

string printVectors(const vector<int> v) {
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

/*
    Exercise One: Fill a vector with 10 random integers between 0 and 1000

    @param: v - a referenced vector to be filled with random values
*/
void randFill(vector<int>& v) {
    if (v.size() != 0) {
        cerr << "Vector must be empty!\n";
    } else {
        mt19937 mt(time(nullptr));

        // use transform to fill the vector
        transform(v.begin(), v.end(), v.begin(), 
            [&mt]() { return mt(); }
        );
    }
} 

int main() {

    vector<int> vect;

    // Ex. 1
    randFill(vect);
    printVectors(vect);
    
    return 0;
}