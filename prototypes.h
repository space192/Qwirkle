#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include "constantes.h"
void menu();

void definirPiocheDegrade(T_TUILE *pioche);

void definirPiocheNormale(T_TUILE *pioche);

void retraitPiocheNormale(T_TUILE *pioche,T_TUILE *main);

void retraitPiocheDegrade(T_TUILE *pioche,T_TUILE *main);

void gotoligcol(int lig, int col);
void deplacerCurseur(int *x, int *y);
void afficherTerrain();

#endif // PROTOTYPES_H_INCLUDED
