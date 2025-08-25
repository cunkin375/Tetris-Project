#include "Grid.h"
#include "Blocks.h"
#include <raylib.h>

#define SCREEN_WIDTH 300 
#define SCREEN_HEIGHT 600

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "raylib Tetris"); 
    SetTargetFPS(144);
    Grid grid;
    grid.Print();
    TBlock block;
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(grid.GetBackgroundColor());
            grid.Draw();
            block.Draw();
        EndDrawing();
    }
    CloseWindow();
}