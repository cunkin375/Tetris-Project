#include "TetrisGame.h"
#include "ColorHandler.h"

#include <raylib.h>

int main() {
    // Remember to refactor magic numbers 
    InitWindow(InitWindowWidth, InitWindowHeight, "Raylib Tetris"); 
    SetTargetFPS(TargetFPS);
    Color BackgroundColor = ColorHandler::Get(TETRIS_DARK_BLUE);
    TetrisGame Game; 
    while (!WindowShouldClose()) {
        BeginDrawing();
        if (!Game.IsOver() && !Game.IsPaused()) {
            Game.HandleInput();
            if (Game.EventTriggered(EventWindowMS)) Game.MoveBlockDown();
            Game.Render();
        } else {
            DrawText("Game Over!\n Press ENTER to Restart", xPosition, yPosition, FontSize, ColorHandler::Get(TETRIS_WHITE));
            if (IsKeyPressed(KEY_ENTER)) Game.ResetGame();
        }
        ClearBackground(BackgroundColor);
        EndDrawing(); 
    }
    CloseWindow();
}