#pragma once

#include "Constants.h"

#include <cstdint>
#include <vector>
#include <raylib.h>


struct Cell {
    uint32_t Value;
    Color Color;
};


class Grid {
public:
    Grid();
    void Print();
    void Draw();
    
    Cell GetCell(size_t Row, size_t Col) const { return m_Grid[Row][Col]; }

private:
    void Initialize();

private:
    Cell m_Grid[g_MaxGridRows][g_MaxGridCols];

};