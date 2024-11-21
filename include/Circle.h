#ifndef CIRCLE_H
#define CIRCLE_H


#include <SDL2/SDL.h>
class Circle{
        
        public:
        float x;  float y;
        float vx; float vy;
        int r; 
        bool isDynamic; 
        SDL_Color color; 
        SDL_Color outlineColor;

        // class method prototypes:
        // constructor
        Circle(float x,  float y, float vx, float vy, int r, bool isDynamic, SDL_Color color, 
               SDL_Color outlineColor);

        void Draw_Circle(SDL_Renderer * renderer);
        void Update_Circle(SDL_Renderer * renderer, int dt);

};


#endif // CIRCLE_H