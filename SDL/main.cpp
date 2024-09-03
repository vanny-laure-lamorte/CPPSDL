using namespace std; 
#include <iostream>
#include <SDL2/SDL.h>
#include "Window.hpp"
#include "GameGraphic.hpp"

int SCREENWIDTH = 900;
int SCREENHEIGHT = 600;

int main(int argc, char* argv[]) {

    // Create window
    Window window(SCREENWIDTH, SCREENHEIGHT);
    if (!window.isInitialized()) {
        cerr << "Failed to initialize the window." << endl;
        return -1;
    }

    SDL_Event windowEvent;

    // Get renderer
    SDL_Renderer *renderer = window.getRenderer(); 
    
    // Create game graphic instance
    GameGraphic gameGraphic(renderer, SCREENWIDTH, SCREENHEIGHT);
    
    // Load textures

    // Main game loop
    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            if (SDL_QUIT == windowEvent.type) {
                break; 
            }
        }

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Gris foncé
        SDL_RenderClear(renderer);

        // Display background
        gameGraphic.displayTexture();
        
        // Present the renderer
        SDL_RenderPresent(renderer);
    }

    // Cleanup

    SDL_Quit();
    return EXIT_SUCCESS;
}
