#include "Element.hpp"

Element::Element(SDL_Renderer *renderer) : renderer(renderer)
{

    if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
    {
        std::cerr << "Failed to initialize SDL_image for JPG: " << IMG_GetError() << std::endl;
    }
}

Element::~Element() {}

SDL_Texture *Element::CreateTexture(const std::string &imagePath)
{
    SDL_Surface *surface = IMG_Load(imagePath.c_str());
    if (!surface)
    {
        std::cerr << "Failed to load image: " << imagePath << ". Error: " << IMG_GetError() << std::endl;
        return nullptr;
    }

    SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture)
    {
        std::cerr << "Failed to create texture from image: " << imagePath << ". Error: " << SDL_GetError() << std::endl;
        return nullptr;
    }

    return texture;
}

void Element::renderTexture(SDL_Texture *texture, int x, int y, int width, int height)
{
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}
