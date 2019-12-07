#ifndef PROTOTYPESG_H_INCLUDED
#define PROTOTYPESG_H_INCLUDED



#endif // PROTOTYPESG_H_INCLUDED
#include "prototypes.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
void jeuGraphique(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde);
SDL_Rect allocationCoordonees(SDL_Rect positionClic);
int coordonees();
SDL_Surface *attribuerImage(int carac,int couleur);
char retournervaleur(T_TUILE plateau[13][27],int i,int j);
int couleurMainJoueurGraphique(T_TUILE main[][6], int j, int l);
int caracMainJoueurGraphique(T_TUILE main[][6], int j, int l);
int allocationCoordoneesMain(SDL_Rect positionClic);
SDL_Rect allocationCoordoneesPlateau(SDL_Rect positionClic);
int allocationX(SDL_Rect positionClic);
int allocationy(SDL_Rect positionClic);
SDL_Surface *attribuerImageMain(int carac,int couleur);
void InitialisercouleurMainJoueurGraphique(T_TUILE main[][6], int j, int l);
void InitialisercaracMainJoueurGraphique(T_TUILE main[][6], int j, int l);
int recupererValeur(T_TUILE plateau[13][27], int y, int x);
int recupererCouleur(T_TUILE plateau[13][27], int y, int x);
int testGraphique(int x,int y,T_TUILE main[][6],T_TUILE plateau[][27],int joueurActif, int tuileJoueur,int *lockC, int *lockF, int *pscore, int *res0);



