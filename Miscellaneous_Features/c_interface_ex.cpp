/**
 * Author: Eric Bruhns
 */


#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

extern "C" {
#include "c_arr.h"
}

void printSet() {
    int odd_ints[] = {1,3,5,7,9};
    std::set<int> my_set(odd_ints, odd_ints + 5);

    std::vector<int> v;
    std::copy(my_set.begin(), my_set.end(), std::back_inserter(v));
    // Print set using C function
    display_array(v.data(), v.size());
}

void printMap() {
    std::map<int,int> my_map;
    my_map[1] = 2;
    my_map[2] = 4;
    my_map[3] = 6;
    my_map[4] = 8;
    std::vector<int> keys;
    std::vector<int> values;

    for(auto el: my_map) {
        keys.push_back(el.first);
        values.push_back(el.second);
    }

    std::cout << "Keys: ";
    display_array(keys.data(), keys.size());

    std::cout << "Values: ";
    display_array(values.data(), values.size());
}

int main() {
    // Print the sets
    printSet();

    // Print the map
    printMap();

    return 0;
}


