#pragma once
#include "ColorHandler.h"
#include <raylib.h>
#include <cstdint>
#include <array>
#include <map>

#define TETROMINO 4
#define POSITION_COUNT 4

struct Position {
    uint16_t row;
    uint16_t col;
};

class Block {
public:
    Block();
    
    void Draw();

public:
    std::map<uint16_t, std::array<Position, POSITION_COUNT>> CellPositions;
    Color Color;

private:
    uint16_t m_RotationState;

};

class IBlock : public Block {
public:
    IBlock() {
        Color = ColorHandler::Get(Cyan);
        CellPositions[0] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1} };
        CellPositions[1] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{1,3} };
        CellPositions[2] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1} };
        CellPositions[3] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{1,3} };
    }
};

class SBlock : public Block {
public:
    SBlock() {
        Color = ColorHandler::Get(Green);
        CellPositions[0] = { Position{0,1}, Position{0,2}, Position{1,0}, Position{1,1} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{1,2}, Position{2,2} };
        CellPositions[2] = { Position{0,1}, Position{0,2}, Position{1,0}, Position{1,1} };
        CellPositions[3] = { Position{0,1}, Position{1,1}, Position{1,2}, Position{2,2} };
    }
};

class TBlock : public Block {
public:
    TBlock() {
        Color = ColorHandler::Get(Purple);
        CellPositions[0] = { Position{0,1}, Position{1,0}, Position{1,1}, Position{1,2} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{1,2}, Position{2,1} };
        CellPositions[2] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{2,1} };
        CellPositions[3] = { Position{0,1}, Position{1,0}, Position{1,1}, Position{2,1} };
    }
};

class LBlock : public Block {
public:
    LBlock() {
        Color = ColorHandler::Get(Blue);
        CellPositions[0] = { Position{0,2}, Position{1,0}, Position{1,1}, Position{1,2} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{2,2} };
        CellPositions[2] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{2,0} };
        CellPositions[3] = { Position{0,0}, Position{0,1}, Position{1,1}, Position{2,1} };
    }
};