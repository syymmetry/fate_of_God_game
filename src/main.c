#include <SDL2/SDL.h>
#include <stdio.h>


int main()
{   
    // инициализация SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        printf("Ошибка инициализации SDL: %s\n", SDL_GetError());
        return 1;
    }

    // create window
    SDL_Window* window = SDL_CreateWindow("Mother`s curse", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

    if (!window)
    {
        printf("window creation error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // initialization render
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("render initialization error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    } 
    
    // game cycle
    int running = 1;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                running = 0;
            }
        }
    }

    // clear screen
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    //Screen update
    SDL_RenderPresent(renderer);

    // clear resurses
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    
    
    return 0;
}
