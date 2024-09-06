#ifndef GAMEOPTION_HPP
#define GAMEOPTION_HPP

using namespace std;

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

class GameOptions
{
public:
    GameOptions(SDL_Renderer *renderer, int screenWidth, int screenHeight);
    ~GameOptions();

    void saveScore(int score);

private:
    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

}; 

#endif // GAMEOPTION_HPP