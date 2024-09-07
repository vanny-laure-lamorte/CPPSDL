#include "GameGraphic.hpp"

#include <fstream>
#include <iostream>

//** Save Score ***//
#include <nlohmann/json.hpp>
#include <fstream> 
#include <string> 
using json = nlohmann::json;

GameGraphic::GameGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{

    element = new Element(renderer);
    gameOptions = new GameOptions(renderer, screenWidth, screenHeight); 
    

    // Test to display the best game
    auto [playerName, score, time, matchCount] = gameOptions -> getBestScore();

    // Affichez les résultats
    cout << "Meilleur joueur: " << playerName << endl;
    cout << "Meilleur score: " << score << endl;
    cout << "Temps: " << time << endl;
    cout << "Nombre de matchs: " << matchCount << endl;

    // Font options
    fontOswald = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 35);
    fontNameGame = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 50);
    fontDetailText = element->LoadFont("assets/fonts/Inter.ttf", 9);
    fontDetailTextBold = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 10);
    fontGameInfo = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 16);
    fontUserProfile = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 14);
    fontBestPlayer = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 20);

    loadGameTexture();

    currentTime = SDL_GetTicks();
}

GameGraphic::~GameGraphic()
{
    IMG_Quit();
    unloadAllTextures();
    delete element;

    // Font
    TTF_CloseFont(fontOswald);
    TTF_CloseFont(fontNameGame);
    TTF_CloseFont(fontDetailText);
    TTF_CloseFont(fontDetailTextBold);
    TTF_CloseFont(fontUserProfile);
    TTF_CloseFont(fontBestPlayer);
}

void GameGraphic::updateGameBoard(const GameBoard &newGameBoard)
{
    gameBoard = newGameBoard;
}

void GameGraphic::displayGrid()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Tile &tile = gameBoard.tiles[i][j];
            int x = 450 + (100 * j);
            int y = 210 + (100 * i);

            element->drawGradientRect(x, y, 92, 92, element->COLOR_LIGHTGREY, element->COLOR_BLACK, true);

            if (tile.getValue() != 0)
            {
                element->drawGradientRectProgressive(x, y, 90, 90, tile.getValue());
                std::string valueStr = std::to_string(tile.getValue());
                SDL_Texture *textTexture = element->createTextureText(fontOswald, valueStr, element->COLOR_WHITE);

                int textWidth, textHeight;
                SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

                int textX = x + (90 - textWidth) / 2;
                int textY = y + (90 - textHeight) / 2;

                element->renderTexture(textTexture, textX, textY, textWidth, textHeight);

                SDL_DestroyTexture(textTexture);
            }
            else
                element->drawGradientRect(x, y, 90, 90, element->COLOR_LIGHTGREYBIS, element->COLOR_DARKGREY, true);
        }
    }
}

void GameGraphic::loadGameTexture()
{
    //*** BACKGROUND ***//

    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    if (!backgroundTexture)
    {
        cerr << "Failed to load background texture: " << SDL_GetError() << endl;
    }

    //*** IMAGE ***//

    testTexture = element->CreateTexture("assets/img/test.png");
    tileImgTexture = element->CreateTexture("assets/img/square.png");
    pinkRectImgTexture = element->CreateTexture("assets/img/btn_pink.png"); // Pink rectangle

    textValueTexture = element->createTextureText(fontOswald, "default", {255, 255, 255, 255});

    userLogoTexture = element->CreateTexture("assets/img/profile.png");

    resetImgTexture = element->CreateTexture("assets/img/reset_white.png"); // Img undo
    undoImgTexture = element->CreateTexture("assets/img/undo_white.png");   // Img undo

    //*** TEXT ***//

    // Text Name Game
    textTitleTexture = element->createTextureText(fontNameGame, "2048", {255, 255, 255, 255});
    if (!textTitleTexture)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textCreatorTexture1 = element->createTextureText(fontDetailText, "Created by Lucas Martinie", element->COLOR_WHITE);
    if (!textCreatorTexture1)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textCreatorTexture2 = element->createTextureText(fontDetailText, "Thanh Lemelle & Vanny Lamorte", element->COLOR_WHITE);
    if (!textCreatorTexture2)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text name user

    textUserInfo2 = element->createTextureText(fontDetailText, "Joined in 2022", {255, 255, 255, 255});
    if (!textUserInfo2)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text Best Player
    textBestPlayer1 = element->createTextureText(fontBestPlayer, "Lucas Martinie", {255, 255, 255, 255});
    if (!textBestPlayer1)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textBestPlayer2 = element->createTextureText(fontDetailText, "Joined in 1995", {255, 255, 255, 255});
    if (!textBestPlayer2)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text Reset and undo
    textReset = element->createTextureText(fontGameInfo, "Reset", {255, 255, 255, 255});
    if (!textReset)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textUndo = element->createTextureText(fontGameInfo, "Undo", {255, 255, 255, 255});
    if (!textUndo)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text Game State

    textScore = element->createTextureText(fontGameInfo, "Score", {255, 255, 255, 255});
    if (!textScore)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textBest = element->createTextureText(fontGameInfo, "Best", {255, 255, 255, 255});
    if (!textBest)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textTimer = element->createTextureText(fontGameInfo, "Timer", {255, 255, 255, 255});
    if (!textCreatorTexture2)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text View More
    textViewMore = element->createTextureText(fontDetailTextBold, "View More", element->COLOR_PINK);
    if (!textViewMore)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text rules
    textRules = element->createTextureText(fontDetailTextBold, "Check Rules", {255, 255, 255, 255});
    if (!textRules)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text General Conditions of Use
    textGCU1 = element->createTextureText(fontDetailText, "This page uses cookies to store data, preferences, and for analytics and ads purposes. Read more", {255, 255, 255, 255});
    if (!textGCU1)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textGCU2 = element->createTextureText(fontDetailText, "in our Privacy Policy - Copyright LuThaVan Production studio - 2024", {255, 255, 255, 255});
    if (!textGCU2)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textValueBestUser = element->createTextureText(fontBestPlayer, "Value Best", {255, 255, 255, 255});
    if (!textValueBestUser)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textValueScorePlayer = element->createTextureText(fontBestPlayer, "Value Score", {255, 255, 255, 255});
    if (!textValueScorePlayer)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textValueTimePlayer = element->createTextureText(fontBestPlayer, "Value Best", {255, 255, 255, 255});
    if (!textValueTimePlayer)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textValueMatchPlayer = element->createTextureText(fontBestPlayer, "Value Time", {255, 255, 255, 255});
    if (!textValueMatchPlayer)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Top 5 players

    textTitleTop = element->createTextureText(fontBestPlayer, "Top 5 players", {255, 255, 255, 255});
    if (!textTitleTop)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textValuePlayersTop = element->createTextureText(fontBestPlayer, "List Players", {255, 255, 255, 255});
    if (!textValuePlayersTop)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // GameOver

    gameOverTexture = element->createTextureText(fontNameGame, "T as perdu nullos ! ", {255, 255, 255, 255});
    if (!gameOverTexture)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    gameOverIMGTexture = element->CreateTexture("assets/img/GameOver.png");
    if (!gameOverIMGTexture)
    {
        cerr << "Failed to create Img texture: " << SDL_GetError() << endl;
    }
}

void GameGraphic::unloadAllTextures()
{
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyTexture(testTexture);
    SDL_DestroyTexture(userLogoTexture);

    // Font
    TTF_CloseFont(fontOswald);
    TTF_CloseFont(fontNameGame);
    TTF_CloseFont(fontDetailText);
    TTF_CloseFont(fontUserProfile);
    TTF_CloseFont(fontBestPlayer);

    // Game Name
    SDL_DestroyTexture(textTitleTexture);
    SDL_DestroyTexture(textCreatorTexture1);
    SDL_DestroyTexture(textCreatorTexture2);

    SDL_DestroyTexture(textReset);
    SDL_DestroyTexture(textUndo);

    SDL_DestroyTexture(textUserInfo1);
    SDL_DestroyTexture(textUserInfo2);

    SDL_DestroyTexture(textBest);
    SDL_DestroyTexture(textScore);
    SDL_DestroyTexture(textTimer);

    SDL_DestroyTexture(textValueScoreUser);
    SDL_DestroyTexture(textValueBestUser);
    SDL_DestroyTexture(textValueScorePlayer);
    SDL_DestroyTexture(textValueTimePlayer);
    SDL_DestroyTexture(textValueMatchPlayer);

    SDL_DestroyTexture(textBestPlayer1);
    SDL_DestroyTexture(textBestPlayer2);

    SDL_DestroyTexture(textViewMore);

    SDL_DestroyTexture(textRules);
    SDL_DestroyTexture(textGCU1);
    SDL_DestroyTexture(textGCU2);

    SDL_DestroyTexture(textTitleTop); // Title top

    // Value
    SDL_DestroyTexture(textValueScoreUser);   // User score
    SDL_DestroyTexture(textValueBestUser);    // User best
    SDL_DestroyTexture(textValueScorePlayer); // Best player score
    SDL_DestroyTexture(textValueTimePlayer);  // Best player time
    SDL_DestroyTexture(textValueMatchPlayer); // Best player match
    SDL_DestroyTexture(textValuePlayersTop);  // List top 5 players

    // Images
    SDL_DestroyTexture(pinkRectImgTexture); // Img Pink rect
    SDL_DestroyTexture(resetImgTexture);    // Img reset
    SDL_DestroyTexture(undoImgTexture);     // Img undo

    // GameOver
    SDL_DestroyTexture(gameOverTexture);    // Text GameOver
    SDL_DestroyTexture(endTimerTexture);    // Text GameOver Timer
    SDL_DestroyTexture(endScoreTexture);    // Text GameOver Score
    SDL_DestroyTexture(chronoTexture);      // Text GameOver Score
    SDL_DestroyTexture(gameOverIMGTexture); // Img GameOver
}

void GameGraphic::displayGameTexture()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    if (displayScoreValue != gameBoard.getScore())
    {
        updateScore();
    };

    displayDesign();
    displayGrid();
    displayChrono();
    displayUsername();
}

// Methode to display frame with rectangles
void GameGraphic::displayRect(){        
    // User
    element->drawRoundedRect(150, 260, 220, 70, 10, element->COLOR_DARKGREY); // First Player info
    element->drawRoundedRect(160, 290, 60, 30, 10, element->COLOR_LIGHTGREY); // Score
    element->drawRoundedRect(230, 290, 60, 30, 10, element->COLOR_LIGHTGREY); // Best
    element->drawRoundedRect(300, 290, 60, 30, 10, element->COLOR_LIGHTGREY); // Timer

    // Top players
    element->drawRoundedRectOpacity(150, 345, 220, 312, 10, {42, 42, 57, 220}); 

    // Game state
    element->drawRoundedRect(385, 70, 520, 72, 10, element->COLOR_DARKGREY); // Game state info
    element->drawRoundedRect(400, 100, 152, 35, 10, element->COLOR_LIGHTGREY); // Score
    element->drawRoundedRect(570, 100, 152, 35, 10, element->COLOR_LIGHTGREY); // Best
    element->drawRoundedRect(740, 100, 152, 35, 10, element->COLOR_LIGHTGREY); // Timer
    element->drawRoundedRectOpacity(385, 155, 520, 500, 10, {42, 42, 57, 220}); // Grid
}

// Method to display images 
void GameGraphic::displayImg(){

    // Img profile pictures
    element->renderTexture(userLogoTexture, 770, 15, 40, 40);  // User photo profile
    element->renderTexture(userLogoTexture, 240, 135, 75, 75); // Best player photo profile

    // Img rectangle
    element->renderTexture(pinkRectImgTexture, 390, 25, 90, 47);  // Rect Reset
    element->renderTexture(pinkRectImgTexture, 495, 25, 90, 47);  // Rect Undo
    element->renderTexture(pinkRectImgTexture, 385, 655, 66, 33); // Rect Rules

    // Img reset and undo
    element->renderTexture(resetImgTexture, 400, 38, 20, 20); 
    element->renderTexture(undoImgTexture, 505, 38, 20, 20);
}

void GameGraphic::displayText(){
    // Display Name Game
    element->displayText(textTitleTexture, fontNameGame, "2048", {255, 255, 255, 255}, 210, 20, false, 0, 0);
    element->displayText(textCreatorTexture1, fontDetailText, "Created by Lucas Martinie", element->COLOR_WHITE, 205, 80, false, 0, 0);
    element->displayText(textCreatorTexture2, fontDetailText, "Thanh Lemelle & Vanny Lamorte", element->COLOR_WHITE, 200, 90, false, 0, 0);

    // Text rest and undo
    element->displayText(textReset, fontGameInfo, "Reset", {255, 255, 255, 255}, 435, 38, false, 0, 0);
    element->displayText(textUndo, fontGameInfo, "Undo", {255, 255, 255, 255}, 540, 38, false, 0, 0);

    // Text name user
    element->displayText(textUserInfo2, fontDetailText, "Joined in 2022", {250, 255, 255, 255}, 840, 45, false, 0, 0);

    // Text best players
    element->displayText(textBestPlayer1, fontBestPlayer, "Lucas Martinie", {255, 255, 255, 255}, 210, 215, false, 0, 0); // Player number 1
    element->displayText(textBestPlayer2, fontDetailText, "Joined in 1995", {255, 255, 255, 255}, 235, 240, false, 0, 0); // Player number 1

    // Top 5 players
    element->displayText(textTitleTop, fontBestPlayer, "Top 5 players", {255, 255, 255, 255}, 210, 350, false, 0, 0);      

    // Text Game state info
    element->displayText(textScore, fontGameInfo, "Score", {255, 255, 255, 255}, 410, 75, false, 0, 0);
    element->displayText(textBest, fontGameInfo, "Best", {255, 255, 255, 255}, 580, 77, false, 0, 0);
    element->displayText(textTimer, fontGameInfo, "Timer", {255, 255, 255, 255}, 750, 75, false, 0, 0);

    // Text best player
    element->displayText(textScore, fontGameInfo, "Score", {255, 255, 255, 255}, 163, 265, false, 0, 0);
    element->displayText(textBest, fontGameInfo, "Best", {255, 255, 255, 255}, 233, 265, false, 0, 0);
    element->displayText(textTimer, fontGameInfo, "Timer", {255, 255, 255, 255}, 303, 265, false, 0, 0);

    // Text View More
    element->displayText(textViewMore, fontDetailTextBold, "View More", element->COLOR_PINK, 155, 660, false, 0, 0);

    // Text Rules
    element->displayText(textRules, fontDetailTextBold, "Check Rules", {255, 255, 255, 255}, 395, 665, false, 0, 0);

    // Text General Conditions of Use
    element->displayText(textGCU1, fontDetailText, "This page uses cookies to store data, preferences, and for analytics and ads purposes. Read more", element->COLOR_WHITE, 460, 663, false, 0, 0);
    element->displayText(textGCU2, fontDetailText, "in our Privacy Policy - Copyright LuThaVan Production studio 2024", element->COLOR_WHITE, 460, 673, false, 0, 0);

}

void GameGraphic::displayValue()
{
    element->displayText(textValueScoreUser, fontBestPlayer, to_string(gameBoard.getScore()), {255, 255, 255, 255}, 415, 105, false, 0, 0); // Value score
    element->displayText(textValueBestUser, fontBestPlayer, "Value Best", {255, 255, 255, 255}, 585, 105, false, 0, 0);                     // Value best

    // Best Player
    element->displayText(textValueScorePlayer, fontUserProfile, "Value Score", {255, 255, 255, 255}, 163, 295, false, 0, 0); // Value score
    element->displayText(textValueTimePlayer, fontUserProfile, "Value Time", {255, 255, 255, 255}, 233, 295, false, 0, 0);   // Value Best
    element->displayText(textValueMatchPlayer, fontUserProfile, "Value Match", {255, 255, 255, 255}, 303, 295, false, 0, 0); // Value Time

    // Top players
    element->displayText(textValuePlayersTop, fontBestPlayer, "List players", {255, 255, 255, 255}, 235, 400, false, 0, 0); // List players     
}

void GameGraphic::displayDesign()
{
    displayRect();
    displayImg(); 
    displayText(); 
    displayValue();     
}

void GameGraphic::updateScore()
{
    SDL_DestroyTexture(textValueScoreUser);
    textValueScoreUser = element->createTextureText(fontBestPlayer, to_string(gameBoard.getScore()), {255, 255, 255, 255});
    if (!textValueScoreUser)
    {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
}

void GameGraphic::displayChrono()
{
    Uint32 currentTime = SDL_GetTicks(); // Get time

    // If game is not Over, timer run and milliseconds are transformed into seconds
    if (!gameOver)
    {
        elapsedTime = (currentTime - gameTimer) / 1000;
    }

    // transform second into minutes and second
    int minutes = elapsedTime / 60;
    int seconds = elapsedTime % 60;

    std::string chronoText = std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

    chronoTexture = element->createTextureText(fontBestPlayer, chronoText.c_str(), element->COLOR_WHITE);

    element->displayText(chronoTexture, fontBestPlayer, chronoText.c_str(), element->COLOR_WHITE, 755, 105, false, 0, 0);

    SDL_DestroyTexture(chronoTexture);
}

void GameGraphic::displayGameOver()
{
    // Transform second into minutes and second
    int minutes = elapsedTime / 60;
    int seconds = elapsedTime % 60;
    std::string chronoText = std::to_string(minutes) + ":" + (seconds < 10 ? "0" : "") + std::to_string(seconds);

    if (!textureGameOver) // Create texture with actual value
    {
        endTimerTexture = element->createTextureText(fontNameGame, chronoText, {255, 255, 255, 255});
        if (!endTimerTexture)
        {
            cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
        }

        endScoreTexture = element->createTextureText(fontNameGame, to_string(gameBoard.getScore()), {255, 255, 255, 255});
        if (!endScoreTexture)
        {
            cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
        }

        // Save score at the end of the game
        gameOptions -> saveScore(user, to_string(gameBoard.getScore()), chronoText, "30");


        textureGameOver = true;
    };

    // Display Black screen, message, timer and score
    element->drawRoundedRectOpacity(440, 200, 420, 420, 10, {252, 244, 153, 220}); // Grid

    element->renderTexture(gameOverIMGTexture, 450, 100, 400, 400);
    element->displayText(gameOverTexture, fontOswald, "T as perdu nullos !", element->COLOR_WHITE, 0, 0, true, screenWidth + 280, screenHeight + 100);
    element->displayText(endTimerTexture, fontOswald, chronoText.c_str(), element->COLOR_WHITE, 0, 0, true, screenWidth + 280, screenHeight + 200);
    element->displayText(endScoreTexture, fontOswald, to_string(gameBoard.getScore()), element->COLOR_WHITE, 0, 0, true, screenWidth + 280, screenHeight + 300);
}

void GameGraphic::displayUsername()
{
    if (user != "")
    {
        if (!usernameLoaded)
        {
            textUserInfo1 = element->createTextureText(fontUserProfile, user, {255, 255, 255, 255});
            if (!textUserInfo1)
            {
                cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
            }
            usernameLoaded = true;
        }
        element->displayText(textUserInfo1, fontUserProfile, user, {250, 255, 255, 255}, 830, 25, false, 0, 0);
    }
}

void GameGraphic::getUsername(std::string username)
{
    user = username;
}