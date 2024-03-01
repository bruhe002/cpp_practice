///////////////////////////////////////////////////
// @lam_ex_2.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {

    int y = 1;

    auto lam = [y = y + 1](int x) { return x + y; };

    auto res = lam(5);

    cout << "y = " << y << endl;
    cout << "res = " << res << endl;

    return 0;
}