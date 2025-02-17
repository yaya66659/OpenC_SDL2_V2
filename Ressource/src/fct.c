#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL.h>
#include"headers\fct.h"

void SDL_ExitWithError(char *message)
{
    SDL_Log("%s > %s\n", message, SDL_GetError());
    exit(EXIT_FAILURE);
}
void SDL_DestroyRessource(SDL_Renderer* r, SDL_Window* w, SDL_Texture* t)
{
    if(t != NULL)
    SDL_DestroyTexture(t);
    if(r != NULL)
    SDL_DestroyRenderer(r);
   if(w != NULL)
    SDL_DestroyWindow(w);

     
}
