#include "prototypes.h"

void jeu(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde)
{
    int BS, i,j,k, m=0, n=8,partie = 1, joueurActif = 0, deplacement = 8, x = 1, y=1, finTour = 0, l = 31, premierTour = 0, lockC = 1, lockF = 1, scoreJoueurActif =0, res0=1, IAjoue=1, tuileAplacer, conditionArret=0;
    int positionX, positionY;
    char couleurTemp=0;
    T_TUILE *pioche = NULL;
    T_TUILE **main;
    T_MINIMAX coupIA[6];
    FILE *fichier;
    T_COORD tuilePLace[36];
    T_TUILE plateau[13][27];
    char nameSauvegarde[100] = "sauvegarde/";
    system("cls");
    for(i=0; i < 6 ; i++)
    {
        coupIA[i].x=-1;
        coupIA[i].y=-1;
        coupIA[i].tuile=-1;
        coupIA[i].score=-1;
    }
    if(sauvegarde == 1)
    {
        selecteurSauvegarde(nameSauvegarde);
        fichier = fopen(nameSauvegarde, "r+");
        if(fichier == NULL)
        {
            printf("erreur dans l'ouverture du fichier");
        }
        else
        {
            fscanf(fichier, "%d\n%d\n%d\n", &BS, &nombreJoueurs, &difficulte);
            main = malloc(nombreJoueurs * sizeof(T_TUILE*));
            for(i = 0 ; i < nombreJoueurs ; i++)
            {
                main[i] = malloc(6 * sizeof(T_TUILE));
            }
            pioche = malloc(BS * sizeof(T_TUILE));
            joueur = malloc(nombreJoueurs * sizeof(T_JOUEUR));
            recupererSauvegarde(fichier, plateau, nombreJoueurs, main, joueur, pioche, BS, difficulte);
        }
        fclose(fichier);
        premierTour = 1;

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
        for(i=0; i < nombreJoueurs; i++)
        {
            joueur[i].score = 0;
        }
    }
    for(i=0; i < 36 ; i++)
    {
        tuilePLace[i].x = 0;
        tuilePLace[i].y = 0;
    }
    system("cls");
    afficherTerrain(plateau);
    while(partie == 1)
    {
        while(joueurActif < nombreJoueurs)
        {
            afficherNom(joueur, joueurActif);
            while(finTour == 0)
            {
                n=8;
                if(joueur[joueurActif].IA == 2)
                {
                    i=0;
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

                        if(test((x-1)/2, (y-1)/2, main, plateau, joueurActif, deplacement, &lockC, &lockF, &scoreJoueurActif, &res0) == 1 || premierTour == 0)
                        {
                            if(premierTour==0)
                            {
                                joueur[joueurActif].score +=2;
                            }
                            afficherTuile(main, joueurActif, deplacement, plateau, x, y);
                            joueur[joueurActif].score = scoreJoueurActif + joueur[joueurActif].score;
                            premierTour = 1;
                            tuilePLace[m].x = (x-1)/2;
                            tuilePLace[m].y = (y-1)/2;
                            m++;
                        }
                        res0 = 1;
                        deplacement = 8;
                    }
                }
                else if(joueur[joueurActif].IA == 1)
                {
                    Leaderbord(joueur, x, y, nombreJoueurs);
                    if(premierTour == 0)
                    {
                        tuileAplacer = rand()%5;
                        positionX = rand()%(15-11+1)+11;
                        positionY = rand()%(8-4+1)+4;
                        gotoligcol(positionY*2+1, positionX*2+1);
                        afficherTuile(main, joueurActif, tuileAplacer, plateau, positionX*2+1, positionY*2+1);
                        tuilePLace[m].x=positionX;
                        tuilePLace[m].y=positionY;
                        premierTour=1;
                        m++;
                    }
                    if(IAjoue==0 && premierTour==1)
                    {
                        finTour=1;
                        deplacement=8;
                        premierTour=1;
                        IAjoue=1;
                    }
                    else if(IAjoue==1 && premierTour==1)
                    {
                        if(BS > 0)
                        {
                            for(i=0; i < 6 ; i++)
                            {
                                miniMax(tuilePLace, plateau, main, lockC,m, lockF, coupIA, joueurActif);
                                if(coupIA[i].score != -1)
                                {
                                    gotoligcol((coupIA[i].y*2)+1, (coupIA[i].x*2)+1);
                                    if(test(coupIA[i].x, coupIA[i].y, main, plateau, joueurActif, coupIA[i].tuile, &lockC, &lockF, &scoreJoueurActif, &res0)==1)
                                    {
                                        joueur[joueurActif].score = scoreJoueurActif + joueur[joueurActif].score;
                                        afficherTuile(main, joueurActif, coupIA[i].tuile, plateau, (coupIA[i].x)*2+1, (coupIA[i].y)*2+1);
                                        deplacement=8;
                                        tuilePLace[m].x = coupIA[i].x;
                                        tuilePLace[m].y = coupIA[i].y;
                                        m++;
                                    }
                                }
                            }
                        }
                        else
                        {
                            finTour = 1;
                            nombreJoueurs = 4;
                            partie=1;
                        }
                        premierTour=1;
                        IAjoue=0;
                    }
                }
            }
            x = 1;
            y = 1;
            if(BS > 0)
            {
                remplirMain(main,pioche,joueurActif,&BS);
            }
            finTour = 0;

            conditionArret = 0;
            i=0;
            if(BS==0)
            {
               {
                   couleurTemp = couleurMainJoueur(main, joueurActif, i);
                   if(couleurTemp== 0)
                   {
                       conditionArret++;
                   }
               }
            }
            if(conditionArret==6)
            {
                effacerEcran();
                printf("Fin de partie!");
                finTour = 1;
                joueurActif = 5;
                partie = 0;

            }
            joueurActif++;

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
        effacerChoix();
        joueurActif = 0;
        gotoligcol(1, 1);
        l=31;
    }
    if(partie == 2)
    {
        effacerEcran();
        nomSauvegarde(nameSauvegarde);
        sauvegarderPartie(nameSauvegarde, plateau, nombreJoueurs, main, joueur, pioche, BS, difficulte);
        sauvegardeScore(joueur, nombreJoueurs);
    }
    else if(partie == 3)
    {
        sauvegardeScore(joueur, nombreJoueurs);
    }
    for(i=0 ; i < 6 ; i++)
    {
        free(main[i]);
    }
    free(main);
    free(pioche);
    free(plateau);
    free(joueur);
}
