#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
using namespace std;

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

//* RENDERER *//

SDL_Renderer *renderer;

//* COLORS *//
const SDL_Color COLOR_BLACK = {0, 0, 0, 255};
const SDL_Color COLOR_WHITE = {255, 255, 255, 255};

//* IMAGES *//

// Surface
SDL_Surface* surfaceBackground;

// Texture
SDL_Texture* textureBackground;

//* METHODES *//

// Background 

void unloadBackground() {
    SDL_DestroyTexture(textureBackground);
}

SDL_Texture* loadBackground(SDL_Renderer *renderer, SDL_Surface *&surface, const char *path)
{
    surface = IMG_Load(path);
    if (!surface)
    {
        cerr << "Failed to load image: " << surface << IMG_GetError() << endl;
    }

    SDL_Texture *surfaceTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!surfaceTexture)
    {
        cerr << "Failed to create texture for the background " << surfaceTexture << SDL_GetError() << endl;
    }

   return surfaceTexture;
}

void renderBackground(SDL_Renderer* renderer, SDL_Texture* surfaceTexture){

    SDL_RenderCopy(renderer, surfaceTexture, nullptr, nullptr);
}


// Images

// textureBoat = loadTexture(renderer,"assets/img/back.png");
// renderTexture(renderer, textureBoat, 100, 100, 500, 500);

SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& imagePath) {

    // Load image
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        cerr << "Failed to load image: " << imagePath << ". Error: " << IMG_GetError() << endl;
        return nullptr;
    }

    // Create texture from surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        cerr << "Failed to create texture from image: " << imagePath << ". Error: " << SDL_GetError() << endl;
        return nullptr;
    }

    return texture;
}

// Function to render an image
void renderTexture( SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height) {
    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

#endif

