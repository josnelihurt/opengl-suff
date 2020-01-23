#include "display.h"
#include <GL/glew.h>
#include <iostream>
using namespace std;
Display::Display(int width, int heigh, const std::string &title)
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                               width, heigh, SDL_WINDOW_OPENGL);
    _glContext = SDL_GL_CreateContext(_window);
    GLenum status = glewInit();

    if (status != GLEW_OK){
        cerr << " unable to start glew" << endl;
    }
}

Display::~Display()
{
    SDL_GL_DeleteContext(_glContext);
    SDL_DestroyWindow(_window);
    SDL_Quit();
}

bool Display::IsClose() const
{
    return _isClose;
}

void Display::Update()
{
    SDL_Event e;
    SDL_GL_SwapWindow(_window);

    while(SDL_PollEvent(&e)){
        if(e.type == SDL_QUIT){
            _isClose = true;
        }
    }
}

void Display::Clear(float r, float g, float b, float a) const
{
    glClearColor(r,g,b,a);
    glClear(GL_COLOR_BUFFER_BIT);
}
