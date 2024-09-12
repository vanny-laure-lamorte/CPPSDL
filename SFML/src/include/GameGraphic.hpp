#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include "Element.hpp"
#include <memory>

#include "GameBoard.hpp"
#include "Tile.hpp"

class GameGraphic
{
public:
    GameGraphic(sf::RenderWindow *window, int screenWidth, int screenHeight);
    ~GameGraphic() = default; // Use default destructor since smart pointers will handle cleanup

    //*** MAIN STRUCTURE */
    void loadTexture();
    void displayTexture();
    void displayBackgroud(); // Background
    void displayTitle();     // Title

    //***  USER GAME ESTATE ***/
    void displayUserGame();
    void displayUserProfile(); // User Profile

    int rectUserFrameX;                          // Rect user position X
    int rectUserFrameY;                          // Rect user position Y
    int rectUserFrameXOffset;                    // Rect user position X Offset
    std::shared_ptr<sf::Texture> blueBtnTexture; // Img blue rect

    int rectPlayerFrameX;       // Rect player position X
    int rectPlayerFrameY;       // Rect player position Y
    int rectPlayerFrameXOffset; // Rect player position X offset

    std::shared_ptr<sf::Texture> profileUserTexture; // Img profile

    //*** RESET & UNDO ***//
    void displayResetUndo();

    //*** GRID ***//
    void displayGrid();
    void updateGame(const GameBoard &newGameBoard); 

    //*** GAME OVER ***//
    void displayLoose();
    std::shared_ptr<sf::Texture> gameOverTexture; 

    //*** TOP PLAYERS ***//
    void displayTopPlayer(); // Top players

    //*** GCU ***//
    GameBoard gameBoard;
    void displayGCU();

    //***CHRONO ***//
    void displayChrono(); // Timer
    void resetChrono();
    
private:

    sf::Clock clock;

    std::unique_ptr<Element> element;
    sf::RenderWindow *window;
    int screenWidth;
    int screenHeight;

    std::shared_ptr<sf::Texture> backgroundTexture;
    std::shared_ptr<sf::Texture> testTexture;

    void animation();
    float animTransition = 0;

    // Font
    sf::Font fontOswald;

    void unloadAllTextures(); // Now a private method, rarely needed
};

#endif // GAMEGRAPHIC_HPP