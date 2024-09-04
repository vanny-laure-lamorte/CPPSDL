#include <iostream>
using namespace std;

#include "GameGraphic.hpp"
#include "Element.hpp"

GameGraphic::GameGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{
    element = new Element(renderer);
    loadTexture();

    // Font options
    fontOswald = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 35);
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
}

void GameGraphic::unloadAllTextures()
{
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(testTexture);

    // Font
    TTF_CloseFont(fontOswald);
    SDL_DestroyTexture(textTitleTexture);
}

void GameGraphic::displayTexture()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    animation();
    displayTitle();
}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.1;
    };
}

void GameGraphic::displayTitle()
{

    element -> drawRoundedRect(900/2, 100, 300, 200, 20, element->COLOR_WHITE);

    // Display title
    textTitleTexture = element->createTextureText(fontOswald, "TILE TWISTER", {255, 255, 255, 255});

    element -> displayText(textTitleTexture, fontOswald, "TILE TWISTER ", {255, 255, 255, 255}, 0, 0, true, 900, 110);
    // element -> displayText(textTitleTexture, fontOswald, "Poop", {255, 255, 255, 255}, 500, 150, false, 0, 0);
}