#ifndef RENDER_H
#define RENDER_H

#include "core.h"
#include "render.h"
#include <stdio.h>
#include <SDL2/SDL.h>

SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer);
void RenderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h);
void RenderText(const char* text, int x, int y, SDL_Color color);


#endif