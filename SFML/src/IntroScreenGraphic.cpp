#include "include/IntroScreenGraphic.hpp"

IntroScreenGraphic::IntroScreenGraphic(sf::RenderWindow *window, int screenWidth, int screenHeight)
    : window(window), screenWidth(screenWidth), screenHeight(screenHeight)
{

    element = std::make_unique<Element>(window);

    loadIntroTexture();

     if (!fontOswald.loadFromFile("assets\\fonts\\Oswald.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }

}


void IntroScreenGraphic::unloadAllIntroTextures()
{
    backgroundTexture.reset();
    profileTexture.reset();

}

void IntroScreenGraphic::loadIntroTexture()
{
    backgroundTexture = element->CreateTexture("assets\\img\\background_blue.jpg");
     if (!backgroundTexture)
    {
        std::cerr << "Failed to load one or more textures" << std::endl;
    }

    profileTexture = element->CreateTexture("assets\\img\\profile_blue.png");
    if (!profileTexture)
    {
        std::cerr << "Failed to load one or more textures" << profileTexture << std::endl;
    }
}

void IntroScreenGraphic::displayIntro()
{
    // Img Background 
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);

    // Rect transparent
    element -> TransparentRect(screenWidth/2 -(300/2) , screenHeight/2 -(350/2) +60, 300, 350, 5, element ->COLOR_WHITE, 100); 

    // Img profile
    element->renderTexture(profileTexture, screenWidth / 2 - (250 / 2) , screenHeight / 2 - (150 / 2) -200, 250, 250); 

    // Get Started
    element->displayText(std::make_shared<sf::Font>(fontOswald), "GET STARTED", 30, element->COLOR_BLACK, 380, screenHeight / 2 - (350 / 2) +120, false, 0, 0);     

    // Pseudo
    // rappel : input box a incerer ici
    element->drawRoundedRect(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +200, 260, 40, 5, element->COLOR_WHITE); // White Rect
    element->displayText(std::make_shared<sf::Font>(fontOswald), "PSEUDO", 14, element->COLOR_LIGHTGREY2, screenWidth / 2 - (260 / 2)+5, 305, false, 0, 0); // Text    

    // INFO ?
    element->displayText(std::make_shared<sf::Font>(fontOswald), "E-MAIL", 14, element->COLOR_LIGHTGREY2, screenWidth / 2 - (260 / 2)+5, 375, false, 0, 0); // Text
    element->drawRoundedRect(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +270, 260, 40, 5, element->COLOR_WHITE); // Rect white

    // Validation
    element->drawRoundedRect(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +340, 260, 40, 5, element->COLOR_BLUE); // Rect white
    element->displayText(std::make_shared<sf::Font>(fontOswald), "NEXT", 18, element->COLOR_WHITE, 445, screenHeight / 2 - (350 / 2) +350, false, 0,0); // Text
}
