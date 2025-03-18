#ifndef CORE_H
#define CORE_H

#include <SDL2/SDL.h>
#include <stdbool.h>

extern SDL_Window* window;
extern SDL_Renderer* renderer;

bool InitEngine();
void RunGameLoop();
void CleanupEngine();

#endif
