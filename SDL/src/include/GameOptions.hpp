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

    void saveScore(const string& playerName, const string& score, const string& timer, string matchCount);
    tuple<string, string, string, string> getBestScore() const;

    

private:
    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;

}; 

#endif // GAMEOPTION_HPP