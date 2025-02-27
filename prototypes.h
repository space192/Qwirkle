#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include "constantes.h"
#include <windows.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dirent.h>
void Color(int couleurDuTexte,int couleurDeFond);
void sauvegarderPartie(char *nomfichier,T_TUILE plateau[][27], int nombreJoueur, T_TUILE paquet[][6], T_JOUEUR *joueur, T_TUILE *pioche, int BS, int difficulte);
void recupererSauvegarde(FILE *fichier, T_TUILE plateau[][27], int nombreJoueur, T_TUILE paquet[][6], T_JOUEUR *joueur, T_TUILE *pioche, int BS, int difficulte);
void miniMax(T_COORD tuilePlace[], T_TUILE plateau[][27], T_TUILE tuile[][6], int lockC,int o, int lockF, T_MINIMAX coupAFaire[], int joueurActif);
void jeu(T_JOUEUR *joueur, int difficulte, int nombreJoueurs, int sauvegarde);
int meilleurCoup(T_MINIMAX coup[]);
int valeurmaximum(int scoreCoup[][4], int *tuile, int *position);
int calculerCoup(T_TUILE plateau[][27], T_TUILE tuile[][6], int coordX, int coordY, int lockC, int lockF, T_MINIMAX *coup, int iteration, int joueurActif);
int maximumCouleurForme(int forme[], int couleur[], int *MAX1, int *MAX2);
void menu();
void effacerEcran();
void afficherTuile( T_TUILE paquet[][6], int i, int k,T_TUILE plateau[][27],int x,int y);
void definirPiocheDegrade(T_TUILE *pioche);
void definirPiocheNormale(T_TUILE *pioche);
void retraitPioche(T_TUILE *pioche,T_TUILE paquet[][6], int *BS, int k);
int test(int x,int y,T_TUILE tuile[][6],T_TUILE plateau[][27],int joueurActif, int tuileJoueur,int *lockC, int *lockF, int *pscore, int *res0);
void deplacerCurseurSauvegarde(int *y, int *num,int k);
void selecteurSauvegarde(char *nomSauvegarde);
void affichageRegle();
void afficherScore();
void sauvegardeScore(T_JOUEUR joueur[], int nombrejoueur);
void gotoligcol(int lig, int col);
void deplacerCurseur(int *x, int *y, int *num);
void afficherTerrain(T_TUILE plateau[13][27]);
void afficherMainJoueur(T_TUILE paquet[][6], int k, int x, int y);
void afficherNom(T_JOUEUR *joueur, int j);
void Leaderbord(T_JOUEUR *joueur, int x, int y, int nombreJoueurs);
void initialiserMain(T_TUILE paquet[][6], int nombreJoueurs);
void remplacerTuile(T_TUILE paquet[][6],T_TUILE *pioche, int j, int *BS);
void remplirMain(T_TUILE paquet[][6],T_TUILE *pioche, int j, int *BS);
void afficherTitre();
void initialiserPlateau(T_TUILE plateau[][27]);
void nomSauvegarde(char *nomSauvegarde);
char formeMainJoueur(T_TUILE paquet[][6], int j, int l);
#endif // PROTOTYPES_H_INCLUDED
