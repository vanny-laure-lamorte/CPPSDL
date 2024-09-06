using namespace std;
#include <iostream>
#include <SDL2/SDL.h>
#include "Game.hpp"
#include "Window.hpp"
#include "GameGraphic.hpp"
#include "GameBoard.hpp"
#include "IntroScreenGraphic.hpp"
#include "EventHandler.hpp"

Game::Game() {}

int Game::play()
{
    // Create window
    Window window(SCREENWIDTH, SCREENHEIGHT);
    if (!window.isInitialized())
    {
        cerr << "Failed to initialize the window." << endl;
        return -1;
    }

    // Get renderer
    SDL_Renderer *renderer = window.getRenderer();

    // Create game graphic instance
    GameGraphic gameGraphic(renderer, SCREENWIDTH, SCREENHEIGHT);

    // Create intro screen graphic instance
    IntroScreenGraphic intro(renderer, SCREENWIDTH, SCREENHEIGHT);

    // Create game board instance
    GameBoard gameBoard;

    // Create the event handler instance
    EventHandler eventHandler(intro, gameBoard, gameGraphic);

    bool running = true;
    while (running)
    {
        // Handle events using the EventHandler class
        eventHandler.handleEvents(running);

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Dark gray
        SDL_RenderClear(renderer);

        if (!intro.introPlayed)
        {
            intro.displayIntro();
        }
        else // Display gameScreen
        {
            gameGraphic.displayGameTexture();
            if (gameGraphic.gameOver) // Display gameOver
            {
                gameGraphic.displayGameOver();
            }
        }

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup
    SDL_Quit();
    return EXIT_SUCCESS;
}
