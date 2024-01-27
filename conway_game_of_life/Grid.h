///////////////////////////////////////////////////
// @Grid.h
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////
#ifndef GRID_H_
#define GRID_H_

#include <string>
#include <vector>
#include <cstdlib>

#include "Cell.h"

class Grid {
    // Cells on screen.
    // We have a border consisting of inactive cells
    // These are used in the calculation for the next generation of cells,
    // but are not displayed on screen
    Cell cells[rowmax+2][colmax+2];
public:
    // Create a cell at (row, col)
    void create(int row, int col);

    // Draw all the cells
    void draw();

    // Populate the grid with cells, at random
    void randomize();

    // Will the cell at (row, column) survive to the next generation?
    bool will_survive(int row, int col);

    // Will a cell be born at (row, col) in the next generation?
    bool will_create(int row, int col);

    // Update to the next generation
    void update(const Grid& next);
};

// Non-member function
// Calculate which cells survive to the next generation and which are born
void calculate(Grid& old_gen, Grid& new_gen);

#endif // GRID_H_