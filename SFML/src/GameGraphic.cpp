#include "include/GameGraphic.hpp"

#include <sstream>
#include <iomanip>
#include <sstream> 

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
    displayBackgroud(); // Background
    displayGrid();      // Grid
    displayTitle();     // Title
    displayUserGame();
    displayUserProfile();
    displayResetUndo(); // Reset & Undo
    displayGCU();       // GCU
    displayChrono();    // Display Chrono
    displayTopPlayer();
    displayBestPlayer(); 

    if (!gameBoard.canMove())
    {
        displayLoose(); // Display loose message
        if(!saveScore){
        gameOptions.saveScore(pseudo, mail, to_string(gameBoard.getScore()), timeString, "1");
        saveScore = true;
        }
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
   
   // Get the user best score from json file
    if (!scoreFetched){
    scoreUserInt = gameOptions.getUserScore(pseudo);
    scoreFetched = true;
    }; 

    // Convert the score from int to string
    string scoreUserstr = to_string(scoreUserInt );

    // Main Grey Rect
    rectUserFrameX = 30;
    rectUserFrameY = screenHeight / 2 - (285 / 2);
    rectUserFrameXOffset = rectUserFrameX + 15;

    element->drawRoundedRect(rectUserFrameX, rectUserFrameY, 180, 285, 10, element->COLOR_LIGHTGREY1);

    //*** SCORE ***//
    element->drawRoundedRect(rectUserFrameXOffset, rectUserFrameY + 15, 150, 40, 10, element->COLOR_WHITE);

    element->displayText(std::make_shared<sf::Font>(fontOswald), "Score", 20, element->COLOR_DARKGREY2, rectUserFrameX + 20, rectUserFrameY + 20, false, 0, 0);
    // Value score
    element->displayText(std::make_shared<sf::Font>(fontOswald), std::to_string(updateScore(gameBoard.getScore())), 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 70, rectUserFrameY + 20, false, 0, 0);

    //*** BEST SCORE ***//
    element->drawRoundedRect(rectUserFrameXOffset, rectUserFrameY + 65, 150, 40, 10, element->COLOR_WHITE);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Best", 20, element->COLOR_DARKGREY2, rectUserFrameX + 20, rectUserFrameY + 70, false, 0, 0);
    // Value best
    element->displayText(std::make_shared<sf::Font>(fontOswald), scoreUserstr, 20, element->COLOR_LIGHTGREY2, rectUserFrameX + 70, rectUserFrameY + 70, false, 0, 0);

    //*** TIMER ***/
    element->drawRoundedRect(rectUserFrameXOffset, rectUserFrameY + 115, 150, 40, 10, element->COLOR_WHITE);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Timer", 20, element->COLOR_DARKGREY2, rectUserFrameX + 20, rectUserFrameY + 120, false, 0, 0);
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
    element->displayText(std::make_shared<sf::Font>(fontOswald),pseudo , 18, element->COLOR_DARKGREY1, rectPlayerFrameXOffset + 40, rectPlayerFrameY - 75, false, 0, 0);           // Display name of the user
    element->displayText(std::make_shared<sf::Font>(fontOswald),mail , 11, element->COLOR_LIGHTGREY2, rectPlayerFrameXOffset + 40, rectPlayerFrameY - 50, false, 0, 0); // Display name of the user

    element->renderTexture(profileUserTexture, rectPlayerFrameX, rectPlayerFrameY - 80, 50, 50); // Img profile picture
}

//*** GRID ***//

sf::Color GameGraphic::determineColor(int value) {
    sf::Color lightPink = sf::Color(255, 182, 193); 
    sf::Color normalPink = sf::Color(249, 99, 209); 
    sf::Color darkpink = sf::Color(252, 58, 200);
    sf::Color verydarkpink = sf::Color(188, 0, 135); 
    sf::Color cyan = sf::Color(49, 194, 224);         
        
    if (value < 16) {
        return lightPink;
    } else if (value >= 16 && value <= 64) {
        return normalPink;
    } 
    else if (value >=64 && value <= 256){
                return darkpink;
    }
    else if (value <2048){
        return verydarkpink;
    }
    else {

        return cyan;
    }
}

// Display grid
void GameGraphic::displayGrid() 
{
    element->drawRoundedRectOpacity(screenWidth / 2 - (550 / 2), screenHeight / 2 - (550 / 2), 550, 550, 5, element->COLOR_LIGHTGREY1);

    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Tile &tile = gameBoard.tiles[i][j];
            int x = screenWidth / 2 - (400 / 2) + (100 * j);
            int y = screenHeight / 2 - (320 / 2) + (100 * i);

            if (tile.getValue() != 0)
            {
                sf::Color tileColor = determineColor(tile.getValue());
                
                element->drawRoundedRect(x, y, 90, 90, 10, tileColor);

                std::string valueStr = std::to_string(tile.getValue());
                sf::Text text;
                int textX = x + (90) / 2;
                int textY = y + (90) / 2;
                element->displayText(std::make_shared<sf::Font>(fontOswald), valueStr, 20, element->COLOR_BLACK, textX, textY, false, 0, 0);
            }
            else
                element->drawRoundedRect(x, y, 90, 90, 10, element->COLOR_LIGHTGREY1);
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
    element->displayText(std::make_shared<sf::Font>(fontOswald), "SCORE : ", 20, element->COLOR_DARKGREY2, 390, 400, false, 0, 0);
    element->displayText(std::make_shared<sf::Font>(fontOswald), to_string(gameBoard.getScore()), 20, element->COLOR_DARKGREY1, 470, 400, false, 0, 0);
    element->renderTexture(gameOverTexture, 300, 130, 300, 300);

    // Display time
    element->displayText(std::make_shared<sf::Font>(fontOswald), "TIME : ", 20, element->COLOR_DARKGREY2, 390, 430, false, 0, 0);
    element->displayText(std::make_shared<sf::Font>(fontOswald), timeString, 20, element->COLOR_DARKGREY1, 470, 430, false, 0, 0);
    element->renderTexture(gameOverTexture, 300, 130, 300, 300);
}

//*** TOP PLAYERS ***//

void GameGraphic::displayBestPlayer(){

    // Get name, score, time and match from the best player
    auto [playerName, score, time, matchCount] = gameOptions.getBestScore();
    string bestPlayerName = playerName;
    std::ostringstream oss;
    oss << bestPlayerName << "'s";

    string bestScore = score;
    string bestTime = time;
    string bestMatchCount = matchCount;;

    // White Rect
    element->drawRoundedRect(rectPlayerFrameXOffset, rectPlayerFrameY + 50, 150, 130, 10, element->COLOR_WHITE); // White Rect best players

    int valuePositionText =  rectPlayerFrameX +80;
    int policeValueUser = 15;

    // Name
    element->displayText(std::make_shared<sf::Font>(fontOswald),oss.str(), 18, element->COLOR_DARKGREY2, rectPlayerFrameX +30 , 200, false, 0, 0); 
    element->displayText(std::make_shared<sf::Font>(fontOswald),"Best Game Details", 15, element->COLOR_DARKGREY2, rectPlayerFrameX +30 , 220, false, 0, 0); 

    // Score
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Score - ", policeValueUser, element->COLOR_DARKGREY2, rectPlayerFrameX +30 , 250, false, 0, 0); 
    element->displayText(std::make_shared<sf::Font>(fontOswald), score, policeValueUser, element->COLOR_LIGHTGREY2, valuePositionText, 250, false, 0, 0); 

    // Time
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Time - ", policeValueUser, element->COLOR_DARKGREY2, rectPlayerFrameX +30 , 270, false, 0, 0);
    element->displayText(std::make_shared<sf::Font>(fontOswald),time, policeValueUser, element->COLOR_LIGHTGREY2, valuePositionText, 270, false, 0, 0);

    // Match 
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Match - ", policeValueUser, element->COLOR_DARKGREY2, rectPlayerFrameX +30 , 290, false, 0, 0); 
    element->displayText(std::make_shared<sf::Font>(fontOswald), matchCount, policeValueUser, element->COLOR_LIGHTGREY2, valuePositionText, 290, false, 0, 0); 
}

// List of the top 5 players
void GameGraphic::displayTopPlayer()
{
    rectPlayerFrameX = 690;                          // Rect player position X
    rectPlayerFrameY = screenHeight / 2 - (320 / 2); // Rect player position Y
    rectPlayerFrameXOffset = rectPlayerFrameX + 15;  // Rect player position X offset

    // Grey and White rect
    element->drawRoundedRect(rectPlayerFrameX, rectPlayerFrameY, 180, 400, 10, element->COLOR_LIGHTGREY1); // Grey Rect best players
    element->drawRoundedRect(rectPlayerFrameXOffset, rectPlayerFrameY + 190, 150, 190, 10, element->COLOR_WHITE); // White Rect best players

    // Title
    element->displayText(std::make_shared<sf::Font>(fontOswald), "TOP PLAYERS", 20, element->COLOR_DARKGREY1, 730, 150, false, 0, 0); // Text Top 5 players

    // Get top five players from Json
    vector<pair<string, int>> topScores = gameOptions.getTopFiveScores();

    // Loop through the top scores and create textures for each

        for (size_t i = 0; i < topScores.size(); ++i)
        {

             const auto &playerScore = topScores[i];

            // Create textures for player name and score
            string playerNameText = playerScore.first;
            string playerScoreText = to_string(playerScore.second);

            // X and Y to position text
            int verticalOffset = 350;
            int lineHeight = 30;

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

int GameGraphic::updateScore(int newScore)
{
    if (updatedScoreValue != newScore)
    {
        updatedScoreValue = newScore;
    }
    return updatedScoreValue;
}