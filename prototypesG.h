#ifndef PROTOTYPESG_H_INCLUDED
#define PROTOTYPESG_H_INCLUDED



#endif // PROTOTYPESG_H_INCLUDED

void jeuGraphique(T_JOUEUR *joueur, int difficulte, int nombreJoueurs,int sauvegarde);
SDL_Rect allocationCoordonees(SDL_Rect positionClic);
int coordonees();
SDL_Surface *attribuerImage(int carac,int couleur);
char retournervaleur(T_TUILE plateau[13][27],int i,int j);
int couleurMainJoueurGraphique(T_TUILE main[][6], int j, int l);
int caracMainJoueurGraphique(T_TUILE main[][6], int j, int l);
int allocationCoordoneesMain(SDL_Rect positionClic);
SDL_Rect allocationCoordoneesPlateau(SDL_Rect positionClic);
int allocationX(SDL_Rect positionClic);
int allocationy(SDL_Rect positionClic);
SDL_Surface *attribuerImageMain(int carac,int couleur);



