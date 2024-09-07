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
        cerr << "Unable to open the file: " << filename << endl;
        return make_tuple("", "", "", "");
    }

    string bestPlayerName = "";
    int bestScore = 0; // Change type to int for correct comparison
    string bestTime = "";
    string bestMatchCount = "";

    for (const auto& entry : scoresJson)
    {
        try
        {
            int currentScore = stoi(entry["Score"].get<string>());
            if (currentScore > bestScore)
            {
                bestScore = currentScore;
                bestPlayerName = entry["PlayerName"].get<string>();
                bestTime = entry["Time"].get<string>();
                bestMatchCount = entry["MatchCount"].get<string>();
            }
        }
        catch (const std::exception& e)
        {
            cerr << "Error processing score entry: " << e.what() << endl;
            continue; // Skip to the next entry if there's an error
        }
    }

    return make_tuple(bestPlayerName, to_string(bestScore), bestTime, bestMatchCount);
}