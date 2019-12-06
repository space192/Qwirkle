#include "prototypes.h"

int calculerCoup(T_TUILE plateau[][27], T_TUILE tuile[][6], int coordX, int coordY, int lockC, int lockF)
{
    int i,j,k=0,m=8, scoreCoup, x,y, scoreCoupParticulier[24];
    int compteurCouleur[6], compteurForme[6];
    char carre = 0xFE, losange = 0x04, trefle = 0x05, pique =  0x06, triangle = 0x1E, croix = 0x9E;
    for(i=0; i < 6; i++)
    {
        switch(tuile[1][i].couleur)
        {
        case 1:
            compteurCouleur[0]++;
            break;
        case 2:
            compteurCouleur[1]++;
            break;
        case 3:
            compteurCouleur[2]++;
            break;
        case 4:
            compteurCouleur[3]++;
            break;
        case 5:
            compteurCouleur[4]++;
        case 6:
            compteurCouleur[5]++;
        }
        if(tuile[1][i].forme == carre)
        {
            compteurForme[0]++;
        }
        else if(tuile[1][i].forme == losange)
        {
            compteurForme[1]++;
        }
        else if(tuile[1][i].forme == trefle)
        {
            compteurForme[2]++;
        }
        else if(tuile[1][i].forme == pique)
        {
            compteurForme[3]++;
        }
        else if(tuile[1][i].forme == triangle)
        {
            compteurForme[4]++;
        }
        else if(tuile[1][i].forme == croix)
        {
            compteurForme[5]++;
        }
    }
    for(i=0; i < 6 ; i++)
    {
        x=0;
        y=0;
        lockC=1;
        lockF=1;
        for(j=0; j < 4 ; j++)
        {
            switch(j)
            {
            case 0:
                x= 1;
                y= 0;
                break;
            case 1:
                x= -1;
                y= 0;
                break;
            case 2:
                x= 0;
                y= 1;
                break;
            case 3:
                x= 0;
                y= -1;
            }
            test(coordX+x,coordY+y, tuile, plateau, 1, i, &lockC, &lockF, &scoreCoup);
            if(lockC == 0 || lockF == 0)
            {
                scoreCoup++;
            }
            scoreCoupParticulier[k]=scoreCoup;
            k++;
        }
    }
    for(i=0; i < 24;i++)
    {
    gotoligcol(m, 100);
    printf("%d et %d", i+1, scoreCoupParticulier[i]);
    m++;
    }
}
