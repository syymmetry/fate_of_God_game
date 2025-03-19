#ifndef CORE_H
#define CORE_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdbool.h>

extern SDL_Window* window;      // Объявляем window как extern
extern SDL_Renderer* renderer;  // Объявляем renderer как extern

bool InitEngine();
void RunGameLoop();
void CleanupEngine();
void RenderMenu();

#endif
