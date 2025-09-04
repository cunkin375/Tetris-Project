#pragma once

#include "util/Constants.h"

#include <vector>
#include <raylib.h>


struct Cell {
    bool IsActive;
    Color Color;
};


class Grid {
public:
    Grid();
    void Print();
    void Draw();
    void ClearFullRows();
    bool IsCellOutside(size_t Row, size_t Col);
    
    inline void SetCell(size_t Row, size_t Col, Color Color) { m_Grid[Row][Col] = Cell{true, Color}; }
    inline Cell GetCell(size_t Row, size_t Col) const { return m_Grid[Row][Col]; }

private:
    void ClearRow(size_t Row);
    void MoveRowsDown(size_t Row, size_t NumRows);
    bool IsRowFull(size_t Row);

private:
    Cell m_Grid[g_MaxGridRows][g_MaxGridCols];

};