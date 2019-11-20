#include "prototypes.h"

void jeu(T_JOUEUR *joueur, int difficulte, int nombreJoueurs)
{
    int sauvegarde = 0, BS, i,j,k;
    T_TUILE *pioche = NULL;
    T_TUILE **main = NULL;
    do
    {
        printf("voulez vous reprendre une partie sauvegarde ?\n1:oui\n2:non\n");
        scanf("%d", &sauvegarde);
    }
    while(sauvegarde <= 2 && sauvegarde >= 1);
    if(sauvegarde == 1)
    {

    }
    else if(sauvegarde == 2)
    {
        main = malloc(nombreJoueurs * sizeof(T_TUILE)); //main[][]
        for(i = 0 ; i < nombreJoueurs ; i++)
        {
            main[i] = malloc(6 * sizeof(T_TUILE));
        }
        if(difficulte == 1) //difficulte 1 = degrade // diffuclte 2 = normal
        {
            BS = 36;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheDegrade(pioche);
            for(k=0;k<nombreJoueurs;k++)
            {
                retraitPiocheDegrade(pioche,main[k],&BS, &k);
            }
        }
        else if(difficulte == 2)
        {
            BS = 108;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheNormale(pioche);
            for(k=0;k<nombreJoueurs;k++)
            {
                retraitPiocheNormale(pioche,main[k],&BS, &k);
            }
        }
    for(i = 0;i < nombreJoueurs ; i++)
    {
        afficherMainJoueur(main[i], &i);
    }


    }
}
