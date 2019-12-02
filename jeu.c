#include "prototypes.h"

void jeu(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde)
{
    int BS, i,k, partie = 1, joueurActif = 0, deplacement = 8, x = 1, y=1, finTour = 0, l = 31, premierTour = 0, lockC = 1, lockF = 1, scoreJoueurActif =0;
    T_TUILE *pioche = NULL;
    T_TUILE **main;
    T_TUILE plateau[13][27];
    char fichierSauvegarde[100], nameSauvegarde[100] = "sauvegarde/";
    for(i=0;i < nombreJoueurs;i++)
    {
        joueur[i].score = 0;
    }
    system("cls");
    if(sauvegarde == 1)
    {
        selecteurSauvegarde(fichierSauvegarde);
        system("cls");
    }
    else if(sauvegarde == 2)
    {
        main = malloc(nombreJoueurs * sizeof(T_TUILE*)); //main[][]
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
        initialiserPlateau(plateau);
    }
    while(partie == 1)
    {
        system("cls");
        afficherTerrain(plateau);

        while(joueurActif < nombreJoueurs)
        {
            afficherNom(joueur, joueurActif);
            while(finTour == 0)
            {
                afficherMainJoueur(main, joueurActif, x, y);
                Leaderbord(joueur, x, y, nombreJoueurs);
                while(deplacement == 8)
                {
                    deplacerCurseur(&x, &y, &deplacement);
                }
                if(deplacement == 7)
                {
                    finTour = 1;
                    deplacement = 8;
                }
                if(deplacement == 6)
                {
                    remplacerTuile(main, pioche, joueurActif, &BS);
                    deplacement = 8;
                    finTour = 1;
                }
                else if(deplacement < 6)
                {
                   if(test((x-1)/2, (y-1)/2, main, plateau, joueurActif, deplacement, &lockC, &lockF, &scoreJoueurActif) == 1 || premierTour == 0)
                   {
                       afficherTuile(main, joueurActif, deplacement, plateau, x, y);
                       joueur[joueurActif].score = scoreJoueurActif + joueur[joueurActif].score;
                       premierTour = 1;
                   }
                   deplacement = 8;
                }
            }
            x = 1;
            y = 1;
            remplirMain(main,pioche,joueurActif,&BS);
            joueurActif++;
            finTour = 0;
        }
        gotoligcol(l,6);
        printf("voulez-vous continuer la partie ?");
        l++;
        gotoligcol(l,6);
        printf("1:Continuer");
        l++;
        gotoligcol(l,6);
        printf("2:Sauvegarder et Quitter");
        l++;
        gotoligcol(l,6);
        printf("3:Quitter sans sauvegarder");
        l++;
        gotoligcol(l,6);
        do
        {
            fflush(stdin);
            scanf("%d", &partie);
            gotoligcol(l++, 6);
        }
        while(partie < 1 || partie > 3);
        effacerEcran();
        joueurActif = 0;
        gotoligcol(1, 1);
        l=31;
    }
    if(partie == 2)
    {
        effacerEcran();
        nomSauvegarde(nameSauvegarde);
        sauvegarderPartie(plateau, nameSauvegarde, nombreJoueurs,main,joueur,pioche,BS, difficulte);
    }
    else if(partie == 3)
    {
        //sauvegarde des scores
    }
}
