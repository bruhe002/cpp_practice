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

template<typename T>
void printVectors(const vector<T> v) {
    copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
    // for (auto e : v) {
    //     cout << e << ", ";
    // }
    cout << endl;
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
    Exercise Two: Find Maximum value of the vector
    Exercise Three: Find Maximum Value Index

    @param: v - vector to be searched
    @return: pair<int,int> - first value will be maximum value, second value will be index
*/
pair<int, int> findMax(const vector<int>& v) {
    if (v.size() == 0) {
        cerr << "There is no max in this vector\n";
        return make_pair(-1,-1);
    } else {
        auto max_num = max_element(v.begin(), v.end());
        int max_idx = distance(v.begin(), max_num); 
        return make_pair(*max_num, max_idx);
    }
}

/*
    Exercise Four: Sum the elements of the vectors

    @param v: vector to sum
    @return: int
*/
int sumVector(const vector<int>& v) {
    return accumulate(v.begin(), v.end(), 0);
}

/*
    Exercise Five: Count the number of odd numbers
    @param v: vector to parse
    @return odd number count
*/
int countOdds(const vector<int> v) {
    vector<int> new_v;

    copy_if(v.begin(), v.end(), back_inserter(new_v),
        [&new_v](int n) { return n % 2 == 1; }
    );

    return new_v.size();
}
/*
    Exercise Six: Normalize the vector
    @param v: vector to normalize
    @return a vector with normalized results
*/
vector<double> normalize(const vector<int>& v) {
    vector<double> ret_v;

    pair<int, int> max_values = findMax(v);
    copy(v.begin(), v.end(), back_inserter(ret_v));
    transform(ret_v.begin(), ret_v.end(), ret_v.begin(), 
        [&max_values](double d) { return d / max_values.first; }
    );

    return ret_v;
}

/*
    Exercise Seven: Sort the Vector and find elements greater than 455
    @param v: vector to sort
    @return pair with first element greater than 455 and num of elements greater than 455
*/
pair<int, int> sortVector455(const vector<int>& v) {
    // sort vector into copy
    vector<int> sorted_v;
    copy(v.begin(), v.end(), back_inserter(sorted_v));
    sort(sorted_v.begin(), sorted_v.end());
}

int main() {

    vector<int> vect(10);

    // Ex. 1
    randFill(vect);
    printVectors(vect);

    // Ex. 2
    // Ex. 3
    pair<int, int> max_values = findMax(vect);
    if(max_values.first != -1) {
        cout << "Max Value = " << max_values.first << endl;
        cout << "Max Value Index = " << max_values.second << endl;
    }

    // Ex. 4
    cout << "Sum of values = " << sumVector(vect) << endl;

    // Ex. 5
    cout << "Num of Odd Numbers = " << countOdds(vect) << endl;

    // Ex. 6
    printVectors(normalize(vect));

    return 0;
}