#ifndef GAMEOPTION_HPP
#define GAMEOPTION_HPP

using namespace std;
#include <iostream>

// Top 5 players
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "nlohmann/json.hpp"

class GameOptions
{
public:
    GameOptions();
    ~GameOptions() = default;

    //*** USER ***//
    void saveScore(const string& playerName, const string& email, const string& score, const string& timer, string matchCount);

    //*** BEST PLAYER ***//
    tuple<string, string, string, string> getBestScore() const;
    int getUserScore(const string &playerName) const; 

    //*** TOP 5 PLAYERS ***//
    vector<pair<string, int>> getTopFiveScores() const ;

private:

}; 

#endif // GAMEOPTION_HPP