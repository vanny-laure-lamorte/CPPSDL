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

    void displayTextNotCentered(TTF_Font *font, const std::string &writeText, SDL_Color color, SDL_Texture *textTexture, int x, int y);
    void displayTextCentered(TTF_Font *font, const std::string &writeText, SDL_Color color, SDL_Texture *textTexture, int screenWidth, int screenHeight);

   
    
    // Colors
    const SDL_Color COLOR_BLACK = {0, 0, 0, 255};
    const SDL_Color COLOR_WHITE = {255, 255, 255, 255};


private:
    SDL_Renderer *renderer;

};

#endif // ELEMENT_HPP
