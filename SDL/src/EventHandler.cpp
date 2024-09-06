#include "EventHandler.hpp"
#include "IntroScreenGraphic.hpp"
#include "GameBoard.hpp"
#include "GameGraphic.hpp"

// Constructor implementation
EventHandler::EventHandler(IntroScreenGraphic& intro, GameBoard& gameBoard, GameGraphic& gameGraphic)
    : intro(intro), gameBoard(gameBoard), gameGraphic(gameGraphic) {}

// Main event handling method
void EventHandler::handleEvents(bool& running)
{
    SDL_Event windowEvent;
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
                handleIntroEvents(windowEvent);
            }
            else
            {
                handleGameEvents(windowEvent);
            }
        }
    }
}

// Handling intro-specific events
void EventHandler::handleIntroEvents(SDL_Event& windowEvent)
{
    switch (windowEvent.key.keysym.sym)
    {
    case SDLK_SPACE:
        if (intro.introPartOne)
            intro.introPartOne = false;
        else
            intro.introPlayed = true;
        break;
    }
}

// Handling game-specific events
void EventHandler::handleGameEvents(SDL_Event& windowEvent)
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
        if (!gameBoard.canMove())
        {
            gameGraphic.updateGameBoard(gameBoard);
            gameGraphic.gameOver = true;
        }
    }
}
