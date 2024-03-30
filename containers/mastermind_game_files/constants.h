#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <array>

namespace constants {
    const int npegs = 4;
    const int nturns = 10;
    const int ncolors = 3;
}

using peg_array = std::array<char, constants::npegs>;

using color_array = std::array<const char, constants::ncolors+1>;

namespace constants {
    const color_array colors = {'R', 'G', 'B'};
}

#endif // CONSTANTS_H