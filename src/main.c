#include<stdlib.h>
#include<stdio.h>
#include<SDL.h>
#include<SDL_image.h>
#include<SDL_ttf.h>

#include"headers\fct.h"
#include"headers\graphique.h"

int main(int argc, char *argv[])
{

	SDL_version vs;
	SDL_VERSION(&vs);

	printf("Bienvenue dans le SDL version : %d.%d.%d\n" , vs.major,vs.minor,  vs.patch);	

	SDL_Window * window = NULL;
	SDL_Renderer * renderer = NULL;

	if(SDL_Init(SDL_INIT_VIDEO) != 0)
	SDL_ExitWithError("erreure initialisation SDL");

	if(SDL_CreateWindowAndRenderer(WINDOW_W, WINDOW_H,0,&window, &renderer) != 0)
		SDL_ExitWithError("erreure creatuion fenetre et rendu");
/****************TTF*******************/
	if(TTF_Init() != 0)
	SDL_ExitWithError("erreure initialisation TTF");

	TTF_Font * police = NULL;
	police = TTF_OpenFont("police/police1.ttf", 64);

	if(police == NULL)
		SDL_ExitWithError("erreure chargement Police TTF");
	

	SDL_Color couleurText1 = {255,255,255};

	SDL_Surface * texte1 = NULL;
	SDL_Texture *  textureTexte1 = NULL; 

	texte1 = TTF_RenderText_Blended(police, "Open SDL2", couleurText1);
	TTF_CloseFont(police);

	if(texte1 == NULL)
		SDL_ExitWithError("erreure chargement Texte Surface TTF");

	textureTexte1 = SDL_CreateTextureFromSurface(renderer, texte1);
	SDL_FreeSurface(texte1);

	if(textureTexte1 == NULL)
		SDL_ExitWithError("Erreure create textureTexte1");

	SDL_Rect rectTexte1;

	if( SDL_QueryTexture(textureTexte1, NULL, NULL, &rectTexte1.w, &rectTexte1.h) != 0)
	{
			SDL_DestroyTexture(textureTexte1);
			SDL_ExitWithError("Erreure chargemente en memoir texte textureTexte1");
	}

	rectTexte1.x =(WINDOW_W-rectTexte1.w)/2;
	rectTexte1.y = 50;

	


/**********************************************************/
	


	SDL_Surface * imageDeFond = NULL;
	SDL_Texture * textureFond = NULL;

	imageDeFond = IMG_Load("images/fond2.jpg");

if(imageDeFond == NULL)
 {
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource( renderer, window, NULL);
	SDL_ExitWithError("erreure chargement image");
 }

textureFond =  SDL_CreateTextureFromSurface(renderer, imageDeFond);
 SDL_FreeSurface(imageDeFond);

 if(textureFond == NULL)
 {
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer, window,NULL);
	SDL_ExitWithError("erreure create texture from suface");
 }

SDL_Rect rectagleImageDeFond;
 if(SDL_QueryTexture(textureFond, NULL,NULL, &rectagleImageDeFond.w, &rectagleImageDeFond.h ) != 0)
 {
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer chargement en memoire de la texture");
 }
rectagleImageDeFond.x =( WINDOW_W-rectagleImageDeFond.w)/2;
rectagleImageDeFond.y = (WINDOW_H-rectagleImageDeFond.h)/2;

if(SDL_RenderCopy(renderer, textureFond, NULL, &rectagleImageDeFond) != 0)
{

	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer application de la texture sur le rendu");
 }




if(SDL_RenderCopy(renderer, textureTexte1, NULL, &rectTexte1) != 0)
	{
		SDL_DestroyTexture(textureTexte1);
						
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("Erreure chargemente en memoir texte textureTexte1");
	}

		SDL_Rect rectSasit;
		rectSasit.x = (WINDOW_W)/4;
		rectSasit.y = (WINDOW_H)/2;
		rectSasit.w = 400;
		rectSasit.h = 80;

		if(SDL_SetRenderDrawColor(renderer, 255,255,255,SDL_ALPHA_OPAQUE) != 0)
		{
			SDL_DestroyTexture(textureTexte1);
						
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("Erreure chargement couleur");
		}
		
		if(SDL_RenderDrawRect(renderer, &rectSasit)!= 0)
		{
			SDL_DestroyTexture(textureTexte1);
						
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("Erreure dessin rectangle");
		}
		

		TTF_Font * policeSaisit = NULL;
	policeSaisit = TTF_OpenFont("police/police1.ttf", 30);
		
	if(policeSaisit == NULL)
	{
			SDL_DestroyTexture(textureTexte1);
						
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Police TTF");
	}
		
	

	SDL_Color couleurSaisit = {255,255,255};

	SDL_Surface * texteSaisit = NULL;
	SDL_Texture *  textureTexteSaisit = NULL; 
	char saisit[_SIZE_T_] = "MonProjet";

		
	SDL_Rect rectSasitTexte;
		rectSasitTexte.x = (WINDOW_W)/4+10;
		rectSasitTexte.y = ((WINDOW_H)/2)+10;
		rectSasitTexte.w = 400;
		rectSasitTexte.h = 80;

texteSaisit = TTF_RenderText_Blended(policeSaisit,saisit, couleurSaisit);
	TTF_CloseFont(policeSaisit);


	if(texteSaisit == NULL)
	{
		SDL_DestroyTexture(textureTexte1);
						
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Texte Surface TTF");
	}

textureTexteSaisit = SDL_CreateTextureFromSurface(renderer, texteSaisit);
	SDL_FreeSurface(texteSaisit);
	if(textureTexteSaisit == NULL)
		{
		SDL_DestroyTexture(textureTexte1);
						
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Texte Surface TTF");
	}

		if( SDL_QueryTexture(textureTexteSaisit, NULL, NULL, &rectSasitTexte.w, &rectSasitTexte.h) != 0)
	{
		SDL_DestroyTexture(textureTexteSaisit);
			SDL_DestroyTexture(textureTexte1);
			SDL_DestroyRessource(renderer, window, textureFond);
			SDL_ExitWithError("Erreure chargemente en memoir texte textureTexte1");
	}
		if(SDL_RenderCopy(renderer, textureTexteSaisit, NULL, &rectSasitTexte) != 0)
		{
		SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Texte Surface TTF");
	}


		SDL_Rect rectBoutonEntrer;
		rectBoutonEntrer.x = WINDOW_W - 150;
		rectBoutonEntrer.y = WINDOW_H-200;
		rectBoutonEntrer.w = 100;
		rectBoutonEntrer.h = 50;

		SDL_Rect rectBoutonEntrerText;
		rectBoutonEntrerText.x = WINDOW_W - 140;
		rectBoutonEntrerText.y = WINDOW_H-190;
		rectBoutonEntrerText.w = 90;
		rectBoutonEntrerText.h = 40;

		if(SDL_RenderFillRect(renderer, &rectBoutonEntrer)!= 0)
		{
				SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Texte Surface TTF");
		}

		TTF_Font *  policeBoutonEntrer = NULL;

		policeBoutonEntrer = TTF_OpenFont("police/police1.ttf", 23);
		if(policeBoutonEntrer == NULL)
	{
		SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement police bouton entrer");
	}

		SDL_Color couloeurBoutonEntrer ={0,0,0};

		SDL_Surface * texteBoutonEntrer = NULL;
		SDL_Texture * textureBoutonEntrer = NULL;

		texteBoutonEntrer = TTF_RenderText_Blended(policeBoutonEntrer,"Cree Projet", couloeurBoutonEntrer);
		TTF_CloseFont(policeBoutonEntrer);

		if(texteBoutonEntrer == NULL)
		{
			SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement police bouton entrer");
		}
		
		textureBoutonEntrer =  SDL_CreateTextureFromSurface(renderer, texteBoutonEntrer);
		SDL_FreeSurface(texteBoutonEntrer);

		if(textureBoutonEntrer == NULL)
		{
			SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("Erreurer creation texture depui surface bouton entrer!");
		}

		if(SDL_QueryTexture(textureBoutonEntrer, NULL, NULL, &rectBoutonEntrerText.w, &rectBoutonEntrerText.h) != 0)
		{
			SDL_DestroyTexture(textureBoutonEntrer);
			SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("Erreurer chargement en memoir de la texture bouton entrer!");
		}

		if(SDL_RenderCopy(renderer, textureBoutonEntrer, NULL, &rectBoutonEntrerText)!= 0)
		{
			SDL_DestroyTexture(textureBoutonEntrer);
			SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("Erreurer  aplication sur rendu  bouton entrer!");
		}

		
		
		
		
		
		
		
		
		
		
		


	SDL_RenderPresent(renderer);

		//SDL_Delay(2000);
/***************************************************************/

SDL_bool lancher  = SDL_TRUE;
booleen majuscule = FAUX;
booleen sourieDedansBoutonEntrer = FAUX;
int posX = 0;
int posY = 0;



enumColor c;
SDL_Texture * textureMessage = NULL;


								
								
				

while(lancher)
{

SDL_Event event;
	while (SDL_PollEvent(&event))
	{
			switch(event.type)
		{
			case SDL_QUIT:
			lancher = SDL_FALSE;
			break;
			

			case SDL_MOUSEMOTION:
				posX = event.motion.x;
				posY = event.motion.y;

			if(mouseInEnter(posX, posY, rectBoutonEntrer) == VRAI)
			sourieDedansBoutonEntrer =VRAI;
			else
			sourieDedansBoutonEntrer =FAUX;
			break;	
			case SDL_MOUSEBUTTONDOWN:
						if(event.button.button == SDL_BUTTON_LEFT)
						{
								if(event.button.clicks >= 2 )
							{
								int ret = creeProjet(saisit);
								printf("return creeprojet = %d", ret );
								creeMakefile(saisit);
								printf("Fichier Makefile cree pour compilation gcc avec SDL2 TTF SD2_image");
								switch(ret)
								{

									

									case -7:
								c = BLANC;
											if((textureMessage = afficheMessage("Entrez un nom de projet",
renderer, window, c)) == NULL)
				{
					SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexteSaisit);
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer Affiche message ");
				}
				SDL_RenderPresent(renderer);


									break;
																		case -6:
				c = ROUGE;
			if((textureMessage = afficheMessage("ECHEC lance VScode", 
renderer, window, c)) == NULL)
				{
					SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexteSaisit);
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer Affiche message ");
				}
				SDL_RenderPresent(renderer);

									break;

																		/*case -5:
				c = ROUGE;
			if((textureMessage = afficheMessage("ECHEC lance terminal", 
renderer, window, c)) == NULL)
				{
					SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexteSaisit);
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer Affiche message ");
				}

									break;*/

									case -4:
				c = ROUGE;
			if((textureMessage = afficheMessage("ECHEC xcopy de Ressource", renderer, window, c)) == NULL)
				{
					SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexteSaisit);
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer Affiche message ");
				}
				SDL_RenderPresent(renderer);

									break;

							case -3:
													 c = ROUGE;
				if((textureMessage = afficheMessage("ECHEC MKDIR cmd", renderer, 
window, c)) == NULL)
				{
					SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexteSaisit);
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer Affiche message ");
				}
				SDL_RenderPresent(renderer);
								break;


																case -2:
											c = ROUGE;
											if((textureMessage = afficheMessage
("Nom deja existant", renderer, 
window, c)) == NULL)
			{
				SDL_DestroyTexture(textureBoutonEntrer);
	SDL_DestroyTexture(textureTexteSaisit);
SDL_DestroyTexture(textureTexte1);
SDL_DestroyRessource(renderer,window, textureFond);
SDL_ExitWithError("Ereurer Affiche message ");
			}
			SDL_RenderPresent(renderer);

								break;



								case -1:
													 c = ROUGE;
				if((textureMessage = afficheMessage("Impossible ouvirir ficher dir", renderer, 
window, c))== NULL)
				{
					SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexteSaisit);
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyRessource(renderer,window, textureFond);
	SDL_ExitWithError("Ereurer Affiche message ");
				}
				SDL_RenderPresent(renderer);
									break;

								case 0 :

								 c = VERT;
								if((textureMessage = afficheMessage("Dossier cree", renderer, window, c)) == NULL)
								{
									SDL_DestroyTexture(textureBoutonEntrer);
						SDL_DestroyTexture(textureTexteSaisit);
					SDL_DestroyTexture(textureTexte1);
					SDL_DestroyRessource(renderer,window, textureFond);
					SDL_ExitWithError("Ereurer Affiche message ");
								}
								SDL_RenderPresent(renderer);
								break;


					

								
								default:

													 c = BLANC;
					if((textureMessage = afficheMessage("Enterez le nom du projet", renderer, 
window, c))== NULL)
					{
						SDL_DestroyTexture(textureBoutonEntrer);
			SDL_DestroyTexture(textureTexteSaisit);
		SDL_DestroyTexture(textureTexte1);
		SDL_DestroyRessource(renderer,window, textureFond);
		SDL_ExitWithError("Ereurer Affiche message ");
					}
					SDL_RenderPresent(renderer);
									break;
								}
																
								
								}
								
								
							}
						
						
						
				
				

			case SDL_KEYDOWN:
			switch(event.key.keysym.sym)
				{

					case SDLK_BACKSPACE:					
					SDL_RenderClear(renderer);
					if(SDL_RenderCopy(renderer, textureFond, NULL, &rectagleImageDeFond) != 0)
						{		
							SDL_DestroyTexture(textureMessage);				
							SDL_DestroyTexture(textureBoutonEntrer);
								SDL_DestroyTexture(textureTexteSaisit);
							SDL_DestroyTexture(textureTexte1);
							SDL_DestroyRessource(renderer,window, textureFond);
							SDL_ExitWithError("Ereurer application de la texture sur le rendu");
						}




						if(SDL_RenderCopy(renderer, textureTexte1, NULL, &rectTexte1) != 0)
							{
								SDL_DestroyTexture(textureMessage);
								SDL_DestroyTexture(textureBoutonEntrer);
								SDL_DestroyTexture(textureTexte1);
								SDL_DestroyTexture(textureTexteSaisit);				
								SDL_DestroyRessource(renderer, window, textureFond);
								SDL_ExitWithError("Erreure chargemente en memoir texte textureTexte1");
							}

							if(SDL_RenderDrawRect(renderer, &rectSasit)!= 0)
							{
								SDL_DestroyTexture(textureMessage);
								SDL_DestroyTexture(textureBoutonEntrer);
								SDL_DestroyTexture(textureTexte1);
								SDL_DestroyTexture(textureTexteSaisit);				
							SDL_DestroyRessource(renderer, window, textureFond);
							SDL_ExitWithError("Erreure dessin rectangle");
							}
							if(SDL_RenderFillRect(renderer, &rectBoutonEntrer)!= 0)
		{
			SDL_DestroyTexture(textureMessage);
			SDL_DestroyTexture(textureBoutonEntrer);
				SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure dessin rectengle bouton entrer");
		}
			if(SDL_RenderCopy(renderer, textureBoutonEntrer, NULL, &rectBoutonEntrerText)!= 0)
		{
			SDL_DestroyTexture(textureMessage);
			SDL_DestroyTexture(textureBoutonEntrer);
			SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("Erreurer aplication sur rendu bouton entrer!");
		}

	
					if((strlen(saisit)) != 0)
					{
						char buffer[_SIZE_T_] ="";
					int i;
					for(i = 0; i<(strlen(saisit)-1); i++)
					{
						buffer[i] = saisit[i];
					}
					buffer[i+1] = '\0';

					strcpy(saisit, buffer);
					}
					
					break;
					case SDLK_LSHIFT:
					
					majuscule =VRAI;
					
					break;
					case SDLK_a:
					if(majuscule)
					strcat(saisit, "A");
					else
					strcat(saisit, "a");
					break;
					case SDLK_b:
					if(majuscule)
					strcat(saisit, "B");
					else
					strcat(saisit, "b");
					break;
					case SDLK_c:
					if(majuscule)
					strcat(saisit, "C");
					else
					strcat(saisit, "c");
					break;
					case SDLK_d:
					if(majuscule)
					strcat(saisit, "D");
					else
					strcat(saisit, "d");
					break;
					case SDLK_e:
					if(majuscule)
					strcat(saisit, "E");
					else
					strcat(saisit, "e");
					break;
					case SDLK_f:
					if(majuscule)
					strcat(saisit, "F");
					else
					strcat(saisit, "f");
					break;
					case SDLK_g:
					if(majuscule)
					strcat(saisit, "G");
					else
					strcat(saisit, "g");
					break;
					case SDLK_h:
					if(majuscule)
					strcat(saisit, "H");
					else
					strcat(saisit, "h");
					break;
					case SDLK_i:
					if(majuscule)
					strcat(saisit, "I");
					else
					strcat(saisit, "i");
					break;
					case SDLK_j:
					if(majuscule)
					strcat(saisit, "J");
					else
					strcat(saisit, "j");
					break;
					case SDLK_k:
					if(majuscule)
					strcat(saisit, "K");
					else
					strcat(saisit, "k");
					break;
					case SDLK_l:
					if(majuscule)
					strcat(saisit, "L");
					else
					strcat(saisit, "l");
					break;
					case SDLK_m:
					if(majuscule)
					strcat(saisit, "M");
					else
					strcat(saisit, "m");
					break;
					case SDLK_n:
					if(majuscule)
					strcat(saisit, "N");
					else
					strcat(saisit, "n");
					break;
					case SDLK_o:
					if(majuscule)
					strcat(saisit, "O");
					else
					strcat(saisit, "o");
					break;
					case SDLK_p:
					if(majuscule)
					strcat(saisit, "P");
					else
					strcat(saisit, "p");
					break;
					case SDLK_q:
					if(majuscule)
					strcat(saisit, "Q");
					else
					strcat(saisit, "q");
					break;
					case SDLK_r:
					if(majuscule)
					strcat(saisit, "R");
					else
					strcat(saisit, "r");
					break;
					case SDLK_s:
					if(majuscule)
					strcat(saisit, "S");
					else
					strcat(saisit, "s");
					break;
					case SDLK_t:
					if(majuscule)
					strcat(saisit, "T");
					else
					strcat(saisit, "t");
					break;
					case SDLK_u:
					if(majuscule)
					strcat(saisit, "U");
					else
					strcat(saisit, "u");
					break;
					case SDLK_v:
					if(majuscule)
					strcat(saisit, "V");
					else
					strcat(saisit, "v");
					break;
					case SDLK_w:
					if(majuscule)
					strcat(saisit, "W");
					else
					strcat(saisit, "w");
					break;
					case SDLK_x:
					if(majuscule)
					strcat(saisit, "X");
					else
					strcat(saisit, "x");
					break;
					case SDLK_y:
					if(majuscule)
					strcat(saisit, "Y");
					else
					strcat(saisit, "y");
					break;
					case SDLK_z:
					if(majuscule)
					strcat(saisit, "Z");
					else
					strcat(saisit, "z");
					break;
					case SDLK_KP_0:
					strcat(saisit, "0");
					break;
					case SDLK_KP_1:
					strcat(saisit, "1");
					break;
					case SDLK_KP_2:
					strcat(saisit, "2");
					break;
					case SDLK_KP_3:
					strcat(saisit, "3");
					break;
					case SDLK_KP_4:
					strcat(saisit, "4");
					break;
					case SDLK_KP_5:
					strcat(saisit, "5");
					break;
					case SDLK_KP_6:
					strcat(saisit, "0");
					break;
					case SDLK_KP_7:
					strcat(saisit, "7");
					break;
					case SDLK_KP_8:
					strcat(saisit, "8");
					break;
					case SDLK_KP_9:
					strcat(saisit, "9");
					break;


					default:
					break;
							
				}
			

		policeSaisit = TTF_OpenFont("police/police1.ttf", 30);

	if(policeSaisit == NULL)
	{
		SDL_DestroyTexture(textureMessage);
		SDL_DestroyTexture(textureBoutonEntrer);
			SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Police TTF");
	}		
				
	if(strlen(saisit) > 0)
	{
			texteSaisit = TTF_RenderText_Blended(policeSaisit, saisit, couleurSaisit);
	TTF_CloseFont(policeSaisit);


	if(texteSaisit == NULL)
	{
		SDL_DestroyTexture(textureMessage);
		SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Texte Surface TTF");
	}

	textureTexteSaisit = SDL_CreateTextureFromSurface(renderer, texteSaisit);
	SDL_FreeSurface(texteSaisit);
	if(textureTexteSaisit == NULL)
		{
			SDL_DestroyTexture(textureMessage);
			SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Texte Surface TTF");
	}

		if( SDL_QueryTexture(textureTexteSaisit, NULL, NULL, &rectSasitTexte.w, &rectSasitTexte.h) != 0)
	{
		SDL_DestroyTexture(textureMessage);
		SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexteSaisit);
			SDL_DestroyTexture(textureTexte1);
			SDL_DestroyRessource(renderer, window, textureFond);
			SDL_ExitWithError("Erreure chargemente en memoir texte textureTexte1");
	}
		if(SDL_RenderCopy(renderer, textureTexteSaisit, NULL, &rectSasitTexte) != 0)
		{
			
			
SDL_DestroyTexture(textureMessage);
			SDL_DestroyTexture(textureBoutonEntrer);
		SDL_DestroyTexture(textureTexte1);
		SDL_DestroyTexture(textureTexteSaisit);				
		SDL_DestroyRessource(renderer, window, textureFond);
		SDL_ExitWithError("erreure chargement Texte Surface TTF");
	}
	}				
		

					
					SDL_RenderPresent(renderer);
			break;

			case SDL_KEYUP:
				switch (event.key.keysym.sym)
				{
				case SDLK_LSHIFT:
					majuscule =FAUX;
					break;
				
				default:
					break;
				}

			break;
			default:
			break;
		

		}
	}
	
	
}

/*************************************************************/
SDL_DestroyTexture(textureMessage);
SDL_DestroyTexture(textureBoutonEntrer);
	SDL_DestroyTexture(textureTexte1);
	SDL_DestroyTexture(textureTexteSaisit);
	SDL_DestroyRessource(renderer,window,textureFond);
	TTF_Quit();
    SDL_Quit();
	return 0;
}