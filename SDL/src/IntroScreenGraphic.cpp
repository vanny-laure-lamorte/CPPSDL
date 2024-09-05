#include <IntroScreenGraphic.hpp>

IntroScreenGraphic::IntroScreenGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight), introPlayed(false)
{
    element = new Element(renderer);
    fontOswald = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 50);
    fontOswaldLittle = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 20);
    startTime = SDL_GetTicks(); // Démarre le chronomètre

    loadIntroTexture();
}

IntroScreenGraphic::~IntroScreenGraphic()
{
    IMG_Quit();
    unloadAllIntroTextures();
    delete element;
    TTF_CloseFont(fontOswald);
}

void IntroScreenGraphic::unloadAllIntroTextures()
{
    SDL_DestroyTexture(logoAnimatedTexture);
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(titleTexture);
    SDL_DestroyTexture(pressSpaceTexture);
}

void IntroScreenGraphic::loadIntroTexture()
{
    logoAnimatedTexture = element->CreateTexture("assets/img/test.png");
    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    pressSpaceTexture = element->createTextureText(fontOswaldLittle, "Press Space to continue", element->COLOR_WHITE);
}

void IntroScreenGraphic::displayIntro()
{
    if (introPartOne)
    {
        Uint32 currentTime = SDL_GetTicks();
        Uint32 elapsedTime = currentTime - startTime;

        if (elapsedTime >= colorChangeDuration)
        {
            introPartOne = false;
            return;
        }

        float progression = static_cast<float>(elapsedTime % colorChangeDuration) / colorChangeDuration;

        if (progression <= 0.5f)
        {
            progression = progression * 2.0f;
        }
        else
        {
            progression = (1.0f - progression) * 2.0f;
        }

        Uint8 colorValue = static_cast<Uint8>(progression * 255);
        SDL_Color currentColor = {colorValue, colorValue, colorValue, 255};

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        titleTexture = element->createTextureText(fontOswald, "A game by ThaLuVa Studio", currentColor);
        element->displayText(titleTexture, fontOswald, "A game by ThaLuVa Studio", currentColor, 0, 0, true, screenWidth, screenHeight);
        SDL_DestroyTexture(titleTexture);

        SDL_RenderPresent(renderer);
    }
    else
    {
        displayAnimation();
    }
}

void IntroScreenGraphic::displayAnimation()
{
    animation();
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    element->renderTexture(logoAnimatedTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    if (displayPressSpace)
        element->displayText(pressSpaceTexture, fontOswaldLittle, "Press Space to continue", element->COLOR_WHITE, 0, 0, true, screenWidth, screenHeight + 400);
}

void IntroScreenGraphic::animation()
{
    if (isGrowing)
    {
        animTransition += animationSpeed;
        if (animTransition >= 350)
        {
            isGrowing = false;
            displayPressSpace = true;
            animationSpeed = 0.02f;
        }
    }
    else
    {
        animTransition -= animationSpeed;
        if (animTransition <= 325)
        {
            isGrowing = true;
        }
    }
}