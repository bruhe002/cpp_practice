///////////////////////////////////////////////////
// @algs1.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vect(const vector<int>& v) {
    for (auto n : v) {
        cout << n << " ";
    }

    cout << endl;
}

int main() {

    // First part of the assignment
    vector<int> num_vect = {1,2,3,4,5};

    print_vect(num_vect);

    // Sort the vector using a lambda expression
    sort(begin(num_vect), end(num_vect), [](int i, int j) {return i > j;});

    // Print the vector again
    print_vect(num_vect);
    return 0;
}