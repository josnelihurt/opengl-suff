#pragma once
#include <SDL2/SDL.h>
#include <string>
class Display
{
public:
    Display(int width, int heigh, const std::string& title);
    virtual ~Display();

    bool IsClose() const;
    void Update();
    void Clear(float r, float g, float b, float a) const;
private:
    SDL_Window* _window;
    SDL_GLContext _glContext;
    bool _isClose{false};
};
