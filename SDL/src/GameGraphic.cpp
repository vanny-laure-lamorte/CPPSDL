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

void GameGraphic::loadTexture()
{
    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    testTexture = element->CreateTexture("assets/img/test.png");
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
    element->drawRoundedRect(900 / 2, 100, 300, 200, 20, element->COLOR_WHITE);
    element->displayText(textTitleTexture, fontOswald, "TILE TWISTER ", {255, 255, 255, 255}, 0, 0, true, 900, 110);
    element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);


    // Display title
    animation();
}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.5;
    };
}
