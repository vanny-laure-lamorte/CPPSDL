#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Element.hpp"
#include "GameBoard.hpp"
#include "GameOptions.hpp"
#include "Tile.hpp"


using namespace std;

class GameGraphic
{
public:
    GameGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight);
    ~GameGraphic();
    void loadGameTexture();
    void unloadAllTextures();
    void displayGameTexture();
    void updateGameBoard(const GameBoard &newGameBoard);

    void displayRect(); 
    void displayImg(); 
    void displayText(); 
    void displayValue(); 
    void displayDesign();

    void displayGrid();
    bool textureGameOver = false;
    void displayGameOver();
    bool gameOver = false;

private:
    Element *element;
    GameOptions *gameOptions; 


    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

    //*** SCORE ***//
    void updateScore();
    int displayScoreValue;

    //*** CHRONO ***/
    Uint32 currentTime = 0;
    Uint32 gameTimer = 0;
    Uint32 elapsedTime = 0;
    void displayChrono();

    //*** GameOver ***/
    SDL_Texture *gameOverTexture; // Text gameOver
    SDL_Texture *endTimerTexture; // Text Timer gameOver
    SDL_Texture *endScoreTexture; // Text Score gameOver

    //** Save Score ***//

    //*** TEXTURE ***//

    // Images Texture
    SDL_Texture *backgroundTexture; // Background
    SDL_Texture *testTexture;
    SDL_Texture *tileImgTexture; // Title
    SDL_Texture *textValueTexture;
    SDL_Texture *userLogoTexture;    // Img logo user
    SDL_Texture *pinkRectImgTexture; // Img Pink Rect
    SDL_Texture *resetImgTexture;    // Img Reset
    SDL_Texture *undoImgTexture;     // Img undo

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
