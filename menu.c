#include "prototypes.h"


void menu()
{
    int graphique, nombreJoueurs, i, difficulte, choix,menu = 1, sauvegarde =2;
    T_JOUEUR *joueur = NULL;
    while(menu == 1)
    {

        afficherTitre();
        printf("Que voulez vous faire ?\n1:Jouer\n2:Afficher Les regles\n3:Consulter les scores\n4:Quitter\n");
        do
        {
            fflush(stdin);
            scanf("%d", &choix);
        }
        while(choix < 1 || choix > 4);
        if(choix == 1)
        {
            system("cls");
            printf("Voullez vous jouer en graphique ou en console ?\n0:console\n1:graphique\n");
            do
            {
                scanf("%d", &graphique);
                fflush(stdin);
            }
            while(graphique < 0 || graphique > 1);
            system("cls");
            do
            {
                Color(11, 0);
                printf("Voullez vous reprendre une partie sauvegarde ?\n1:oui\n2:non\n");
                Color(15, 0);
                scanf("%d", &sauvegarde);
                fflush(stdin);
            }
            while(sauvegarde > 2 || sauvegarde < 1);
            if(sauvegarde==2)
            {
                Color(11, 0);
                printf("Parfait ! Combien de joueur veulent jouer au Qwirkle ?\n\n");
                Color(15, 0);
                do
                {
                    fflush(stdin);
                    scanf("%d", &nombreJoueurs);
                }
                while(nombreJoueurs < 2 || nombreJoueurs > 4);
                system("cls");
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
            }
            if(graphique == 0)
            {
                system("cls");
                jeu(joueur, difficulte, nombreJoueurs, sauvegarde);
                menu = 0;
            }
            else if(graphique == 1)
            {
                system("cls");
                jeuGraphique(joueur, difficulte, nombreJoueurs, sauvegarde);
                menu = 0;
            }
        }
        else if (choix == 2)
        {
            system("cls");
            affichageRegle();
            menu = 1;
            system("cls");
        }
        else if(choix == 3)
        {
            afficherScore();
            menu = 1;
        }
        else if(choix == 4)
        {
            system("cls");
            menu = 0;
        }
    }
    printf("Merci d'avoir Jouer !\n");
    system("pause");
}
