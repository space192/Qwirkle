#include "prototypes.h"

void jeu(T_JOUEUR *joueur, int difficulte, int nombreJoueurs)
{
    int sauvegarde = 0, BS;
    T_TUILE *pioche = NULL;
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
        if(difficulte == 1) //difficulte 1 = degrade // diffuclte 2 = normal
        {
            BS = 36;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheDegrade(pioche);
        }
        else if(difficulte == 2)
        {
            BS = 108;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheNormale(pioche);
        }
    }

}
