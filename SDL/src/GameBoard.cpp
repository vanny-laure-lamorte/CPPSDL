#include "GameBoard.hpp"
#include "Tile.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>

// Global counter for unique IDs
static int globalTileIdCounter = 0;

GameBoard::GameBoard(int size) : size(size), tiles(size, std::vector<Tile>(size))
{
    srand(static_cast<unsigned>(time(0))); // Seed the random number generator

    addRandomTile();
    addRandomTile();
}

void GameBoard::display() const
{
    std::cout << "-----------------------------\n";
    for (const auto &row : tiles)
    {
        for (const auto &tile : row)
        {
            if (tile.isEmpty())
                std::cout << "|    \t";
            else
                std::cout << "|" << tile.getValue() << "\t";
        }
        std::cout << "|\n-----------------------------\n";
    }
}

bool GameBoard::shiftLeft(std::vector<Tile> &line)
{
    bool moved = false;
    int insertPos = 0;
    for (int i = 0; i < size; ++i)
    {
        if (!line[i].isEmpty())
        {
            if (i != insertPos)
            {
                line[insertPos].setValue(line[i].getValue());
                line[insertPos].setId(line[i].getId());
                line[i].setValue(0);
                line[i].setId(-1); // Reset the ID of the moved tile
                moved = true;
            }
            insertPos++;
        }
    }
    return moved;
}

bool GameBoard::mergeTiles(std::vector<Tile> &line)
{
    bool merged = false;
    for (int i = 0; i < size - 1; ++i)
    {
        if (!line[i].isEmpty() && line[i].getValue() == line[i + 1].getValue())
        {
            int newValue = line[i].getValue() * 2;

            // Merge tiles
            line[i].setValue(newValue);
            score += newValue;

            // Reset the ID of the merged tile
            line[i + 1].setValue(0);
            line[i + 1].setId(-1);

            merged = true;
        }
    }
    return merged;
}

bool GameBoard::moveLeft()
{
    bool moved = false;
    for (int i = 0; i < size; ++i)
    {
        std::vector<Tile> &row = tiles[i];
        bool shifted = shiftLeft(row);
        bool merged = mergeTiles(row);
        if (merged)
        {
            shiftLeft(row);
            moved = true;
        }
        else if (shifted)
        {
            moved = true;
        }
        for (int j = 0; j < size; ++j)
        {
            updateTilePosition(row[j].getId(), j, i);  // Correct position
        }
    }
    return moved;
}

bool GameBoard::moveRight()
{
    bool moved = false;
    for (int i = 0; i < size; ++i)
    {
        std::vector<Tile> &row = tiles[i];
        std::reverse(row.begin(), row.end());
        bool shifted = shiftLeft(row);
        bool merged = mergeTiles(row);
        if (merged)
        {
            shiftLeft(row);
            moved = true;
        }
        else if (shifted)
        {
            moved = true;
        }
        std::reverse(row.begin(), row.end());
        for (int j = 0; j < size; ++j)
        {
            updateTilePosition(row[j].getId(), size - 1 - j, i);  // Correct position
        }
    }
    return moved;
}

bool GameBoard::moveUp()
{
    bool moved = false;
    for (int col = 0; col < size; ++col)
    {
        std::vector<Tile> column;
        for (int row = 0; row < size; ++row)
        {
            column.push_back(tiles[row][col]);
        }
        bool shifted = shiftLeft(column);
        bool merged = mergeTiles(column);
        if (merged)
        {
            shiftLeft(column);
            moved = true;
        }
        else if (shifted)
        {
            moved = true;
        }
        for (int row = 0; row < size; ++row)
        {
            tiles[row][col].setValue(column[row].getValue());
            tiles[row][col].setId(column[row].getId());
            updateTilePosition(column[row].getId(), col, row);  // Correct position
        }
    }
    return moved;
}

bool GameBoard::moveDown()
{
    bool moved = false;
    for (int col = 0; col < size; ++col)
    {
        std::vector<Tile> column;
        for (int row = 0; row < size; ++row)
        {
            column.push_back(tiles[row][col]);
        }
        std::reverse(column.begin(), column.end());
        bool shifted = shiftLeft(column);
        bool merged = mergeTiles(column);
        if (merged)
        {
            shiftLeft(column);
            moved = true;
        }
        else if (shifted)
        {
            moved = true;
        }
        std::reverse(column.begin(), column.end());
        for (int row = 0; row < size; ++row)
        {
            tiles[row][col].setValue(column[row].getValue());
            tiles[row][col].setId(column[row].getId());
            updateTilePosition(column[row].getId(), col, size - 1 - row);  // Correct position
        }
    }
    return moved;
}

void GameBoard::addRandomTile()
{
    std::vector<std::pair<int, int>> emptyTiles;

    // Collect empty tiles
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (tiles[i][j].isEmpty())
            {
                emptyTiles.emplace_back(i, j);
            }
        }
    }

    if (!emptyTiles.empty())
    {
        int randomIndex = rand() % emptyTiles.size();
        int id = globalTileIdCounter++; // Get the next available ID

        int value = (rand() % 10 < 9) ? 2 : 4; // 90% chance of 2, 10% chance of 4
        tiles[emptyTiles[randomIndex].first][emptyTiles[randomIndex].second].setValue(value);
        tiles[emptyTiles[randomIndex].first][emptyTiles[randomIndex].second].setId(id);
        updateTilePosition(id, emptyTiles[randomIndex].first, emptyTiles[randomIndex].second); // Assign the tile ID and position
    }
}

bool GameBoard::isFull() const
{
    for (const auto &row : tiles)
    {
        for (const auto &tile : row)
        {
            if (tile.isEmpty())
            {
                return false;
            }
        }
    }
    return true;
}

bool GameBoard::canMove() const
{
    if (!isFull())
    {
        return true;
    }
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (tiles[i][j].getValue() == tiles[i][j + 1].getValue())
            {
                return true;
            }
        }
    }
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            if (tiles[i][j].getValue() == tiles[i + 1][j].getValue())
            {
                return true;
            }
        }
    }
    return false;
}

void GameBoard::updateTilePosition(int id, int newX, int newY)
{
    // Update position in tilePosition map
    tilePosition[id] = std::make_pair(newX, newY);
    
    // Update position in the Tile object
    for (auto &row : tiles)
    {
        for (auto &tile : row)
        {
            if (tile.getId() == id)
            {
                tile.setX(newX);
                tile.setY(newY);
            }
        }
    }
}