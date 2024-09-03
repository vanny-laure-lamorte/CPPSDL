#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>


#include "Element.hpp"

class GameGraphic {
public:
    GameGraphic(SDL_Renderer* _renderer, int screenWidth, int screenHeight);
    ~GameGraphic();
    void GameloadBackgroundTexture();
    void GameunloadAllTextures();
    void GamedisplayBackground();

private:
    SDL_Renderer* renderer;
    SDL_Texture* backgroundTexture;
    
    int screenWidth;
    int screenHeight;

    Element * element; 

};

#endif // GAMEGRAPHIC_HPP
