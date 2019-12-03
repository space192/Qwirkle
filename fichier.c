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
    score = fopen("scores.txt", "a");
    if(score == NULL)
    {
        printf("erreur lors de la sauvegarde des scores peut etre que le fichier score est manquant.\n");
    }
    else
    {
        for(i = 0 ; i < nombrejoueur ; i++)
        {
            fprintf(score, "%d", joueur[i].score);
        }
        fclose(score);
    }
}

void selecteurSauvegarde(char *nomSauvegarde)
{
    struct dirent *de;
    DIR *dr = opendir("./bin/debug/sauvegarde");
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
    scanf("%s", sauvegardeTemp);
    strcat(nomSauvegarde, sauvegardeTemp);
    strcat(nomSauvegarde, typeSauvegarde);
    fichier = fopen(nomSauvegarde, "w");
    if(fichier == NULL)
    {
        printf("erreur lors de la creation de la sauvegarde");
    }
}

void sauvegarderPartie(T_TUILE plateau[][27], char *nomSauvegarde, int nombreJoueur, T_TUILE main[][6], T_JOUEUR *joueur, T_TUILE *pioche, int BS, int difficulte)
{
    FILE *fichier = NULL;
    fichier = fopen(nomSauvegarde, "w");
    int i,j;
    if(fichier == NULL)
    {
        printf("erreur d'ouverture du fichier");
        exit(0);
    }
    fprintf(fichier, "a\n");
    fprintf(fichier, "%d\nz\n%d\ne\n%d\n", BS, nombreJoueur, difficulte);
    for(i=0; i < nombreJoueur; i++)
    {
        fprintf(fichier, "%s\n%d\n", joueur[i].nom, joueur[i].score);
    }
    fprintf(fichier, "\nr\n");
    for(i=0;i < nombreJoueur; i++)
    {
        for(j=0;j < 6 ; j++)
        {
            fprintf(fichier, "%c%d", main[i][j].forme, main[i][j].couleur);
        }
        fprintf(fichier ,"\n");
    }
    fprintf(fichier, "t\n");
    for(i=0; i < BS; i++)
    {
        fprintf(fichier, "%c%d", pioche[i].forme, pioche[i].forme);
    }
    fprintf(fichier, "\ny\n");
    for(i=0; i< 13;i++)
    {
        for(j=0; j < 27 ; j++)
        {
            fprintf(fichier, "%c%d", plateau[i][j].forme, plateau[i][j].couleur);
        }
        fprintf(fichier, "\n");
    }
    fclose(fichier);
}

void recupererSauvegarde(T_TUILE plateau[][27], char *nomSauvegarde, int *nombreJoueur, T_TUILE main[][6], T_JOUEUR *joueur, T_TUILE *pioche, int *BS, int *difficulte)
{
    int i,j;
    char poubelle;
    FILE *fichier = NULL;
    fichier = fopen(nomSauvegarde, "r");
    if(fichier == NULL)
    {
        printf("erreur d'ouverture de la sauvegarde");
        exit(0);
    }
    for(i=0;i<nombreJoueur;i++)
    {
        fscanf(fichier, "%s\n%d\n", joueur[i].nom, joueur[i].score);
    }
    fscanf(fichier, "%c", &poubelle);
    printf("merde1\n");
    for(i=0;i < nombreJoueur;i++)
    {
        for(j=0;j < 6 ; j++)
        {
            fscanf(fichier, "%c%d", main[i][j].forme, main[i][j].couleur);
        }
        fscanf(fichier, "\n");
    }
    fscanf(fichier, "%c\n", &poubelle);
    printf("merde2\n");
    for(i = 0 ; i < BS; i++)
    {
        fscanf(fichier, "%c%d", pioche[i].forme, pioche[i].forme);
    }
    fscanf(fichier, "%c\n", &poubelle);
    printf("merde3\n");
    for(i=0; i< 13;i++)
    {
        for(j=0; j < 27 ; j++)
        {
            fscanf(fichier, "%c%d", plateau[i][j].forme, plateau[i][j].couleur);
        }
        fscanf(fichier, "\n");
    }
    printf("merde4\n");
    fclose(fichier);
}

void recupererSauvegardeAuxiliere(int *BS, int *nombreJoueur, char *nomSauvegarde, int *difficulte)
{
    char poubelle;
    FILE *fichier = NULL;
    fichier = fopen(nomSauvegarde, "r");
    if(fichier == NULL)
    {
        printf("erreur d'ouverture de la sauvegarde\n");
    }
    fscanf(fichier, "%c\n%d\n%c\n%d\n%c\n%d\n", &poubelle, BS, &poubelle, nombreJoueur, &poubelle, difficulte);
    fclose(fichier);
}
