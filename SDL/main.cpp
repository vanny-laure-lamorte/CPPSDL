using namespace std;
#include <iostream>
#include <SDL2/SDL.h>
#include "Window.hpp"
#include "GameGraphic.hpp"
#include "GameBoard.hpp"
#include "IntroScreenGraphic.hpp"

int SCREENWIDTH = 1050;
int SCREENHEIGHT = 700;

int main(int argc, char *argv[])
{

    // Create window
    Window window(SCREENWIDTH, SCREENHEIGHT);
    if (!window.isInitialized())
    {
        cerr << "Failed to initialize the window." << endl;
        return -1;
    }

    SDL_Event windowEvent;

    // Get renderer
    SDL_Renderer *renderer = window.getRenderer();

    // Create game graphic instance
    GameGraphic gameGraphic(renderer, SCREENWIDTH, SCREENHEIGHT);

    IntroScreenGraphic intro(renderer, SCREENWIDTH, SCREENHEIGHT);

    // Create game instance
    GameBoard gameBoard;

    bool running = true;
    while (running)
    {
        while (SDL_PollEvent(&windowEvent))
        {
            if (SDL_QUIT == windowEvent.type)
            {
                running = false;
            }
            else if (windowEvent.type == SDL_KEYUP)
            {
                if (!intro.introPlayed)
                {
                    switch (windowEvent.key.keysym.sym)
                    {
                    case SDLK_SPACE:
                        if (intro.introPartOne)
                            intro.introPartOne = false;
                        else
                            intro.introPlayed = true;
                    }
                }
                else
                {
                    bool moved = false;
                    switch (windowEvent.key.keysym.sym)
                    {
                    case SDLK_q:
                    case SDLK_LEFT:
                        moved = gameBoard.moveLeft();
                        break;
                    case SDLK_d:
                    case SDLK_RIGHT:
                        moved = gameBoard.moveRight();
                        break;
                    case SDLK_z:
                    case SDLK_UP:
                        moved = gameBoard.moveUp();
                        break;
                    case SDLK_s:
                    case SDLK_DOWN:
                        moved = gameBoard.moveDown();
                        break;
                    }

                    if (moved)
                    {
                        gameBoard.addRandomTile();
                        gameGraphic.updateGameBoard(gameBoard);
                        gameBoard.display();

                        if (!gameBoard.canMove())
                        {
                            cout << "Game Over! Merci d'avoir joué." << endl;
                            running = false;
                        }
                    }
                }
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Gris foncé
        SDL_RenderClear(renderer);
        if (!intro.introPlayed)
        {
            intro.displayIntro();
        }
        else
        {
            gameGraphic.displayGameTexture();
        }

        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup

    SDL_Quit();
    return EXIT_SUCCESS;
}
