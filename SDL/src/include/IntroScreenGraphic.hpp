#ifndef INTROSCREENGRAPHIC_HPP
#define INTROSCREENGRAPHIC_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Element.hpp"
#include <iostream>
#include <cstring>

class IntroScreenGraphic
{
private:
    Element *element;
    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

    TTF_Font *fontOswald;
    TTF_Font *fontOswaldLittle;

    void loadIntroTexture();
    void unloadAllIntroTextures();

    // Animation
    float animTransition = 0;
    float animationSpeed = 0.1;
    float logoPositionX = 525;
    float logoPositionY = 350;
    bool logoChooseUser = false;
    bool isGrowing = true;
    void animation();

    // Input Rect
    float inputRectWidth = 0;
    float inputRectHeight = 0;
    SDL_Texture *enterNameTexture;
    SDL_Texture *backgroundTexture;

    SDL_Texture *logoAnimatedTexture;
    SDL_Texture *pressKeyTexture;
    SDL_Texture *titleTexture;
    SDL_Texture *pressSpaceTexture;
    bool displayPressSpace = false;

    SDL_Texture *directionnalKeyTexture;
    SDL_Texture *uKeyTexture;
    SDL_Texture *rKeyTexture;

    SDL_Texture *directionnalKeyTextTexture;
    SDL_Texture *rKeyTextTexture;
    SDL_Texture *uKeyTextTexture;

    Uint32 startTime;
    Uint32 colorChangeDuration = 5000;

    // Input Username
    void renderInputText();
    SDL_Texture *userNameInputTexture;
    SDL_Texture *pressStartTexture;

public:
    IntroScreenGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight);
    ~IntroScreenGraphic();

    // Input UserName
    std::string inputText = "";
    bool typingEnabled = false;

    // Intro States
    bool introPlayed = false;
    bool introPartOne = true;
    bool introPartTwo = true;
    bool moveToCorner = false;
    void displayAnimation();

    void displayIntro();
};

#endif