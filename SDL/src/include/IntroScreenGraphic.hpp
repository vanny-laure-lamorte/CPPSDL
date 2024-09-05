#ifndef INTROSCREENGRAPHIC_HPP
#define INTROSCREENGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Element.hpp"

class IntroScreenGraphic
{
private:
    Element *element;
    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

    TTF_Font *fontOswald;
    TTF_Font *fontOswaldLittle;

    float animTransition = 0;
    float animationSpeed = 0.1;
    bool isGrowing = true;
    void animation();

    void loadIntroTexture();
    void unloadAllIntroTextures();

    SDL_Texture *logoAnimatedTexture;
    SDL_Texture *pressKeyTexture;
    SDL_Texture *titleTexture;
    SDL_Texture *pressSpaceTexture;
    bool displayPressSpace = false;

    SDL_Texture *backgroundTexture;

    Uint32 startTime;
    Uint32 colorChangeDuration = 5000;

public:
    IntroScreenGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight);
    ~IntroScreenGraphic();

    bool introPlayed = false;
    bool introPartOne = true;
    void displayAnimation();

    void displayIntro();
};

#endif