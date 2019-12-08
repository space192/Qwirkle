#include "prototypes.h"

int calculerCoup(T_TUILE plateau[][27], T_TUILE tuile[][6], int coordX, int coordY, int lockC, int lockF, T_MINIMAX *coup, int iteration, int joueurActif)
{
    int i,j,k=0,scoreCoup, x,y, scoreCoupParticulier[6][4], res0=1, success, tuile1, direction, MAXscore=0, nombreForme[6], nombreCouleur[6], nombreCTemp, nombreNTemp, MAX1, MAX2;
    for(i=0; i < 6 ; i++)
    {
        nombreNTemp = tuile[joueurActif][i].couleur;
        nombreCTemp = tuile[joueurActif][i].forme;
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
            success = test(coordX+x,coordY+y, tuile, plateau, joueurActif, i, &lockC, &lockF, &scoreCoup, &res0);
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
            coup[iteration].x = coordX+1;
            coup[iteration].y = coordY;
            break;
        case 1:
            coup[iteration].x= coordX-1;
            coup[iteration].y=coordY;
            break;
        case 2:
            coup[iteration].x=coordX;
            coup[iteration].y=coordY+1;
            break;
        case 3:
            coup[iteration].x=coordX;
            coup[iteration].y=coordY-1;
        }
        maximumCouleurForme(nombreForme, nombreCouleur, &MAX1, &MAX2);
        if(tuile1 == MAX1)
        {
            scoreCoupParticulier[tuile1][direction]++;
        }
        if(tuile1 == MAX2)
        {
            scoreCoupParticulier[tuile1][direction]++;
        }
        coup[iteration].tuile=tuile1;
        coup[iteration].score=scoreCoupParticulier[tuile1][direction];
    }
    else
    {
        coup[iteration].tuile=-1;
        coup[iteration].score=-1;
        coup[iteration].x=-1;
        coup[iteration].y=-1;
    }
}

void miniMax(T_COORD tuilePlace[], T_TUILE plateau[][27], T_TUILE tuile[][6], int lockC,int o, int lockF, T_MINIMAX coupAFaire[], int joueurActif)
{
    T_MINIMAX meilleur[36];
    T_COORD tuilePlaceImaginaire[36];
    int meilleurTruc=0, temp;
    int i,j,k=0,p=1, tempX, tempY, tempTuile, tempScore;
    T_TUILE plateauTest[13][27];
    T_TUILE mainTest[1][6];
    for(i=0; i < 36 ; i++)
    {
        meilleur[i].score = -1;
        meilleur[i].x = -1;
        meilleur[i].y = -1;
        meilleur[i].tuile = -1;
        tuilePlaceImaginaire[i].x = tuilePlace[i].x;
        tuilePlaceImaginaire[i].y = tuilePlace[i].y;
    }
    for(i=0; i < 13; i++)
    {
        for(j=0; j < 27; j++)
        {
            plateauTest[i][j].forme = plateau[i][j].forme;
            plateauTest[i][j].couleur = plateau[i][j].couleur;
        }
    }
    for(i=0; i < 6 ; i++)
    {
        mainTest[1][i].forme = tuile[joueurActif][i].forme;
        mainTest[1][i].couleur = tuile[joueurActif][i].couleur;
    }
    while(meilleurTruc!=-1)
    {
        for(i=0; i < 36 ; i++)
        {
            if(tuilePlaceImaginaire[i].x != 0 && tuilePlaceImaginaire[i].y != 0)
            {
                calculerCoup(plateauTest, mainTest, tuilePlaceImaginaire[i].x, tuilePlaceImaginaire[i].y, lockC, lockF, meilleur, i, joueurActif);
            }
        }
        meilleurTruc = meilleurCoup(meilleur);
        tempX = meilleur[meilleurTruc].x;
        tempY = meilleur[meilleurTruc].y;
        tempTuile = meilleur[meilleurTruc].tuile;
        tempScore = meilleur[meilleurTruc].score;
        tuilePlaceImaginaire[o+p].x = meilleur[meilleurTruc].x;
        tuilePlaceImaginaire[o+p].y = meilleur[meilleurTruc].y;
        coupAFaire[k].x = tempX;
        coupAFaire[k].y = tempY;
        coupAFaire[k].tuile = tempTuile;
        coupAFaire[k].score = tempScore;
        plateauTest[tempY][tempX].forme = mainTest[1][tempTuile].forme;
        plateauTest[tempY][tempX].couleur = mainTest[1][tempTuile].couleur;
        mainTest[1][tempTuile].forme = ' ';
        mainTest[1][tempTuile].couleur = 0;
        k++;
        p++;
        temp = meilleurTruc;
        for(i=0; i < 6 ; i++)
        {
            if(mainTest[1][i].forme == ' ' && mainTest[1][i].couleur == 0)
            {
                meilleurTruc = -1;
            }
            else
            {
                meilleurTruc = temp;
            }
        }
    }
}



int valeurmaximum(int scoreCoup[][4], int *tuile, int *position)
{
    int MAX1=0,i,j;
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

int maximumCouleurForme(int forme[], int couleur[], int *MAX1, int *MAX2)
{
    int i;
    for(i=0; i < 6; i++)
    {
        if(forme[i] > *MAX1)
        {
            *MAX1 = i;
        }
        if(couleur[i] > *MAX2)
        {
            *MAX2 = i;
        }
    }
}

int meilleurCoup(T_MINIMAX coup[])
{
    int i;
    int MAX=-1;
    for(i=0; i < 36 ; i++)
    {
        if(coup[i].score > MAX)
        {
            MAX = i;
        }
    }
    return MAX;
}
