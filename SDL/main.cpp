using namespace std; 
#include <iostream>
#include <SDL2/SDL.h>

#include "Window.hpp"

int SCREENWIDTH = 600;
int SCREENHEIGHT = 750;

int main(int argc, char* argv[]) {

    // Create window
    Window window(SCREENWIDTH, SCREENHEIGHT);
    if (!window.isInitialized())
    {
        cerr << "Failed to initialize the window." << endl;
        return -1;
    }
    SDL_Event windowEvent;

    // Get renderer
    SDL_Renderer *renderer = window.getRenderer(); 
    
    // Create game instance

    // Main game loop

    while (true) {
        if (SDL_PollEvent(&windowEvent)) {
            
            if (SDL_QUIT == windowEvent.type) {
                break; 
            }
        }
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}

