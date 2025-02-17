OpenC_SDL2_V2

🎮 Description

OpenC_SDL2_V2 est un générateur de projets SDL2 permettant de créer automatiquement une structure propre et fonctionnelle pour les applications graphiques en C,
utilisant SDL2, SDL2_TTF et SDL2_image.

Ce programme facilite la mise en place d’un projet en générant l’arborescence complète des fichiers et dossiers nécessaires,
en incluant un Makefile et un code de base minimal permettant d’ouvrir une fenêtre SDL2.

🚀 Fonctionnalités

✔ Interface graphique pour entrer le nom du projet.
✔ Création automatique d’une arborescence optimisée :

    OpenSDL2/
    ├── projets/
    │   ├── [nom_du_projet]/
    │       ├── bin/       # Contient l'exécutable et les DLL SDL2
    │       ├── images/    # Contient 4 images par défaut
    │       ├── include/   # Contient les headers SDL2, SDL2_TTF et SDL2_image
    │       ├── lib/       # Contient les fichiers .a nécessaires pour la compilation
    │       ├── police/    # Contient 2 polices de caractères par défaut
    │       ├── src/       # Contient les fichiers main.c et fct.c
    │       ├── headers/   # Contient fct.h
    │       ├── Makefile   # Généré automatiquement pour faciliter la compilation

✔ Code prérempli avec les fonctions essentielles :

    -Initialisation de SDL2 avec création de fenêtre et rendu.
      
    -Gestion des erreurs SDL2 (quitWithError()).
      
    -Libération propre des ressources SDL2 (destroyResources()).
✔ Makefile intégré pour compiler facilement le projet.
✔ Ouverture automatique du projet dans VSCode après sa création.


📥 Téléchargement

Télécharge la dernière version de OpenC_SDL2_V2 ici :🔗 [Lien Google Drive](https://drive.google.com/file/d/1RpF-2GQvuJXWziB2b26X8CvhLq6mQRiT/view?usp=sharing)

🛠 Installation et Utilisation

1️⃣ Installation

    Aucune installation requise ! Il suffit de décompresser l’archive et de lancer launcher.bat

2️⃣ Utilisation

    Lance launcher.bat.
    
    Entre le nom du projet.
    
    Double Clique sur le bouton "Entrer".

Le projet est généré dans le dossier projets et s’ouvre automatiquement dans VSCode !

3️⃣ Compilation du projet généré

Une fois le projet généré, ouvre une Invite de commande et rends-toi dans le dossier du projet et utilise :
```sh
make all
```
Cela compilera le projet et créera un exécutable dans le dossier bin/.

## 📩 Contact
Si vous avez des suggestions ou des retours, contactez-moi sur **[GitHub Issues](https://github.com/yaya66659/BlocKeyboard/issues)** ou par mail : **yann66659@gmail.com**.  


## 📜 Licence

Ce projet est sous licence **GNU General Public License v3.0 (GPL v3)**.  
Vous êtes libre de l’utiliser, le modifier et le redistribuer sous les termes de cette licence.  

📌 **Résumé des conditions principales** :
- Vous **pouvez modifier** et redistribuer le programme.
- Toute version modifiée **doit rester sous GPL v3**.
- Ce programme est fourni **"tel quel", sans garantie**.  

🔗 Texte complet de la licence : [LICENSE](LICENSE)  
🔗 Plus d’informations : [https://www.gnu.org/licenses/gpl-3.0.html](https://www.gnu.org/licenses/gpl-3.0.html)  

✨ Auteur

Développé par Yann PICHAT.

