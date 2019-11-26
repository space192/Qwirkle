#include "prototypes.h"


void menu()
{
    int graphique, nombreJoueurs, i, difficulte;
    Color(11, 0);
    printf("--Bienvenue dans Qwirkle--\n\n\n\n");
    Color(15, 0);
    printf("Voullez vous jouer en graphique ou en console ?\n0:console\n1:graphique\n");
    do
    {
        scanf("%d", &graphique);
        fflush(stdin);
    }
    while(graphique < 0 || graphique > 1);
    system("cls");

    Color(11, 0);
    printf("Parfait ! Combien de joueur veulent jouer au Qwirkle ?\n\n");
    Color(15, 0);
    do
    {
        scanf("%d", &nombreJoueurs);
    }
    while(nombreJoueurs < 2 || nombreJoueurs > 4);
    system("cls");
    T_JOUEUR *joueur = NULL;
    joueur = malloc(nombreJoueurs * sizeof(T_JOUEUR));
    for(i = 0; i < nombreJoueurs; i++)
    {
        Color(11, 0);
        printf("Entrez le nom du joueur %d:\n", i+1);
        Color(15, 0);
        fflush(stdin);
        gets(joueur[i].nom);
    }
    system("cls");
    printf("Super on va enfin pouvoir jouer :D\n\n");
    Color(11, 0);
    printf("Mais dis moi dans quel difficulte veux tu jouer ?\n\n");
    Color(15, 0);
    printf("1:Degrade\n2:Normal\n");
    do
    {
        scanf("%d", &difficulte);
        fflush(stdin);
    }
    while(difficulte < 1 || difficulte > 2);
    if(graphique == 0)
    {
        system("cls");
        jeu(joueur, difficulte, nombreJoueurs);
    }
    else if (graphique = 1)
    {
        printf("graphic\n");
    }
    printf("Merci d'avoir Jouer !\n");
}
