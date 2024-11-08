#ifndef SDLUTILS_H
#define SDLUTILS_H

#include <SDL2/SDL.h>

typedef struct Window_RenderContextPair{
        SDL_Window* window;
        SDL_Renderer * renderContext;
};


#endif // SDLUTILS_H