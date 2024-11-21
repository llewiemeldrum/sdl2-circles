# Ideas:
### What i need: 
-       some way to separate my two layers, the top one being the rasterized circle
        and the bottom one being the actual render of the circle. 
To simplify the process, ill make two classes (?)
1. PixelRenderLayer: the rasterized layer that goes on top. 
        Members:
        - array[][] of pixels, which are basically just SDL_colors
        - opacity 
        Methods:
        - static DrawLayer()
        - SetPixel(x,y)
        - getPixel(x,y)
        - Clear(color) : 