#include "TetrisGame.h"
#include "ColorHandler.h"

#include <raylib.h>

int main() {
    InitWindow(300, 600, "raylib Tetris"); 
    SetTargetFPS(144);
    Color BackgroundColor = ColorHandler::Get(TETRIS_DARK_BLUE);
    TetrisGame Game; 
    while (!WindowShouldClose()) {
        BeginDrawing();
        if (!Game.IsOver() && !Game.IsPaused()) {
            Game.HandleInput();
            if (Game.EventTriggered(0.5)) Game.MoveBlockDown();
            Game.Update();
        } else {
            DrawText("Game Over!\n Press ENTER to Restart", 20, 280, 20, ColorHandler::Get(TETRIS_WHITE));
            if (IsKeyPressed(KEY_ENTER)) Game.ResetGame();
        }
        ClearBackground(BackgroundColor);
        EndDrawing(); 
    }
    CloseWindow();
}