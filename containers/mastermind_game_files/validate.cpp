///////////////////////////////////////////////////
// @validate.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <algorithm>
#include <string>
#include <iterator>

#include "validate.h"

using namespace std;

// Find the number of exact matches
int exact_matches(const peg_array& guess, const peg_array& solution) {
    peg_array matches;
    transform(begin(guess), end(guess), begin(solution), begin(matches),
        [](const char c1, const char c2) { return (c1 == c2) ? c1 : '\0'; }
    );

    return count_if(begin(matches), end(matches),
        [](const char c) { return c != '\0'; }
    );
}

// Find number of loose matches
int loose_matches(const peg_array& guess, const peg_array& solution) {
    string copy_guess;

    // Counter to store the number of loose matches
    int count{0};

    // Make a copy of the user's guess
    copy(begin(guess), end(guess), back_inserter(copy_guess));

    for(auto color = begin(solution); color != end(solution); ++color) {
        auto it = find_if(begin(copy_guess), end(copy_guess),
            [=](const char c) { return c == *color; }
        );

        if(it != end(copy_guess)) {
            ++count;
            copy_guess.erase(it);
        }
    }

    return count;

}