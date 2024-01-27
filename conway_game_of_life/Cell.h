///////////////////////////////////////////////////
// @Cell.h
//
// Author: Eric Bruhns
//
///////////////////////////////////////////////////
#ifndef CELL_H_
#define CELL_H_

#include <iostream>

#include "Life.h"

class Cell {
    // Cell status
    bool alive;
public:
    // Constructor
    // Cells are empty by default
    Cell(): alive(false) {}

    // Draw the cell on the grid
    void draw(int row, int col) const;

    // Bring cell to life
    void create() {
        alive = true;
    }

    // End cell's life
    void erase() {
        alive = false;
    }

    bool is_alive() const { return alive; }
};

#endif // CELL_H