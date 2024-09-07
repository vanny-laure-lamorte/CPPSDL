#include <iostream>
using namespace std;

#include "GameOptions.hpp"

//** Save Score ***//
#include <nlohmann/json.hpp>
#include <fstream>
#include <string>
using json = nlohmann::json;

#include "Window.hpp"

GameOptions::GameOptions(SDL_Renderer *renderer, int screenWidth, int screenHeight)
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight)
{
}

GameOptions::~GameOptions()
{
}

void GameOptions::saveScore(const string& playerName, const string& score, const string& timer, string matchCount)
{
    // Give name to the JSON file
    const string filename = "scores.json";

    // Create a JSON object
    json scoresJson;

    // If existing data
    ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        try
        {
            inputFile >> scoresJson;
        }
        catch (json::parse_error &e)
        {
            cerr << "Error reading JSON file: " << e.what() << endl;
            scoresJson = json::array();
        }
        inputFile.close();
    }
    else
    {
        // If the file does not exist
        scoresJson = json::array();
    }

    // Create a new score object
    json newScore = {
        {"PlayerName", playerName}, // Save player name
        {"Score", score},           // Save score
        {"Time", timer},            // Save current time
        {"MatchCount", matchCount}  // Save number of matches
    };

    // Add the new score object to the array
    scoresJson.push_back(newScore);

    // Save the updated scores to the file
    ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << scoresJson.dump(4);
        outputFile.close();
        cout << "Score saved successfully!" << endl;
    }
    else
    {
        cerr << "Error opening file for writing." << endl;
    }
}



tuple<string, string, string, string> GameOptions::getBestScore() const
{
    const string filename = "scores.json";
    json scoresJson;

    ifstream inputFile(filename);
    if (inputFile.is_open())
    {
        try
        {
            inputFile >> scoresJson;
        }
        catch (json::parse_error &e)
        {
            cerr << "Error reading JSON file: " << e.what() << endl;
            return make_tuple("", "", "", "");
        }
        inputFile.close();
    }
    else
    {
        return make_tuple("", "", "", "");
    }

    string bestPlayerName = "";
    string bestScore = "0";
    string bestTime = "";
    string bestMatchCount = "";

    for (const auto& entry : scoresJson)
    {
        string currentScore = entry["Score"].get<string>();
        if (currentScore > bestScore)
        {
            bestScore = currentScore;
            bestPlayerName = entry["PlayerName"].get<string>();
            bestTime = entry["Time"].get<string>();
            bestMatchCount = entry["MatchCount"].get<string>();
        }
    }

    return make_tuple(bestPlayerName, bestScore, bestTime, bestMatchCount);
}