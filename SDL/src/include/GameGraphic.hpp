#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Element.hpp"

class GameGraphic {
public:
    GameGraphic(SDL_Renderer* renderer, int screenWidth, int screenHeight);
    ~GameGraphic();
    void loadTexture();
    void unloadAllTextures();
    void displayTexture();

    // Font
    void displayTextTexture();

private:
    Element* element;
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;

    SDL_Texture* backgroundTexture;
    SDL_Texture* testTexture;
    
    void animation();
    float animTransition = 0;

    //Font
    SDL_Texture *textTexture; 

    TTF_Font *fontOswald;

};

#endif // GAMEGRAPHIC_HPP
