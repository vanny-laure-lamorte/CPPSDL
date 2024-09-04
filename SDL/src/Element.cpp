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


// Method to display text

// How to use it ?
// To Display Centered Text: element.displayText(textTexture, font, "Hello World", {255, 255, 255, 255}, 0, 0, true, 800, 600);
// To Display Non-Centered Text: element.displayText(textTexture, font, "Hello World", {255, 255, 255, 255}, 100, 150, false, 0, 0); 

void Element::displayText(SDL_Texture *textTexture, TTF_Font *font, const std::string &writeText, SDL_Color color, int x, int y, bool isCentered, int screenWidth, int screenHeight) 
{

    // Check if the texture and font are valid
  if (!textTexture || !font) {
        std::cerr << "Invalid texture or font." << std::endl;
        return;
    }

    // Calculate text dimensions
    int textWidth, textHeight;
    TTF_SizeText(font, writeText.c_str(), &textWidth, &textHeight);
    SDL_Rect textRect;

    // Set text position if text not centered
    if (isCentered)
    {
        // Center the text on the screen
        textRect = {screenWidth / 2 - textWidth / 2, screenHeight / 2 - textHeight / 2, textWidth, textHeight};
    }
    else
    {
        // Set Text position if text not centered by using x, y 
        textRect = {x, y, textWidth, textHeight};
    }

    // Render the text texture
    SDL_RenderCopy(renderer, textTexture, nullptr, &textRect);
}

// Rect radius

void Element::drawRoundedRect(int x, int y, int width, int height, int radius, SDL_Color color) {
    // Set the draw color
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);

    // Draw the main body of the rectangle (center part without the rounded corners)
    SDL_Rect bodyRect = {x + radius, y, width - 2 * radius, height};
    SDL_RenderFillRect(renderer, &bodyRect);

    // Draw the left and right rectangles
    SDL_Rect leftRect = {x, y + radius, radius, height - 2 * radius};
    SDL_Rect rightRect = {x + width - radius, y + radius, radius, height - 2 * radius};
    SDL_RenderFillRect(renderer, &leftRect);
    SDL_RenderFillRect(renderer, &rightRect);

    // Draw the rounded corners using circles
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx * dx + dy * dy) <= (radius * radius)) {
                SDL_RenderDrawPoint(renderer, x + radius + dx, y + radius + dy); // Top-left corner
                SDL_RenderDrawPoint(renderer, x + width - radius + dx, y + radius + dy); // Top-right corner
                SDL_RenderDrawPoint(renderer, x + radius + dx, y + height - radius + dy); // Bottom-left corner
                SDL_RenderDrawPoint(renderer, x + width - radius + dx, y + height - radius + dy); // Bottom-right corner
            }
        }
    }
}





