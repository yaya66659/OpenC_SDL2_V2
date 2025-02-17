#ifndef _FCT_H_

#define _FCT_H_

#define _SIZE_T_ 255
#define SIZE_NOM_PROJET 500

#define WINDOW_W 800
#define WINDOW_H 430

typedef enum{
    FAUX,
    VRAI
}booleen;

void SDL_ExitWithError(char *messag);
void SDL_DestroyRessource(SDL_Renderer* r, SDL_Window* w, SDL_Texture* t);

booleen mouseInEnter(int x, int y, SDL_Rect rect);

int creeProjet(char* nomProjet);
void creeMakefile(char * nomProjet);

booleen copyRessourceDansDossierProjet(char *nomProjet);
///booleen lanceTerminal(char *nomProjet);
booleen lanceVsCode(char *nomProjet);


#endif ///_FCT_H_