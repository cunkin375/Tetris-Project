#include "Grid.h"
#include "ColorHandler.h"
#include <iostream>

// Public Methods

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
void Grid::ClearFullRows() { size_t FullRowCount = 0;
    for (int32_t Row = g_MaxGridRows - 1; Row >= 0; --Row) {
        if (IsRowFull(Row)) {
            ClearRow(Row);
            ++FullRowCount;
        } else if (FullRowCount > 0) {
            MoveRowsDown(Row, FullRowCount);
            Row += FullRowCount; // Recheck this row after moving down
        }
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

// Private Methods

void Grid::ClearRow(size_t Row) {
    for (size_t Col = 0; Col < g_MaxGridCols; ++Col)
        m_Grid[Row][Col] = Cell{false, ColorHandler::Get(TETRIS_DARK_GRAY)};
}

void Grid::MoveRowsDown(size_t Row, size_t NumRows) {
    for (size_t Col = 0; Col < g_MaxGridCols; ++Col) {
        m_Grid[Row + NumRows][Col] = m_Grid[Row][Col];
        m_Grid[Row][Col] = Cell{false, ColorHandler::Get(TETRIS_DARK_GRAY)};
    }
} 

bool Grid::IsRowFull(size_t Row) {
    for (size_t Col = 0; Col < g_MaxGridCols; ++Col)
        if (!m_Grid[Row][Col].IsActive) return false;
    return true;
}