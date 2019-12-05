#include "prototypes.h"

void jeuGraphique(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
   {
       printf("erreur lors de l'initialisation de la SDL");
       exit(0);
   }


   SDL_Window* salut = NULL;
   SDL_Rect* fenetreGenerale = NULL;
   SDL_Surface* image= NULL;
   salut = SDL_CreateWindow("coucou", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1837, 1065, SDL_WINDOW_SHOWN);
   SDL_SetWindowFullscreen(salut,SDL_WINDOW_FULLSCREEN_DESKTOP);
   fenetreGenerale = SDL_GetWindowSurface(salut);
   image= IMG_Load("Graphique/plateau9.png");
   SDL_BlitSurface(image, NULL, fenetreGenerale, NULL);
   SDL_UpdateWindowSurface(salut);
   system("pause");

    SDL_DestroyWindow(salut);
    SDL_Quit();
    return 0;
}
