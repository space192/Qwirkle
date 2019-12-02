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

void sauvegardeScore(T_JOUEUR joueur[4])
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
        for(i = 0 ; i < 4 ; i++)
        {
            fputs(joueur[i].nom, score);
            fputs(joueur[i].score, score);
            fputs(joueur[i].tuiles, score);
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
    strcpy(nomSauvegarde, nomFichier[l]);
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
    for(i=0; i< 13;i++)
    {
        for(j=0; j < 27 ; j++)
        {
            fprintf(fichier, "%c%d", plateau[i][j].forme, plateau[i][j].couleur);
        }
        fprintf(fichier, "\n");
    }
    fprintf(fichier, "z\n");
    for(i=0; i < nombreJoueur; i++)
    {
        fprintf(fichier, "%s\n%d\n", joueur[i].nom, joueur[i].score);
    }
    fprintf(fichier, "\ne\n");
    for(i=0;i < nombreJoueur; i++)
    {
        for(j=0;j < 6 ; j++)
        {
            fprintf(fichier, "%c%d", main[i][j].forme, main[i][j].couleur);
        }
        fprintf(fichier ,"\n");
    }
    fprintf(fichier, "r\n");
    for(i=0; i < BS; i++)
    {
        fprintf(fichier, "%c%d", pioche[i].forme, pioche[i].forme);
    }
    fprintf(fichier, "\nt\n%d\ny\n%d\nu\n%d", BS,nombreJoueur, difficulte);

}


void recupererPartie(T_TUILE plateau[][27], char *nomSauvegarde, int nombreJoueur, T_TUILE main[][6], T_JOUEUR *joueur, T_TUILE *pioche, int BS, int difficulte)
{
    FILE *fichier = NULL;
    fichier = fopen(nomSauvegarde, "r");
    int i,j;
    if(fichier == NULL)
    {
        printf("erreur d'ouverture du fichier")
    }
}
