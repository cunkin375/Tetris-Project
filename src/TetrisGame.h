#pragma once

/* TetrisGame.h
 * ---------------------------------------------------------------------------
 * Main header file for the Tetris game.
 * Includes all necessary headers and defines core game constants.
 * --------------------------------------------------------------------------- */


#include "Grid.h"
#include "Block.h"

#include <vector>
#include <memory>

class TetrisGame {
public: 
    TetrisGame();

    void Update();
    void HandleInput();

private:
    void MoveBlockDown();
    void LockBlock();
    bool BlockFits();
    bool IsBlockOutside();

    std::vector<Block> GetAllBlocks();
    Block GetRandomBlock();

private:
    Grid m_Grid;
    Block m_CurrentBlock;
    Block m_NextBlock;
    std::vector<Block> m_Blocks;
    
};