#include "prototypes.h"

void jeuGraphique(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("erreur lors de l'initialisation de la SDL");
        exit(0);
    }
    if(TTF_Init() == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
        exit(EXIT_FAILURE);
    }

    TTF_Font *police = NULL;

    SDL_Surface *texte = NULL;
    police = TTF_OpenFont("ELEPHNT.TTF", 40);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Color couleurBlanche = {240, 240, 240};
    SDL_Rect positionTexte;
    char phrase[25] = "";
    char phraseScore1[25] = "";
    char phraseScore2[25] = "";
    char phraseScore3[25] = "";
    char phraseScore4[25] = "";






    int continuer=1;
    int couleur;
    char carac;



    int BS, i,k,j,m=0, partie = 1, joueurActif = 0, deplacement = 8, x = 1, y=1, finTour = 0, l = 31, premierTour = 0, lockC = 1, lockF = 1, scoreJoueurActif =0;
    T_TUILE *pioche = NULL;
    T_TUILE **main;
    FILE *fichier;
    T_TUILE plateau[13][27];
    char nameSauvegarde[100] = "sauvegarde/";

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
            recupererSauvegarde(fichier , plateau, nombreJoueurs, main, joueur, pioche, BS, difficulte);
        }
        fclose(fichier);

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





    SDL_Window* salut = NULL;
    SDL_Surface *plateau1= NULL;

    T_TUILE tuile[36];
    T_TUILE tuileMain[6];

    SDL_Rect* positionPlateau = NULL;
    SDL_Rect positionTuile;
    SDL_Rect positionTuileMain;
    SDL_Rect positionCurseur;
    SDL_Rect positionCurseur2;
    SDL_Event clicSouris;
    SDL_Event clicSouris2;

    salut = SDL_CreateWindow("coucou", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1837, 1065, SDL_WINDOW_SHOWN);
    SDL_SetWindowFullscreen(salut,SDL_WINDOW_FULLSCREEN_DESKTOP);
    positionPlateau = SDL_GetWindowSurface(salut);
    plateau1= IMG_Load("Graphique/plateau9.png");
    //tuile = IMG_Load("Graphique/Ronds/RondViolet.png");
    SDL_BlitSurface(plateau1, NULL, positionPlateau, NULL);
    SDL_UpdateWindowSurface(salut);
    positionTuile.x=70;
    positionTuile.y=40;
    SDL_UpdateWindowSurface(salut);




    for(i=0;i<27;i++)
    {
        for(j=0;j<13;j++)
        {
            if(plateau[j][i].forme != ' ')
            {
               carac = plateau[j][i].forme;
               couleur = (plateau[j][i].couleur);
               SDL_Delay(100);
               tuile[m].surface = attribuerImage(carac,couleur);
               positionTuile.y = (40+ (j*69));
               positionTuile.x = (70+ (i*69));

               SDL_BlitSurface(tuile[m].surface, NULL, positionPlateau, &positionTuile);
               SDL_UpdateWindowSurface(salut);
               m++;

            }

        }

    }



     while(partie == 1)
    {
        while(joueurActif < nombreJoueurs)
        {
            sprintf(phrase, "C'est � %s de jouer ", joueur[joueurActif].nom);
            positionTexte.x=1320;
            positionTexte.y=906;
            texte = TTF_RenderText_Shaded(police, phrase, couleurBlanche, couleurNoire);
            SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
            SDL_UpdateWindowSurface(salut);
            positionTexte.x=90;
            positionTexte.y=920;
            police = TTF_OpenFont("ELEPHNT.TTF", 30);
            texte = TTF_RenderText_Shaded(police, "Appuyez ICI pour changer de tuile", couleurBlanche, couleurNoire);
            SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
            SDL_UpdateWindowSurface(salut);
            positionTexte.x=90;
            positionTexte.y=960;
            texte = TTF_RenderText_Shaded(police, "Appuyez ICI pour passez votre tour", couleurBlanche, couleurNoire);
            SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
            SDL_UpdateWindowSurface(salut);

            while(finTour == 0)
            {
                afficherMainJoueur(main, joueurActif, x, y);
                m=0;

                for(i=0;i<6;i++)
                {
                    couleur = couleurMainJoueurGraphique(main,joueurActif,i);
                    carac = caracMainJoueurGraphique(main,joueurActif,i);

                    tuileMain[i].surface = attribuerImage(carac,couleur);
                    positionTuileMain.y = (992);
                    positionTuileMain.x = (1382+i*69);

                    SDL_BlitSurface(tuileMain[i].surface, NULL, positionPlateau, &positionTuileMain);
                    SDL_UpdateWindowSurface(salut);
                }




                Leaderbord(joueur, x, y, nombreJoueurs);
                if(2==nombreJoueurs)
                {
                    sprintf(phraseScore1, "Score joueur1 = %d ", joueur[0].score);
                    positionTexte.x=(850);
                    positionTexte.y=(906);
                    texte = TTF_RenderText_Shaded(police, phraseScore1, couleurBlanche, couleurNoire);
                    SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
                    SDL_UpdateWindowSurface(salut);
                    sprintf(phraseScore2, "Score joueur2 = %d ", joueur[1].score);
                    positionTexte.x=(850);
                    positionTexte.y=(943);
                    texte = TTF_RenderText_Shaded(police, phraseScore2, couleurBlanche, couleurNoire);
                    SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
                    SDL_UpdateWindowSurface(salut);
                }

                while(continuer == 1)
                {
                    SDL_WaitEvent(&clicSouris);
                    switch(clicSouris.type)
                    {
                    case SDL_MOUSEBUTTONDOWN:
                    positionCurseur.x = clicSouris.button.x;
                    positionCurseur.y = clicSouris.button.y;
                    deplacement = allocationCoordoneesMain(positionCurseur);
                    continuer = 0;
                    }
                    if(deplacement==8)
                    {
                        continuer = 1;
                    }
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
                    SDL_WaitEvent(&clicSouris2);
                    switch(clicSouris2.type)
                    {
                    case SDL_MOUSEBUTTONDOWN:
                    positionCurseur2.x = clicSouris.button.x;
                    positionCurseur2.y = clicSouris.button.y;
                    positionCurseur2 = allocationCoordoneesPlateau(positionCurseur2);
                    continuer = 0;
                    }

                   if(test((x-1)/2, (y-1)/2, main, plateau, joueurActif, deplacement, &lockC, &lockF, &scoreJoueurActif) == 1 || premierTour == 0)
                   {
                        couleur = couleurMainJoueurGraphique(main,joueurActif,deplacement);
                        carac = caracMainJoueurGraphique(main,joueurActif,deplacement);

                        tuileMain[deplacement].surface = attribuerImage(carac,couleur);
                        positionTuileMain.y = positionCurseur2.y;
                        positionTuileMain.x = positionCurseur2.x;

                        SDL_BlitSurface(tuileMain[deplacement].surface, NULL, positionPlateau, &positionTuileMain);
                        SDL_UpdateWindowSurface(salut);

                        //afficherTuile(main, joueurActif, deplacement, plateau, x, y);
                        joueur[joueurActif].score = scoreJoueurActif + joueur[joueurActif].score;
                        premierTour = 1;

                       //evaluer(plateau, main, (x-1)/2, (y-1)/2);
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
        effacerChoix();
        joueurActif = 0;
        gotoligcol(1, 1);
        l=31;
    }





    /*while(continuer == 1)
     {
         SDL_WaitEvent(&clicSouris);
         switch(clicSouris.type)
         {
             case SDL_MOUSEBUTTONDOWN:
                 positionTuile.x = clicSouris.button.x;
                 positionTuile.y = clicSouris.button.y;
                 positionTuile = allocationCoordonees(positionTuile);
                 continuer = 0;
         }
     if(positionTuile.y < 700 && positionTuile.y > 81 && positionTuile.x > 30 && positionTuile.x < 700)
     {
         SDL_BlitSurface(tuile, NULL, positionPlateau, &positionTuile);
         SDL_UpdateWindowSurface(salut);
         continuer = 1;
     }
     else
     {
         continuer = 1;
     }
     }*/


    SDL_DestroyWindow(salut);
    SDL_Quit();
    TTF_CloseFont(police);
    TTF_Quit();
    TTF_Quit();
    return 0;
}
