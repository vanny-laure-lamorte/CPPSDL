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

    //*** TEXTURE ***//

    // Images Texture
    SDL_Texture* backgroundTexture; //Background
    SDL_Texture* testTexture;
    SDL_Texture* tileImgTexture; // Title
    SDL_Texture* textValueTexture;
    SDL_Texture* userLogoTexture; // Img logo user
    SDL_Texture* pinkRectImgTexture; // Img Pink Rect
    SDL_Texture* resetImgTexture; // Img Reset
    SDL_Texture* undoImgTexture; // Img undo
    

    // Text Title
    SDL_Texture *textTitleTexture;
    SDL_Texture *textCreatorTexture1;
    SDL_Texture *textCreatorTexture2; 

    // Text Top 5 players
    SDL_Texture *textTitleTop; 
    SDL_Texture *textValuePlayersTop; 

    // Text user info
    SDL_Texture *textUserInfo1; 
    SDL_Texture *textUserInfo2; 
    SDL_Texture *textScore; 
    SDL_Texture *textBest; 
    SDL_Texture *textTimer;
    SDL_Texture *textValueScoreUser; 
    SDL_Texture *textValueBestUser;  
    SDL_Texture *textValueTimeUser; 

    // Text btn reset and undo
    SDL_Texture *textReset; 
    SDL_Texture *textUndo; 

    // Text best player info
    SDL_Texture *textBestPlayer1; 
    SDL_Texture *textBestPlayer2; 
    SDL_Texture *textValueScorePlayer; 
    SDL_Texture *textValueTimePlayer; 
    SDL_Texture *textValueMatchPlayer; 

    // Text footer
    SDL_Texture *textViewMore;
    SDL_Texture *textRules; 
    SDL_Texture *textGCU1; 
    SDL_Texture *textGCU2; 

    //*** FONT ***//
    TTF_Font *fontOswald;
    TTF_Font *fontNameGame;
    TTF_Font *fontDetailText; 
    TTF_Font *fontDetailTextBold; 
    TTF_Font *fontUserProfile; 
    TTF_Font *fontBestPlayer; 
    TTF_Font *fontGameInfo; 

    GameBoard gameBoard;

};

#endif // GAMEGRAPHIC_HPP
