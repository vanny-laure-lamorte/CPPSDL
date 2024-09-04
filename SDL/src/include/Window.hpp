// Window.hpp
#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Window
{
public:
    Window(int screenWidth, int screenHeight);
    ~Window();
    bool isInitialized() const;
    void update() const;
    SDL_Renderer *getRenderer() const;
    int screenWidth;
    int screenHeight;

private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool initialized;
};

#endif // WINDOW_HPP
