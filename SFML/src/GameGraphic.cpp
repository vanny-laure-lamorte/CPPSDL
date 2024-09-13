#include "include/GameGraphic.hpp"

#include <sstream>
#include <iomanip>

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

// Unload all texture
void GameGraphic::unloadAllTextures()
{
    backgroundTexture.reset();
    testTexture.reset();
    profileUserTexture.reset();
    blueBtnTexture.reset();
    gameOverTexture.reset();
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

    // Img looser logo
    gameOverTexture = element->CreateTexture("assets\\img\\GameOver.png");
    if (!gameOverTexture)
    {
        std::cerr << "Failed to load one or more textures" << gameOverTexture << std::endl;
    }
}

void GameGraphic::displayTexture()
{
    element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    // animation();

    displayBackgroud(); // Background
    displayGrid();      // Grid
    displayTitle();     // Title
    displayUserGame();
    displayUserProfile();
    displayResetUndo(); // Reset & Undo
    displayGCU();       // GCU
    displayChrono();    // Display Chrono

    displayTopPlayer();

    if (!gameBoard.canMove())
    {
        std::cout << "Game over!" << std::endl;
        displayLoose(); // Display loose message
        std::cout << "Press any key to exit." << std::endl;

        // Save score at the end of the game
        gameOptions.saveScore("Poop", "poop@gmail.com", "7894", timeString, "12");
    }
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
    element->displayText(std::make_shared<sf::Font>(fontOswald), "2048", 50, sf::Color::White, 405, 30, false, 0, 0);                           // Name game
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Created by Lucas Martinie", 11, sf::Color::White, 385, 90, false, 0, 0);      // Creators names
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Thanh Lemelle & Vanny Lamorte", 11, sf::Color::White, 375, 105, false, 0, 0); // Creators names
}

//*** USER ***//

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
    element->drawRoundedRect(rectPlayerFrameX, rectPlayerFrameY - 85, 180, 60, 10, element->COLOR_LIGHTGREY1);                                                                          // White Rect best players
    element->displayText(std::make_shared<sf::Font>(fontOswald), "LuThanVa", 18, element->COLOR_LIGHTGREY2, rectPlayerFrameXOffset + 40, rectPlayerFrameY - 75, false, 0, 0);           // Display name of the user
    element->displayText(std::make_shared<sf::Font>(fontOswald), "luThanVa@gmail.com", 11, element->COLOR_LIGHTGREY2, rectPlayerFrameXOffset + 40, rectPlayerFrameY - 50, false, 0, 0); // Display name of the user

    element->renderTexture(profileUserTexture, rectPlayerFrameX, rectPlayerFrameY - 80, 50, 50); // Img profile picture
}

//*** GRID ***//

// Display grid
void GameGraphic::displayGrid()
{

    //  Background transparent rect
    element->drawRoundedRectOpacity(screenWidth / 2 - (550 / 2), screenHeight / 2 - (550 / 2), 550, 550, 5, element->COLOR_LIGHTGREY1);

    // Grid of the game
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Tile &tile = gameBoard.tiles[i][j];
            int x = screenWidth / 2 - (400 / 2) + (100 * j);
            int y = screenHeight / 2 - (320 / 2) + (100 * i);

            if (tile.getValue() != 0)
            {
                element->drawRoundedRect(x, y, 90, 90, 10, element->COLOR_BLACK);

                // Texte
                std::string valueStr = std::to_string(tile.getValue());
                sf::Text text;
                int textX = x + (90) / 2;
                int textY = y + (90) / 2;
                element->displayText(std::make_shared<sf::Font>(fontOswald), valueStr, 20, element->COLOR_LIGHTGREY2, textX, textY, false, 0, 0);
            }
            else
                element->drawRoundedRect(x, y, 90, 90, 10, element->COLOR_WHITE);
        }
    }
}

// Update the grid after the user input
void GameGraphic::updateGame(const GameBoard &newGameBoard)
{
    gameBoard = newGameBoard;
}

// Display game over message
void GameGraphic::displayLoose()
{

    // Rect light grey background
    element->drawRoundedRect(screenWidth / 2 - (400 / 2), screenHeight / 2 - (320 / 2), 390, 390, 5, element->COLOR_LIGHTGREY1);

    // Rect Score and time
    element->drawRoundedRect(screenWidth / 2 - (400 / 2) + 20, screenHeight / 2 + 85, 350, 80, 5, element->COLOR_WHITE);

    // Display score
    element->displayText(std::make_shared<sf::Font>(fontOswald), "SCORE : ", 20, element->COLOR_DARKGREY1, 390, 400, false, 0, 0);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "52435", 20, element->COLOR_DARKGREY1, 470, 400, false, 0, 0);
    element->renderTexture(gameOverTexture, 300, 130, 300, 300);

    // Display time
    element->displayText(std::make_shared<sf::Font>(fontOswald), "TIME : ", 20, element->COLOR_DARKGREY1, 390, 430, false, 0, 0);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "02:46", 20, element->COLOR_DARKGREY1, 470, 430, false, 0, 0);
    element->renderTexture(gameOverTexture, 300, 130, 300, 300);
}

//*** TOP PLAYERS ***//

// List of the top 5 players
void GameGraphic::displayTopPlayer()
{

    rectPlayerFrameX = 690;                          // Rect player position X
    rectPlayerFrameY = screenHeight / 2 - (320 / 2); // Rect player position Y
    rectPlayerFrameXOffset = rectPlayerFrameX + 15;  // Rect player position X offset

    element->drawRoundedRect(rectPlayerFrameX, rectPlayerFrameY, 180, 320, 10, element->COLOR_LIGHTGREY1); // White Rect best players

    element->displayText(std::make_shared<sf::Font>(fontOswald), "Top 5 players", 20, element->COLOR_LIGHTGREY2, 730, 160, false, 0, 0); // Text Top 5 players

    element->drawRoundedRect(705, 200, 150, 245, 10, element->COLOR_WHITE); // White Rect best players

    // Get to five players from Json
    vector<pair<string, int>> topScores = gameOptions.getTopFiveScores();

    // Loop through the top scores and create textures for each

        for (size_t i = 0; i < topScores.size(); ++i)
        {

             const auto &playerScore = topScores[i];

            // Create textures for player name and score
            string playerNameText = playerScore.first;
            string playerScoreText = to_string(playerScore.second);

            // X and Y to position text
            int verticalOffset = 230;
            int lineHeight = 40;

            int nameX = 720;
            int nameY = verticalOffset + i * lineHeight;

            int scoreX = 790;
            int scoreY = nameY;

            element->displayText(std::make_shared<sf::Font>(fontOswald), playerNameText, 18, element->COLOR_LIGHTGREY2, nameX, nameY, false, 0, 0); // Text Name
            element->displayText(std::make_shared<sf::Font>(fontOswald), playerScoreText, 18, element->COLOR_LIGHTGREY2, scoreX, scoreY, false, 0, 0);    // Text Score

            
        }
    }

//*** GCU ***//

// Display Text General Conditions of Use
void GameGraphic::displayGCU()
{
    element->displayText(std::make_shared<sf::Font>(fontOswald), "This page uses cookies to store data, preferences for analytics purposes. Read more in our Privacy Policy - Copyright LuThaVan Production studio 2024", 10, element->COLOR_LIGHTGREY2, screenWidth / 2 - (550 / 2), screenHeight - 20, false, 0, 0);
}

//*** CHRONO ***/

void GameGraphic::displayChrono()
{
    sf::Time time = clock.getElapsedTime();
    int seconds = time.asSeconds();
    int minutes = seconds / 60;
    seconds = seconds % 60;

    std::stringstream ss;
    ss << std::setw(2) << std::setfill('0') << minutes << ":"
       << std::setw(2) << std::setfill('0') << seconds;
    if (gameBoard.canMove())
    {
        timeString = ss.str();
    }
    element->displayText(std::make_shared<sf::Font>(fontOswald), timeString, 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 70, rectUserFrameY + 120, false, 0, 0);
}

void GameGraphic::resetChrono()
{
    clock.restart();
}