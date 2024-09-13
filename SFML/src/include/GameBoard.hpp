#ifndef GameBoard_HPP
#define GameBoard_HPP

#include <vector>
#include "Tile.hpp"

class GameBoard {
    /*
    * The GameBoard class represents the game board of the 2048 game.
    * The game board is a square grid with a size of 4x4.
    * The game board is made up of tiles.
    * The game board can be displayed.
    * The game board can be shifted left, right, up, or down.
    * The game board can have a random tile added.
    * The game board can be checked if it is full.
    * The game board can be checked if it can move.
    */
private:
    int size;

public:
    GameBoard(int size = 4);
    bool shiftLeft(std::vector<Tile>& line);
    bool mergeTiles(std::vector<Tile>& line);
    void display() const;
    bool moveLeft();
    bool moveRight();
    bool moveUp();
    bool moveDown();
    void addRandomTile();
    bool isFull() const;
    bool canMove() const;
    std::vector<std::vector<Tile>> tiles;
    int getScore() const;

};

#endif // GameBoard_HPP
