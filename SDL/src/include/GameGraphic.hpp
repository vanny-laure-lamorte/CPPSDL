#ifndef GameGraphic_HPP
#define GameGraphic_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

using namespace std;

class GameGraphic
{
public:
    GameGraphic(SDL_Renderer *_renderer, int screenWidth, int screenHeight); 

    ~GameGraphic();  

private:

    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

  

    // Rect
    // SDL_Rect buttonRect;

    // Texture
    SDL_Texture *backgroundTexture;

    // Textures 
};

#endif
