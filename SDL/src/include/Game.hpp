#ifndef GAME_HPP
#define GAME_HPP

#include "GameBoard.hpp"

class Game
{
    /*
     * The Game class represents the 2048 game.
     * The game can be played.
     * The game has a 4x4 game board.
     * The game can be played until the game is over.
     */

private:
    int SCREENWIDTH = 1050;
    int SCREENHEIGHT = 700;
    GameBoard gameBoard;

public:
    Game();
    int play();
};

#endif // GAME_HPP
