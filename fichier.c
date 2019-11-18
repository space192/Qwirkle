#include "constantes.h"
#include <time.h>

void affichageRegle()
{
    FILE* regles = NULL;
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

}

void sauvegardeScore(T_JOUEUR joueur[4])
{
    FILE* score = NULL;
    int i;
    score = fopen("scores.txt", "a");
    if(regles == NULL)
    {
        printf("erreur lors de la sauvegarde des scores peut etre que le fichier score est manquant.\n");
    }
    else
    {
        for(i = 0 ; i < 4 ; i++)
        {
            fputs(joueur[i].nom, score);
            fputs(joueur[i].score, score);
            fputs(joueur.tuiles, score);
        }
        fclose(score);
    }
}
