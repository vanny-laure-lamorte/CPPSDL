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

void GameGraphic::loadTexture()
{
    // Background
    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    if (!backgroundTexture) {
        cerr << "Failed to load background texture: " << SDL_GetError() << endl;
    }

    testTexture = element->CreateTexture("assets/img/test.png");

    // Display Name Game

    textTitleTexture = element->createTextureText(fontNameGame, "2048", {255, 255, 255, 255});
    if (!textTitleTexture) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

      textCreatorTexture1 = element->createTextureText(fontDetailText, "Created by Lucas Martinie", {255, 255, 255, 255});
    if (!textTitleTexture) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textCreatorTexture2 = element->createTextureText(fontDetailText, "Thanh Lemelle & Vanny", {255, 255, 255, 255});
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

    // Display Name Game
    element -> displayText(textTitleTexture, fontNameGame, "2048", {255, 255, 255, 255}, 20, 50, false, 0, 0);  

    element -> displayText(textCreatorTexture1, fontDetailText, "Created by Lucas Martinie", {255, 255, 255, 255}, 30, 80, false, 0, 0);

    element -> displayText(textCreatorTexture2, fontDetailText, "Thanh Lemelle & Vanny Lamorte", {255, 255, 255, 255}, 40, 100, false, 0, 0);

}