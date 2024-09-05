#include "include/GameGraphic.hpp"

GameGraphic::GameGraphic(sf::RenderWindow* window, int screenWidth, int screenHeight)
    : window(window), screenWidth(screenWidth), screenHeight(screenHeight), animTransition(0) 
{
    element = std::make_unique<Element>(window);
    loadTexture();

    if (!fontOswald.loadFromFile("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\fonts\\Super Caramel.ttf")) {
        std::cerr << "Error loading font: Super Caramel.ttf" << std::endl;
    }
}

void GameGraphic::loadTexture() {
    backgroundTexture = element->CreateTexture("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\img\\background.jpg");
    testTexture = element->CreateTexture("C:\\Users\\tslem\\Desktop\\Laplateforme\\bachelore2\\depot\\cpp\\projetGroupe\\CPPSDL\\SFML\\assets\\img\\test.png");

    if (!backgroundTexture || !testTexture) {
        std::cerr << "Failed to load one or more textures" << std::endl;
    }
}

void GameGraphic::displayTexture() {
    element->renderTexture(backgroundTexture, 0, 0, screenWidth, screenHeight);
    element->renderTexture(testTexture, screenWidth / 2 - animTransition / 2, screenHeight / 2 - animTransition / 2, animTransition, animTransition);
    animation();
    displayTitle();
}

void GameGraphic::animation() {
    if (animTransition < 250) {
        animTransition += 0.1f; // Use float literal for precision
    }
}

void GameGraphic::displayTitle() {
    /* test purpose below*/
    //element->drawRoundedRect(screenWidth / 2 - 150, 100, 300, 200, 20, sf::Color::White);
    element->displayText(std::make_shared<sf::Font>(fontOswald), "TILE TWISTER", sf::Color::White, 0, 0, true, screenWidth, 110);
}