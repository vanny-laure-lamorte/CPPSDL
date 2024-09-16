#include "EventHandler.hpp"
#include "IntroScreenGraphic.hpp"
#include "GameBoard.hpp"
#include "GameGraphic.hpp"

#include <iostream>

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
                handleIntroEvents(windowEvent); // Intro key events
            }
            else
            {
                handleGameEvents(windowEvent); // Game key events
            }
        }
        else if (windowEvent.type == SDL_MOUSEBUTTONDOWN)
        {
            if (!intro.introPlayed)
            {
                handleIntroEvents(windowEvent); // Intro mouse events
            }
            else
            {
                handleGameEvents(windowEvent); // Game mouse events
            }
        }
        else if (windowEvent.type == SDL_TEXTINPUT && intro.typingEnabled)
        {
            intro.inputText += windowEvent.text.text;
        }
        else if (windowEvent.type == SDL_KEYDOWN && intro.typingEnabled)
        {
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
        {
            intro.introPlayed = true;
            gameGraphic.getUsername(intro.inputText);
            gameBoard = gameGraphic.resetGame();
        }
        break;

    case SDLK_KP_PLUS:
        intro.introPartOne = false;
        intro.introPartTwo = false;
        intro.introPlayed = true;
        gameGraphic.getUsername("LacVanThu");
        gameBoard = gameGraphic.resetGame();
        break;
    }

    // Handle mouse click for PressStartRect
    if (windowEvent.type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        if (mouseX >= PressStartRect.x && mouseX <= (PressStartRect.x + PressStartRect.w) &&
            mouseY >= PressStartRect.y && mouseY <= (PressStartRect.y + PressStartRect.h))
        {
            if (!intro.inputText.empty())
            {
                intro.introPlayed = true;
                gameGraphic.getUsername(intro.inputText);
                gameBoard = gameGraphic.resetGame();
            }
        }
    }
}

// Handling game-specific events
void EventHandler::handleGameEvents(SDL_Event &windowEvent)
{
    bool moved = false;

    // Check for keyboard events
    if (windowEvent.type == SDL_KEYUP)
    {
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
        case SDLK_r:
            gameBoard = gameGraphic.resetGame();
            break;
        case SDLK_u:
            gameBoard = gameGraphic.undoGame();
            break;
        }
    }
    // Check for mouse click events
    else if (windowEvent.type == SDL_MOUSEBUTTONDOWN)
    {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);

        // Check if the mouse is on reset button
        if (mouseX >= resetRect.x && mouseX <= (resetRect.x + resetRect.w) &&
            mouseY >= resetRect.y && mouseY <= (resetRect.y + resetRect.h))
        {
            gameBoard = gameGraphic.resetGame();
        }

        // Check if the mouse is on undo button
        if (mouseX >= undoRect.x && mouseX <= (undoRect.x + undoRect.w) &&
            mouseY >= undoRect.y && mouseY <= (undoRect.y + undoRect.h))
        {
            gameBoard = gameGraphic.undoGame();
        }
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
