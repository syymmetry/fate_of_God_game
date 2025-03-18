#include "render.h"
#include <SDL_image.h>

SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(filename);
    if (!surface) {
        printf("Ошибка загрузки изображения: %s\n", IMG_GetError());
        return NULL;
    }

    texture = SDL_CreateTextFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void RenderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h) {
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}