#include <iostream>
using namespace std;

#include "GameGraphic.hpp"
#include "Element.hpp"

GameGraphic::GameGraphic(SDL_Renderer *renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{
    
    element = new Element(renderer);

    // Font options
    fontOswald = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 35);
    fontNameGame = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 50);
    fontDetailText = element->LoadFont("assets/fonts/Inter.ttf", 9);
    fontDetailTextBold = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 10);
    fontGameInfo = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 16);
    fontUserProfile = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 14);
    fontBestPlayer = element->LoadFont("assets/fonts/Oswald-Medium.ttf", 20);

    loadTexture();   
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

void GameGraphic::updateGameBoard(const GameBoard& newGameBoard) {
    gameBoard = newGameBoard;
}

void GameGraphic::displayGrid()
{
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            Tile &tile = gameBoard.tiles[i][j];
            int x = 555 + (100 * j);
            int y = 230 + (100 * i);

            element->renderTexture(tileImgTexture, x, y, 90, 90);

            if (tile.getValue() != 0)
            {
                std::string valueStr = std::to_string(tile.getValue());
                SDL_Texture *textTexture = element->createTextureText(fontOswald, valueStr, {0, 0, 0, 255});

                int textWidth, textHeight;
                SDL_QueryTexture(textTexture, NULL, NULL, &textWidth, &textHeight);

                int textX = x + (90 - textWidth) / 2;
                int textY = y + (90 - textHeight) / 2;

                element->renderTexture(textTexture, textX, textY, textWidth, textHeight);

                SDL_DestroyTexture(textTexture);
            }
        }
    }
}
void GameGraphic::loadTexture()
{
    //*** BACKGROUND ***//

    backgroundTexture = element->CreateTexture("assets/img/background.jpg");
    if (!backgroundTexture) {
        cerr << "Failed to load background texture: " << SDL_GetError() << endl;
    }

    //*** IMAGE ***//

    testTexture = element->CreateTexture("assets/img/test.png");
    tileImgTexture = element->CreateTexture("assets/img/square.png");
    pinkRectImgTexture = element->CreateTexture("assets/img/btn_pink.png"); // Pink rectangle
    
    textValueTexture = element->createTextureText(fontOswald, "default", {255, 255, 255, 255});

    userLogoTexture = element -> CreateTexture("assets/img/profile.png");

    resetImgTexture = element -> CreateTexture("assets/img/reset_white.png"); // Img undo
    undoImgTexture = element -> CreateTexture("assets/img/undo_white.png"); // Img undo

    //*** TEXT ***//

    // Text Name Game
    textTitleTexture = element->createTextureText(fontNameGame, "2048", {255, 255, 255, 255});
    if (!textTitleTexture) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

      textCreatorTexture1 = element->createTextureText(fontDetailText, "Created by Lucas Martinie", element ->COLOR_PINK);
    if (!textCreatorTexture1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textCreatorTexture2 = element->createTextureText(fontDetailText, "Thanh Lemelle & Vanny Lamorte", element ->COLOR_PINK);
    if (!textCreatorTexture2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text name user
    textUserInfo1 = element->createTextureText(fontUserProfile, "Alicia Cordial", {255, 255, 255, 255});
    if (!textUserInfo1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textUserInfo2 = element->createTextureText(fontDetailText, "Joined in 2022", {255, 255, 255, 255});
    if (!textUserInfo2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }   
    
    // Text Best Player
    textBestPlayer1 = element->createTextureText(fontBestPlayer, "Thanh Lemelle", {255, 255, 255, 255});
    if (!textBestPlayer1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textBestPlayer2 = element->createTextureText(fontDetailText, "Joined in 1994", {255, 255, 255, 255});
    if (!textBestPlayer2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text Reset and undo
     textReset = element->createTextureText(fontGameInfo, "Reset", {255, 255, 255, 255});
    if (!textReset) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textUndo = element->createTextureText(fontGameInfo, "Undo", {255, 255, 255, 255});
    if (!textUndo) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text Game State

     textScore = element->createTextureText(fontGameInfo, "Score", {255, 255, 255, 255});
    if (!textScore) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    textBest = element->createTextureText(fontGameInfo, "Best", {255, 255, 255, 255});
    if (!textBest) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
  
    textTimer = element->createTextureText(fontGameInfo, "Timer", {255, 255, 255, 255});
    if (!textCreatorTexture2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text View More
    textViewMore = element->createTextureText(fontDetailTextBold, "View More", element ->COLOR_PINK);
    if (!textViewMore) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text rules
    textRules= element->createTextureText(fontDetailTextBold, "Check Rules", {255, 255, 255, 255});
    if (!textRules) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }

    // Text General Conditions of Use
    textGCU1 = element->createTextureText(fontDetailText, "This page uses cookies to store data, preferences, and for analytics and ads purposes. Read more", {255, 255, 255, 255});
    if (!textGCU1) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
    }
    textGCU2 = element->createTextureText(fontDetailText, "in our Privacy Policy - Copyright LuThanVan Production studio - 2024", {255, 255, 255, 255});
    if (!textGCU2) {
        cerr << "Failed to create text title texture: " << SDL_GetError() << endl;
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
    SDL_DestroyTexture(textMatch);  

    SDL_DestroyTexture(textBestPlayer1); 
    SDL_DestroyTexture(textBestPlayer2); 


    SDL_DestroyTexture(textViewMore);  

    SDL_DestroyTexture(textRules);  
    SDL_DestroyTexture(textGCU1);  
    SDL_DestroyTexture(textGCU2);  


    // Images
    SDL_DestroyTexture(pinkRectImgTexture); // Img Pink rect
    SDL_DestroyTexture(resetImgTexture); // Img reset
    SDL_DestroyTexture(undoImgTexture); // Img undo   

}

void GameGraphic::displayTexture()
{
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    // element->drawRoundedRect(screenWidth - 550, screenHeight - 525, 500, 500, 20, element->COLOR_GREY);

    // element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    // animation();
  
    // displayGrid();
    displayTitle();
}

void GameGraphic::animation()
{
    if (animTransition < 250)
    {
        animTransition += 0.5;
    };
}
void GameGraphic::displayTitle()
{

    // Frame with grey rectangle

    element -> drawRoundedRect(150, 270, 220, 60, 10, element -> COLOR_DARKGREY); // First Player info
    element -> drawRoundedRectOpacity(150, 345, 220, 312, 10,{42, 42, 57, 220}); // Grid

    element -> drawRoundedRect(385, 60, 520, 63, 10, element -> COLOR_DARKGREY); // Game state info
    element -> drawRoundedRect(400, 69, 152, 47, 10, element -> COLOR_LIGHTGREY); // Score
    element -> drawRoundedRect(570, 69, 152, 47, 10, element -> COLOR_LIGHTGREY); // Best
    element -> drawRoundedRect(740, 69, 152, 47, 10, element -> COLOR_LIGHTGREY); // Timer
    
    element -> drawRoundedRectOpacity(385, 135, 520, 520, 10,{42, 42, 57, 220}); // Grid

    //*** IMAGE ***//

    // Display User logo Image
    element->renderTexture(userLogoTexture,770,8,50,50); // User photo profile
    element->renderTexture(userLogoTexture, 230, 150,75,75); // Best player photo profile

    element->renderTexture(pinkRectImgTexture, 390,10,95,47); // Rect Reset
    element->renderTexture(pinkRectImgTexture, 495,10,95,47); // Rect Undo
    element->renderTexture(pinkRectImgTexture, 385, 655, 66,33); // Rect Rules 

    element->renderTexture(resetImgTexture, 400, 20, 25,25); // Img reset 
    element->renderTexture(undoImgTexture, 505, 20, 25,25); // Img undo

    // Display Name Game
    element -> displayText(textTitleTexture, fontNameGame, "2048", {255, 255, 255, 255}, 210, 30, false, 0, 0); 
    element -> displayText(textCreatorTexture1, fontDetailText, "Created by Lucas Martinie", element ->COLOR_PINK, 205, 90, false, 0, 0);
    element -> displayText(textCreatorTexture2, fontDetailText, "Thanh Lemelle & Vanny Lamorte", element ->COLOR_PINK, 200, 100, false, 0, 0);

      // Text rest and undo
    element -> displayText(textReset, fontGameInfo,"Reset", {255, 255, 255, 255}, 435, 23, false, 0, 0);
    element -> displayText(textUndo, fontGameInfo, "Undo", {255, 255, 255, 255}, 540, 23, false, 0, 0);


    // Text name user
    element -> displayText(textUserInfo1, fontUserProfile, "Alicia Cordial", {250, 255, 255, 255}, 830, 20, false, 0, 0);
    element -> displayText(textUserInfo2, fontDetailText, "Joined in 2022", {250, 255, 255, 255}, 840, 40, false, 0, 0);

    // Text best player
    element -> displayText(textBestPlayer1, fontBestPlayer, "Thanh Lemelle", {255, 255, 255, 255}, 210, 230, false, 0, 0);
    element -> displayText(textBestPlayer2, fontDetailText, "Joined in 1994", {255, 255, 255, 255}, 235, 255, false, 0, 0);

    // Text Game state info
    element -> displayText(textScore, fontGameInfo, "Score", {255, 255, 255, 255}, 410, 80, false, 0, 0);
    element -> displayText(textBest, fontGameInfo, "Best", {255, 255, 255, 255}, 580, 80, false, 0, 0);
    element -> displayText(textTimer, fontGameInfo, "Timer", {255, 255, 255, 255}, 750, 80, false, 0, 0);

    // Text best player  info
    element -> displayText(textScore, fontGameInfo, "Score", {255, 255, 255, 255}, 157, 275, false, 0, 0);
    element -> displayText(textBest, fontGameInfo, "Best", {255, 255, 255, 255}, 247, 275, false, 0, 0);
    element -> displayText(textTimer, fontGameInfo, "Timer", {255, 255, 255, 255}, 322, 275, false, 0, 0);

    // element -> displayText(textMatch, fontGameInfo, "Match", {255, 255, 255, 255}, 460, 110, false, 0, 0);

    // Text View More 
    element -> displayText(textViewMore, fontDetailTextBold, "View More", element ->COLOR_PINK, 155, 660, false, 0, 0);

    // Text Rules
    element -> displayText(textRules, fontDetailTextBold, "Check Rules", {255, 255, 255, 255}, 395, 665, false, 0, 0);

    // Text General Conditions of Use
    element -> displayText(textGCU1, fontDetailText, "This page uses cookies to store data, preferences, and for analytics and ads purposes. Read more", element ->COLOR_WHITE, 460, 663, false, 0, 0);
    element -> displayText(textGCU2, fontDetailText, "in our Privacy Policy - Copyright LuThanVan Production studio 2024", element ->COLOR_WHITE, 460, 673, false, 0, 0);



}
