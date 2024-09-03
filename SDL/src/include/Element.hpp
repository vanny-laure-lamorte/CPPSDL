#ifndef ELEMENT_HPP
#define ELEMENT_HPP

#include <iostream>
using namespace std;

#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

#include "Window.hpp"

//* RENDERER *//
extern SDL_Renderer *renderer; 


//* COLORS *//
extern const SDL_Color COLOR_BLACK;
extern const SDL_Color COLOR_WHITE;

SDL_Texture* loadBackground(SDL_Renderer *renderer, SDL_Surface *&surface, const char *path);
void renderBackground(SDL_Renderer* renderer, SDL_Texture* surfaceTexture);
SDL_Texture* loadTexture(SDL_Renderer* renderer, const std::string& imagePath);
void renderTexture(SDL_Renderer* renderer, SDL_Texture* texture, int x, int y, int width, int height);

#endif
