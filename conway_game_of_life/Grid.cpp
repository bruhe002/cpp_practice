///////////////////////////////////////////////////
// @Grid.h
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////

#include <iostream>
#include <ctime>

#include "Grid.h"

// Create a cell at (row, col)
void Grid::create(int row, int col) {
    cells[row][col].create();
}

// Draw all the cells, including the border
void Grid::draw() {
    // ANSI control command
    // \x1b means "excape"
    // Escape[2J clears the screen and returns the cursor to the home position

    std::cout << "\x1b[2j]";

    for (int row = 0; row < rowmax; ++row) {
        for (int col = 0; col < colmax; ++col) {
            cells[row][col].draw(row, col);
        }
    }

}

// Populate the grid with cells, at random
void Grid::randomize() {
    const int factor = 5;
    const int cutoff = RAND_MAX/factor;
    time_t now;
    time(&now);
    //srand(now);

    for(int row = 1; row < rowmax; row++) {
        for (int col = 1; col < colmax; ++col) {
            if (rand()/cutoff == 0) {
                create(row, col);
            }
        }
    }
}

// Will the cell at (row, col) survive the next generation?
bool Grid::will_survive(int row, int col) {
    if (!cells[row][col].is_alive()) {
        // There is no cell at this position!
        return false;
    }

    // Find the number of live neighbors for this cell
    //
    // x x x
    // x o x
    // x x x
    int neighbors = cells[row-1][col-1].is_alive() +
                    cells[row-1][col].is_alive() +
                    cells[row][col-1].is_alive() +
                    cells[row][col+1].is_alive() +
                    cells[row+1][col-1].is_alive() +
                    cells[row+1][col].is_alive() +
                    cells[row+1][col+1].is_alive();

    if (neighbors < min_neighbors || neighbors > max_neighbors) {
        // Cell has died
        return false;
    }

    // If we get here, the cell has survived
    return true;
}

// Update to the next generation
void Grid::update(const Grid& next) {
    for (int row = 1; row < rowmax; ++row) {
        for (int col = 1; col < colmax; ++col) {
            cells[row][col] = next.cells[row][col];
        }
    }
}

// By default, all cells in the next gen are initially unpopulated
// Calculate which live cells survive to the next gen
// and unpopulated cells are populated in the next generation
void calculate(Grid& old_gen, Grid& new_gen) {
    for (int row = 1; row < rowmax; ++row) {
        for (int col = 1; col < colmax; ++col) {
            // Will this live cell survive to the next gen
            if (old_gen.will_survive(row,col)) {
                new_gen.create(row, col);
            }
            // Will this unpopulated cell be populated in the next generation?
            else if (old_gen.will_create(row, col)) {
                new_gen.create(row, col);
            }
        }
    }
}
