#include "include/GameGraphic.hpp"

GameGraphic::GameGraphic(sf::RenderWindow* window, int screenWidth, int screenHeight)
    : window(window), screenWidth(screenWidth), screenHeight(screenHeight), animTransition(0) 
{
    element = std::make_unique<Element>(window);
    loadTexture();

    if (!fontOswald.loadFromFile("assets\\fonts\\Oswald.ttf")) {
        std::cerr << "Error loading font: Super Caramel.ttf" << std::endl;
    }
}

void GameGraphic::loadTexture() {
    backgroundTexture = element->CreateTexture("assets\\img\\background_white.jpg");
    testTexture = element->CreateTexture("assets\\img\\test.png");

    if (!backgroundTexture || !testTexture) {
        std::cerr << "Failed to load one or more textures" << std::endl;
    }
}

void GameGraphic::displayTexture() {
    element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    // animation();

    displayBackgroud(); // Background
    displayTitle(); // Title
    displayGrid(); // Frame
    displayUserGame(); 
    displayUserProfile(); 
    displayTopPlayer(); 
    displayResetUndo(); // Reset & Undo

}

void GameGraphic::animation() {
    if (animTransition < 250) {
        animTransition += 0.1f; // Use float literal for precision
    }
}

// Method to display background
void GameGraphic::displayBackgroud(){
        element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
}

// Method to display title and creators name
void GameGraphic::displayTitle() {
    /* test purpose below*/
    //element->drawRoundedRect(screenWidth / 2 - 150, 100, 300, 200, 20, sf::Color::White); 

    element->displayText(std::make_shared<sf::Font>(fontOswald), "2048", 50, sf::Color::White, 45 , 50, false, 0, 0); // Name game
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Created by Lucas Martinie", 11, sf::Color::White, 35, 110, false, 0, 0); // Creators names
    element->displayText(std::make_shared<sf::Font>(fontOswald), "Thanh Lemelle & Vanny Lamorte", 11, sf::Color::White, 20 , 125, false, 0, 0); // Creators names    
}


//** GRID **//
// Method to display white frame
void GameGraphic::displayGrid(){

    element -> drawRoundedRectOpacity(screenWidth/2-(550/2), screenHeight/2-(550/2), 550, 550, 5, element -> COLOR_LIGHTGREY1); // Grid rect
    

}


//** USER **//

void GameGraphic::displayUserGame(){
        
        // Main Grey Rect
        int rectTopPlayerFrameX = 30;
        int rectTopPlayerFrameY = screenHeight/2-(285/2);
        element -> drawRoundedRect(rectTopPlayerFrameX, rectTopPlayerFrameY, 180, 285, 10, element ->COLOR_LIGHTGREY1); 

        // Score
        element -> drawRoundedRect(45, rectTopPlayerFrameY +15, 150, 40, 10, element ->COLOR_WHITE);

        element->displayText(std::make_shared<sf::Font>(fontOswald), "Score", 20, element ->COLOR_LIGHTGREY2, rectTopPlayerFrameX +20, rectTopPlayerFrameY +20, false, 0, 0); // Text Top 5 players

        // Best score 
        element -> drawRoundedRect(45, rectTopPlayerFrameY +65, 150, 40, 10, element ->COLOR_WHITE);
        element->displayText(std::make_shared<sf::Font>(fontOswald), "Best", 20, element ->COLOR_LIGHTGREY2, rectTopPlayerFrameX +20, rectTopPlayerFrameY +70, false, 0, 0); // Text Top 5 players

        // Time
        element -> drawRoundedRect(45, rectTopPlayerFrameY +115, 150, 40, 10, element ->COLOR_WHITE); 
        element->displayText(std::make_shared<sf::Font>(fontOswald), "Timer", 20, element ->COLOR_LIGHTGREY2, rectTopPlayerFrameX +20, rectTopPlayerFrameY +120, false, 0, 0); // Text Top 5 players   

        element -> drawRoundedRect(45, rectTopPlayerFrameY +180, 150, 40, 10, element ->COLOR_LIGHTGREY2);  
        element->displayText(std::make_shared<sf::Font>(fontOswald), "Reset", 20, element ->COLOR_WHITE, rectTopPlayerFrameX +70, rectTopPlayerFrameY +185, false, 0, 0); // Text Top 5 players   
  
        element -> drawRoundedRect(45, rectTopPlayerFrameY +230, 150, 40, 10, element ->COLOR_LIGHTGREY2);
        element->displayText(std::make_shared<sf::Font>(fontOswald), "Undo", 20, element ->COLOR_WHITE, rectTopPlayerFrameX +70, rectTopPlayerFrameY +235, false, 0, 0); // Text Top 5 players     

     
}

void GameGraphic::displayResetUndo(){

 
   
}




void GameGraphic::displayUserProfile(){
   
}



//** TOP PLAYERS **//
void GameGraphic::displayTopPlayer(){

    element -> drawRoundedRect(690, screenHeight/2-(320/2), 180, 320, 10, element ->COLOR_LIGHTGREY1); // White Rect best players

    element->displayText(std::make_shared<sf::Font>(fontOswald), "Top 5 players", 20, element ->COLOR_LIGHTGREY2, 730 , 160, false, 0, 0); // Text Top 5 players

    element -> drawRoundedRect(705, 200, 150, 245, 10, element ->COLOR_WHITE); // White Rect best players


}



