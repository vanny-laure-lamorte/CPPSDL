#include "EventHandler.hpp"
#include "IntroScreenGraphic.hpp"
#include "GameBoard.hpp"
#include "GameGraphic.hpp"

// Constructor implementation
EventHandler::EventHandler(IntroScreenGraphic &intro, GameBoard &gameBoard, GameGraphic &gameGraphic)
    : intro(intro), gameBoard(gameBoard), gameGraphic(gameGraphic) {}

// Main event handling method
void EventHandler::handleEvents(bool &running)
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
        else if (windowEvent.type == SDL_TEXTINPUT && intro.typingEnabled)
        {
            // Ajoute le texte saisi à la chaîne inputText
            intro.inputText += windowEvent.text.text;
        }
        else if (windowEvent.type == SDL_KEYDOWN && intro.typingEnabled)
        {
            // Gère la touche BACKSPACE pour supprimer un caractère
            if (windowEvent.key.keysym.sym == SDLK_BACKSPACE && !intro.inputText.empty())
            {
                intro.inputText.pop_back();
            }
        }
    }
}

// Handling intro-specific events
void EventHandler::handleIntroEvents(SDL_Event &windowEvent)
{
    switch (windowEvent.key.keysym.sym)
    {
    case SDLK_SPACE:
        if (intro.introPartOne)
        {
            intro.introPartTwo = true;
            intro.introPartOne = false;
        }
        else if (intro.introPartTwo)
        {
            intro.moveToCorner = true;
        }
        break;
    case SDLK_RETURN:
        if (!intro.inputText.empty())
            intro.introPlayed = true;
    }
}

// Handling game-specific events
void EventHandler::handleGameEvents(SDL_Event &windowEvent)
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
