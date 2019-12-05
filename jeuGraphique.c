#include "prototypes.h"
#include "prototypesG.h"

void jeuGraphique(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("erreur lors de l'initialisation de la SDL");
        exit(0);
    }
    int continuer =1;


    SDL_Window* salut = NULL;
    SDL_Surface *plateau= NULL, *tuile = NULL;
    SDL_Rect* positionPlateau = NULL;
    SDL_Rect positionTuile;
    SDL_Event clicSouris;
    salut = SDL_CreateWindow("coucou", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1837, 1065, SDL_WINDOW_SHOWN);
    //SDL_SetWindowFullscreen(salut,SDL_WINDOW_FULLSCREEN_DESKTOP);
    positionPlateau = SDL_GetWindowSurface(salut);
    plateau= IMG_Load("Graphique/plateau9.png");
    //tuile = IMG_Load("Graphique/Ronds/RondViolet.png");
    SDL_BlitSurface(plateau, NULL, positionPlateau, NULL);
    SDL_UpdateWindowSurface(salut);
    positionTuile.x=70;
    positionTuile.y=40;
    tuile = attribuerImage(0xFE,4);
    SDL_BlitSurface(tuile, NULL, positionPlateau, &positionTuile);
    SDL_UpdateWindowSurface(salut);

    /*while(continuer == 1)
     {
         SDL_WaitEvent(&clicSouris);
         switch(clicSouris.type)
         {
             case SDL_MOUSEBUTTONDOWN:
                 positionTuile.x = clicSouris.button.x;
                 positionTuile.y = clicSouris.button.y;
                 positionTuile = allocationCoordonees(positionTuile);
                 continuer = 0;
         }
     if(positionTuile.y < 700 && positionTuile.y > 81 && positionTuile.x > 30 && positionTuile.x < 700)
     {
         SDL_BlitSurface(tuile, NULL, positionPlateau, &positionTuile);
         SDL_UpdateWindowSurface(salut);
         continuer = 1;
     }
     else
     {
         continuer = 1;
     }
     }*/

    system("pause");

    SDL_DestroyWindow(salut);
    SDL_Quit();
    return 0;
}
