#pragma once

#include <memory>

struct WindowProperties {
    uint32_t Width;
    uint32_t Height;
    uint32_t TargetFPS;
    float EventWindowMS;

    WindowProperties(uint32_t width = 500, 
                     uint32_t height = 620, 
                     uint32_t targetFPS = 144, 
                     float eventWindowMS = 0.5f)
                    : Width(width), Height(height)
                    , TargetFPS(targetFPS)
                    , EventWindowMS(eventWindowMS) 
    {
    }
};

class Window {
public:
    Window();
    ~Window();

    void Clear();
    void Draw();
    void Close();
    bool ShouldClose() const;

private:

};