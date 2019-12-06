#include "prototypes.h"

int calculerCoup(T_TUILE plateau[][27], T_TUILE tuile[][6], int coordX, int coordY, int lockC, int lockF, int iteration)
{
    int i,j,l=0,m=8, scoreCoup, x=0,y=0, tuile1 = 0, position = 0, MAX, success, res0 = 1, scoreCoupParticulier[6][4];
    //char carre = 0xFE, losange = 0x04, trefle = 0x05, pique =  0x06, triangle = 0x1E, croix = 0x9E;
    if(iteration < 6)
    {
        for(i=0; i < 6 ; i++)
        {
            if(tuile[1][i].forme != ' ' && tuile[1][i].couleur != 0)
            {
                x=0;
                y=0;
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
                    lockC=1;
                    lockF=1;
                    success = test(coordX+x,coordY+y, tuile, plateau, 1, i, &lockC, &lockF, &scoreCoup, &res0);
                    if((lockC==0 || lockF == 0) && success == 1)
                    {
                        scoreCoup++;
                    }
                    scoreCoupParticulier[i][j]=scoreCoup;
                    success = 0;
                }
            }
            for(i=0; i < 6; i++)
            {
                for(j=0; j < 4; j++)
                {
                    gotoligcol(m, 100);
                    printf("%d et %d", i+1, scoreCoupParticulier[i][j]);
                    m++;
                }
                m++;
            }
            MAX = valeurmaximum(scoreCoupParticulier, &tuile1, &position);
            gotoligcol(m, 90);
            printf("SCORE MAX : %d tuile :%d et direction : %d", MAX, tuile1, position);
            switch(position)
            {
            case 1:
                coordX = coordX+1;
                coordY = coordY;
                break;
            case 2:
                coordX = coordX-1;
                coordY = coordY;
            case 3:
                coordX = coordX;
                coordY = coordY+1;
                break;
            case 4:
                coordX = coordX;
                coordY = coordY-1;
            }
            calculerCoup(plateau, main,coordX,coordY,lockC, lockF, iteration+1);
        }
    }
    else
    {
        return 0;
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
                *tuile = i+1;
                *position = j+1;
            }
        }
    }
    return MAX1;
}


