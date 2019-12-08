#include "prototypesG.h"

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
    SDL_Surface *texteTemp = NULL;
    police = TTF_OpenFont("ELEPHNT.TTF", 40);
    SDL_Color couleurNoire = {0, 0, 0};
    SDL_Color couleurBlanche = {240, 240, 240};
    SDL_Rect positionTexte;
    SDL_Rect positionTexteTemp;
    char phrase[50] = "";
    char phraseScore1[25] = "";
    char phraseScore2[25] = "";
    char phraseScore3[25] = "";
    int continuer=1;
    int continuer2=0;
    int continuer3 =1;
    int couleur;
    char carac;
    int res0 = 1;
    int choix=0;
    int BS, i,j,m=0, partie = 1, joueurActif = 0, deplacement = 8, x = 1, y=1, finTour = 0, premierTour = 0, lockC = 1, lockF = 1, scoreJoueurActif =0;
    T_TUILE *pioche = NULL;
    T_TUILE **paquet;
    FILE *fichier;
    T_TUILE plateau2[13][27];
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
            paquet = malloc(nombreJoueurs * sizeof(T_TUILE*));
            for(i = 0 ; i < nombreJoueurs ; i++)
            {
                paquet[i] = malloc(6 * sizeof(T_TUILE));
            }
            pioche = malloc(BS * sizeof(T_TUILE));
            joueur = malloc(nombreJoueurs * sizeof(T_JOUEUR));
            recupererSauvegarde(fichier, plateau2, nombreJoueurs, paquet, joueur, pioche, BS, difficulte);
        }
        fclose(fichier);
    }
    else if(sauvegarde == 2)
    {
        paquet = malloc(nombreJoueurs * sizeof(T_TUILE*)); //paquet[][]
        for(i = 0 ; i < nombreJoueurs ; i++)
        {
            paquet[i] = malloc(6 * sizeof(T_TUILE*));
        }
        if(difficulte == 1) //difficulte 1 = degrade // diffuclte 2 = normal
        {
            BS = 36;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheDegrade(pioche);
            initialiserMain(paquet, nombreJoueurs);
            retraitPioche(pioche,paquet,&BS, nombreJoueurs);
        }
        else if(difficulte == 2)
        {
            BS = 108;
            pioche = malloc(BS * sizeof(T_TUILE));
            definirPiocheNormale(pioche);
            initialiserMain(paquet, nombreJoueurs);
            retraitPioche(pioche,paquet,&BS, nombreJoueurs);
        }
        initialiserPlateau(plateau2);
        for(i=0; i < nombreJoueurs; i++)
        {
            joueur[i].score = 0;
        }
    }
    for(i=0; i < 13 ; i++)
    {
        for(j=0; j < 27; j++)
        {
            plateau[i][j].forme = recupererValeur(plateau2, i, j);
            plateau[i][j].couleur= recupererCouleur(plateau2, i, j);
        }
    }
    i=0;
    j=0;
    SDL_Window* salut = NULL;
    SDL_Surface *plateau1= NULL;
    T_TUILE tuile[36];
    T_TUILE tuileMain[6];
    T_TUILE selection;
    T_TUILE bouton;
    SDL_Rect* positionPlateau = NULL;
    SDL_Rect positionTuile;
    SDL_Rect positionTuileMain;
    SDL_Rect positionCurseur;
    SDL_Rect positionCurseur2;
    SDL_Rect positionCurseur3;
    SDL_Rect positionBouton;
    SDL_Event clicSouris;
    SDL_Event clicSouris2;
    SDL_Event clicSouris3;
    SDL_Rect positionMenu;
    SDL_Surface *menuPause = NULL;
    salut = SDL_CreateWindow("coucou", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1837, 1065, SDL_WINDOW_SHOWN);
    SDL_SetWindowFullscreen(salut,SDL_WINDOW_FULLSCREEN_DESKTOP);
    positionPlateau = SDL_GetWindowSurface(salut);
    plateau1= IMG_Load("Graphique/plateau9.png");
    SDL_BlitSurface(plateau1, NULL, positionPlateau, NULL);
    SDL_UpdateWindowSurface(salut);
    positionTuile.x=70;
    positionTuile.y=40;
    SDL_UpdateWindowSurface(salut);
    bouton.surface = IMG_Load("Graphique/Pause.png");
    positionBouton.x=0;
    positionBouton.y=1021;
    SDL_BlitSurface(bouton.surface, NULL, positionPlateau, &positionBouton);
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
            positionTexte.x=1320;
            positionTexte.y=906;
            positionTexteTemp.x=1340;
            positionTexteTemp.y=906;
            texteTemp = IMG_Load("Graphique/RectangleNoir.png");
            SDL_BlitSurface(texteTemp, NULL, positionPlateau, &positionTexteTemp);
            SDL_UpdateWindowSurface(salut);
            police = TTF_OpenFont("ELEPHNT.TTF", 30);
            sprintf(phrase, "C'est à %s de jouer ", joueur[joueurActif].nom);
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
                    couleur = couleurMainJoueurGraphique(paquet,joueurActif,i);
                    carac = caracMainJoueurGraphique(paquet,joueurActif,i);
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
                if(nombreJoueurs==3)
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
                    sprintf(phraseScore3, "Score joueur3 = %d ", joueur[2].score);
                    positionTexte.x=(850);
                    positionTexte.y=(980);
                    texte = TTF_RenderText_Shaded(police, phraseScore3, couleurBlanche, couleurNoire);
                    SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
                    SDL_UpdateWindowSurface(salut);
                }
                if(nombreJoueurs==4)
                {
                    police = TTF_OpenFont("ELEPHNT.TTF", 25);
                    sprintf(phraseScore1, "Score joueur1 = %d ", joueur[0].score);
                    positionTexte.x=(850);
                    positionTexte.y=(906);
                    texte = TTF_RenderText_Shaded(police, phraseScore1, couleurBlanche, couleurNoire);
                    SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
                    SDL_UpdateWindowSurface(salut);
                    sprintf(phraseScore2, "Score joueur2 = %d ", joueur[1].score);
                    positionTexte.x=(850);
                    positionTexte.y=(936);
                    texte = TTF_RenderText_Shaded(police, phraseScore2, couleurBlanche, couleurNoire);
                    SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
                    SDL_UpdateWindowSurface(salut);
                    sprintf(phraseScore1, "Score joueur3 = %d ", joueur[2].score);
                    positionTexte.x=(850);
                    positionTexte.y=(966);
                    texte = TTF_RenderText_Shaded(police, phraseScore1, couleurBlanche, couleurNoire);
                    SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
                    SDL_UpdateWindowSurface(salut);
                    sprintf(phraseScore3, "Score joueur4 = %d ", joueur[3].score);
                    positionTexte.x=(850);
                    positionTexte.y=(996);
                    texte = TTF_RenderText_Shaded(police, phraseScore3, couleurBlanche, couleurNoire);
                    SDL_BlitSurface(texte, NULL, positionPlateau, &positionTexte);
                    SDL_UpdateWindowSurface(salut);
                    police = TTF_OpenFont("ELEPHNT.TTF", 30);
                }
                while(continuer == 1)
                {
                    continuer3=1;
                    SDL_WaitEvent(&clicSouris);
                    switch(clicSouris.type)
                    {
                    case SDL_MOUSEBUTTONDOWN:
                        positionCurseur.x = clicSouris.button.x;
                        positionCurseur.y = clicSouris.button.y;
                        deplacement = allocationCoordoneesMain(positionCurseur);
                        positionCurseur = allocationCoordoneesMain2(positionCurseur);
                        selection.surface = IMG_Load("Graphique/Degrade.png");
                        if((deplacement<6)&&(deplacement>=0))
                        {
                            SDL_BlitSurface(selection.surface, NULL, positionPlateau, &positionCurseur);
                            SDL_UpdateWindowSurface(salut);
                        }
                        else if(deplacement==-1)
                        {
                            bouton.surface = IMG_Load("Graphique/Play.png");
                            SDL_BlitSurface(bouton.surface, NULL, positionPlateau, &positionBouton);
                            SDL_UpdateWindowSurface(salut);
                            positionMenu.x =689;
                            positionMenu.y =245;
                            menuPause= IMG_Load("Graphique/MenuPause.png");
                            SDL_BlitSurface(menuPause, NULL, positionPlateau, &positionMenu);
                            SDL_UpdateWindowSurface(salut);
                            while(continuer3==1)
                            {
                                SDL_WaitEvent(&clicSouris3);
                                switch(clicSouris3.type)
                                {
                                case SDL_MOUSEBUTTONDOWN:
                                    positionCurseur3.x = clicSouris3.button.x;
                                    positionCurseur3.y = clicSouris3.button.y;
                                    choix = allocationCoordoneesPause(positionCurseur3);
                                    if (choix == -1)
                                    {
                                        bouton.surface = IMG_Load("Graphique/Pause.png");
                                        SDL_BlitSurface(plateau1, NULL, positionPlateau, NULL);
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
                                        for(j=0; j<13; j++)
                                        {
                                            for(i=0; i<27; i++)
                                            {
                                                if(plateau[j][i].forme != ' ')
                                                {
                                                    carac = plateau[j][i].forme;
                                                    couleur = (plateau[j][i].couleur);
                                                    tuile[m].surface = attribuerImage(carac,couleur);
                                                    positionTuile.y = (40+ (j*69));
                                                    positionTuile.x = (70+ (i*69));
                                                    SDL_BlitSurface(tuile[m].surface, NULL, positionPlateau, &positionTuile);
                                                    SDL_UpdateWindowSurface(salut);
                                                    m++;
                                                }
                                            }
                                        }
                                        SDL_BlitSurface(bouton.surface, NULL, positionPlateau, &positionBouton);
                                        SDL_UpdateWindowSurface(salut);
                                        continuer3=0;
                                    }
                                    else if(choix == 2)
                                    {
                                        continuer=0;
                                        continuer2=0;
                                        continuer3=0;
                                        joueurActif=4;
                                        finTour=1;
                                        partie =0;
                                    }
                                    else if(choix == 1)
                                    {
                                        continuer=0;
                                        continuer2=0;
                                        continuer3=0;
                                        joueurActif=4;
                                        finTour=1;
                                        partie =0;
                                    }
                                    break;
                                }
                                deplacement=8;
                            }
                        }
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
                    remplacerTuile(paquet, pioche, joueurActif, &BS);
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
                            x = ((positionCurseur2.x - 70)/69);
                            y = ((positionCurseur2.y - 40)/69);
                            if(test(x,y, paquet, plateau, joueurActif, deplacement, &lockC, &lockF, &scoreJoueurActif, &res0) == 1 || premierTour == 0)
                            {
                                continuer2 = 0;
                                continuer=1;
                                positionTuileMain.y = positionCurseur2.y;
                                positionTuileMain.x = positionCurseur2.x;
                                SDL_BlitSurface(tuileMain[deplacement].surface, NULL, positionPlateau, &positionTuileMain);
                                SDL_UpdateWindowSurface(salut);
                                joueur[joueurActif].score = scoreJoueurActif + joueur[joueurActif].score;
                                premierTour = 1;
                                plateau[y][x].forme=caracMainJoueurGraphique(paquet,joueurActif,deplacement);
                                plateau[y][x].couleur=couleurMainJoueurGraphique(paquet,joueurActif,deplacement);
                                InitialisercouleurMainJoueurGraphique(paquet,joueurActif,deplacement);
                                InitialisercaracMainJoueurGraphique(paquet,joueurActif,deplacement);
                                x=0;
                                y=0;
                            }
                            else
                            {
                                continuer2 = 0;
                                continuer=1;
                            }
                            res0=1;
                            deplacement = 8;
                        }
                        positionCurseur2.x = 0;
                        positionCurseur2.y = 0;
                        positionCurseur.x = 0;
                        positionCurseur.y = 0;
                        positionTuile.x = 0;
                        positionTuile.y = 0;
                        res0 = 1;
                    }
                }
            }
            remplirMain(paquet,pioche,joueurActif,&BS);
            joueurActif++;
            finTour = 0;
        }
        joueurActif = 0;
    }
    if(choix == 1)
    {
        SDL_DestroyWindow(salut);
        nomSauvegarde(nameSauvegarde);
        sauvegarderPartie(nameSauvegarde, plateau, nombreJoueurs, paquet, joueur, pioche, BS, difficulte);
        sauvegardeScore(joueur, nombreJoueurs);
    }
    else if(choix == 2)
    {
        SDL_DestroyWindow(salut);
        sauvegardeScore(joueur, nombreJoueurs);
    }
    SDL_Quit();
    TTF_CloseFont(police);
    TTF_Quit();
    TTF_Quit();
}
