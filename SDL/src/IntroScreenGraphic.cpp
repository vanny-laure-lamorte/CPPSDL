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
    SDL_DestroyTexture(enterNameTexture);
    SDL_DestroyTexture(directionnalKeyTexture);
    SDL_DestroyTexture(uKeyTexture);
    SDL_DestroyTexture(rKeyTexture);

    SDL_DestroyTexture(directionnalKeyTextTexture);
    SDL_DestroyTexture(rKeyTextTexture);
    SDL_DestroyTexture(uKeyTextTexture);

    SDL_DestroyTexture(userNameInputTexture);
    SDL_DestroyTexture(pressStartTexture);
}

void IntroScreenGraphic::loadIntroTexture()
{
    logoAnimatedTexture = element->CreateTexture("assets/img/test.png");
    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    pressSpaceTexture = element->createTextureText(fontOswaldLittle, "Press Space to continue", element->COLOR_WHITE);
    enterNameTexture = element->createTextureText(fontOswaldLittle, "Please enter your name", element->COLOR_WHITE);

    directionnalKeyTextTexture = element->createTextureText(fontOswaldLittle, "Use ZQSD (or arrows) to move tiles", element->COLOR_WHITE);
    uKeyTextTexture = element->createTextureText(fontOswaldLittle, "Press u to undo last move", element->COLOR_WHITE);
    rKeyTextTexture = element->createTextureText(fontOswaldLittle, "Press r to reset game", element->COLOR_WHITE);

    directionnalKeyTexture = element->CreateTexture("assets/img/directionalKey.png");
    uKeyTexture = element->CreateTexture("assets/img/uKey.png");
    rKeyTexture = element->CreateTexture("assets/img/rKey.png");

    userNameInputTexture = element->CreateTexture("assets/img/userNameInputBox.png");
    pressStartTexture = element->CreateTexture("assets/img/btn_start.png");
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
    else if (introPartTwo)
    {
        element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
        displayAnimation();
    }
    else
    {
        element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    }
}

void IntroScreenGraphic::displayAnimation()
{
    animation(); // Manage size of elements

    element->renderTexture(logoAnimatedTexture, logoPositionX - animTransition / 2, logoPositionY - animTransition / 2, animTransition, animTransition); // Logo size and position

    if (displayPressSpace) // Display "Press space" button once logo reach its full size
    {
        element->displayText(pressSpaceTexture, fontOswaldLittle, "Press Space to continue", element->COLOR_WHITE, 0, 0, true, screenWidth, screenHeight + 400);
    }
    if (moveToCorner && animTransition <= 150) // Draw input box if logo have moved
    {
        // element->drawRoundedRect(screenWidth / 2 - inputRectWidth / 2 - 5, screenHeight / 2 - inputRectHeight / 2 - 5, inputRectWidth + 10, inputRectHeight + 10, 10, element->COLOR_PINK);
        // element->drawRoundedRect(screenWidth / 2 - inputRectWidth / 2, screenHeight / 2 - inputRectHeight / 2, inputRectWidth, inputRectHeight, 10, element->COLOR_WHITE);

        element->renderTexture(userNameInputTexture, screenWidth / 2 - inputRectWidth / 2 - 5, screenHeight / 2 - inputRectHeight / 2 - 5, inputRectWidth + 10, inputRectHeight + 10);
        renderInputText();

        if (typingEnabled) // display Enter your name and Key bindings if input box is ready
        {
            element->displayText(enterNameTexture, fontOswaldLittle, "Please enter your name", element->COLOR_WHITE, 0, 0, true, screenWidth, screenHeight - 150);
            element->renderTexture(pressStartTexture, screenWidth / 2 - 100, 400, 200, 30); // Start button

            element->drawRectOpacity(screenWidth / 2 - 300, 560, 600, 120, element->COLOR_WHITE_TRANSPARENT); // Transparent Rect

            element->renderTexture(directionnalKeyTexture, 280, 500, 225, 225); // ZQSD/arrow keys
            element->displayText(directionnalKeyTextTexture, fontOswaldLittle, "Use ZQSD (or arrows) to move tiles", element->COLOR_WHITE, 270, 650, false, 0, 0);

            element->renderTexture(uKeyTexture, 570, 570, 50, 50);
            element->displayText(uKeyTextTexture, fontOswaldLittle, "Press u to undo last move", element->COLOR_WHITE, 615, 580, false, 0, 0);

            element->renderTexture(rKeyTexture, 570, 620, 50, 50);
            element->displayText(rKeyTextTexture, fontOswaldLittle, "Press r to reset game", element->COLOR_WHITE, 615, 630, false, 0, 0);
        }
    }
}

void IntroScreenGraphic::animation()
{
    if (!moveToCorner) // While waiting for space key to be pressed, display breathing logo
    {
        if (isGrowing) // Growing
        {
            animTransition += animationSpeed;
            if (animTransition >= 350)
            {
                isGrowing = false;
                displayPressSpace = true;
                animationSpeed = 0.02f;
            }
        }
        else // Shrinking
        {
            animTransition -= animationSpeed;
            if (animTransition <= 325)
            {
                isGrowing = true;
            }
        }
    }
    else // Move Logo to Upleft corner
    {
        if (!logoChooseUser) // If Logo havn't reached its size yet (because of skip) Gives it its real size
        {
            animTransition = 350;
            logoChooseUser = true;
        }
        if (animTransition > 150) // Shrink and move logo
        {
            animTransition -= 0.07;
            logoPositionX -= 0.15;
            logoPositionY -= 0.09;
        }
        else // Create input Box by upsizing it
        {
            if (inputRectWidth < screenWidth / 2 - 100)
            {
                inputRectWidth += 1.1;
                inputRectHeight += 1.2;
            }
            else
            {
                if (!typingEnabled)
                {
                    SDL_StartTextInput();
                    typingEnabled = true;
                }
            }
        }

        displayPressSpace = false;
    }
}

void IntroScreenGraphic::renderInputText()
{
    if (!inputText.empty())
    {
        int textWidth = 0;
        int textHeight = 0;

        if (TTF_SizeText(fontOswaldLittle, inputText.c_str(), &textWidth, &textHeight) == 0)
        {
            SDL_Texture *inputTextTexture = element->createTextureText(fontOswaldLittle, inputText.c_str(), element->COLOR_BLACK);

            element->renderTexture(inputTextTexture, screenWidth / 2 - textWidth / 2, screenHeight / 2 - textHeight / 2, textWidth, textHeight);

            SDL_DestroyTexture(inputTextTexture);
        }
    }
}
