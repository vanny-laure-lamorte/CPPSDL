#include "Tile.hpp"

Tile::Tile() : value(0), id(-1), x(0), y(0) {}

void Tile::setValue(int value) { this->value = value; }
int Tile::getValue() const { return value; }

void Tile::setId(int id) { this->id = id; }
int Tile::getId() const { return id; }

void Tile::setX(int x) { this->x = x; }
int Tile::getX() const { return x; }

void Tile::setY(int y) { this->y = y; }
int Tile::getY() const { return y; }

bool Tile::isEmpty() const { return value == 0; }
