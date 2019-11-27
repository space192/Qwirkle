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
    char nomFichier[50][50];
    int i=0,j = 0, y = 0, deplacement = 1, l;
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
    }
    for(i=2;i<4;i++)
    {
        gotoligcol(j, 7);
        printf("%s", nomFichier[i]);
        j++;
    }
    gotoligcol(0,0);
    printf("---->");
    while(deplacement==1)
    {
        deplacerCurseurSauvegarde(&y, &deplacement);
        printf("---->");
        l = y+2;
    }
    strcpy(nomSauvegarde, nomFichier[l]);
    closedir(dr);
}

void deplacerCurseurSauvegarde(int *y, int *num)
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
    gotoligcol(*y, 0);
}
