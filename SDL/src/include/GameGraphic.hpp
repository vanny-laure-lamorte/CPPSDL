#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Element.hpp"
#include "GameBoard.hpp"
#include "GameOptions.hpp"
#include "Tile.hpp"
#include <map>

using namespace std;
struct TileAnimation
{
    int currentX;
    int currentY;
    int targetX;
    int targetY;
    bool hasReachedTarget() const
    {
        return currentX == targetX && currentY == targetY;
    }
};
class GameGraphic
{
public:
    GameGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight);
    ~GameGraphic();
    void loadGameTexture();
    void unloadAllTextures();
    void displayGameTexture();
    void updateGameBoard(const GameBoard &newGameBoard);
    void initializeAnimations();

    void displayRect();
    void displayImg();
    void displayText();
    void displayValue();
    void displayDesign();

    void displayGrid();
    void getUsername(std::string username);

    void displayGameOver();
    bool gameOver = false;

    GameBoard resetGame();
    GameBoard undoGame();

    // User best score
    bool scoreFetched;
    int scoreUserInt;
    string scoreUserstr;
    void getUserBestScore();

    // Top 5 players
    string topPlayerName;
    string topScore;
    SDL_Texture *textTitleTop;
    SDL_Texture *playerNameTexture;
    SDL_Texture *playerScoreTexture;
    vector<SDL_Texture *> playerNameTextures;
    vector<SDL_Texture *> playerScoreTextures;

    void unloadTexturesTopPlayers();

    void loadTopFivePlayers();
    void displayToFivePlayers();

    GameBoard gameBoard;
    GameBoard oldGameBoard;
    
private:
    Element *element;
    GameOptions *gameOptions;
    std::map<int, TileAnimation> animations;

    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

    //*** BEST PLAYER INFO ***/
    void infoBestPlayer();
    string bestPlayerName;
    string bestScore;
    string bestTime;
    string bestMatchCount;
    SDL_Texture *textTime;
    SDL_Texture *textMatch;
    SDL_Texture *textValueBestPlayerName;
    SDL_Texture *textValueBestScore;
    SDL_Texture *textValueBestTime;
    SDL_Texture *textValueBestMatchCount;

    //*** SCORE ***//
    void updateScore();
    int displayScoreValue;

    //*** CHRONO ***/
    Uint32 startTime = 0;
    Uint32 gameTimer = 0;
    Uint32 elapsedTime = 0;
    void displayChrono();
    void resetChrono();

    //*** GameOver ***/
    bool textureGameOver = false;
    SDL_Texture *gameOverTexture;    // Text gameOver
    SDL_Texture *endTimerTexture;    // Text Timer gameOver
    SDL_Texture *endScoreTexture;    // Text Score gameOver
    SDL_Texture *gameOverIMGTexture; // IMG Score gameOver
    SDL_Texture *chronoTexture;

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

    ;

    // Text user info
    SDL_Texture *textUserInfo1;
    SDL_Texture *textUserInfo2;
    SDL_Texture *textScore;
    SDL_Texture *textBest;
    SDL_Texture *textTimer;
    SDL_Texture *textValueScoreUser = nullptr;
    SDL_Texture *textValueBestUser;

    // Text btn reset and undo
    SDL_Texture *textReset;
    SDL_Texture *textUndo;

    // Text best player info
    SDL_Texture *textBestPlayer2;

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

    //*** USERNAME ***//
    void displayUsername();
    bool usernameLoaded = false;
    std::string user = "";
};

#endif // GAMEGRAPHIC_HPP
