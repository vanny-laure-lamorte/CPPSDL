#ifndef TILE_HPP
#define TILE_HPP

class Tile {
    /*
    * The Tile class represents a single tile on the game board.
    * Each tile has a value, which is a power of 2.
    * A tile with a value of 0 is considered empty.
    * The value of a tile can be set and retrieved.
    * The isEmpty method returns true if the tile is empty.
    */
private:
    int value;

public:
    Tile();
    explicit Tile(int value); 
    int getValue() const;
    void setValue(int value);
    bool isEmpty() const;
};

#endif // TILE_HPP
