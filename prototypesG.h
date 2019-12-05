#ifndef PROTOTYPESG_H_INCLUDED
#define PROTOTYPESG_H_INCLUDED



#endif // PROTOTYPESG_H_INCLUDED

void jeuGraphique(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde);
SDL_Rect allocationCoordonees(SDL_Rect positionClic);
int coordonees();
SDL_Surface *attribuerImage(int carac,int couleur);
char retournervaleur(T_TUILE plateau[13][27],int i,int j);

