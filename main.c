#include <SDL2/SDL.h>
#include "src/engine/core.h"
#include <stdio.h>

int main() {
    if (!InitEngine()) {
        return 1;
    }

    RunGameLoop();

    CleanupEngine();
    return 0;
}