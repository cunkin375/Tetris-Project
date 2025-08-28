#include "Grid.h"
#include "ColorHandler.h"
#include <iostream>

/* Grid Constructor:
 * ---------------------------------------------------------------------------
 * Initializes the grid with default values and sets the background Color.
 * The grid is represented as a 2D array of Cells, each initialized to
 * a default Color and Active boolean.
 * --------------------------------------------------------------------------- */
Grid::Grid() {
    for (size_t Row = 0; Row < g_MaxGridRows; ++Row) {
        for (size_t Col = 0; Col < g_MaxGridCols; ++Col) {
            m_Grid[Row][Col].Color = ColorHandler::Get(TETRIS_DARK_GRAY);
            m_Grid[Row][Col].IsActive = false;
        } 
    }
}

void Grid::Print() {
    for (size_t Row = 0; Row < g_MaxGridRows; ++Row)  {
        for (size_t Col = 0; Col < g_MaxGridCols; ++Col) {
            std::cout << m_Grid[Row][Col].IsActive << " "; }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (size_t Row = 0; Row < g_MaxGridRows; ++Row) {
        for (size_t Col = 0; Col < g_MaxGridCols; ++Col) {
            Cell ActiveCell = m_Grid[Row][Col]; 
            DrawRectangle(Col * g_CellSize + 1, Row * g_CellSize + 1,
                          g_CellSize - 1, g_CellSize - 1, 
                          ActiveCell.Color);
        }
    }
}

bool Grid::IsCellOutside(size_t Row, size_t Col) {
    return (!(Row >= 0 && Row < g_MaxGridRows &&
              Col >= 0 && Col < g_MaxGridCols));
}