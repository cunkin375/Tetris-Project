#include "Blocks.h"
#include "Grid.h"

Block::Block()
    : m_RotationState(0) 
    , m_RowOffset(0)
    , m_ColOffset(0)
{
}

void Block::Draw() {
    std::array<Position, POSITION_COUNT> CurrentPositions = GetCellPositions(); 
    for(const Position& Pos : CurrentPositions)
        DrawRectangle(Pos.Col * CELL_SIZE + 1, Pos.Row * CELL_SIZE + 1,
                      CELL_SIZE - 1, CELL_SIZE - 1, Color);
}

void Block::Move(int32_t RowOffset, int32_t ColOffset) {
    m_RowOffset += RowOffset;
    m_ColOffset += ColOffset;
}

std::array<Position, POSITION_COUNT> Block::GetCellPositions() {
    std::array<Position, POSITION_COUNT> ActiveTiles = CellPositions[m_RotationState];
    std::array<Position, POSITION_COUNT> NewTiles;
    for (size_t i = 0; i < POSITION_COUNT; ++i)
        NewTiles[i] = Position(ActiveTiles[i].Row + m_RowOffset, ActiveTiles[i].Col + m_ColOffset);
    return NewTiles;
}