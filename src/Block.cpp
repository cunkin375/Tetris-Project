#include "Block.h"

Block::Block()
    : m_RotationState(0) 
    , m_RowOffset(0)
    , m_ColOffset(0)
{
}

void Block::Draw() {
    std::array<Position, g_PositionCount> CurrentPositions = GetCellPositions(); 
    for(const Position& Pos : CurrentPositions)
        DrawRectangle(Pos.Col * g_CellSize + 1, Pos.Row * g_CellSize + 1,
                      g_CellSize - 1, g_CellSize - 1, Color);
}

void Block::Move(int32_t RowOffset, int32_t ColOffset) {
    m_RowOffset += RowOffset;
    m_ColOffset += ColOffset;
}

// RotateClockwise and RotateCounterClockwise:
// Mod 4 to cycle through 0-3

void Block::RotateClockwise() {
    m_RotationState = (m_RotationState + 1) % 4;
}

void Block::RotateCounterClockwise() {
    m_RotationState = (m_RotationState + 3) % 4;
}


std::array<Position, g_PositionCount> Block::GetCellPositions() {
    std::array<Position, g_PositionCount> ActiveTiles = CellPositions[m_RotationState];
    std::array<Position, g_PositionCount> NewTiles;
    for (size_t i = 0; i < g_PositionCount; ++i)
        NewTiles[i] = Position(ActiveTiles[i].Row + m_RowOffset,
                               ActiveTiles[i].Col + m_ColOffset);
    return NewTiles;
}