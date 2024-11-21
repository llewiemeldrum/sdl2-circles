#ifndef SDLUTILS_H
#define SDLUTILS_H

#include <SDL2/SDL.h>

typedef struct {
        SDL_Window* window;
        SDL_Renderer * renderContext;
} Window_RenderContextPair;


#endif // SDLUTILS_H