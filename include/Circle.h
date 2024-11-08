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
        public: 
        Circle(float x,  float y, float vx, float vy, int r, bool isDynamic, SDL_Color color, 
               SDL_Color outlineColor);

        void Draw_Circle(SDL_Renderer * renderer, Circle * c);
        void Update_Circle(SDL_Renderer * renderer, Circle * c, int dt);

        private:
        void Internal_Draw_Circle(SDL_Renderer * renderer, int cX, int cY, int r, SDL_Color color, 
                                  SDL_Color outlineColor);
};


#endif // CIRCLE_H