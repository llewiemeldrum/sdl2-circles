#include "Circle.h"
#include <SDL2/SDL.h>
#include "AppConstants.h"
#include "MathUtils.h"

Circle::Circle(float x,  float y, float vx, float vy, int r, bool isDynamic, 
                SDL_Color color,  SDL_Color outlineColor)
                : x(x), y(y), vx(vx), vy(vy), r(r), isDynamic(isDynamic),
                color(color), outlineColor(outlineColor)
{

}

void Circle::Update_Circle(SDL_Renderer * renderer, int dt)
{
        if (this->isDynamic==false)
                return;
        float r = this->r;
        float x = this->x; 
        float y = this->y;
        // handle collisions
                // 1. collision detection
                // 2. collision resolution
                // 3. collision response
        // edge collisions
        if (y + r > WINDOW_HEIGHT){
                this->y = WINDOW_HEIGHT - r;
                this->vy*=-1.0;
        }
        if (y - r < 0){
                this->y = 0 + r;
                this->vy*=-1.0;
        }
        if (x +r > WINDOW_WIDTH){
                this->x = WINDOW_WIDTH - r;
                this->vx*=-1;
        }
        if (x -r < 0){
                this->x = 0 + r;
                this->vx*=-1;
        }
              
        this->vx*=elasticity; this->vy*=elasticity;
        this->x+=this->vx; this->y+=this->vy;        
        this->vy += G * dt;          

}

void Circle::Draw_Circle(SDL_Renderer * renderer)
{
        //const int diameter = r*2;
	int x1 = this->x;
	int y1  = this->y;
        // for (int i = 0; i<WINDOW_WIDTH; i++){
        //         for (int y = 0; y<10; y++){
        //         // SDL_SetRenderDrawColor(renderer, outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a);
        //         // SDL_RenderDrawPoint(renderer, i, (int)(WINDOW_WIDTH)-y-r); 
        //         }
        // }
	for (int x2 = this->x-r; x2<this->x+r; x2++){
		for (int y2 = this->y-r; y2<this->y+r; y2++){
			float distFromCenter = dist(x1,y1,x2,y2);
			if (distFromCenter<r){	
                                // if (r-distFromCenter<GLOBAL_OUTLINE_SIZE /*|| distFromCenter<5*/){
                                        	
                                //         //SDL_SetRenderDrawColor(renderer, outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a);
                                // } else {
                                //         SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                                // }
                                SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                                SDL_RenderDrawPoint(renderer, x2, y2);
                        }
		}
	}
}