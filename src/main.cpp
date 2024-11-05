#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define WHITE 255, 255, 255, 255
#define BACKGROUND_COLOR 255, 255, 255, 255
#define G 1
#define elasticity 0.99

#define dist(x1, y1, x2, y2) sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2))
#define GLOBAL_OUTLINE_SIZE 2
typedef struct Circle{
	float x;
	float y;
	float vx;
	float vy;

	int r;
	bool isDynamic;
	SDL_Color color;
        SDL_Color outlineColor;
} Circle;


Circle * Create_Circle(float x, float y, float vx, float vy, int r, bool isDynamic, SDL_Color color, SDL_Color outlineColor){
	Circle * cPtr = (Circle *)malloc(sizeof(Circle));
	cPtr->x = x; 
	cPtr->y = y;
	cPtr->vx = vx;
	cPtr->vy = vy;
	cPtr->r = r;
	cPtr->isDynamic = isDynamic;
	cPtr->color = color;
        cPtr->outlineColor = outlineColor;
	return cPtr;
}
void Internal_Draw_Circle(SDL_Renderer * renderer, int cX, int cY, int r, SDL_Color color, SDL_Color outlineColor);
void Draw_Circle(SDL_Renderer * renderer, Circle * c);
void Update_Circle(SDL_Renderer * renderer, Circle * c, int dt);

void drawBackground (SDL_Renderer * ren, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
const int WINDOW_WIDTH = 300; const int WINDOW_HEIGHT = 300;


int main (int argc, char** argv){
	SDL_Window* window = NULL;
	SDL_Renderer *renderContext = NULL;

	if (SDL_Init(SDL_INIT_VIDEO)< 0){
		printf("SDL failed to init. SDL_Error:\
			%s\n", SDL_GetError());
		exit(-1);
	}
	SDL_Init(SDL_INIT_VIDEO);
   	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderContext);
        SDL_Event e;
        bool running = true; 
        Circle * circlePtr = Create_Circle(0, 0, 15, 10, 50, true, {0, 0, 0}, {0, 0, 0});
	while(running){ 
                // print statements (?)
                int x,y;
                SDL_GetMouseState(&x,&y);
                SDL_Log("%f,%f\n, r:%i\n",circlePtr->x,circlePtr->y,circlePtr->r);
                // event handler
	    	while( SDL_PollEvent( &e ) ){
		    	if( e.type == SDL_QUIT ){
			    running = false;
		        } 
		    }
		                                //SDL_GetMouseState(&x,&y);
                // Update game logic here
                Update_Circle(renderContext, circlePtr, 1);

                // Render frame here
                drawBackground(renderContext, BACKGROUND_COLOR);
		Draw_Circle(renderContext,circlePtr);
		
                SDL_RenderPresent(renderContext);
                // delay to control fps 
                SDL_Delay(16); // about 60fps (60fps is 16.67ms frametime)
	} 
	SDL_DestroyRenderer(renderContext);
	SDL_DestroyWindow(window);
	printf("execution terminated, quitting now.\n");
	return 0;
}
void drawBackground (SDL_Renderer * ren, Uint8 r, Uint8 g, Uint8 b, Uint8 a){
        SDL_SetRenderDrawColor(ren, r, g, b, a);
        SDL_RenderClear(ren);
}

void Update_Circle(SDL_Renderer * renderer, Circle * c, int dt){
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

void Draw_Circle(SDL_Renderer * renderer, Circle * c){
	Internal_Draw_Circle(renderer, c->x, c->y, c->r, c->color, c->outlineColor);
}
void Internal_Draw_Circle(SDL_Renderer * renderer, int cX, int cY, int r, SDL_Color color, SDL_Color outlineColor){
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
