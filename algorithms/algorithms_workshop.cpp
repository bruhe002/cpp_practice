///////////////////////////////////////////////////
// @algorithm_workshop.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <experimental/iterator>
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
    copy(v.begin(), v.end(), experimental::make_ostream_joiner(EvenFile, ", ")); 

    EvenFile.close();
}

string normalize_str(const string& s) {
    string ret_str{""};

    copy_if(s.begin(), s.end(), back_inserter(ret_str), 
        [](char s) { return isalpha(s); }
    );

    transform(ret_str.begin(), ret_str.end(), ret_str.begin(), 
        [](char c) { return tolower(c); }
    );

    return ret_str;
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

    // Ex. 13
    // Read words file
    ifstream WordsFile{"words.txt"};
    istream_iterator<string> eos;
    istream_iterator<string> f_iter(WordsFile);

    // Copy to string
    vector<string> words_v{f_iter, eos};
    
    vector<string> new_words;
    // Make all same case
    transform(words_v.begin(), words_v.end(), back_inserter(new_words), normalize_str);

    sort(new_words.begin(), new_words.end());

    auto it = unique(new_words.begin(), new_words.end());

    vector<string> unique_words;
    copy(new_words.begin(), it, back_inserter(unique_words));
    cout << "UNIQUE STRING:" << endl;
    printVectors(unique_words);

    // Ex. 14
    cout << "words.txt # of words = " << words_v.size() << endl;
    WordsFile.close();
    ifstream WordsFile_2{"words.txt"};
    // Ex. 15
    istreambuf_iterator<char> c_eos, fc_iter(WordsFile_2);
    string s{fc_iter, c_eos};

    int lines = count(s.begin(), s.end(), '\n');
    cout << "words.txt # of lines = " << lines << endl;
    
    // Ex 16
    string all_char{""};
    copy_if(s.begin(), s.end(), back_inserter(all_char), 
        [](char c) { return isalpha(c); }
    );

    cout << "words.txt # of char = " << all_char.size() << endl;

    WordsFile_2.close();

    // Ex 17
    ifstream WordsFile_3("words.txt");
    ifstream SecondWordsFile("words2.txt");

    istream_iterator<string> wf1(WordsFile_3), wf2(SecondWordsFile);

    vector<string> words_1{wf1, eos};
    vector<string> words_2{wf2, eos};

    vector<string> new_words_1;
    vector<string> new_words_2;

    transform(words_1.begin(), words_1.end(), back_inserter(new_words_1), normalize_str);
    transform(words_2.begin(), words_2.end(), back_inserter(new_words_2), normalize_str);
    sort(new_words_1.begin(), new_words_1.end());
    sort(new_words_2.begin(), new_words_2.end());
    

    it = set_intersection(new_words_1.begin(), new_words_1.end(), 
                          new_words_2.begin(), new_words_2.end(), 
                          new_words_1.begin()
    );

    vector<string> inter_words;  
    copy(new_words_1.begin(), it, back_inserter(inter_words));
    cout << "words.txt && words2.txt = ";
    printVectors(inter_words);  

    return 0;
}