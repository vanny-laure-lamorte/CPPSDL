#include "Game.hpp"
#include <iostream>

Game::Game() : gameBoard() {}

void Game::play() {
    char move;
    while (gameBoard.canMove()) {
        gameBoard.display();
        std::cout << "Enter your move (w/a/s/d): ";
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
                std::cout << "Invalid move! Use w/a/s/d." << std::endl;
        }

        if (moved) {
            gameBoard.addRandomTile();
        } else {
            std::cout << "No move made. Try another direction." << std::endl;
        }
    }

    gameBoard.display();
    std::cout << "Game Over! Thank you for playing." << std::endl;
}
