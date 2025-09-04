#pragma once

#include <raylib.h>

enum Colors {
    TETRIS_DARK_GRAY,
    TETRIS_DARK_BLUE,
    TETRIS_GREEN,
    TETRIS_RED,
    TETRIS_ORANGE,
    TETRIS_YELLOW,
    TETRIS_PURPLE,
    TETRIS_CYAN,
    TETRIS_BLUE,
    TETRIS_WHITE
};

namespace ColorHandler {
    static inline Color Get(Colors Color) {
        switch (Color) {
        case TETRIS_DARK_GRAY: return { 26,  31,  40, 255};
        case TETRIS_DARK_BLUE: return { 44,  44, 127, 255};
        case TETRIS_GREEN:     return { 47, 250,  23, 255};
        case TETRIS_RED:       return {232,  18,  18, 255};
        case TETRIS_ORANGE:    return {255, 165,   0, 255};
        case TETRIS_YELLOW:    return {255, 255,   0, 255};
        case TETRIS_PURPLE:    return {160,  32, 240, 255};
        case TETRIS_CYAN:      return {  0, 255, 255, 255};
        case TETRIS_BLUE:      return {  0,   0, 255, 255};
        case TETRIS_WHITE:     return {255, 255, 255, 255};
        default:/*Just Incase*/return {255, 255, 255, 255};
        } 
    } 
}