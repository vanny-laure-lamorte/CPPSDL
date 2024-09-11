#include "include/GameGraphic.hpp"

GameGraphic::GameGraphic(sf::RenderWindow *window, int screenWidth, int screenHeight)
    : window(window), screenWidth(screenWidth), screenHeight(screenHeight), animTransition(0)
{
    element = std::make_unique<Element>(window);
    loadTexture();

    if (!fontOswald.loadFromFile("assets\\fonts\\Oswald.ttf"))
    {
        std::cerr << "Error loading font" << std::endl;
    }
}

void GameGraphic::unloadAllTextures()
{

}

void GameGraphic::loadTexture()
{
    backgroundTexture = element->CreateTexture("assets\\img\\background_white.jpg");
    testTexture = element->CreateTexture("assets\\img\\test.png");
    profileUserTexture = element->CreateTexture("assets\\img\\profile_blue.png");

    if (!backgroundTexture || !testTexture)
    {
        std::cerr << "Failed to load one or more textures" << std::endl;
    }

    // Img blue btn
    blueBtnTexture = element->CreateTexture("assets\\img\\button_blue.png");
    if (!blueBtnTexture)
    {
        std::cerr << "Failed to load one or more textures" << blueBtnTexture << std::endl;
    }

    // Img user profile
    profileUserTexture = element->CreateTexture("assets\\img\\profile_blue.png");
    if (!profileUserTexture)
    {
        std::cerr << "Failed to load one or more textures" << profileUserTexture << std::endl;
    }
}

void GameGraphic::displayTexture()
{
    element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    // animation();

    displayBackgroud(); // Background
    displayTitle();     // Title
    displayGrid();      // Frame
    displayUserGame();
    displayUserProfile();
    displayTopPlayer();
    displayResetUndo(); // Reset & Undo
    displayGCU(); // GCU
}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.1f; // Use float literal for precision
    }
}

// Method to display background
void GameGraphic::displayBackgroud()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
}

// Method to display title and creators name
void GameGraphic::displayTitle()
{
    element->displayText(std::make_shared<sf::Font>(fontOswald), "2048", 50, sf::Color::White, 45, 50, false, 0, 0);                           // Name game
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Created by Lucas Martinie", 11, sf::Color::White, 35, 110, false, 0, 0);     // Creators names
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Thanh Lemelle & Vanny Lamorte", 11, sf::Color::White, 20, 125, false, 0, 0); // Creators names
}

//** GRID **//
// Method to display white frame
void GameGraphic::displayGrid()
{
    element->drawRoundedRectOpacity(screenWidth / 2 - (550 / 2), screenHeight / 2 - (550 / 2), 550, 550, 5, element->COLOR_LIGHTGREY1); // Grid rect
}

//** USER **//

void GameGraphic::displayUserGame()
{
    // Main Grey Rect
    rectUserFrameX = 30;
    rectUserFrameY = screenHeight / 2 - (285 / 2);
    rectUserFrameXOffset = rectUserFrameX + 15;

    element->drawRoundedRect(rectUserFrameX, rectUserFrameY, 180, 285, 10, element->COLOR_LIGHTGREY1);

    //*** SCORE ***//
    element->drawRoundedRect(rectUserFrameXOffset, rectUserFrameY + 15, 150, 40, 10, element->COLOR_WHITE);

    element->displayText(std::make_shared<sf::Font>(fontOswald), "Score", 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 20, rectUserFrameY + 20, false, 0, 0);
    // Value score
    element->displayText(std::make_shared<sf::Font>(fontOswald), "24112199", 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 70, rectUserFrameY + 20, false, 0, 0); 

    //*** BEST SCORE ***// 
    element->drawRoundedRect(rectUserFrameXOffset, rectUserFrameY + 65, 150, 40, 10, element->COLOR_WHITE);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Best", 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 20, rectUserFrameY + 70, false, 0, 0);
    // Value best 
    element->displayText(std::make_shared<sf::Font>(fontOswald), "20650", 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 70, rectUserFrameY + 70, false, 0, 0); 

    //*** TIMER ***/
    element->drawRoundedRect(rectUserFrameXOffset, rectUserFrameY + 115, 150, 40, 10, element->COLOR_WHITE);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Timer", 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 20, rectUserFrameY + 120, false, 0, 0);
    // Value Time
    element->displayText(std::make_shared<sf::Font>(fontOswald), "20:00", 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 70, rectUserFrameY + 120, false, 0, 0); 
}

void GameGraphic::displayResetUndo()
{
    // Reset
    element->renderTexture(blueBtnTexture, rectUserFrameXOffset, rectUserFrameY + 185, 150, 40);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Reset", 20, element->COLOR_WHITE, rectUserFrameX + 70, rectUserFrameY + 190, false, 0, 0);

    // Undo
    element->renderTexture(blueBtnTexture, rectUserFrameXOffset, rectUserFrameY + 230, 150, 40);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Undo", 20, element->COLOR_WHITE, rectUserFrameX + 70, rectUserFrameY + 235, false, 0, 0);
}

void GameGraphic::displayUserProfile()
{
    element->drawRoundedRect(rectPlayerFrameX, rectPlayerFrameY-85, 180, 60, 10, element->COLOR_LIGHTGREY1); // White Rect best players
    element->displayText(std::make_shared<sf::Font>(fontOswald), "LuThanVa", 18, element->COLOR_LIGHTGREY2, rectPlayerFrameXOffset+40, rectPlayerFrameY-75, false, 0, 0); // Display name of the user
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Joined in 2024", 11, element->COLOR_LIGHTGREY2, rectPlayerFrameXOffset+40, rectPlayerFrameY-50, false, 0, 0); // Display name of the user


    element->renderTexture(profileUserTexture, rectPlayerFrameX, rectPlayerFrameY-80, 50, 50); // Img profile picture
}


//** TOP PLAYERS **//
void GameGraphic::displayTopPlayer()
{    
    rectPlayerFrameX = 690; // Rect player position X
    rectPlayerFrameY = screenHeight / 2 - (320 / 2); // Rect player position Y
    rectPlayerFrameXOffset = rectPlayerFrameX + 15; // Rect player position X offset  

    element->drawRoundedRect(rectPlayerFrameX, rectPlayerFrameY, 180, 320, 10, element->COLOR_LIGHTGREY1); // White Rect best players

    element->displayText(std::make_shared<sf::Font>(fontOswald), "Top 5 players", 20, element->COLOR_LIGHTGREY2, 730, 160, false, 0, 0); // Text Top 5 players

    element->drawRoundedRect(705, 200, 150, 245, 10, element->COLOR_WHITE); // White Rect best players
}

 // Display Text General Conditions of Use
void GameGraphic::displayGCU(){
    element->displayText(std::make_shared<sf::Font>(fontOswald),"This page uses cookies to store data, preferences for analytics purposes. Read more in our Privacy Policy - Copyright LuThaVan Production studio 2024", 10, element->COLOR_LIGHTGREY2,screenWidth / 2 - (550 / 2), screenHeight-20, false, 0, 0); 
}

