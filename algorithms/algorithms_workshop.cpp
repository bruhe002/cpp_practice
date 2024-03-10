///////////////////////////////////////////////////
// @algorithm_workshop.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <fstream>
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
    cout << "Sorted array = ";
    printVectors(sorted_v);

    // Find the values
    auto up = upper_bound(sorted_v.begin(), sorted_v.end(), 455);
    return make_pair(*up, distance(up, sorted_v.end()));
}

/*
    Exercise Eight: Copy odd numbers to an output vector
    @param v: vector to copy
    @return output vector
*/
vector<double> oddVector(const vector<int>& v) {
    // copy odds into a new vector
    vector<double> d;

    copy_if(v.begin(), v.end(), back_inserter(d), 
        [](int n) { return n % 2 == 1; }
    );

    return d;
}

/*
    Exercise Nine: Sort vector in descending order
    @param v: vector to sort
*/
void sortDescending(vector<int>& v) {

    sort(v.begin(), v.end(), 
        [](int n, int m) { return n > m; }
    );
}

/*
    Exercise Ten: Randomly shuffle vector in a certain range
    @param v: vector to shuffle
*/
void shuffleMiddleVect(vector<int>& v) {
    random_shuffle(v.begin()+1, v.end()-1);
}

/*
    Exercise Eleven: Removing odds from a vector
    @param v: vector to shuffle
*/
vector<int> removeOdds(vector<int>& v) {
    vector<int> even_v;
    auto it = remove_if(v.begin(), v.end(), 
        [](int n) { return n % 2 == 1; }
    );
    
    copy(v.begin(), it, back_inserter(even_v));

    return even_v;
}

/*
    Exercise Twelve: Writing elements to file
    @param v: vector to write
*/
void writeToFile(const vector<int>& v) {
    ofstream EvenFile("even_vector.txt");
    ostream_iterator<int> iter(EvenFile, ", ");

    copy(v.begin(), v.end(), iter);

    EvenFile.close();

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
    cout << "Normalized vector = ";
    printVectors(normalize(vect));

    // Ex. 7
    pair<int,int> p = sortVector455(vect);
    cout << "First Element greater than 455 = " << p.first << endl;
    cout << "Number of elements greater than 455 = " << p.second << endl;

    // Ex. 8
    cout << "Odd vectors = ";
    printVectors(oddVector(vect));

    // Ex. 9
    sortDescending(vect);
    cout << "Sorted Descending Array = ";
    printVectors(vect);

    // Ex. 10
    shuffleMiddleVect(vect);
    cout << "Random shuffle array(except first and last) = ";
    printVectors(vect);

    // Ex. 11
    vector<int> even_v(removeOdds(vect));
    cout << "Odds Removed = ";
    printVectors(even_v);

    // Ex. 12
    cout << "Writing to a file..." << endl;
    writeToFile(even_v);
    
    return 0;
}