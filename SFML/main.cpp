#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <direct.h>

#include <SFML/Graphics.hpp>
#include "src/include/Window.hpp"
#include "src/include/GameGraphic.hpp"
#include "src/include/GameBoard.hpp"
#include "src/include/IntroScreenGraphic.hpp"


int SCREENWIDTH = 900;
int SCREENHEIGHT = 600;
bool running = true;

int main()
{
    // Create window
    Window window(SCREENWIDTH, SCREENHEIGHT);
    if (!window.isInitialized())
    {
        std::cerr << "Failed to initialize the window." << std::endl;
        return -1;
    }

    GameBoard gameBoard;
    // Get the SFML window object
    sf::RenderWindow *renderWindow = window.getWindow();

    //*** Create instance ***//
    GameGraphic gameGraphic(renderWindow, SCREENWIDTH, SCREENHEIGHT); // Game Graphic
    IntroScreenGraphic introScreenGraphic (renderWindow, SCREENWIDTH, SCREENHEIGHT); // Intro Screen Graphic

    // Main game loop
    while (renderWindow->isOpen())
    {
        sf::Event event;
        while (running)
        {
                bool moved = false;
            while (renderWindow->pollEvent(event))
            {


                if (event.type == sf::Event::Closed)
                {
                    running = false;
                    renderWindow->close();

                }

                if (event.type == sf::Event::KeyPressed)

                    switch (event.key.code)
                    {
                    // Move to left
                    case (sf::Keyboard::Left):
                    case (sf::Keyboard::Q):
                        moved = gameBoard.moveLeft();
                        break;

                    // Move to right
                    case (sf::Keyboard::Right):
                    case (sf::Keyboard::D):
                        moved = gameBoard.moveRight();
                        break;

                    // Move Up
                    case (sf::Keyboard::Up):
                    case (sf::Keyboard::Z):
                        moved = gameBoard.moveUp();
                        break;

                    // Move Down
                    case (sf::Keyboard::Down):
                    case (sf::Keyboard::S):
                        moved = gameBoard.moveDown();
                        break;

                    // Error input
                    default:
                        std::cout << "Invalid move! Use w/a/s/d." << std::endl;
                    }
            }
                // Clear the screen
                renderWindow->clear(sf::Color(50, 50, 50)); // Dark gray

                // Display background and other textures

                bool introDisplay = true; 

                if (introDisplay){
                introScreenGraphic.displayIntro();                 
                }
                else{
                gameGraphic.displayTexture();
                introDisplay = false;
                }

                // Display what was drawn on the window
                renderWindow->display();

                if (moved)
                {
                    gameBoard.display();
                    gameBoard.addRandomTile();
                    gameGraphic.updateGame(gameBoard);
                }
        }
    }

    // Unload texture from all page graphic
    gameGraphic.unloadAllTextures();
    introScreenGraphic.unloadAllIntroTextures();

    return EXIT_SUCCESS;
}
