#ifndef _FCT_H_
#include<SDL_image.h>
#include<SDL_ttf.h>
#include<SDL.h>

#define _FCT_H_

#define _SIZE_T_ 255
#define WINDOW_W 800
#define WINDOW_H 450



typedef enum{
    FAUX,
    VRAI
}booleen;

void SDL_ExitWithError(char* message);
void SDL_DestroyRessource(SDL_Renderer* r, SDL_Window* w, SDL_Texture* t);

#endif /*_FTC_H_*/