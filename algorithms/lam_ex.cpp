///////////////////////////////////////////////////
// @lam_ex.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>

using namespace std;

int main() {

    int x{42}, y{99}, z{0};

    // This will create an object of the lambda expression 
    // and the variables are essentially member variables which will retain their values
    auto lam = [=, &z]() mutable { ++x; ++y; z = x + y; };

    lam();
    lam();

    cout << "x = " << x << endl;
    cout << "y = " << y << endl;
    cout << "z = " << z << endl;

    return 0;
}