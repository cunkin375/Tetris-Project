#pragma once

#include "Constants.h"
#include "ColorHandler.h"

#include <raylib.h>
#include <memory>
#include <array>
#include <map>


struct Position {
    uint32_t Row;
    uint32_t Col;
    Position() : Row(0), Col(0) {}
    Position(uint32_t Row, uint32_t Col) : Row(Row), Col(Col) {}
};

// Parent Class
class Block {
public:
    Block();
    
    void Draw();
    void Move(int32_t RowOffset, int32_t ColOffset);
    void RotateClockwise();
    void RotateCounterClockwise();
    
    std::array<Position, g_PositionCount> GetCellPositions();

public:
    std::map<uint32_t, std::array<Position, g_PositionCount>> CellPositions;
    Color Color;

private:
    uint32_t m_RotationState;
    int32_t m_RowOffset;
    int32_t m_ColOffset;

};

// Child Classes
class IBlock : public Block {
public:
    IBlock() {
        Color = ColorHandler::Get(TETRIS_CYAN);
        // Rotation states
        CellPositions[0] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{1,3} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1} };
        CellPositions[2] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{1,3} };
        CellPositions[3] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1} };
        // Initial position adjustment
        Move(-1,3);
    }
};

class SBlock : public Block {
public:
    SBlock() {
        Color = ColorHandler::Get(TETRIS_GREEN);
        // Rotation states
        CellPositions[0] = { Position{0,1}, Position{0,2}, Position{1,0}, Position{1,1} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{1,2}, Position{2,2} };
        CellPositions[2] = { Position{0,1}, Position{0,2}, Position{1,0}, Position{1,1} };
        CellPositions[3] = { Position{0,1}, Position{1,1}, Position{1,2}, Position{2,2} };
        // Initial position adjustment
        Move(0,3);
    }
};

class ZBlock : public Block {
public:
    ZBlock() {
        Color = ColorHandler::Get(TETRIS_RED);
        // Rotation states
        CellPositions[0] = { Position{0,0}, Position{0,1}, Position{1,1}, Position{1,2} };
        CellPositions[1] = { Position{0,2}, Position{1,1}, Position{1,2}, Position{2,1} };
        CellPositions[2] = { Position{0,0}, Position{0,1}, Position{1,1}, Position{1,2} };
        CellPositions[3] = { Position{0,2}, Position{1,1}, Position{1,2}, Position{2,1} };
        // Initial position adjustment
        Move(0,3);
    }
};

class TBlock : public Block {
public:
    TBlock() {
        Color = ColorHandler::Get(TETRIS_PURPLE);
        // Rotation states
        CellPositions[0] = { Position{0,1}, Position{1,0}, Position{1,1}, Position{1,2} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{1,2}, Position{2,1} };
        CellPositions[2] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{2,1} };
        CellPositions[3] = { Position{0,1}, Position{1,0}, Position{1,1}, Position{2,1} };
        // Initial position adjustment
        Move(0,3);
    }
};

class LBlock : public Block {
public:
    LBlock() {
        Color = ColorHandler::Get(TETRIS_BLUE);
        // Rotation states
        CellPositions[0] = { Position{0,2}, Position{1,0}, Position{1,1}, Position{1,2} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{2,2} };
        CellPositions[2] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{2,0} };
        CellPositions[3] = { Position{0,0}, Position{0,1}, Position{1,1}, Position{2,1} };
        // Initial position adjustment
        Move(0,3);
    }
};

class JBlock : public Block {
public:
    JBlock() {
        Color = ColorHandler::Get(TETRIS_ORANGE);
        // Rotation states
        CellPositions[0] = { Position{0,0}, Position{1,0}, Position{1,1}, Position{1,2} };
        CellPositions[1] = { Position{0,1}, Position{0,2}, Position{1,1}, Position{2,1} };
        CellPositions[2] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{2,2} };
        CellPositions[3] = { Position{0,1}, Position{1,1}, Position{2,0}, Position{2,1} };
        // Initial position adjustment
        Move(0,3);
    }
};

class OBlock : public Block {
public:
    OBlock() {
        Color = ColorHandler::Get(TETRIS_YELLOW);
        // Rotation states
        CellPositions[0] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        CellPositions[1] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        CellPositions[2] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        CellPositions[3] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        // Initial position adjustment
        Move(0,4);
    }
};