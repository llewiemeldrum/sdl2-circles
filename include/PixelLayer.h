#ifndef PIXELLAYER_H
#define PIXELLAYER_H

#include <SDL2/SDL.h>

class PixelLayer{
        private:
        public:
        int width; int height;
        int scalingFactor; 
        int pixelSize;
        SDL_Color * pixels;

        Uint8 opacity; 
        PixelLayer(int scalingFactor, Uint8 opacity);
        // a scaling factor of N means that pixels of the pixelLayer will be N times the size
        // of a pixel in the underlying layer.
        void SetPixel(int x, int y, SDL_Color col);
        SDL_Color GetPixel(int x, int y);
        void clear();
        void drawPixel(SDL_Renderer * renderContext, int x, int y);
        void DrawLayer(SDL_Renderer * renderContext);
};

#endif // PIXELLAYER_H