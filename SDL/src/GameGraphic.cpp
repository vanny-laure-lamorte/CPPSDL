#include <iostream>
using namespace std;

#include "GameGraphic.hpp"
#include "Element.hpp"

GameGraphic::GameGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{
    
    element = new Element(renderer);

    // Font options
    fontOswald = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 35);
    fontNameGame = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 50);
    fontDetailText = element->LoadFont("assets/fonts/Inter.ttf", 9);
    fontUserProfile = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 14);
    fontBestPlayer = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 14);

    loadTexture();   
}

GameGraphic::~GameGraphic()
{
    IMG_Quit();
    unloadAllTextures();
    delete element;

    // Font
    TTF_CloseFont(fontOswald);
    TTF_CloseFont(fontNameGame);
    TTF_CloseFont(fontDetailText);
    TTF_CloseFont(fontUserProfile);
    TTF_CloseFont(fontBestPlayer);
}

void GameGraphic::updateGameBoard(const GameBoard& newGameBoard) {
    gameBoard = newGameBoard;
}

void GameGraphic::displayGrid()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Tile &tile = gameBoard.tiles[i][j];
            int x = 555 + (100 * j);
            int y = 230 + (100 * i);

            element->renderTexture(tileImgTexture, x, y, 90, 90);

            if (tile.getValue() != 0)
            {
                std::string valueStr = std::to_string(tile.getValue());
                SDL_Texture *textTexture = element->createTextureText(fontOswald, valueStr, {0, 0, 0, 255});

                int textWidth, textHeight;
                SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

                int textX = x + (90 - textWidth) / 2;
                int textY = y + (90 - textHeight) / 2;

                element->renderTexture(textTexture, textX, textY, textWidth, textHeight);

                SDL_DestroyTexture(textTexture);
            }
        }
    }
}
void GameGraphic::loadTexture()
{
    //*** BACKGROUND ***//

    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    if (!backgroundTexture) {
        cerr << "Failed to load background texture: " << SDL_GetError() << endl;
    }

    //*** IMAGE ***//

    testTexture = element->CreateTexture("assets/img/test.png");
    tileImgTexture = element->CreateTexture("assets/img/square.png");
    textValueTexture = element->createTextureText(fontOswald, "default", {255, 255, 255, 255});
    userLogoTexture = element -> CreateTexture("assets/img/profile.png");


    textTitleTexture = element->createTextureText(fontOswald, "TILE TWISTER", {255, 255, 255, 255});


    //*** TEXT ***//

    // Text Name Game
    textTitleTexture = element->createTextureText(fontNameGame, "2048", {255, 255, 255, 255});
    if (!textTitleTexture) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

      textCreatorTexture1 = element->createTextureText(fontDetailText, "Created by Lucas Martinie", {255, 255, 255, 255});
    if (!textCreatorTexture1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textCreatorTexture2 = element->createTextureText(fontDetailText, "Thanh Lemelle & Vanny Lamorte", {255, 255, 255, 255});
    if (!textCreatorTexture2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text name user
    textUserInfo1 = element->createTextureText(fontUserProfile, "Alicia Cordial", {255, 255, 255, 255});
    if (!textUserInfo1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textUserInfo2 = element->createTextureText(fontDetailText, "Joined in 2022", {255, 255, 255, 255});
    if (!textUserInfo2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }   
    
    // Text Best Player
    textBestPlayer1 = element->createTextureText(fontUserProfile, "Thanh Lemelle", {255, 255, 255, 255});
    if (!textBestPlayer1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textBestPlayer2 = element->createTextureText(fontDetailText, "Joined in 1994", {255, 255, 255, 255});
    if (!textBestPlayer2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text General Conditions of Use
    textGCU1 = element->createTextureText(fontDetailText, "Copyright LuThaVan Production studio 2024", {255, 255, 255, 255});
    if (!textGCU1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textGCU2 = element->createTextureText(fontDetailText, "Terms of Use Privacy Policy Cookies", {255, 255, 255, 255});
    if (!textGCU2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

}

void GameGraphic::unloadAllTextures()
{
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(testTexture);
    SDL_DestroyTexture(userLogoTexture);

    // Font
    TTF_CloseFont(fontOswald);
    TTF_CloseFont(fontNameGame);
    TTF_CloseFont(fontDetailText);
    TTF_CloseFont(fontUserProfile);
    TTF_CloseFont(fontBestPlayer);

    // Game Name
    SDL_DestroyTexture(textTitleTexture);
    SDL_DestroyTexture(textCreatorTexture1); 
    SDL_DestroyTexture(textCreatorTexture2); 

    SDL_DestroyTexture(textUserInfo1); 
    SDL_DestroyTexture(textUserInfo2); 

    SDL_DestroyTexture(textBestPlayer1); 
    SDL_DestroyTexture(textBestPlayer2); 

}

void GameGraphic::displayTexture()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    // element->drawRoundedRect(screenWidth - 550, screenHeight - 525, 500, 500, 20, element->COLOR_GREY);

    // element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    // animation();
  
    // displayGrid();
    displayTitle();
}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.5;
    };
}
void GameGraphic::displayTitle()
{

    // Frame with grey rectangle

    element -> drawRoundedRect(180, 300, 200, 48, 10, element -> COLOR_DARKGREY); // First Player info
    element -> drawRoundedRect(180, 360, 200, 292, 10, element -> COLOR_DARKGREY); // Top 10 players

    element -> drawRoundedRect(395, 30, 72, 22, 10, element -> COLOR_PINK); // Reset
    element -> drawRoundedRect(480, 30, 71, 21, 10, element -> COLOR_PINK); // Undo

    element -> drawRoundedRect(395, 60, 520, 63, 10, element -> COLOR_DARKGREY); // Game state info
    element -> drawRoundedRect(408, 69, 152, 47, 10, element -> COLOR_LIGHTGREY); // Score
    element -> drawRoundedRect(580, 69, 152, 47, 10, element -> COLOR_LIGHTGREY); // Best
    element -> drawRoundedRect(752, 69, 152, 47, 10, element -> COLOR_LIGHTGREY); // Timer

    element -> drawRoundedRect(395, 135, 520, 520, 10, element -> COLOR_DARKGREY); // Grid

    element -> drawRoundedRect(400, 660, 65, 22, 10, element -> COLOR_PINK); // Rule

    // Display Name Game
    element -> displayText(textTitleTexture, fontNameGame, "2048", {255, 255, 255, 255}, 180, 50, false, 0, 0); 
    element -> displayText(textCreatorTexture1, fontDetailText, "Created by Lucas Martinie", {255, 255, 255, 255}, 180, 120, false, 0, 0);
    element -> displayText(textCreatorTexture2, fontDetailText, "Thanh Lemelle & Vanny Lamorte", {255, 255, 255, 255}, 180, 130, false, 0, 0);

    // Text name user
    element -> displayText(textUserInfo1, fontUserProfile, "Alicia Cordial", {255, 255, 255, 255}, 840, 20, false, 0, 0);
    element -> displayText(textUserInfo2, fontDetailText, "Joined in 2022", {255, 255, 255, 255}, 845, 40, false, 0, 0);

    // Text best player
    element -> displayText(textBestPlayer1, fontUserProfile, "Thanh Lemelle", {255, 255, 255, 255}, 180, 250, false, 0, 0);
    element -> displayText(textBestPlayer2, fontDetailText, "Joined in 1994", {255, 255, 255, 255}, 180, 270, false, 0, 0);

    // Text General Conditions of Use
    element -> displayText(textGCU1, fontDetailText, "Copyright LuThaVan Production studio 2024", {255, 255, 255, 255}, 480, 663, false, 0, 0);
    element -> displayText(textGCU2, fontDetailText, "Terms of Use Privacy Policy  Cookies", {255, 255, 255, 255}, 480, 673, false, 0, 0);

    // Display User logo Image
    element->renderTexture(userLogoTexture,790,8,50,50); // User photo profile
    element->renderTexture(userLogoTexture, 250, 200,100,50); // Best player photo profile
}
