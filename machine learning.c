#include "prototypes.h"

int calculerCoup(T_TUILE plateau[][27], T_TUILE tuile[][6], int coordX, int coordY, int lockC, int lockF, T_MINIMAX *faitChier)
{
    int i,j,k=0,m=8, scoreCoup, x,y, scoreCoupParticulier[6][4], res0=1, success, tuile1, direction;
    int MAXx, MAXy, MAXscore=-1;
    int compteurCouleur[6], compteurForme[6];
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
            success = test(coordX+x,coordY+y, tuile, plateau, 1, i, &lockC, &lockF, &scoreCoup, &res0);
            if((lockC == 0 || lockF == 0) && success)
            {
                scoreCoup++;
            }
            scoreCoupParticulier[i][j]=scoreCoup;
            printf("", scoreCoup);
        }
    }
    valeurmaximum(scoreCoupParticulier, &tuile1, &direction);
    switch(direction)
    {
    case 0:
        faitChier->x = coordX+1;
        faitChier->y = coordY;
        break;
    case 1:
        faitChier->x= coordX-1;
        faitChier->y=coordY;
        break;
    case 2:
        faitChier->x=coordX;
        faitChier->y=coordY+1;
        break;
    case 3:
        faitChier->x=coordX;
        faitChier->y=coordY-1;
    }
    faitChier->tuile=tuile1;
    faitChier->score=scoreCoupParticulier[tuile1][direction];
    m++;
    gotoligcol(m, 100);
    printf("x:%d, y:%d, tuile:%d, score:%d", faitChier->x, faitChier->y, faitChier->tuile, faitChier->score);
}

int valeurmaximum(int scoreCoup[][4], int *tuile, int *position)
{
    int MAX1=0,MAX2=0,i,j;
    for(i=0; i < 6; i++)
    {
        for(j = 0; j < 4; j++)
        {
            if(scoreCoup[i][j] > MAX1)
            {
                MAX1 = scoreCoup[i][j];
                *tuile = i;
                *position = j;
            }
        }
    }
    return MAX1;
}
