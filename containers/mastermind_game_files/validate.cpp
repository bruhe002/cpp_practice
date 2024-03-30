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
    ;)

    return count_if(begin(matches), end(matches),
        [](const char c) { return c != '\0'; }
    );
}