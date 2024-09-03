using namespace std;

#include "Element.hpp"
#include <stdexcept>

Element::Element(SDL_Renderer *renderer) : renderer(renderer)
{

    // Initialize Image
    if (!(IMG_Init(IMG_INIT_JPG) & IMG_INIT_JPG))
    {
        std::cerr << "Failed to initialize SDL_image for JPG: " << IMG_GetError() << std::endl;
    }

    // Initialize TTF
    if (TTF_Init() == -1)
    {
        throw std::runtime_error("TTF_Init Error: " + std::string(TTF_GetError()));
    }
}

Element::~Element()
{
    IMG_Quit(); // Quit images when Element is destroyed

    TTF_Quit();
}

//* IMAGES *//

// Create Texture
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

// Render Texture
void Element::renderTexture(SDL_Texture *texture, int x, int y, int width, int height)
{
    SDL_Rect destRect = {x, y, width, height};
    SDL_RenderCopy(renderer, texture, nullptr, &destRect);
}

//* FONT *//

// Method to Load a font
TTF_Font *Element::LoadFont(const std::string &fontPath, int fontSize)
{
    TTF_Font *font = TTF_OpenFont(fontPath.c_str(), fontSize);
    if (!font)
    {
        std::cerr << "Failed to load font: " << fontPath << ". Error: " << TTF_GetError() << std::endl;
    }
    return font;
}

// Method to create texture for a text
SDL_Texture *Element::createTextureText(TTF_Font *font, const std::string &writeText, SDL_Color color)
{

    SDL_Surface *textSurface = TTF_RenderText_Blended(font, writeText.c_str(), color);
    if (!textSurface)
    {
        cerr << "Failed to render text: " << TTF_GetError() << endl;
    }

    SDL_Texture *textTexture  = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    if (!textTexture)
    {
        cerr << "Failed to create text texture: " << SDL_GetError() << endl;
    }
    return textTexture;
}


// Method to create display text
void Element::displayText(TTF_Font *font, const std::string &writeText, SDL_Color color, SDL_Texture *textTexture, int x, int y)
{
    int textWidth, textHeight;
    TTF_SizeText(font,writeText.c_str(), &textWidth, &textHeight);    
    
    SDL_Rect textRect = {x , y, textWidth, textHeight};

    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}



