#ifndef RENDER_H
#define RENDER_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

extern SDL_Renderer* renderer;
extern TTF_Font* titleFont;
extern TTF_Font* menuFont;

SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer);
void RenderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h);
void RenderText(TTF_Font* font, const char* text, int x, int y, SDL_Color color);
void RenderTextWithShadow(TTF_Font* font, const char* text, int x, int y, SDL_Color color, SDL_Color shadowColor);
void RenderButton(TTF_Font* font, const char* text, int x, int y, int w, int h);

#endif 