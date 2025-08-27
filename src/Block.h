#pragma once

#include "Constants.h"
#include "ColorHandler.h"

#include <raylib.h>
#include <cstdint>
#include <array>
#include <map>


struct Position {
    uint32_t Row;
    uint32_t Col;
    Position() : Row(0), Col(0) {} // Default constructor
    Position(uint32_t Row, uint32_t Col) : Row(Row), Col(Col) {}
};

// Parent Class
class Block {
public:
    Block();
    
    void Draw();
    void Move(int32_t RowOffset, int32_t ColOffset);
    
    std::array<Position, POSITION_COUNT> GetCellPositions();

public:
    std::map<uint32_t, std::array<Position, POSITION_COUNT>> CellPositions;
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
        Color = ColorHandler::Get(Cyan);
        CellPositions[0] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{1,3} };
        CellPositions[1] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1} };
        CellPositions[2] = { Position{0,1}, Position{1,1}, Position{2,1}, Position{3,1} };
        CellPositions[3] = { Position{1,0}, Position{1,1}, Position{1,2}, Position{1,3} };
        // Initial position adjustment
        Move(-1,3);
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
        // Initial position adjustment
        Move(0,3);
    }
};

class ZBlock : public Block {
public:
    ZBlock() {
        Color = ColorHandler::Get(Red);
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
        Color = ColorHandler::Get(Purple);
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
        Color = ColorHandler::Get(Blue);
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
        Color = ColorHandler::Get(Orange);
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
        Color = ColorHandler::Get(Yellow);
        CellPositions[0] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        CellPositions[1] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        CellPositions[2] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        CellPositions[3] = { Position{0,0}, Position{0,1}, Position{1,0}, Position{1,1} };
        // Initial position adjustment
        Move(0,4);
    }
};