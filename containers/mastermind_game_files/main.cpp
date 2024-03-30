///////////////////////////////////////////////////
// @main.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <random>

#include "constants.h"
#include "validate.h"
#include "inputs.h"

using namespace std;

peg_array populate() {
    peg_array code{0};
    static mt19937 mt;
    uniform_int_distribution<int> ud(0, constants::ncolors-1);

    generate(begin(code), end(code),
        [&]() { return constants::colors[ud(mt)]; }
    );
}

int main() {
    peg_array pegs = populate();

    bool winner{false};
    for(int i = 0; i < constants::nturns; ++i) {
        peg_array input = get_input();

        auto exact = exact_matches(input, pegs);
        auto loose = loose_matches(input, pegs) - exact;
        cout << exact << " exact match(es)\n";
        cout << loose << " near match(es)\n";

        if (exact == constants::npegs) {
            cout << "You have found the correct solution! ";
            for (auto peg : pegs) cout << peg;
            cout << endl;
            winner = true;
            break;
        }
    }
    if(!winner) {
        cout << "Sorry! The solution was:";
        for(auto peg : pegs) {
            cout << peg;
        }
        cout << endl;
    }

    return 0;
}