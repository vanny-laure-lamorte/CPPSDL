<!-- CREATE THE INITIAL WINDOW SDL -->
        
(1) Copy and paste include and lib folders from folder x86_64-w64-mingw32 into src folder.

(2) Copy and past what's inside bin folder "SDL2.dll" and "sdl2-config" at the root of the projetc.$

(3) Create a Makefile file and write : 
"all:
	g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2".

(4) Modify the "includePath" by adding "${workspaceFolder}/SDL/src/include" after "${default}".

(5) Create a file called main.cpp : 
"#include <iostream>
using namespace std; 
#include <SDL2/SDL.h>
const int WIDTH = 800, HEIGHT = 600; 
int main(int argc, char*argv[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window *window = SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI); 

    if(NULL == window){
    cout << "ERROR. Couldn't create window: " << SDL_GetError() << endl; 
    }

    SDL_Event windowEvent; 

    while(true){
        if (SDL_PollEvent(&windowEvent)){
            if (SDL_QUIT == windowEvent.type)
            {break;}
        }
    }
    SDL_DestroyWindow(window); 
    SDL_Quit(); 
    return EXIT_SUCCESS;
}
"

(6) Type comment "g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2" directly in the terminal.

(7) type comment "./main.exe" in the terminal.

<!-- COMPILE -->

<!-- First step -->
g++ -I src/include -L src/lib -o main main.cpp -lmingw32 -lSDL2main -lSDL2
