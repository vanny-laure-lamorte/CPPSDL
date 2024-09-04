#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Element.hpp"
#include "GameBoard.hpp"
#include "Tile.hpp"
class GameGraphic {
public:
    GameGraphic(SDL_Renderer* renderer, int screenWidth, int screenHeight);
    ~GameGraphic();
    void loadTexture();
    void unloadAllTextures();
    void displayTexture();

    // Font
    void displayTitle();

private:
    Element* element;
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;

    SDL_Texture* backgroundTexture;
    SDL_Texture* testTexture;

    SDL_Texture* tileImgTexture;
    SDL_Texture* textValueTexture;
    
    void animation();
    void displayGrid();
    float animTransition = 0;

    //Font
    SDL_Texture *textTitleTexture; 
    TTF_Font *fontOswald;
    GameBoard gameBoard;

};

#endif // GAMEGRAPHIC_HPP
