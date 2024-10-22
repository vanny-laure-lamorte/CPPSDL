#ifndef GAMEGRAPHIC_HPP
#define GAMEGRAPHIC_HPP

#include <SFML/Graphics.hpp>
#include "Element.hpp"
#include "IntroScreenGraphic.hpp"

#include <memory>

#include "GameBoard.hpp"
#include "GameOptions.hpp"

#include "Tile.hpp"

class GameGraphic
{
public:
    GameGraphic(sf::RenderWindow *window, int screenWidth, int screenHeight);
    ~GameGraphic() = default; 

    //*** MAIN STRUCTURE ***//
    void loadTexture(); 
    void unloadAllTextures();  
    void displayTexture(); 
    void displayBackgroud();
    void displayTitle(); 

    //***  USER GAME ESTATE ***//
    void displayUserGame();
    void displayUserProfile(); // User Profile
    bool scoreFetched = false;
    int scoreUserInt;

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
    sf::Color determineColor(int value);
    void displayGrid();
    void updateGame(const GameBoard &newGameBoard); 

    //*** GAME OVER ***//
    void displayLoose();
    std::shared_ptr<sf::Texture> gameOverTexture; 

    //*** TOP PLAYERS ***//
    void displayBestPlayer(); 
    void displayTopPlayer();

    //*** GCU ***//
    void displayGCU();

    //*** INSTANCE ***//
    GameBoard gameBoard;
    GameOptions gameOptions;
    std::unique_ptr<Element> element;

    //*** CHRONO ***//
    void displayChrono();
    void resetChrono();
    std::string timeString;

    //***Score ***//
    int updateScore(int newScore);
    int updatedScoreValue = 0;
    bool saveScore = false;
    
    float animTransition = 0;

    //*** FONT ***//
    sf::Font fontOswald;
    void setUserName(string userName)
    {
        pseudo = userName;
    }

    void setUserMail(string userMail)
    {
        mail = userMail;
    }  

private:

    sf::Clock clock;
    string pseudo;
    string mail;

    sf::RenderWindow *window;
    int screenWidth;
    int screenHeight;

    std::shared_ptr<sf::Texture> backgroundTexture;
    std::shared_ptr<sf::Texture> testTexture;

    void animation();

};

#endif // GAMEGRAPHIC_HPP