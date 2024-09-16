#include "include/IntroScreenGraphic.hpp"
#include <iostream>

IntroScreenGraphic::IntroScreenGraphic(sf::RenderWindow* window, int screenWidth, int screenHeight)
    : window(window), screenWidth(screenWidth), screenHeight(screenHeight),
      inputBox1(sf::Vector2f(260, 40), sf::Vector2f(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +200), fontOswald),
      inputBox2(sf::Vector2f(260, 40), sf::Vector2f(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +270), fontOswald) // Second InputBox
{
    element = std::make_unique<Element>(window);
    loadIntroTexture();

    if (!fontOswald.loadFromFile("assets\\fonts\\Oswald.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }
}

void IntroScreenGraphic::loadIntroTexture()
{
    backgroundTexture = element->CreateTexture("assets\\img\\background_blue.jpg");
    if (!backgroundTexture)
    {
        std::cerr << "Failed to load background texture" << std::endl;
    }

    profileTexture = element->CreateTexture("assets\\img\\profile_blue.png");
    if (!profileTexture)
    {
        std::cerr << "Failed to load profile texture" << std::endl;
    }
}

void IntroScreenGraphic::unloadAllIntroTextures()
{
    backgroundTexture.reset();
    profileTexture.reset();
}

void IntroScreenGraphic::displayIntro()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);

    // Display profile picture
    element->renderTexture(profileTexture, screenWidth / 2 - (250 / 2), screenHeight / 2 - (150 / 2) - 200, 250, 250);

    // Draw test for input boxes
    // PSEUDO
    element->drawRoundedRect(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +200, 260, 40, 5, element->COLOR_WHITE); // White Rect
    element->displayText(std::make_shared<sf::Font>(fontOswald), "PSEUDO", 14, element->COLOR_LIGHTGREY2, screenWidth / 2 - (260 / 2)+5, 305, false, 0, 0); // Text    

    // INFO ?
    element->displayText(std::make_shared<sf::Font>(fontOswald), "E-MAIL", 14, element->COLOR_LIGHTGREY2, screenWidth / 2 - (260 / 2)+5, 375, false, 0, 0); // Text
    element->drawRoundedRect(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +270, 260, 40, 5, element->COLOR_WHITE); // Rect white

    // Validation
    element->drawRoundedRect(screenWidth / 2 - (260 / 2), screenHeight / 2 - (350 / 2) +340, 260, 40, 5, element->COLOR_BLUE); // Rect white
    element->displayText(std::make_shared<sf::Font>(fontOswald), "NEXT", 18, element->COLOR_WHITE, 445, screenHeight / 2 - (350 / 2) +350, false, 0,0); // Text

    // Other UI elements (buttons, text)
    element->displayText(std::make_shared<sf::Font>(fontOswald), "GET STARTED", 30, element->COLOR_BLACK, 380, screenHeight / 2 - (350 / 2) + 120, false, 0, 0);

    // Draw Input Boxes
    inputBox1.draw(*window);
    inputBox2.draw(*window);
}

void IntroScreenGraphic::handleMouseInput(sf::Vector2i mousePos)
{
    inputBox1.checkFocus(mousePos);
    inputBox2.checkFocus(mousePos);
}

void IntroScreenGraphic::handleTextInput(sf::Event event)
{
    inputBox1.handleInput(event);
    inputBox2.handleInput(event);
}
