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
            Game.HandleInput();
            ClearBackground(BackgroundColor);
            Game.Update();
        EndDrawing(); 
    }
    CloseWindow();
}