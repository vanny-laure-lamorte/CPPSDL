#include "GameGraphic.hpp"
#include "Element.hpp"

#include <iostream>
using namespace std;

GameGraphic::GameGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{
    element = new Element(renderer);
    loadTexture();
}

GameGraphic::~GameGraphic()
{
    IMG_Quit();
    delete element;
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
}

void GameGraphic::displayTexture()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    element->renderTexture(testTexture, screenWidth / 2 - animTransition/2, screenHeight / 2 - animTransition/2, animTransition, animTransition);
    animation();
}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.1;
    };
}