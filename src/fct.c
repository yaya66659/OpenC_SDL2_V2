/*  
 * Ce fichier fait partie de OpenC_SDL2_V2.  
 *  
 * OpenC_SDL2_V2 est un logiciel libre : vous pouvez le redistribuer et/ou le modifier  
 * selon les termes de la licence GNU General Public License publiée par  
 * la Free Software Foundation, soit la version 3 de la licence,  
 * soit (à votre choix) toute version ultérieure.  
 *  
 * OpenC_SDL2_V2 est distribué dans l’espoir qu’il sera utile,  
 * mais SANS AUCUNE GARANTIE ; sans même la garantie implicite  
 * de COMMERCIALISATION ou D’ADAPTATION À UN OBJET PARTICULIER.  
 * Voir la Licence Publique Générale GNU pour plus de détails.  
 *  
 * Vous devriez avoir reçu une copie de la Licence Publique Générale GNU  
 * avec OpenC_SDL2_V2. Si ce n’est pas le cas, voir <https://www.gnu.org/licenses/>.  
 */

#include<stdlib.h>
#include<stdio.h>
#include<string.h>

#include<SDL.h>
#include<SDL_ttf.h>
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

booleen mouseInEnter(int x, int y, SDL_Rect rect)
{
   booleen dedans = FAUX;
   
        for(int i = rect.y; i<(rect.y+rect.h); i++)
        {
            for(int j = rect.x; j<(rect.x+rect.w); j++)
            {
                if(x  == j && y == i)
                {
                    /*printf("VRAI i = %d / j = %d\n",i, j);*/
                   dedans = VRAI;
                }
                
               
              
            }

           
        }

        return dedans;
        

}

/******************************************************************/
/*CREE DOSSIER DU DOM RECU
VALEUR DE RETOURE:
    -1 impossible ouvrirre ficDirProjets 
    -2 echec de la cmd MKDIR
    0 tout c'est bien derouler le nom du dossier n'est pas deja present
    1 le nom du dossier et deja present*/    
int creeProjet(char *nomProjet)
{

    if(!strcmp(nomProjet, ""))
    {
        return -7;
    }
    system("dir /B projets > .dirProjets.txt");
    printf("cmd system dir sur projets %s\n", nomProjet);

    char lesNoms[SIZE_NOM_PROJET] = " ";

    FILE * ficDirProjets = NULL;

    ficDirProjets = fopen(".dirProjets.txt", "r");

    if(!ficDirProjets)
    {
        printf("Erreure ouverure fic dir projets\n\n");
        return -1;
    }
 
    while(!feof(ficDirProjets))
    {
      
        fscanf(ficDirProjets, "%s\n", lesNoms);

        if(!strcmp(lesNoms, nomProjet))
        {
              
              fclose(ficDirProjets);
               return -2;
        }
       
       
       
              
    }

    
    



fclose(ficDirProjets);




char cmdMKDIR[_SIZE_T_] = "mkdir projets\\";

strcat(cmdMKDIR, nomProjet);

if(system(cmdMKDIR) <0)
{
    printf("ECHEC cmd MKDIR projets = %s\n", cmdMKDIR);
    return -3;
}

if(copyRessourceDansDossierProjet(nomProjet) == FAUX)
    return -4;

 

 /*if(lanceTerminal(nomProjet) == FAUX)
 return -5;*/

 if(lanceVsCode(nomProjet) == FAUX)
 return -6;

    return 0;
    
}
booleen copyRessourceDansDossierProjet(char *nomProjet)
{

    char cmdXcopy[_SIZE_T_] = "xcopy /E Ressource\\* projets\\";

    strcat(cmdXcopy, nomProjet);

    if(system(cmdXcopy) < 0)
    return FAUX;


    printf("Ressources copier avec la cmd > %s\n", cmdXcopy);

    return VRAI;

}


void creeMakefile(char * nomProjet){
    
        FILE * ficMakefile = NULL;
       char cheminFicMakefile[_SIZE_T_] ="projets\\";
       strcat(cheminFicMakefile, nomProjet);
       strcat(cheminFicMakefile, "\\Makefile" ); 
        ficMakefile = fopen(cheminFicMakefile, "w");
        if(ficMakefile == NULL)
        {
            printf("Erreure creation du Makefile ficMakefile =NULL\n");
            exit(EXIT_FAILURE);
        }
    
        char printMakefile[1000] = "CC = gcc\nEXEC = bin/";
        strcat(printMakefile, nomProjet);
        strcat(printMakefile, "\nSRC = $(wildcard src/*.c)\nOBJ = $(patsubst src/%.c,obj/%.o,$(SRC))\n\n#    Compilation\nall: $(EXEC)\n\n$(EXEC): $(OBJ)\n\t$(CC) -o $@ $^ -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf\n\nobj/%.o: src/%.c\n\t$(CC) -c $< -o $@ -I include -L lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf\n\nclean :\n\tfor %%f in (obj\\*.o)do del /F /Q \"%%f\"\n\ncleanall : clean\n\tdel /F /Q bin\\");
        strcat(printMakefile, nomProjet);
        strcat(printMakefile, ".exe");
    
    
        fprintf(ficMakefile, "%s",printMakefile);
    
        fclose(ficMakefile);
    
}

/*booleen lanceTerminal(char *nomProjet){
    
    char cmdCMD[_SIZE_T_] = "cmd /E cd projets\\";
    strcat(cmdCMD, nomProjet);
    

    if(system(cmdCMD) < 0)
    return FAUX;

   
    return VRAI;


}*/
booleen lanceVsCode(char *nomProjet){
    char cmdVScode[_SIZE_T_] = "code projets\\";
    strcat(cmdVScode, nomProjet);
    strcat(cmdVScode, " .");
    
    if(system(cmdVScode) <0)
    return FAUX;



    return VRAI;

}
