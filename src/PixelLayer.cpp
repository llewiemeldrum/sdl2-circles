#include "PixelLayer.h"
#include "AppConstants.h"
#include <SDL2/SDL.h>
#include <ColorUtils.h>

PixelLayer::PixelLayer(int scalingFactor, Uint8 opacity)
: scalingFactor(scalingFactor), opacity(opacity)
{
       
        width = WINDOW_WIDTH/scalingFactor;
        height = WINDOW_HEIGHT/scalingFactor;
        pixels = (SDL_Color *)( malloc( sizeof(SDL_Color)*(width*height) ));
        pixelSize = WINDOW_WIDTH/width;
}
        // a scaling factor of N means that pixels of the pixelLayer will be N times the size
        // of a pixel in the underlying layer.
        void PixelLayer::SetPixel(int x, int y, SDL_Color col){
                int offset = ((width*y)+x);
                *(pixels + offset)  = col;
        }

        SDL_Color PixelLayer::GetPixel(int x, int y){
                return pixels[(width*y)+x];
        }

        void PixelLayer::clear(){
                for (int y = 0; y<height; y++)
                        for (int x = 0; x<width; x++){
                                SDL_Color color = {(Uint8)rand(), (Uint8)rand(), 255};
                                SetPixel(x,y, color);
                        }
        }

        void PixelLayer::drawPixel(SDL_Renderer * renderContext, int px, int py){
                SDL_Color p = GetPixel(px,py);
                int x = px*pixelSize;
                int y = py*pixelSize;
                for (int ix = 0; ix<pixelSize; ix++)
                        for (int iy = 0; iy<pixelSize; iy++){
                                SDL_SetRenderDrawColor(renderContext, p.r, p.g, p.b, opacity);
                                SDL_RenderDrawPoint(renderContext, x+ix, y+iy);
                        }
        }

        void PixelLayer::DrawLayer(SDL_Renderer * renderContext){
               for (int y = 0; y<height; y++)
                        for (int x = 0; x<width; x++)
                                drawPixel(renderContext, x,y);
        }