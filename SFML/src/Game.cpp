#include "Game.hpp"
#include <iostream>


void Game::play() {


    gameBoard.display();
    std::cout << "Game Over! Thank you for playing." << std::endl;
}
