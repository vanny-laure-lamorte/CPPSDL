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
    GameGraphic gameGraphic(renderWindow, SCREENWIDTH, SCREENHEIGHT); // Game Graphic
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
                // Handle game key events (you can add specific controls here)
            }

            if (event.type == sf::Event::MouseButtonPressed)
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(*renderWindow);
                introScreenGraphic.handleMouseInput(mousePos); // Handle input for intro screen
            }

            if (event.type == sf::Event::TextEntered)
            {
                std::cout << "Text entered: " << event.text.unicode << std::endl;
                introScreenGraphic.handleTextInput(event); // Handle text input for intro screen
            }
        }

        // Rendering
        renderWindow->clear(sf::Color(50, 50, 50)); // Clear the screen

        if (introDisplay)
        {
            introScreenGraphic.displayIntro(); // Display intro screen if flag is true
        }
        else
        {
            gameGraphic.displayTexture(); // Display game screen if intro is done
                    // Display what was drawn on the window
            renderWindow->display();

            

            if (moved)
            {
                gameBoard.display();
                gameGraphic.updateGame(gameBoard);
                gameBoard.addRandomTile();
            }
        }
    }

    // Unload textures for cleanup
    gameGraphic.unloadAllTextures();
    introScreenGraphic.unloadAllIntroTextures();

    return EXIT_SUCCESS;
}
