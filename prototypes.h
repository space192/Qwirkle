#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include "constantes.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
void jeu(T_JOUEUR *joueur, int difficulte, int nombreJoueurs);
void menu();

void definirPiocheDegrade(T_TUILE *pioche);

void definirPiocheNormale(T_TUILE *pioche);

void retraitPiocheNormale(T_TUILE *pioche,T_TUILE main[][6], int *BS, int k);

void retraitPiocheDegrade(T_TUILE *pioche,T_TUILE main[][6], int *BS, int k);

void gotoligcol(int lig, int col);
void deplacerCurseur(int *x, int *y, int *num);
void afficherTerrain();
void afficherMainJoueur(T_TUILE main[][6], int k);
void Color(int couleurDuTexte,int couleurDeFond);
void afficherNom(T_JOUEUR joueur);
void Leaderbord(T_JOUEUR *joueur);
void initialiserMain(T_TUILE main[][6], int nombreJoueurs);
void remplacerTuile(T_TUILE main[][6],T_TUILE *pioche, int j, int *BS);
#endif // PROTOTYPES_H_INCLUDED
