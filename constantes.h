#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED
#include <SDL2/SDL.h>

typedef struct JOUEUR
{
    char nom[50];
    int score;
}T_JOUEUR;

typedef struct TUILE
{
    char forme;
    int couleur;
    SDL_Surface *surface;
}T_TUILE;

typedef struct MINIMAX
{
    int x;
    int y;
    int score;
    int tuile;
}T_MINIMAX;

typedef struct Coordones
{
    int x;
    int y;
}T_COORD;



#endif // CONSTANTES_H_INCLUDED
