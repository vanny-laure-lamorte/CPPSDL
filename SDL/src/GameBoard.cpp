#include "GameBoard.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>

GameBoard::GameBoard(int size) : size(size), tiles(size, std::vector<Tile>(size)) {
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator. It is used to generate random tile with value 2 or 4 unsing local time as seed
    addRandomTile();
    addRandomTile();
}

void GameBoard::display() const {
    std::cout << "-----------------------------\n";
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            if (tile.isEmpty())
                std::cout << "|    \t";
            else
                std::cout << "|" << tile.getValue() << "\t";
        }
        std::cout << "|\n-----------------------------\n";
    }
}

bool GameBoard::shiftLeft(std::vector<Tile>& line) {
    bool moved = false;
    // Shift all non-empty tiles to the left
    int insertPos = 0;
    for (int i = 0; i < size; ++i) {
        if (!line[i].isEmpty()) {
            if (i != insertPos) {
                line[insertPos].setValue(line[i].getValue());
                line[i].setValue(0);
                moved = true;
            }
            insertPos++;
        }
    }
    return moved;
}

bool GameBoard::mergeTiles(std::vector<Tile>& line) {
    bool merged = false;
    for (int i = 0; i < size - 1; ++i) {
        if (!line[i].isEmpty() && line[i].getValue() == line[i + 1].getValue()) {
            line[i].setValue(line[i].getValue() * 2);
            score += line[i].getValue();
            line[i + 1].setValue(0);
            merged = true;
        }
    }
    return merged;
}

bool GameBoard::moveLeft() {
    bool moved = false;
    for (int i = 0; i < size; ++i) {
        std::vector<Tile>& row = tiles[i];
        bool shifted = shiftLeft(row);
        bool merged = mergeTiles(row);
        if (merged) {
            shiftLeft(row);
            moved = true;
        } else if (shifted) {
            moved = true;
        }
    }
    return moved;
}

bool GameBoard::moveRight() {
    bool moved = false;
    for (int i = 0; i < size; ++i) {
        std::vector<Tile>& row = tiles[i];
        // Reverse the row for right movement
        std::reverse(row.begin(), row.end());
        bool shifted = shiftLeft(row);
        bool merged = mergeTiles(row);
        if (merged) {
            shiftLeft(row);
            moved = true;
        } else if (shifted) {
            moved = true;
        }
        // Reverse back the row to original order
        std::reverse(row.begin(), row.end());
    }
    return moved;
}

bool GameBoard::moveUp() {
    bool moved = false;
    for (int col = 0; col < size; ++col) {
        std::vector<Tile> column;
        // Extract the column
        for (int row = 0; row < size; ++row) {
            column.push_back(tiles[row][col]);
        }
        bool shifted = shiftLeft(column);
        bool merged = mergeTiles(column);
        if (merged) {
            shiftLeft(column);
            moved = true;
        } else if (shifted) {
            moved = true;
        }
        // Update the GameBoard with the new column
        for (int row = 0; row < size; ++row) {
            tiles[row][col].setValue(column[row].getValue());
        }
    }
    return moved;
}

bool GameBoard::moveDown() {
    bool moved = false;
    for (int col = 0; col < size; ++col) {
        std::vector<Tile> column;
        // Extract the column
        for (int row = 0; row < size; ++row) {
            column.push_back(tiles[row][col]);
        }
        // Reverse the column for downward movement
        std::reverse(column.begin(), column.end());
        bool shifted = shiftLeft(column);
        bool merged = mergeTiles(column);
        if (merged) {
            shiftLeft(column);
            moved = true;
        } else if (shifted) {
            moved = true;
        }
        // Reverse back the column to original order
        std::reverse(column.begin(), column.end());
        // Update the GameBoard with the new column
        for (int row = 0; row < size; ++row) {
            tiles[row][col].setValue(column[row].getValue());
        }
    }
    return moved;
}

void GameBoard::addRandomTile() {
    std::vector<std::pair<int, int>> emptyTiles;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (tiles[i][j].isEmpty()) {
                emptyTiles.emplace_back(i, j); // emplace_back is more efficient than push_back. it constructs the object in place
            }
        }
    }

    if (!emptyTiles.empty()) {
        int randomIndex = rand() % emptyTiles.size();
        //int value = (rand() % 2 + 1) * 2; // 2 or 4
        int value = (rand() % 10 < 9) ? 2 : 4; // 90% chance of 2, 10% chance of 4
        tiles[emptyTiles[randomIndex].first][emptyTiles[randomIndex].second].setValue(value);
    }
}

bool GameBoard::isFull() const {
    for (const auto& row : tiles) {
        for (const auto& tile : row) {
            if (tile.isEmpty()) {
                return false;
            }
        }
    }
    return true;
}

bool GameBoard::canMove() const {
    if (!isFull()) {
        return true;
    }

    // Check horizontal moves
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - 1; ++j) {
            if (tiles[i][j].getValue() == tiles[i][j + 1].getValue()) {
                return true;
            }
        }
    }

    // Check vertical moves
    for (int j = 0; j < size; ++j) {
        for (int i = 0; i < size - 1; ++i) {
            if (tiles[i][j].getValue() == tiles[i + 1][j].getValue()) {
                return true;
            }
        }
    }

    return false;
}
