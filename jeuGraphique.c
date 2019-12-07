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
    int continuer2=0;
    int couleur;
    char carac;
    int res0 = 1;


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
            recupererSauvegarde(fichier, plateau, nombreJoueurs, main, joueur, pioche, BS, difficulte);
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
    SDL_Surface* selection = NULL;

    SDL_Rect* positionPlateau = NULL;
    SDL_Rect positionTuile;
    SDL_Rect positionTuileMain;
    SDL_Rect positionCurseur;
    SDL_Rect positionCurseur2;
    SDL_Event clicSouris;
    SDL_Event clicSouris2;

    salut = SDL_CreateWindow("coucou", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1837, 1065, SDL_WINDOW_SHOWN);
    //SDL_SetWindowFullscreen(salut,SDL_WINDOW_FULLSCREEN_DESKTOP);
    positionPlateau = SDL_GetWindowSurface(salut);
    plateau1= IMG_Load("Graphique/plateau9.png");
    //tuile = IMG_Load("Graphique/Ronds/RondViolet.png");
    SDL_BlitSurface(plateau1, NULL, positionPlateau, NULL);
    SDL_UpdateWindowSurface(salut);
    positionTuile.x=70;
    positionTuile.y=40;
    SDL_UpdateWindowSurface(salut);




    for(j=0; j<13; j++)
    {
        for(i=0; i<27; i++)
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
            police = TTF_OpenFont("ELEPHNT.TTF", 40);
            sprintf(phrase, "C'est à %s de jouer ", joueur[joueurActif].nom);
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
                continuer = 1;
                continuer2=0;
                for(i=0; i<6; i++)
                {
                    couleur = couleurMainJoueurGraphique(main,joueurActif,i);
                    carac = caracMainJoueurGraphique(main,joueurActif,i);

                    tuileMain[i].surface = attribuerImageMain(carac,couleur);
                    positionTuileMain.y = (992);
                    positionTuileMain.x = (1382+i*69);

                    SDL_BlitSurface(tuileMain[i].surface, NULL, positionPlateau, &positionTuileMain);
                    SDL_UpdateWindowSurface(salut);
                }



                if(nombreJoueurs==2)
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
                        selection = IMG_Load("Graphique/Dégradé.png");
                        SDL_BlitSurface(selection, NULL, positionPlateau, &positionCurseur);

                        continuer = 0;
                        continuer2=1;
                    break;
                    }
                }


                if(deplacement == 7)
                {
                    finTour = 1;
                    deplacement = 8;
                    continuer = 1;
                    continuer2=0;
                }
                if(deplacement == 6)
                {
                    remplacerTuile(main, pioche, joueurActif, &BS);
                    deplacement = 8;
                    finTour = 1;
                    continuer = 1;
                    continuer2=0;
                }
                else if(deplacement < 6)
                {
                    while(continuer2 == 1)
                    {
                        SDL_WaitEvent(&clicSouris2);
                        switch(clicSouris2.type)
                        {
                        case SDL_MOUSEBUTTONDOWN:
                            positionCurseur2.x = clicSouris2.button.x;
                            positionCurseur2.y = clicSouris2.button.y;
                            positionCurseur2 = allocationCoordoneesPlateau(positionCurseur2);
                            //printf("%d\n",positionCurseur2.x);
                            //printf("%d\n",positionCurseur2.y);

                            y = ((positionCurseur2.x - 70)/69);
                            x = ((positionCurseur2.y - 40)/69);
                            printf("%d\n",x);
                            printf("%d\n",y);
                            if(test(x,y, main, plateau, joueurActif, deplacement, &lockC, &lockF, &scoreJoueurActif, &res0) == 1 || premierTour == 0)
                            {
                            continuer2 = 0;
                            continuer=1;
                            printf("Premier test passé\n");
                            }
                            else
                            {
                                res0=1;
                            }


                        }
                    }

                    if(test(x,y, main, plateau, joueurActif, deplacement, &lockC, &lockF, &scoreJoueurActif, &res0) == 1 || premierTour == 0)
                    {
                        //couleur = couleurMainJoueurGraphique(main,joueurActif,deplacement);
                        //carac = caracMainJoueurGraphique(main,joueurActif,deplacement);

                        //tuileMain[a].surface = attribuerImage(carac,couleur);
                        positionTuileMain.y = positionCurseur2.y;
                        positionTuileMain.x = positionCurseur2.x;

                        SDL_BlitSurface(tuileMain[deplacement].surface, NULL, positionPlateau, &positionTuileMain);
                        SDL_UpdateWindowSurface(salut);

                            //afficherTuile(main, joueurActif, deplacement, plateau, x, y);
                        joueur[joueurActif].score = scoreJoueurActif + joueur[joueurActif].score;
                        premierTour = 1;


                        plateau[y][x].forme=caracMainJoueurGraphique(main,joueurActif,deplacement);
                        plateau[y][x].couleur=couleurMainJoueurGraphique(main,joueurActif,deplacement);
                        InitialisercouleurMainJoueurGraphique(main,joueurActif,deplacement);
                        InitialisercaracMainJoueurGraphique(main,joueurActif,deplacement);

                        x=0;
                        y=0;
                        printf("J'ai posé\n");
                        printf("%d\n", continuer);
                        printf("%d\n", continuer2);

                            //evaluer(plateau, main, (x-1)/2, (y-1)/2);
                    }
                    positionCurseur2.x = 0;
                    positionCurseur2.y = 0;
                    positionCurseur.x = 0;
                    positionCurseur.y = 0;
                    positionTuile.x = 0;
                    positionTuile.y = 0;

                    res0 = 1;
                    deplacement = 8;
                }

            }
            remplirMain(main,pioche,joueurActif,&BS);
            joueurActif++;
            finTour = 0;
        }
        joueurActif = 0;
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
