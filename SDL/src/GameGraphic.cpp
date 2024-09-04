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
    fontNameGame = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 40);
    fontDetailText = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 7);
    fontUserProfile = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 11);
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
    // Background
    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    if (!backgroundTexture) {
        cerr << "Failed to load background texture: " << SDL_GetError() << endl;
    }

    testTexture = element->CreateTexture("assets/img/test.png");
    tileImgTexture = element->CreateTexture("assets/img/square.png");
    textValueTexture = element->createTextureText(fontOswald, "default", {255, 255, 255, 255});

    textTitleTexture = element->createTextureText(fontOswald, "TILE TWISTER", {255, 255, 255, 255});

    // Display Name Game

    textTitleTexture = element->createTextureText(fontNameGame, "2048", {255, 255, 255, 255});
    if (!textTitleTexture) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

      textCreatorTexture1 = element->createTextureText(fontDetailText, "Created by Lucas Martinie", {255, 255, 255, 255});
    if (!textTitleTexture) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textCreatorTexture2 = element->createTextureText(fontDetailText, "Thanh Lemelle & Vanny Lamorte", {255, 255, 255, 255});
    if (!textTitleTexture) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
}

void GameGraphic::unloadAllTextures()
{
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(testTexture);


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

    element -> displayText(textCreatorTexture1, fontDetailText, "Created by Lucas Martinie", {255, 255, 255, 255}, 180, 80, false, 0, 0);

    element -> displayText(textCreatorTexture2, fontDetailText, "Thanh Lemelle & Vanny Lamorte", {255, 255, 255, 255}, 180, 100, false, 0, 0);

}
