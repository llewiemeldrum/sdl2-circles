#include <SDL2/SDL.h>
void drawBackground (SDL_Renderer * ren, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
        SDL_SetRenderDrawColor(ren, r, g, b, a);
        SDL_RenderClear(ren);
}