#include <SDL2/SDL.h>
void drawBackground (SDL_Renderer * ren, SDL_Color c){
        SDL_SetRenderDrawColor(ren, c.r, c.g, c.b, c.a);
        SDL_RenderClear(ren);
}