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
void Draw_Circle(SDL_Renderer * renderer, Circle * c)
{
        Internal_Draw_Circle(renderer, c->x, c->y, c->r, c->color, c->outlineColor);
}
void Update_Circle(SDL_Renderer * renderer, Circle * c, int dt)
{
        if (c->isDynamic==false)
                return;
        float r = c->r;
        float x = c->x; 
        float y = c->y;
        // handle collisions
                // 1. collision detection
                // 2. collision resolution
                // 3. collision response
        // edge collisions
        if (y + r > WINDOW_HEIGHT){
                c->y = WINDOW_HEIGHT - r;
                c->vy*=-1.0;
        }
        if (y - r < 0){
                c->y = 0 + r;
                c->vy*=-1.0;
        }
        if (x +r > WINDOW_WIDTH){
                c->x = WINDOW_WIDTH - r;
                c->vx*=-1;
        }
        if (x -r < 0){
                c->x = 0 + r;
                c->vx*=-1;
        }
              
        c->vx*=elasticity; c->vy*=elasticity;
        c->x+=c->vx; c->y+=c->vy;        
        c->vy += G * dt;          

}

void Internal_Draw_Circle(SDL_Renderer * renderer, int cX, int cY, int r, SDL_Color color, SDL_Color outlineColor)
{
        const int diameter = r*2;
	int x1 = cX;
	int y1  = cY;
        for (int i = 0; i<WINDOW_WIDTH; i++){
                for (int y = 0; y<10; y++){
                // SDL_SetRenderDrawColor(renderer, outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a);
                // SDL_RenderDrawPoint(renderer, i, (int)(WINDOW_WIDTH)-y-r); 
                }
        }
	for (int x2 = cX-r; x2<cX+r; x2++){
		for (int y2 = cY-r; y2<cY+r; y2++){
			float distFromCenter = dist(x1,y1,x2,y2);
			if (distFromCenter<r){	
                                if (r-distFromCenter<GLOBAL_OUTLINE_SIZE /*|| distFromCenter<5*/){
                                        	
                                        //SDL_SetRenderDrawColor(renderer, outlineColor.r, outlineColor.g, outlineColor.b, outlineColor.a);
                                } else {
                                        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
                                }
                                SDL_RenderDrawPoint(renderer, x2, y2);
                        }
		}
	}
}