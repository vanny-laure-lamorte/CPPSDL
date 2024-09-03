#include "Element.hpp"

// Définition des variables globales
SDL_Renderer *renderer = nullptr;
const SDL_Color COLOR_BLACK = {0, 0, 0, 255};
const SDL_Color COLOR_WHITE = {255, 255, 255, 255};

//* METHODES *//

// Background 
SDL_Texture* loadBackground(SDL_Renderer *renderer, SDL_Surface *&surface, const char *path)
{
    surface = IMG_Load(path);
    if (!surface)
    {
        cerr << "Failed to load image: " << IMG_GetError() << endl;
        return nullptr;
    }

    SDL_Texture *surfaceTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!surfaceTexture)
    {
        cerr << "Failed to create texture for the background " << SDL_GetError() << endl;
    }

   return surfaceTexture;
}

void renderBackground(SDL_Renderer* renderer, SDL_Texture* surfaceTexture){
    SDL_RenderCopy(renderer, surfaceTexture, nullptr, nullptr);
}

// Images
SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& imagePath) {
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        cerr << "Failed to load image: " << IMG_GetError() << endl;
        return nullptr;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        cerr << "Failed to create texture from image: " << SDL_GetError() << endl;
    }
    return texture;
}

// Function to render an image
void renderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height) {
    SDL_Rect destRect = { x, y, width, height };
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}
