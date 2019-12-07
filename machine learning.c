#include "prototypes.h"

int calculerCoup(T_TUILE plateau[][27], T_TUILE tuile[][6], int coordX, int coordY, int lockC, int lockF, T_MINIMAX *faitChier, int iteration)
{
    int i,j,k=0,scoreCoup, x,y, scoreCoupParticulier[6][4], res0=1, success, tuile1, direction, MAXscore=0, nombreForme[6], nombreCouleur[6], nombreCTemp, nombreNTemp;
    for(i=0; i < 6 ; i++)
    {
        nombreNTemp = tuile[1][i].couleur;
        nombreCTemp = tuile[1][i].forme;
        switch(nombreNTemp)
        {
        case 1:
            nombreCouleur[0]++;
            break;
        case 2:
            nombreCouleur[1]++;
            break;
        case 3:
            nombreCouleur[2]++;
            break;
        case 4:
            nombreCouleur[3]++;
            break;
        case 5:
            nombreCouleur[4]++;
            break;
        case 6:
            nombreCouleur[5]++;
            break;
        }
        switch(nombreCTemp)
        {
        case 0xFE://carré
            nombreForme[0]++;
            break;
        case 0x04://loange
            nombreForme[1]++;
            break;
        case 0x05://trefle
            nombreForme[2]++;
            break;
        case 0x06://pique
            nombreForme[3]++;
            break;
        case 0x1E://triangle
            nombreForme[4]++;
            break;
        case 0x9E://croix
            nombreForme[5]++;
            break;
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
            success = test(coordX+x,coordY+y, tuile, plateau, 1, i, &lockC, &lockF, &scoreCoup, &res0);
            if((lockC == 0 || lockF == 0) && success)
            {
                scoreCoup++;
            }
            scoreCoupParticulier[i][j]=scoreCoup;
            printf("", scoreCoup);
        }
    }
    MAXscore = valeurmaximum(scoreCoupParticulier, &tuile1, &direction);
    if(MAXscore>0)
    {
        switch(direction)
        {
        case 0:
            faitChier[iteration].x = coordX+1;
            faitChier[iteration].y = coordY;
            break;
        case 1:
            faitChier[iteration].x= coordX-1;
            faitChier[iteration].y=coordY;
            break;
        case 2:
            faitChier[iteration].x=coordX;
            faitChier[iteration].y=coordY+1;
            break;
        case 3:
            faitChier[iteration].x=coordX;
            faitChier[iteration].y=coordY-1;
        }
        faitChier[iteration].tuile=(tuile1+1);
        faitChier[iteration].score=scoreCoupParticulier[tuile1][direction];
    }
    else
    {
        faitChier[iteration].tuile=-1;
        faitChier[iteration].score=-1;
        faitChier[iteration].x=-1;
        faitChier[iteration].y=-1;
    }
}

void miniMax(T_COORD tuilePlace[], T_TUILE plateau[][27], T_TUILE tuile[][6], int lockC, int lockF)
{
    T_MINIMAX meilleur[36];
    int i,m=10;
    for(i=0; i < 36 ; i++)
    {
        if(tuilePlace[i].x != 0 && tuilePlace[i].y != 0)
        {
            calculerCoup(plateau, tuile, tuilePlace[i].x, tuilePlace[i].y, lockC, lockF, meilleur, i);
            gotoligcol(m, 90);
            m++;
        }
    }
    m=10;
    for(i=0; i < 36 ; i++)
    {
        if(tuilePlace[i].x != 0 && tuilePlace[i].y != 0)
        {
            gotoligcol(m, 100);
            printf("                               ");
            gotoligcol(m, 100);
            printf("x:%d, y:%d, tuile :%d, score:%d", meilleur[i].x, meilleur[i].y, meilleur[i].tuile, meilleur[i].score);
            m++;
        }
    }
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
    if(MAX1 > 100)
    {
        return -1;
    }
    return MAX1;
}
