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
    fontOswald = element -> LoadFont("assets/fonts/Oswald-Medium.ttf", 50);


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

}

void GameGraphic::displayTexture()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    element->renderTexture(testTexture, screenWidth / 2 - animTransition/2, screenHeight / 2 - animTransition/2, animTransition, animTransition);
    animation();
    displayTextTexture();


}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.1;
    };
}

void GameGraphic::displayTextTexture(){
    // SDL_Surface *textSurface = TTF_RenderText_Blended(fontOswald, "Poop", {255, 255, 255, 255});
    // if (!textSurface)
    // {
    //     cerr << "Failed to render text: " << TTF_GetError() << endl;
    // }

    // textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    // SDL_FreeSurface(textSurface);
    // if (!textTexture)
    // {
    //     cerr << "Failed to create text texture: " << SDL_GetError() << endl;
    // }

    textTexture = element -> createTextureText(fontOswald, "Poop", {255, 255, 255, 255}); 

   element -> displayText(fontOswald, "Poop", {255, 255, 255, 255}, textTexture, 100, 100);


    // int textWidth, textHeight;
    // TTF_SizeText(fontOswald, "Poop", &textWidth, &textHeight);    
    
    // SDL_Rect textRect = {screenWidth / 2 - textWidth / 2, 40, textWidth, textHeight};

    // SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);    
}