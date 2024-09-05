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
    void loadGameTexture();
    void unloadAllTextures();
    void displayGameTexture();
    void updateGameBoard(const GameBoard& newGameBoard);

    // Font
    void displayTitle();
    void displayGrid();

private:
    Element* element;
    SDL_Renderer* renderer;
    int screenWidth;
    int screenHeight;

    SDL_Texture* backgroundTexture;

    SDL_Texture* tileImgTexture;
    SDL_Texture* textValueTexture;
    

    //Font
    SDL_Texture *textTitleTexture; 
    TTF_Font *fontOswald;
    GameBoard gameBoard;

};

#endif // GAMEGRAPHIC_HPP
