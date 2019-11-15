#ifndef CONSTANTES_H_INCLUDED
#define CONSTANTES_H_INCLUDED

typedef struct JOUEUR
{
    char nom[20];
    int score;
    char tuiles[6][3];
}T_JOUEUR;

typedef struct TUILE
{
    char forme;
    int couleur;
    int positionX;
    int positionY;

}T_TUILE


#endif // CONSTANTES_H_INCLUDED
