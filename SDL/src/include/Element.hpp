#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
using namespace std;

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

#include "Window.hpp"

class Element
{

public:
    Element(SDL_Renderer *renderer);
    ~Element();

    //* COLORS *//
    const SDL_Color COLOR_BLACK = {0, 0, 0, 255};
    const SDL_Color COLOR_WHITE = {255, 255, 255, 255};

    //* METHODS *//
    void renderBackground(SDL_Renderer *renderer, SDL_Texture *surfaceTexture);
    SDL_Texture *loadTexture(const string &imagePath);
    void renderTexture(SDL_Texture *texture, int x, int y, int width, int height);

private:
    SDL_Renderer *renderer;
};

#endif
