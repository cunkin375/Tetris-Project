#pragma once
#include <raylib.h>

/* Colors Enum:
 * ---------------------------------------------------------------------------
 * Enumeration of predefined colors used in the Tetris game.
 * Each color corresponds to a specific RGBA value defined in ColorHandler.
 * --------------------------------------------------------------------------- */
enum Colors {
    DarkGray,
    DarkBlue,
    Green,
    Red,
    Orange,
    Yellow,
    Purple,
    Cyan,
    Blue
};

/* ColorHandler Class:
 * ---------------------------------------------------------------------------
 * Static class that provides a method to get predefined colors.
 * Each color is represented as a struct with RGBA values.
 * Color struct comes from raylib.h
 * --------------------------------------------------------------------------- */
class ColorHandler {
public:
    static inline Color Get(Colors color) {
        switch (color) {
        case DarkGray: return { 26,  31,  40, 255};
        case DarkBlue: return { 44,  44, 127, 255};
        case Green:    return { 47, 250,  23, 255};
        case Red:      return {232,  18,  18, 255};
        case Orange:   return {255, 165,   0, 255};
        case Yellow:   return {255, 255,   0, 255};
        case Purple:   return {160,  32, 240, 255};
        case Cyan:     return {  0, 255, 255, 255};
        case Blue:     return {  0,   0, 255, 255};
        default:       return {255, 255, 255, 255};
        } 
    } 
};