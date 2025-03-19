#include "render.h"
#include "core.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

SDL_Texture* LoadTexture(const char* filename, SDL_Renderer* renderer) {
    SDL_Texture* texture = NULL;
    SDL_Surface* surface = IMG_Load(filename);
    if (!surface) {
        SDL_Log("Ошибка загрузки изображения: %s", IMG_GetError());
        return NULL;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return texture;
}

void RenderTexture(SDL_Texture* texture, SDL_Renderer* renderer, int x, int y, int w, int h) {
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void RenderText(const char* text, int x, int y, SDL_Color color) {
    static TTF_Font* font = NULL;
    if (!font) {
        font = TTF_OpenFont("assets/font.ttf", 48);
        if (!font) {
            SDL_Log("Ошибка загрузки шрифта: %s", TTF_GetError());
            return;
        }
    }

    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    if (!surface) {
        SDL_Log("Ошибка рендеринга текста: %s", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    if (!texture) {
        SDL_Log("Ошибка создания текстуры: %s", SDL_GetError());
        return;
    }

    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect dest = {x, y, w, h};
    SDL_RenderCopy(renderer, texture, NULL, &dest);

    SDL_DestroyTexture(texture);
}