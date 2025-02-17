#include<stdlib.h>
#include<stdio.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

#include"headers\fct.h"
#include "headers\graphique.h"

SDL_Texture* afficheMessage(char *message, SDL_Renderer* r, SDL_Window* w, 
enumColor color){


TTF_Font * police1 = NULL;
police1 = TTF_OpenFont("police\\police1.ttf", _POLICE_SIZE_MESSAGE_);

if(police1 == NULL)
{
    return NULL;
} 
RGBColors c = colorRGB(color);
SDL_Color couleur = {c.R, c.G, c.B, 0};


SDL_Surface* surfaceMessage = NULL;
SDL_Texture* textureMessage = NULL;

surfaceMessage = TTF_RenderText_Blended(police1, message, couleur);
TTF_CloseFont(police1);

if(surfaceMessage ==NULL)
return NULL;

textureMessage = SDL_CreateTextureFromSurface(r, surfaceMessage);
SDL_FreeSurface(surfaceMessage);
if(textureMessage == NULL)
{
    
    return NULL;
}

SDL_Rect messageRect;
messageRect.x = (WINDOW_W-messageRect.h)/2;
messageRect.y = (WINDOW_W-messageRect.h)/2.5;
messageRect.h = WINDOW_H/6;
messageRect.w = WINDOW_W/4;


if(SDL_SetRenderDrawColor(r, 0, 0, 0,255))
{
     SDL_DestroyTexture(textureMessage);
 return NULL;
}

if(SDL_RenderFillRect(r, &messageRect) != 0)
{
    SDL_DestroyTexture(textureMessage);
    return NULL;
}

if(SDL_QueryTexture(textureMessage, NULL, NULL, &messageRect.w, &messageRect.h))
{
    SDL_DestroyTexture(textureMessage);
    return NULL;
}

if(SDL_RenderCopy(r, textureMessage, 0, &messageRect ))
{
     SDL_DestroyTexture(textureMessage);
 return NULL;
}

if(SDL_SetRenderDrawColor(r, 255, 255, 255,0))
{
     SDL_DestroyTexture(textureMessage);
 return NULL;
}


return textureMessage;

}

RGBColors colorRGB(enumColor c){

   RGBColors RGB;

    switch (c)
    {
      case ROUGE:
        RGB.R = 255;
        RGB.G = 0;
        RGB.B = 0;
    
     break;
      case VERT:
       RGB.R = 0;
       RGB.G = 255;
       RGB.B = 0;
     break;
      case BLEU:
  RGB.R = 0;
  RGB.G = 0;
  RGB.B = 255;
     break;
      case BLANC:
  RGB.R = 255;
  RGB.G = 255;
  RGB.B = 2550;
     break;
      case NOIR:
  RGB.R = 0;
  RGB.G = 0;
  RGB.B = 0;
     break;
    
    default:
        break;
    }


    return RGB;

}