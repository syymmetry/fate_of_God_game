#include "core.h"
#include <stdio.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;

Uint32 previousTime = 0;

float GetDeltaTime() {
    Uint32 currentTime = SDL_GetTicks();
    float delta = (currentTime - previousTime) / 1000.0f; 
    previousTime = currentTime;
    return delta;
}

int InitSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Ошибка инициализации SDL: %s", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Mother`s curse",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              1280, 720,
                              SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("Ошибка создания окна: %s", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("Ошибка создания рендера: %s", SDL_GetError());
        return false;
    }

    return true;
}

bool InitEngine() {
    if (!InitSDL()) {
        return false;
    }
    return true;
}

void RunGameLoop() {
    bool running = true;
    SDL_Event event;

    previousTime = SDL_GetTicks();

    while (running) {
        float deltaTime = GetDeltaTime(); 

        // Обработка событий
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        SDL_RenderPresent(renderer);
    }
}

void CleanupEngine() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
