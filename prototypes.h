#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include "constantes.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void jeu(T_JOUEUR *joueur);
void menu();

void definirPiocheDegrade(T_TUILE *pioche);

void definirPiocheNormale(T_TUILE *pioche);

void retraitPiocheNormale(T_TUILE *pioche,T_TUILE *main);

void retraitPiocheDegrade(T_TUILE *pioche,T_TUILE *main);

void gotoligcol(int lig, int col);
void deplacerCurseur(int *x, int *y);
void afficherTerrain();
void afficherMainJoueur(T_TUILE *main);
void Color(int couleurDuTexte,int couleurDeFond);
void afficherNom(T_JOUEUR joueur);
void Leaderbord(T_JOUEUR *joueur);
#endif // PROTOTYPES_H_INCLUDED
