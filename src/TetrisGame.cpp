#include "TetrisGame.h"

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
        break;
    case KEY_RIGHT:
        m_CurrentBlock.Move(0,1);
        break;
    case KEY_DOWN:
        m_CurrentBlock.Move(1,0);
        break;
    }
}

std::vector<Block> TetrisGame::GetAllBlocks() {
    return { IBlock(), SBlock(), ZBlock(), TBlock(), LBlock(), JBlock(), OBlock() };
}

Block TetrisGame::GetRandomBlock() {
    if (m_Blocks.empty()) m_Blocks = GetAllBlocks();
    size_t Index = GetRandomValue(0, m_Blocks.size() - 1);
    Block SelectedBlock = m_Blocks[Index];
    m_Blocks.erase(m_Blocks.begin() + Index);
    return SelectedBlock; 
}
