//gcc src/*.c -o bin/SDL2prog -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf
#include<stdlib.h>
#include<stdio.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

#include"headers\fct.h"

int main(int argc, char *argv[])
{

	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;
	
	SDL_version sdlVersion;
	SDL_VERSION(&sdlVersion);

	printf("Bienvenue dans la SDL2 Version %d.%d.%d!\n", sdlVersion.major, sdlVersion.minor,sdlVersion.patch);

	/****INITIALISATION DE LA SDL *****/

	if(SDL_Init(SDL_INIT_VIDEO) != 0 )
	SDL_ExitWithError("erreure initialisation SDL");

/***************INITIALISATION TTF**********************/
	if(TTF_Init() != 0)
	SDL_ExitWithError("erreure initialisation TTF");


	/****CREATION DU LA FENETRE ET DU RENDU ******/

	if(SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H, 0, &window, &renderer) != 0)
	SDL_ExitWithError("Erreure creation fentre et rendu");

SDL_RenderPresent(renderer);// actualisation du rendu


	
	

	//SDL_Delay(3000);
/*********BOUCLE INFINI CAPTURE DES EVENEMENT****************/
	SDL_bool progLancher = SDL_TRUE;

	while (progLancher)
	{
		SDL_Event event;

		
		while (SDL_PollEvent(&event))
		{
			switch(event.type)
			{

				case SDL_QUIT :
					progLancher = SDL_FALSE;
				break;

				default:
				break;

			}
		}
		
	}
	




	/****lIBERATION DE LA MEMOIR POUR EVITER LES FUITES ****/
	
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	TTF_Quit();	
	SDL_Quit();
    
	return 0;
}