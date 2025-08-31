#pragma once

#include "Window.h"
#include "TetrisGame.h"

class Application {
public:
    Application();

    void Run();

private:
    void Update();

private:
    Window m_Window;
    TetrisGame m_Game;
    
};