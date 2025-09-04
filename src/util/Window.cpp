#include "Window.h"
#include "Constants.h"
#include "ColorHandler.h"

#include <raylib.h>

Window::Window() 
    : m_Handle(WindowProperties{}) 
{
    InitWindow(m_Handle.Width, m_Handle.Height, "Tetris - C++ Raylib");
    SetTargetFPS(m_Handle.TargetFPS);
}

void Window::Clear() {
    ClearBackground(ColorHandler::Get(TETRIS_DARK_BLUE));
    EndDrawing();
}

void Window::Draw() {
    BeginDrawing();
}

void Window::DrawGameOverScreen() {
    DrawText("Game Over!\n Press ENTER to Restart", xPosition, yPosition, FontSize, ColorHandler::Get(TETRIS_WHITE));
}

void Window::Close() {
    CloseWindow();
}

bool Window::ShouldClose() {
    return WindowShouldClose();
}