#include "Grid.h"
#include "ColorHandler.h"
#include <iostream>

// Public Methods
Grid::Grid() 
    : m_BackgroundColor(ColorHandler::Get(DarkBlue)) { 
    Initialize(); 
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

// Private Methods
void Grid::Initialize() {
    for (size_t row = 0; row < GRID_ROWS; ++row) {
        for (size_t col = 0; col < GRID_COLS; ++col) {
            m_Grid[row][col].Color = ColorHandler::Get(DarkGray);
            m_Grid[row][col].Value = 0;
        } 
    }
}