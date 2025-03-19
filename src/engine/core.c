#include "core.h"
#include "render.h" 
#include <stdio.h>
#include <SDL2/SDL_mixer.h>

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* backgroundTexture = NULL;
Mix_Music* backgroundMusic = NULL;

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

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        SDL_Log("Ошибка инициализации SDL_mixer: %s", Mix_GetError());
        return false;
    }

    backgroundMusic = Mix_LoadMUS("assets/music.mp3");
    if (!backgroundMusic) {
        SDL_Log("Ошибка загрузки музыки: %s", Mix_GetError());
        return false;
    }

    if (Mix_PlayMusic(backgroundMusic, -1) == -1) {
        SDL_Log("Ошибка загрузки музыки: %s", Mix_GetError());
        return false;
    }

    window = SDL_CreateWindow("Fate of God",
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


    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        SDL_Log("Ошибка инициализации SDL_image: %s", IMG_GetError());
        return false;
    }

    if (TTF_Init() != 0) {
        SDL_Log("Ошибка инициализации SDL_ttf: %s", TTF_GetError());
        return false;
    }

    backgroundTexture = LoadTexture("assets/background.png", renderer);
    if (!backgroundTexture) {
        SDL_Log("Ошибка загрузки фона: %s", SDL_GetError());
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

void RenderMenu() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);


    RenderTexture(backgroundTexture, renderer, 0, 0, 1280, 720);

    // Цвета
    SDL_Color gold = {255, 215, 0, 255};
    SDL_Color darkRed = {139, 0, 0, 255};
    SDL_Color white = {255, 255, 255, 255};

    RenderTextWithShadow("Fate of God", 450, 50, gold, darkRed);

    RenderTextWithShadow("Single Player", 500, 200, white, darkRed);
    RenderTextWithShadow("Battle Net", 500, 250, white, darkRed);
    RenderTextWithShadow("Gateway: None", 500, 300, white, darkRed);
    RenderTextWithShadow("Other Multiplayer", 500, 350, white, darkRed);
    RenderTextWithShadow("ZY-EL 4.5.2", 500, 400, white, darkRed);
    RenderTextWithShadow("Credits", 500, 450, white, darkRed);
    RenderTextWithShadow("Cinematics", 500, 500, white, darkRed);

    SDL_RenderPresent(renderer);
}

void RunGameLoop() {
    bool running = true;
    SDL_Event event;

    previousTime = SDL_GetTicks();

    while (running) {
        float deltaTime = GetDeltaTime();

        SDL_Log("Delta Time: %f", deltaTime);

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }
        
        RenderMenu();
    }
}

void CleanupEngine() {
    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();
    SDL_DestroyTexture(backgroundTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
}
