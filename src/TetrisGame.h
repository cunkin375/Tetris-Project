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
    void MoveBlockDown();
    void PlaceBlockDown();
    void HandleInput();
    bool EventTriggered(double_t Interval);
    void ResetGame();
    
    inline void EndGame() { m_GameOver = true; }
    inline void Pause() { m_Paused = true; }
    inline void Unpause() { m_Paused = false; }
    inline bool IsOver() const { return m_GameOver; }
    inline bool IsPaused() const { return m_Paused; }

private:
    void LockBlock();
    bool BlockFits();
    bool IsBlockOutside();

    std::vector<Block> GetAllBlocks();
    Block GetRandomBlock();

private:
    bool m_GameOver;
    bool m_Paused;
    double_t m_LastUpdateTime;
    Grid m_Grid;
    Block m_CurrentBlock;
    Block m_NextBlock;
    std::vector<Block> m_Blocks;
    
};