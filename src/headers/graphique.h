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
