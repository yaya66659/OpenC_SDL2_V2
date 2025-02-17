#ifndef __GRAPHIQUZE____H__

#define __GRAPHIQUE__H__


#define _POLICE_SIZE_MESSAGE_ 35

#include <SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

#include "fct.h"


typedef enum enumColor{

    BLANC,
    NOIR,
    ROUGE,
    VERT,
    BLEU
    }enumColor;

    typedef struct{
    int R;
    int G;
    int B;

    } RGBColors;

    
SDL_Texture* afficheMessage(char *message, SDL_Renderer* r, SDL_Window* w, enumColor color);

RGBColors colorRGB(enumColor c);


#endif /*__GRAPHIQUE__*/