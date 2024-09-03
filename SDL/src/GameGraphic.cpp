#include "GameGraphic.hpp"
#include "Window.hpp"

#include <iostream>
using namespace std;

GameGraphic::GameGraphic(SDL_Renderer *_renderer, int screenWidth, int screenHeight)
    : renderer(_renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{   

  if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG)) {
       cerr << "Failed to initialize SDL_image for JPG: " << IMG_GetError() << endl;
    }
}

GameGraphic::~GameGraphic()
{
    GameunloadAllTextures(); 
    IMG_Quit(); 
}

void GameGraphic::GameloadBackgroundTexture(){

     SDL_Surface *backgroundSurface = IMG_Load("assets/img/background.jpg");
    if (!backgroundSurface)
    {
        cerr << "Failed to load background image: " << IMG_GetError() << endl;
        return;
    }

    backgroundTexture = SDL_CreateTextureFromSurface(renderer, backgroundSurface);
    SDL_FreeSurface(backgroundSurface);

    if (!backgroundTexture)
    {
        cerr << "Failed to create background texture: " << SDL_GetError() << endl;
    }  

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


