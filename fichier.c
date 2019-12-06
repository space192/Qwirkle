#include "prototypes.h"


void affichageRegle()
{
    FILE *regles = NULL;
    regles = fopen("regles.txt", "r");
    if(regles == NULL)
    {
        printf("erreur dans l'affichage des regles peut etre que le fichier regle est manquant.\n");
    }
    else
    {
        char chaineRegle[1000];
        while(fgets(chaineRegle, 1000, regles) != NULL)
        printf("%s", chaineRegle);
        fclose(regles);
    }
    system("pause");
}

void sauvegardeScore(T_JOUEUR joueur[], int nombrejoueur)
{
    FILE* score = NULL;
    int i;
    score = fopen("scores.txt", "a+");
    if(score == NULL)
    {
        printf("erreur lors de la sauvegarde des scores peut etre que le fichier score est manquant.\n");
    }
    else
    {
        for(i = 0 ; i < nombrejoueur ; i++)
        {
            fprintf(score, "%s : %d\n", joueur[i].nom ,joueur[i].score);
        }
        fprintf(score, "\n");
        fclose(score);
    }
}

void afficherScore()
{
    FILE *score = NULL;
    score = fopen("scores.txt", "r");
    if(score == NULL)
    {
        printf("erreur lors de l'ouverture des scores");
    }
    else
    {
        char chaineScore[10000];
        system("cls");
        while(fgets(chaineScore, 10000, score)!=NULL)
        printf("%s", chaineScore);
        fclose(score);
    }
    system("pause");
}

void selecteurSauvegarde(char *nomSauvegarde)
{
    struct dirent *de;
    DIR *dr = opendir("./sauvegarde");
    char nomFichier[100][50];
    int i=0,j = 0, y = 0, deplacement = 1, l,k=0;
    system("cls");
    if(dr == NULL)
    {
        printf("erreur d'ouverture de dossier");
        exit(0);
    }
    while((de = readdir(dr)) !=NULL)
    {
        strcpy(nomFichier[i], de->d_name);
        i++;
        k++;
    }
    for(i=2;i<k;i++)
    {
        gotoligcol(j, 7);
        printf("%s", nomFichier[i]);
        j++;
    }
    gotoligcol(0,0);
    printf("---->");
    while(deplacement==1)
    {
        deplacerCurseurSauvegarde(&y, &deplacement, k);
        printf("---->");
        l = y+2;
    }
    strcat(nomSauvegarde, nomFichier[l]);
    closedir(dr);
}

void deplacerCurseurSauvegarde(int *y, int *num, int k)
{
    int c;
    c = getch();
    switch(c)
    {
        case 224:
        {
            c = getch();
            switch(c)
            {
            case 72:
                *y = *y-1;
                gotoligcol(*y+1,0);
                printf("     ");
                break;
            case 80:
                *y = *y+1;
                gotoligcol(*y-1,0);
                printf("     ");
                break;
            }
        break;
        }
    case 13: //0
        *num = 0;
        break;
    }
    if(*y == -1)
    {
        *y = 0;
    }
    else if(*y > k-3)
    {
        *y=*y-1;
    }
    gotoligcol(*y, 0);
}

void nomSauvegarde(char *nomSauvegarde)
{
    char typeSauvegarde[5] = ".sav";
    char sauvegardeTemp[50];
    FILE *fichier = NULL;
    printf("entrez le nom de votre sauvegarde\n");
    fflush(stdin);
    gets(sauvegardeTemp);
    strcat(nomSauvegarde, sauvegardeTemp);
    strcat(nomSauvegarde, typeSauvegarde);
    fichier = fopen(nomSauvegarde, "w");
    if(fichier == NULL)
    {
        printf("erreur lors de la creation de la sauvegarde");
    }
}

void sauvegarderPartie(char *nomfichier, T_TUILE plateau[][27], int nombreJoueur, T_TUILE main[][6], T_JOUEUR *joueur, T_TUILE *pioche, int BS, int difficulte)
{
    int i,j;
    FILE *fichier = NULL;
    fichier = fopen(nomfichier ,"w+");
    fprintf(fichier, "%d\n%d\n%d\n", BS, nombreJoueur, difficulte);
    for(i=0;i < nombreJoueur; i++)
    {
        for(j=0;j < 6 ; j++)
        {
            fprintf(fichier, "%c%d", main[i][j].forme, main[i][j].couleur);
        }
    }
    for(i=0; i < BS; i++)
    {
        fprintf(fichier, "%c%d", pioche[i].forme, pioche[i].couleur);
    }
    for(i=0; i< 13;i++)
    {
        for(j=0; j < 27 ; j++)
        {
            fprintf(fichier, "%c%d", plateau[i][j].forme, plateau[i][j].couleur);
        }
    }
    fprintf(fichier, "\n");
    for(i=0; i < nombreJoueur; i++)
    {
        fprintf(fichier, "%d\n", strlen(joueur[i].nom));
    }
    for(i=0; i < nombreJoueur; i++)
    {
        fprintf(fichier, "%s%d\n", joueur[i].nom,joueur[i].score);
    }
    fclose(fichier);
}

void recupererSauvegarde(FILE *fichier, T_TUILE plateau[][27], int nombreJoueur, T_TUILE main[][6], T_JOUEUR *joueur, T_TUILE *pioche, int BS, int difficulte)
{
    int i,j,temp[4];
    system("cls");
    for(i=0;i < nombreJoueur; i++)
    {
        for(j=0;j < 6;j++)
        {
            main[i][j].forme = fgetc(fichier);
            fscanf(fichier, "%d", &main[i][j].couleur);
        }
    }
    for(i=0;i < BS; i++)
    {
        pioche[i].forme = fgetc(fichier);
        fscanf(fichier, "%d", &pioche[i].couleur);
    }
    for(i=0;i < 13;i++)
    {
        for(j=0;j < 27; j++)
        {
            plateau[i][j].forme = fgetc(fichier);
            fscanf(fichier, "%d", &plateau[i][j].couleur);
        }
    }
    fscanf(fichier, "\n");
    for(i=0; i < nombreJoueur; i++)
    {
        fscanf(fichier, "%d", &temp[i]);
    }
    fscanf(fichier, "\n");
    for(i=0; i < nombreJoueur; i++)
    {
        for(j=0; j < temp[i] ; j++)
        {
            joueur[i].nom[j] = fgetc(fichier);
        }
        if(i==0)
        {
            joueur[i].nom[temp[i]] = '\0';
        }
        joueur[i].nom[temp[i]+1] = '\0';
        fscanf(fichier, " %d", &joueur[i].score);
        fscanf(fichier, "\n");
    }
    effacerEcran();
}
