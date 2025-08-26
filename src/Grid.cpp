#include "Grid.h"
#include "ColorHandler.h"
#include <iostream>

//  PUBLIC METHODS
/* Grid Constructor:
 * ---------------------------------------------------------------------------
 * Initializes the grid with default values and sets the background color.
 * The grid is represented as a 2D array of Cells, each initialized to
 * a default color and value.
 * --------------------------------------------------------------------------- */
Grid::Grid() 
    : m_BackgroundColor(ColorHandler::Get(DarkBlue)) { 
    for (size_t row = 0; row < GRID_ROWS; ++row) {
        for (size_t col = 0; col < GRID_COLS; ++col) {
            m_Grid[row][col].Color = ColorHandler::Get(DarkGray);
            m_Grid[row][col].Value = 0;
        } 
    }
}

void Grid::Print() {
    for (size_t row = 0; row < GRID_ROWS; ++row)  {
        for (size_t col = 0; col < GRID_COLS; ++col) {
            std::cout << m_Grid[row][col].Value << " "; }
        std::cout << std::endl;
    }
}

void Grid::Draw() {
    for (size_t row = 0; row < GRID_ROWS; ++row) {
        for (size_t col = 0; col < GRID_COLS; ++col) {
            Cell ActiveCell = m_Grid[row][col]; 
            DrawRectangle(col * CELL_SIZE + 1, row * CELL_SIZE + 1,
                          CELL_SIZE - 1, CELL_SIZE - 1, 
                          ActiveCell.Color);
        }
    }
}