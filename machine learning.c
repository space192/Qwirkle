#include "prototypes.h"

int evaluer(T_TUILE plateau[][27], T_TUILE main[][6], int coordX, int coordY)
{
    int i,k=8;
    int scoreIteration[6];
    int possibilite[6];
    int lockC=1, lockF=1;//prototype de test : test(int x,int y,T_TUILE main[][6],T_TUILE plateau[][27],int joueurActif, int tuileJoueur, int *lockC, int *lockF, int *pscore)
    for(i=0; i < 6 ; i++)//parcour des tuiles de la main du joueur
    {
        possibilite[i]=test(coordX, coordY, main, plateau, 0, i, &lockC, &lockF, &scoreIteration[i]);
    }
    for(i=0; i < 6; i++)
    {
        gotoligcol(k, 60);
        k++;
        printf("possibilite iteration %d et score iteration%d", possibilite[i], scoreIteration[i]);
        gotoligcol(coordX, coordY);
    }

}
