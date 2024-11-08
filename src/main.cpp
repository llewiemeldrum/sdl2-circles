#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include "MathUtils.h"
#include "AppConstants.h"
#include "Circle.h"
#include "ColorUtils.h"
#include "DrawUtils.h"
#include "SDLUtils.h"

Window_RenderContextPair * InitializeSDL();
void SDL_Loop(SDL_Renderer * renderContext);

int main (int argc, char** argv){
        Window_RenderContextPair * Window_RenderContext = \
        InitializeSDL();
        SDL_Loop(Window_RenderContext);
	return 0;
}

Window_RenderContextPair * InitializeSDL(){
        SDL_Window* window = NULL;
	SDL_Renderer *renderContext = NULL;

	if (SDL_Init(SDL_INIT_VIDEO)< 0){
		printf("SDL failed to init. SDL_Error:\
			%s\n", SDL_GetError());
                exit(-1);
	}
	SDL_Init(SDL_INIT_VIDEO);
   	SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderContext);
        Window_RenderContextPair * ret = (Window_RenderContextPair*)malloc(sizeof(Window_RenderContextPair));
        ret->window = window;
        ret->renderContext = renderContext;
        return ret;
}

void SDL_Loop(Window_RenderContextPair * Window_RenderContext){
        SDL_Renderer * renderContext = Window_RenderContext->renderContext;
        SDL_Window * window = Window_RenderContext->window;

        SDL_Event e;
        bool running = true; 
        Circle * circle = new Circle(0, 0, 15, 10, 50, true, {0, 0, 0}, {0, 0, 0});
	while(running){ 
                // print statements (?)
                int x,y;
                SDL_GetMouseState(&x,&y);
                SDL_Log("%f,%f\n, r:%i\n",circle->x,circle->y,circle->r);
                // event handler
	    	while( SDL_PollEvent( &e ) ){
		    	if( e.type == SDL_QUIT ){
			    running = false;
		        } 
		    }
		                                //SDL_GetMouseState(&x,&y);
                // Update game logic here
                circle->Update_Circle(renderContext, circle, 1);

                // Render frame here
                drawBackground(renderContext, BACKGROUND_COLOR);
		circle->Draw_Circle(renderContext,circle);
		
                SDL_RenderPresent(renderContext);
                // delay to control fps 
                SDL_Delay(16); // about 60fps (60fps is 16.67ms frametime)
	} 
	SDL_DestroyRenderer(renderContext);
	
	printf("execution terminated, quitting now.\n");
}