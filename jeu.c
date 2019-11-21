#include "prototypes.h"

void jeu(T_JOUEUR *joueur, int difficulte, int nombreJoueurs)
{
    int sauvegarde, BS, i,k, partie = 1, joueurActif = 0, deplacement = 0, x = 1, y=1;
    T_TUILE *pioche = NULL;
    T_TUILE **main;
    do
    {
        printf("voulez vous reprendre une partie sauvegarde ?\n1:oui\n2:non\n");
        scanf("%d", &sauvegarde);
        fflush(stdin);
    }
    while(sauvegarde > 2 || sauvegarde < 1);
    if(sauvegarde == 1)
    {
    }
    else if(sauvegarde == 2)
    {
        main = malloc(nombreJoueurs * sizeof(T_TUILE *)); //main[][]
        for(i = 0 ; i < nombreJoueurs ; i++)
        {
           main[i] = malloc(6 * sizeof(T_TUILE*));
        }
        if(difficulte == 1) //difficulte 1 = degrade // diffuclte 2 = normal
        {
            BS = 36;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheDegrade(pioche);
            initialiserMain(main, nombreJoueurs);
            retraitPioche(pioche,main,&BS, nombreJoueurs);
        }
        else if(difficulte == 2)
        {
            BS = 108;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheNormale(pioche);
            initialiserMain(main, nombreJoueurs);
            retraitPioche(pioche,main,&BS, nombreJoueurs);
        }
    }
    gotoligcol(0,0);
    for(i = 0 ; i < 10000; i++)
    {

        printf(" ");
    }
    while(partie == 1)
    {
        system("cls");
        afficherTerrain();
        while(joueurActif != nombreJoueurs+1)
        {
            afficherMainJoueur(main, joueurActif);
            while(deplacement == 0)
            {
                deplacerCurseur(&x, &y, &deplacement);
            }
        }
    }
}
