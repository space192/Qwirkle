#include "prototypes.h"
#include "prototypesG.h"

void jeuGraphique(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde)
{
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("erreur lors de l'initialisation de la SDL");
        exit(0);
    }
    int continuer =1;
    int couleur;
    int carac;


    int BS, i,k,j, partie = 1, joueurActif = 0, deplacement = 8, x = 1, y=1, finTour = 0, l = 31, premierTour = 0, lockC = 1, lockF = 1, scoreJoueurActif =0;
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

    SDL_Surface ** tuile = malloc(sizeof(SDL_Surface *) * 302);
    for( i = 0; i < 302; i++){

    tuile[i] = malloc(sizeof(SDL_Surface*));
    }

    SDL_Rect* positionPlateau = NULL;
    SDL_Rect positionTuile;
    SDL_Event clicSouris;
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




    for(i=0;i<26;i++)
    {
        for(j=0;j<12;j++)
        {
            if(plateau[i][j].forme != ' ')
            {
               carac=  plateau[i][j].forme;
               couleur =plateau[i][j].couleur ;

               tuile[i+(j*26)] = attribuerImage(carac,couleur );
               positionTuile.y = (40+ (i*69));
               positionTuile.x = (70+ (j*69));

               SDL_BlitSurface(tuile[i+(j*26)], NULL, positionPlateau, &positionTuile);
               SDL_UpdateWindowSurface(salut);


            }
        }
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

    system("pause");

    SDL_DestroyWindow(salut);
    SDL_Quit();
    return 0;
}
