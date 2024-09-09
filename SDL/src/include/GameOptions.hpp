#ifndef GAMEOPTION_HPP
#define GAMEOPTION_HPP

using namespace std;
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

// Top 5 players
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include <nlohmann/json.hpp>

class GameOptions
{
public:
    GameOptions(SDL_Renderer *renderer, int screenWidth, int screenHeight);
    ~GameOptions();

    void saveScore(const string& playerName, const string& score, const string& timer, string matchCount);
    tuple<string, string, string, string> getBestScore() const;

    // Top 5 players info
    vector<pair<string, int>> getTopFiveScores() const ;

private:
    SDL_Renderer *renderer;
    int screenWidth;
    int screenHeight;


}; 

#endif // GAMEOPTION_HPP