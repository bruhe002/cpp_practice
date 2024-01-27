///////////////////////////////////////////////////
// @Cell.cpp
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include "Cell.h"

// Draw the cell on the grid
void Cell::draw(int row, int col) const {
    // ANSI control command
    // escape[n;mH moves the cursor to row n, col m
    // These are 1 based, i.e row 1 is the first row
    std::cout << "\x1b[" << row + 1 << ";" << col +1 << "H";
    std::cout << (alive ? live_cell : dead_cell);
}