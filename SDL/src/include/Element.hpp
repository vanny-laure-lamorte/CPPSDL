#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>

class Element
{
public:
    Element(SDL_Renderer *renderer);
    ~Element();

    // Images
    SDL_Texture *CreateTexture(const std::string &imagePath);
    void renderTexture(SDL_Texture *texture, int x, int y, int width, int height);

    // Fonts
    TTF_Font *LoadFont(const std::string &fontPath, int fontSize); // Load a font

    SDL_Texture *createTextureText(TTF_Font *font, const std::string &writeText, SDL_Color color);

    void displayText(SDL_Texture *textTexture, TTF_Font *font, const std::string &writeText, SDL_Color color, int x, int y, bool isCentered, int screenWidth, int screenHeight);

    // Rectangle
    void drawRoundedRect(int x, int y, int width, int height, int radius, SDL_Color color);

    // Gradienty

    void drawGradientRectProgressive(int x, int y, int width, int height, int tileValue);
    void drawGradientRect(int x, int y, int width, int height, SDL_Color startColor, SDL_Color endColor, bool horizontal);

    // Colors
    const SDL_Color COLOR_BLACK = {0, 0, 0, 255};
    const SDL_Color COLOR_WHITE = {255, 255, 255, 255};
    const SDL_Color COLOR_GREY = {200, 200, 200, 255};
    const SDL_Color COLOR_LIGHTGREY = {200, 200, 200, 255};
    const SDL_Color COLOR_PINK = {206, 0, 124, 255};
    const SDL_Color COLOR_BLUE = {75, 86, 228, 255};

private:
    SDL_Renderer *renderer;
};

#endif // ELEMENT_HPP
