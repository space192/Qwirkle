#include "prototypes.h"

int evaluer(T_TUILE plateau[13][27], T_TUILE main[][6], int coordX[6], int coordY[6])
{
    int i, j,score, x, y;
    for(i=0; i < 6 ; i++) //prototype de test : test(int x,int y,T_TUILE main[][6],T_TUILE plateau[][27],int joueurActif, int tuileJoueur, int *lockC, int *lockF, int *pscore);
    {
        switch(i)
        {
        case 0:
            x=1;
            y=0;
            break;
        case 1:
            x=-1;
            y=0;
            break;
        case 2:
            x=0;
            y=1;
            break;
        case 3:
            x=0;
            y=-1;
            break;
        }

        for(j=0; j < 6 ; j++)
        {

        }
    }

}

