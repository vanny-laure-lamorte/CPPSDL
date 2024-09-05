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
    explicit Tile(int value); // explicit keyword is used to avoid implicit conversion. It means that the constructor can only be used for direct initialization and not for implicit conversions. Aka, it can only be used when you explicitly call it.
    int getValue() const;
    void setValue(int value);
    bool isEmpty() const;
};

#endif // TILE_HPP
