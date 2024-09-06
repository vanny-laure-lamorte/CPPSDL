#ifndef EVENTHANDLER_HPP
#define EVENTHANDLER_HPP

#include <SDL2/SDL.h>

class IntroScreenGraphic;
class GameBoard;
class GameGraphic;

class EventHandler
{
public:
    EventHandler(IntroScreenGraphic& intro, GameBoard& gameBoard, GameGraphic& gameGraphic);

    void handleEvents(bool& running);

private:
    IntroScreenGraphic& intro;
    GameBoard& gameBoard;
    GameGraphic& gameGraphic;

    // Handle events related to the intro part
    void handleIntroEvents(SDL_Event& windowEvent);

    // Handle events related to the game part
    void handleGameEvents(SDL_Event& windowEvent);
};

#endif // EVENTHANDLER_HPP
