#include "Grid.h"
#include "ColorHandler.h"
#include <iostream>

/* Grid Constructor:
 * ---------------------------------------------------------------------------
 * Initializes the grid with default values and sets the background Color.
 * The grid is represented as a 2D array of Cells, each initialized to
 * a default Color and value.
 * --------------------------------------------------------------------------- */
Grid::Grid() {
    for (size_t Row = 0; Row < g_MaxGridRows; ++Row) {
        for (size_t Col = 0; Col < g_MaxGridCols; ++Col) {
            m_Grid[Row][Col].Color = ColorHandler::Get(DarkGray);
            m_Grid[Row][Col].Value = 0;
        } 
    }
}

void Grid::Print() {
    for (size_t Row = 0; Row < g_MaxGridRows; ++Row)  {
        for (size_t Col = 0; Col < g_MaxGridCols; ++Col) {
            std::cout << m_Grid[Row][Col].Value << " "; }
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