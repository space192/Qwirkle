#include "prototypes.h"


void menu()
{
    int graphique = 0, nombreJoueurs, i, difficulte;
    printf("Bienvenue dans le Qwirkle\nVoullez vous jouer en graphique ou en console ?\n0:console\n1:graphique\n");
    do
    {
        scanf("%d", &graphique);
    }
    while(graphique != 0 && graphique != 1);
    printf("Parfait ! Combien de joueur veulent jouer au Qwirkle ?\n");
    do
    {
        scanf("%d", &nombreJoueurs);
    }
    while(nombreJoueurs < 1 && nombreJoueurs >4);
    T_JOUEUR *joueur = NULL;
    joueur = malloc(nombreJoueurs * sizeof(T_JOUEUR));
    for(i = 0; i < nombreJoueurs; i++)
    {
        printf("entrer le nom du joueur %d\n", i+1);
        fflush(stdin);
        gets(joueur[i].nom);
    }
    printf("Super on va enfin pouvoir jouer :D\nMais dis moi dans quel difficulte veux tu jouer ?\n1:Degrade\n2:Normal\n");
    do
    {
        scanf("%d", &difficulte);
    }
    while(difficulte <= 1 && difficulte >= 2);
    if(graphique == 0)
    {
        jeu(joueur, difficulte, nombreJoueurs);
    }
    else if (graphique = 1)
    {
        printf("graphic\n");
    }
    printf("Merci d'avoir Jouer !\n");
}
