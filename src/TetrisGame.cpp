#include "TetrisGame.h"

#include <array>

// Public Methods

TetrisGame::TetrisGame()
    : m_Grid()
    , m_Blocks(GetAllBlocks())
{
    m_CurrentBlock = GetRandomBlock();
    m_NextBlock = GetRandomBlock();
}

void TetrisGame::Update() { 
    m_Grid.Draw();
    m_CurrentBlock.Draw();
}

void TetrisGame::HandleInput() {
    switch(GetKeyPressed()) {
    case KEY_LEFT:
        m_CurrentBlock.Move(0,-1);
        if (IsBlockOutside() || !BlockFits()) m_CurrentBlock.Move(0,1);
        break;
    case KEY_RIGHT:
        m_CurrentBlock.Move(0,1);
        if (IsBlockOutside() || !BlockFits()) m_CurrentBlock.Move(0,-1);
        break;
    case KEY_DOWN:
        MoveBlockDown();
        break;
    case KEY_UP:
        m_CurrentBlock.RotateClockwise();
        if (IsBlockOutside() || !BlockFits()) m_CurrentBlock.RotateCounterClockwise();
    }
}

// Private Methods

void TetrisGame::MoveBlockDown() {
    m_CurrentBlock.Move(1,0);
    if (IsBlockOutside() || !BlockFits()) {
        m_CurrentBlock.Move(-1,0);
        LockBlock();
        m_Grid.ClearFullRows();
    }
}

void TetrisGame::LockBlock() {
    std::array<Position, g_PositionCount> ActiveTiles = m_CurrentBlock.GetCellPositions();
    for (const Position& Pos : ActiveTiles)
        m_Grid.SetCell(Pos.Row, Pos.Col, m_CurrentBlock.Color);
    m_CurrentBlock = m_NextBlock;
    m_NextBlock = GetRandomBlock();
}

bool TetrisGame::BlockFits() {
    std::array<Position, g_PositionCount> ActiveTiles = m_CurrentBlock.GetCellPositions();
    for (Position Pos : ActiveTiles)
        if (m_Grid.GetCell(Pos.Row, Pos.Col).IsActive)
            return false;
    return true;
}

bool TetrisGame::IsBlockOutside()  {
    std::array<Position, g_PositionCount> ActiveTiles = m_CurrentBlock.GetCellPositions();
    for (Position Pos : ActiveTiles)
        if (m_Grid.IsCellOutside(Pos.Row, Pos.Col)) 
            return true;
    return false;
}

std::vector<Block> TetrisGame::GetAllBlocks() {
    return { IBlock(), SBlock(), ZBlock(), TBlock(), 
             LBlock(), JBlock(), OBlock() };
}

Block TetrisGame::GetRandomBlock() {
    if (m_Blocks.empty()) m_Blocks = GetAllBlocks();
    size_t Index = GetRandomValue(0, m_Blocks.size() - 1);
    Block SelectedBlock = m_Blocks[Index];
    m_Blocks.erase(m_Blocks.begin() + Index);
    return SelectedBlock; 
}