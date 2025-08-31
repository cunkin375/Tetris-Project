#pragma once

constexpr size_t g_MaxGridRows = 20;
constexpr size_t g_MaxGridCols = 10;
constexpr size_t g_CellSize = 30;
constexpr size_t g_CellOffset = 11;
constexpr size_t g_CellSplit = 1;
constexpr size_t g_PositionCount = 4;

// Window Setttings
// Move to Window class
constexpr uint32_t InitWindowWidth = 500;
constexpr uint32_t InitWindowHeight = 620;
constexpr uint32_t TargetFPS = 144;
constexpr double_t EventWindowMS = 0.5;

// Game Over Message 
// Move to window class
constexpr uint32_t xPosition = 40;  
constexpr uint32_t yPosition = 280; 
constexpr uint32_t FontSize = 20;   