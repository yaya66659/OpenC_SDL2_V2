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
