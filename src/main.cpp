#include "TetrisGame.h"
#include "ColorHandler.h"

#include <raylib.h>

#define SCREEN_WIDTH 300 
#define SCREEN_HEIGHT 600

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib Tetris"); 
    SetTargetFPS(144);
    Color BackgroundColor = ColorHandler::Get(DarkBlue);
    TetrisGame Game; 
    while (!WindowShouldClose()) {
        BeginDrawing();
            Game.HandleInput();
            ClearBackground(BackgroundColor);
            Game.Draw();
        EndDrawing(); 
    }
    CloseWindow();
}