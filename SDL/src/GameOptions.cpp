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
    : renderer(renderer), screenWidth(screenWidth), screenHeight(screenHeight){}

GameOptions::~GameOptions(){}

// Method to save score 
void GameOptions::saveScore(int score) {

    // Give name to the JSON file
    const string filename = "scores.json";

    // Create a JSON object
    json scoresJson;

    // If existing data
    ifstream inputFile(filename);
    if (inputFile.is_open()) {
        try {
            inputFile >> scoresJson;
        } catch (json::parse_error& e) {
            std::cerr << "Error reading JSON file: " << e.what() << endl;
            scoresJson = json::array();
        }
        inputFile.close();
    } else {
        // If the file does not exist
        scoresJson = json::array();
    }

    // Create a new score object
    json newScore = {
        {"score", score}, // Save Score
        {"timestamp", time(nullptr)} // Save current time
    };

    // Add the new score object to the array
    scoresJson.push_back(newScore);

    // Save the updated scores to the file
    ofstream outputFile(filename);
    if (outputFile.is_open()) {
        outputFile << scoresJson.dump(4);
        outputFile.close();
        std::cout << "Score saved successfully!" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }
}