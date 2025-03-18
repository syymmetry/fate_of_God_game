#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>

SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer);

void RenderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h);


#endif