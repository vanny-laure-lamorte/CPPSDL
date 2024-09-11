#include "include/Tile.hpp"

Tile::Tile() : value(0) {}

Tile::Tile(int value) : value(value) {}

int Tile::getValue() const {
    return value;
}

void Tile::setValue(int value) {
    this->value = value;
}

bool Tile::isEmpty() const {
    return value == 0;
}
