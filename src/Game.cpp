#include "Game.hpp"
#include <iostream>

Game::Game() : gameBoard() {}

void Game::play() {
    char move;
    while (gameBoard.canMove()) {
        gameBoard.display();
        std::cout << "Entrez votre mouvement (z/q/s/d) : ";
        std::cin >> move;

        bool moved = false;
        switch (move) {
            case 'q': 
            case 'Q':
                moved = gameBoard.moveLeft(); 
                break;
            case 'd': 
            case 'D':
                moved = gameBoard.moveRight(); 
                break;
            case 'z': 
            case 'Z':
                moved = gameBoard.moveUp(); 
                break;
            case 's': 
            case 'S':
                moved = gameBoard.moveDown(); 
                break;
            default: 
                std::cout << "Mouvement invalide ! Utilisez z/q/s/d." << std::endl;
        }

        if (moved) {
            gameBoard.addRandomTile();
        } else {
            std::cout << "Aucun mouvement effectué. Essayez une autre direction." << std::endl;
        }
    }

    gameBoard.display();
    std::cout << "Game Over! Merci d'avoir joué." << std::endl;
}
