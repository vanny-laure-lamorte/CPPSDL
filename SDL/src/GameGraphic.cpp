#include "GameGraphic.hpp"
#include "Window.hpp"

#include <iostream>
using namespace std;

GameGraphic::GameGraphic(SDL_Renderer *_renderer, int screenWidth, int screenHeight)
    : renderer(_renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{   


    element= new Element(renderer);
}

GameGraphic::~GameGraphic()
{
    GameunloadAllTextures(); 
    IMG_Quit(); 
}

void GameGraphic::GameloadBackgroundTexture(){
        backgroundTexture = element->loadTexture("assets/img/background.jpg");
}

void GameGraphic::GameunloadAllTextures()
{
    SDL_DestroyTexture(backgroundTexture);
}

void GameGraphic:: GamedisplayBackground(){
     if (backgroundTexture)
    {
        SDL_RenderCopy(renderer, backgroundTexture, nullptr, nullptr);
    }
    else
    {
        cerr << "Background texture is not loaded, cannot display it." << endl;
    }

}


