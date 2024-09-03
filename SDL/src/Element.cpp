#include "Element.hpp"

//* METHODES *//

Element::Element(SDL_Renderer *renderer) : renderer(renderer) {}

Element::~Element()
{
    IMG_Quit();
}

void Element::renderBackground(SDL_Renderer *renderer, SDL_Texture *surfaceTexture)
{
    SDL_RenderCopy(renderer, surfaceTexture, nullptr, nullptr);
}

// Images
SDL_Texture *Element::loadTexture(const string &imagePath)
{

    SDL_Surface *surface = IMG_Load(imagePath.c_str());
    if (!surface)
    {
        cerr << "Failed to load image: " << IMG_GetError() << endl;
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
    {
        cerr << "Failed to create texture from image: " << SDL_GetError() << endl;
    }
    return texture;
}

// Function to render an image
void Element::renderTexture(SDL_Texture *texture, int x, int y, int width, int height)
{
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}
