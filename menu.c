#include "prototypes.h"
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void menu()
{
	int graphique = 0, nombreJoueurs, i, difficulte;
  printf("Bienvenue dans le Qwirkle\nVoulez vous jouer en graphique ou en console ?\n");
  do
  {
  	scanf("%d", &graphique);
  }while(graphique != 0 && graphique != 1);
  printf("Parfait ! Combien de joueur veulent jouer au Qwirkle ?\n");
  do
  {
  	scanf("%d", &nombreJoueurs);
  }
  while(nombreJoueurs < 1 && nombreJoueurs >4);
  T_JOUEUR *joueur = NULL;
  joueur = malloc(nombreJoueurs * sizeof(T_JOUEUR));
  for(i = 0; i < 4; i++)
  {
  	fflush(stdin);
    gets(joueur[i].nom);
  }
  printf("Super on va enfin pouvoir jouer :D\nMais dis moi dans quel difficulté veux tu jouer ?\n1:Degrade\n2:Normal\n");
  do
  {
  	scanf("%d", &difficulte);
  }
  while(difficulte <= 1 && difficulte >= 2);
  if(graphique = 0)
  {
  }
  else if (graphique = 1)
  {
  }
  printf("Merci d'avoir Jouer !\n");
}
