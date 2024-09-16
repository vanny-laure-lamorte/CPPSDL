#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <string>
#include <direct.h>

#include "src/include/Window.hpp"
#include "src/include/GameGraphic.hpp"
#include "src/include/GameBoard.hpp"
#include "src/include/IntroScreenGraphic.hpp"

int SCREENWIDTH = 900;
int SCREENHEIGHT = 600;
bool running = true;
bool introDisplay = true; // Initially set to true to show the intro screen
int buttonX = 900 / 2 - (260 / 2);
int buttonY = 600 / 2 - (350 / 2) + 340;

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

    //*** Create instances ***//
    GameGraphic gameGraphic(renderWindow, SCREENWIDTH, SCREENHEIGHT);               // Game Graphic
    IntroScreenGraphic introScreenGraphic(renderWindow, SCREENWIDTH, SCREENHEIGHT); // Intro Screen Graphic

    // Main game loop
    while (renderWindow->isOpen())
    {
        sf::Event event;
        bool moved = false;
        while (renderWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                renderWindow->close();
            }

            if (event.type == sf::Event::KeyPressed)
            {
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

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*renderWindow);
                introScreenGraphic.handleMouseInput(mousePos); // Handle input for intro screen

                if (event.mouseButton.x >= buttonX && event.mouseButton.x <= buttonX + 260 &&
                    event.mouseButton.y >= buttonY && event.mouseButton.y <= buttonY + 40)
                {
                    introDisplay = false;
                    gameGraphic.setUserName(introScreenGraphic.getInputString1());
                    gameGraphic.setUserMail(introScreenGraphic.getInputString2());
                }
            }

            if (event.type == sf::Event::TextEntered)
            {
                std::cout << "Text entered: " << event.text.unicode << std::endl;
                introScreenGraphic.handleTextInput(event); // Handle text input for intro screen
            }
        }

        // Rendering
        renderWindow->clear(sf::Color(50, 50, 50));

        if (introDisplay)
        {
            introScreenGraphic.displayIntro(); // Display intro screen if flag is true
        }
        else
        {
            gameGraphic.displayTexture(); // Display game screen if intro is done
                                          // Display what was drawn on the window

            if (moved)
            {
                gameBoard.display();
                gameBoard.addRandomTile();
                gameGraphic.updateGame(gameBoard);
            }
        }
        renderWindow->display();
    }

    // Unload textures for cleanup
    gameGraphic.unloadAllTextures();
    introScreenGraphic.unloadAllIntroTextures();

    return EXIT_SUCCESS;
}
