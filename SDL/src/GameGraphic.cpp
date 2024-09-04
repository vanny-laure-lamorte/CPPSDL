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

    loadTexture();
}

GameGraphic::~GameGraphic()
{
    IMG_Quit();
    unloadAllTextures();
    delete element;

    // Font
    TTF_CloseFont(fontOswald);
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

                std::cout << "Rendering tile at (" << x << ", " << y << ") with value " << tile.getValue() << std::endl;
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
    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    testTexture = element->CreateTexture("assets/img/test.png");
    tileImgTexture = element->CreateTexture("assets/img/square.png");
    textValueTexture = element->createTextureText(fontOswald, "default", {255, 255, 255, 255});

    textTitleTexture = element->createTextureText(fontOswald, "TILE TWISTER", {255, 255, 255, 255});
}

void GameGraphic::unloadAllTextures()
{
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(testTexture);
    SDL_DestroyTexture(textTitleTexture);
}

void GameGraphic::displayTexture()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    element->drawRoundedRect(screenWidth - 550, screenHeight - 525, 500, 500, 20, element->COLOR_GREY);

    // element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    // animation();

    // Display title
    element->displayText(textTitleTexture, fontOswald, "TILE TWISTER ", {255, 255, 255, 255}, 0, 0, true, screenWidth, screenHeight - 500);
    displayGrid();
}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.5;
    };
}
