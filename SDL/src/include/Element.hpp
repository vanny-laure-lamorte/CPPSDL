#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Element
{
public:
    Element(SDL_Renderer *renderer);
    ~Element();

    SDL_Texture *CreateTexture(const std::string &imagePath);
    void renderTexture(SDL_Texture *texture, int x, int y, int width, int height);
    
    const SDL_Color COLOR_BLACK = {0, 0, 0, 255};
    const SDL_Color COLOR_WHITE = {255, 255, 255, 255};

private:
    SDL_Renderer *renderer;
};

#endif // ELEMENT_HPP
