#include "TetrisGame.h"
#include "ColorHandler.h"

#include <raylib.h>

int main() {
    // Remember to refactor magic numbers 
    uint32_t InitWindowWidth = 500;
    uint32_t InitWindowHeight = 620;
    uint32_t TargetFPS = 144;
    InitWindow(InitWindowWidth, InitWindowHeight, "Raylib Tetris"); 
    SetTargetFPS(TargetFPS);
    Color BackgroundColor = ColorHandler::Get(TETRIS_DARK_BLUE);
    TetrisGame Game; 
    while (!WindowShouldClose()) {
        BeginDrawing();
        if (!Game.IsOver() && !Game.IsPaused()) {
            Game.HandleInput();
            if (Game.EventTriggered(0.5)) Game.MoveBlockDown();
            Game.Render();
        } else {
            uint32_t xPosition = 40;
            uint32_t yPosition = 280;
            uint32_t FontSize = 20;
            DrawText("Game Over!\n Press ENTER to Restart", xPosition, yPosition, FontSize, ColorHandler::Get(TETRIS_WHITE));
            if (IsKeyPressed(KEY_ENTER)) Game.ResetGame();
        }
        ClearBackground(BackgroundColor);
        EndDrawing(); 
    }
    CloseWindow();
}