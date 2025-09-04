#include "Application.h"

Application::Application() 
    : m_Window()
    , m_Game()
{
}

void Application::Run() {
    while (!m_Window.ShouldClose()) {
        m_Window.Draw();
        Update();
        m_Game.Render();
        m_Window.Clear();
    }
    m_Window.Close();
}

void Application::Update() {
    if (!m_Game.IsOver() && !m_Game.IsPaused()) {
        m_Game.HandleInput();
        if (m_Game.EventTriggered(EventWindowMS)) m_Game.MoveBlockDown();
    } else {
        m_Window.DrawGameOverScreen();
        if (IsKeyPressed(KEY_ENTER)) m_Game.ResetGame();
    }
}