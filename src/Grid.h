#pragma once
#include <cstdint>
#include <vector>
#include <raylib.h>

#define GRID_ROWS 20
#define GRID_COLS 10
#define CELL_SIZE 30

struct Cell {
    uint16_t Value;
    Color Color;
};


class Grid {
public:
    Grid();
    void Print();
    void Draw();
    
    Cell GetCell(size_t row, size_t col) const { return m_Grid[row][col]; }
    Color GetBackgroundColor() const { return m_BackgroundColor; }

private:
    void Initialize();

private:
    Cell m_Grid[GRID_ROWS][GRID_COLS];
    Color m_BackgroundColor;
};