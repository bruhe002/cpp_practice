///////////////////////////////////////////////////
// @random_walk.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <random>
#include <thread>
#include <string>

using namespace std;

// Come back after you learn SFML Graphics!!
// To calculate the new position, we add the horizontal velocity and vertical velocity
// Use randomness to simulate the walk
// Use mt19937 and bernoulli distribution


// Non SFML Graphics for one dimension
int main() {
    int x{0};
    int vx{0};
    const int width{40};
    string blank_line(width, ' ');

    mt19937 mt;
    bernoulli_distribution bd;

    while(true) {
        if (bd(mt)) {
            vx = 1;

            if (x == width) {
                vx = -1;
            }
        }
        else {
            vx = -1;

            if(x == 0) {
                vx = 1;
            }
        }

        x += vx;

        cout << "\r" << blank_line;

        string position(x, ' ');
        cout << "\r" << position << '.' << flush;

        this_thread::sleep_for(100ms);
    }
}