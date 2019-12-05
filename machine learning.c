#include "prototypes.h"

int evaluer(T_TUILE plateau[13][27], T_TUILE main[][6], int coordX, int coordY)
{
    int i, j,k=8, x, y;
    int scoreIteration[6];
    int possibilite[6];
    int lockC=1, lockF=1;//prototype de test : test(int x,int y,T_TUILE main[][6],T_TUILE plateau[][27],int joueurActif, int tuileJoueur, int *lockC, int *lockF, int *pscore)
    int scoreCoup;
    for(i=0; i < 6 ; i++)//parcour des tuiles de la main du joueur
    {
            possibilite[i]=test(coordX+1, coordY, main, plateau, 1, i, &lockC, &lockF, &scoreIteration[i]);
    }
    for(i=0; i < 6; i++)
    {
        gotoligcol(k, 60);
        k++;
        printf("possibilite iteration %d et score iteration%d", possibilite[i], scoreIteration[i]);
        gotoligcol(x, y);
    }

}

