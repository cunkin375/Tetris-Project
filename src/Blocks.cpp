#include "Blocks.h"
#include "Grid.h"

Block::Block() : m_RotationState(0) 
{
}

void Block::Draw() {
    std::array<Position, POSITION_COUNT> CurrentPositions = CellPositions[m_RotationState];
    for(const Position& pos : CurrentPositions)
        DrawRectangle(pos.col * CELL_SIZE + 1, pos.row * CELL_SIZE + 1,
                      CELL_SIZE - 1, CELL_SIZE - 1, Color);
}