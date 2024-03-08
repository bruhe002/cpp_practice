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

void printVectors(const vector<int> v) {
    copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
    // for (auto e : v) {
    //     cout << e << ", ";
    // }
    // cout << endl;
}

/*
    Exercise One: Fill a vector with 10 random integers between 0 and 1000

    @param: v - a referenced vector to be filled with random values
*/
void randFill(vector<int>& v) {
    if (v.size() != 10) {
        cerr << "Vector must have a size of 10!\n";
    } else {
        mt19937 mt(time(nullptr));
        std:: uniform_int_distribution d(0, 1000);
        // use transform to fill the vector
        transform(v.begin(), v.end(), v.begin(), 
            [&mt, &d](int n) { return d(mt); }
        );
    }
}

/*
    Exercise two: Find Maximum value of the vector

    @param: v - vector to be searched
*/
int findMax(const vector<int>& v) {
    if (v.size() == 0) {
        cerr << "There is no max in this vector\n";
        return -1;
    } else {
        auto max = max_element(v.begin(), v.end());

        return *max;
    }
}

int main() {

    vector<int> vect(10);

    // Ex. 1
    randFill(vect);
    printVectors(vect);

    // Ex. 2
    int max_value = findMax(vect);
    if(max_value > -1) {
        cout << "Max Value: = " << max_value << endl;
    }

    return 0;
}