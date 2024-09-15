#ifndef TILE_HPP
#define TILE_HPP

class Tile
{
    /*
     * The Tile class represents a single tile on the game board.
     * Each tile has a value, which is a power of 2.
     * A tile with a value of 0 is considered empty.
     * Each tile also has a unique id and position (x, y) on the game board.
     * The value, id, and position of a tile can be set and retrieved.
     * The isEmpty method returns true if the tile is empty.
     */
private:
    int value;
    int id; // Unique identifier for the tile
    int x;  // X position on the board
    int y;  // Y position on the board

public:
    Tile();
    void setValue(int value);
    int getValue() const;
    void setId(int id);
    int getId() const;
    void setX(int x);
    int getX() const;
    void setY(int y);
    int getY() const;
    bool isEmpty() const;
};

#endif // TILE_HPP
