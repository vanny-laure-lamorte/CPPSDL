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

// Method to save score
void GameOptions::saveScore(string score, string timer)
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
            std::cerr << "Error reading JSON file: " << e.what() << endl;
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
        {"Score", score}, // Save Score
        {"Time", timer}   // Save current time
    };

    // Add the new score object to the array
    scoresJson.push_back(newScore);

    // Save the updated scores to the file
    ofstream outputFile(filename);
    if (outputFile.is_open())
    {
        outputFile << scoresJson.dump(4);
        outputFile.close();
        std::cout << "Score saved successfully!" << endl;
    }
    else
    {
        cerr << "Error opening file for writing." << endl;
    }
}

pair<string, string> GameOptions::getBestScore()
{
    const string filename = "scores.json";
    json scoresJson;

    // Open the JSON file and read existing scores
    ifstream inputFile(filename);
    if (!inputFile.is_open())
    {
        cerr << "Error opening file for reading." << endl;
        return {"0", "00:00"};
    }

    try
    {
        inputFile >> scoresJson;
    }
    catch (json::parse_error &e)
    {
        cerr << "Error reading JSON file: " << e.what() << endl;
        return {"0", "00:00"};
    }
    inputFile.close();

    // Initialize variables to store the best score
    int bestScore = 0;
    string bestTime = "00:00";

    // Iterate through all scores to find the best one
    for (const auto &entry : scoresJson)
    {
        int currentScore = stoi(entry.at("Score").get<string>());
        string currentTime = entry.at("Time").get<string>();

        if (currentScore > bestScore)
        {
            bestScore = currentScore;
            bestTime = currentTime;
        }
    }

    return {to_string(bestScore), bestTime};
}