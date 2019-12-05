#include "prototypes.h"
#include "prototypesG.h"

int coordonees()
{
    SDL_Rect carte[5][5];
    int i, j,k,l, xOriginal = 31, yOriginal = 81;
    for(i = 0; i <= 5-1; i++)
    {
        for(j = 0; j <= 5-1; j++)
        {
            carte[i][j].x = 0;
            carte[i][j].y = 0;
        }
    }
    for(i = 0; i <= 5-1; i++)
    {
        for(j = 0; j <= 5-1; j++)
        {
            carte[i][j].x = xOriginal;
            carte[i][j].y = yOriginal;
            xOriginal = xOriginal + 121;
            printf("%d et %d\n", carte[i][j].x, carte[i][j].y);

        }
        xOriginal = 31;
        yOriginal = yOriginal + 121;
    }
}


SDL_Rect allocationCoordonees(SDL_Rect positionClic)
{
    int i, j, xOriginal = 31, yOriginal = 81;
    for(i = 0; i<= 5; i++)
    {
        for(j=0; j <= 5 ; j++)
        {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+121) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+121))
            {
                positionClic.x = xOriginal;
                positionClic.y = yOriginal;
            }
            xOriginal = xOriginal + 121;
        }
        xOriginal = 31;
        yOriginal = yOriginal + 121;
    }
    return positionClic;
}

SDL_Surface *attribuerImage(int carac,int couleur)
{
    SDL_Surface *tuile = NULL;

        if ((couleur==1)&&(carac == 0xFE))
        {
           tuile = IMG_Load("Graphique/Ronds/RondViolet.png");
           printf("1");
        }
        else if((couleur == 2)&&(carac == 0xFE))
        {
            tuile = IMG_Load("Graphique/Ronds/RondCyan.png");
            printf("1");
        }
        else if((couleur == 3)&&(carac == 0xFE))
        {
            tuile = IMG_Load("Graphique/Ronds/RondJaune.png");
            printf("1");
        }
        else if((couleur == 4)&&(carac == 0xFE))
        {
            tuile = IMG_Load("Graphique/Ronds/RondRouge.png");
            printf("1");
        }
        else if((couleur == 5)&&(carac == 0xFE))
        {
            tuile = IMG_Load("Graphique/Ronds/RondVert.png");
            printf("1");
        }
        else if((couleur == 6)&&(carac == 0xFE))
        {
            tuile = IMG_Load("Graphique/Ronds/RondBleu.png");
            printf("1");
        }


        else if ((couleur==1)&&(carac == 0x04))
        {
           tuile = IMG_Load("Graphique/Carres/CarreViolet.png");
           printf("1");
        }
        else if((couleur == 2)&&(carac == 0x04))
        {
           tuile = IMG_Load("Graphique/Carres/CarreCyan.png");
           printf("1");
        }
        else if((couleur == 3)&&(carac == 0x04))
        {
            tuile = IMG_Load("Graphique/Carres/CarreJaune.png");
            printf("1");
        }
        else if((couleur == 4)&&(carac == 0x04))
        {
            tuile = IMG_Load("Graphique/Carres/CarreOrange.png");
            printf("1");
        }
        else if((couleur == 5)&&(carac == 0x04))
        {
            tuile = IMG_Load("Graphique/Carres/CarreVert.png");
            printf("1");
        }
        else if((couleur == 6)&&(carac == 0x04))
        {
            tuile = IMG_Load("Graphique/Carres/CarreBleu.png");
            printf("1");
        }

        else if((couleur==1)&&(carac == 0x05))
        {
           tuile = IMG_Load("Graphique/Triangles/TriangleViolet.png");
           printf("1");
        }
        else if((couleur == 2)&&(carac == 0x05))
        {
           tuile = IMG_Load("Graphique/Triangles/TriangleCyan.png");
           printf("1");
        }
        else if((couleur == 3)&&(carac == 0x05))
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleJaune.png");
            printf("1");
        }
        else if((couleur == 4)&&(carac == 0x05))
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleRouge.png");
            printf("1");
        }
        else if((couleur == 5)&&(carac == 0x05))
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleVert.png");
            printf("1");
        }
        else if((couleur == 6)&&(carac == 0x05))
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleBleue.png");
            printf("1");
        }

        else if ((couleur==1)&&(carac == 0x06))
        {
           tuile = IMG_Load("Graphique/Trefles/TrefleViolet.png");
           printf("1");
        }
        else if((couleur == 2)&&(carac == 0x06))
        {
           tuile = IMG_Load("Graphique/Trefles/TrefleCyan.png");
           printf("1");
        }
        else if((couleur == 3)&&(carac == 0x06))
        {
            tuile = IMG_Load("Graphique/Trefles/TrefleJaune.png");
            printf("1");
        }
        else if((couleur == 4)&&(carac == 0x06))
        {
            tuile = IMG_Load("Graphique/Trefles/TrefleRouge.png");
            printf("1");
        }
        else if((couleur == 5)&&(carac == 0x06))
        {
            tuile = IMG_Load("Graphique/Trefles/TrefleVert.png");
            printf("1");
        }
        else if((couleur == 6)&&(carac == 0x06))
        {
            tuile = IMG_Load("Graphique/Trefles/TrefleBleue.png");
            printf("1");
        }

        else if ((couleur==1)&&(carac == 0x1E))
        {
           tuile = IMG_Load("Graphique/Losanges/LosangeViolet.png");
           printf("1");
        }
        else if((couleur == 2)&&(carac == 0x1E))
        {
           tuile = IMG_Load("Graphique/Losanges/LosangeCyan.png");
           printf("1");
        }
        else if((couleur == 3)&&(carac == 0x1E))
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeJaune.png");
            printf("1");
        }
        else if((couleur == 4)&&(carac == 0x1E))
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeRouge.png");
            printf("1");
        }
        else if((couleur == 5)&&(carac == 0x1E))
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeVert.png");
            printf("1");
        }
        else if((couleur == 6)&&(carac == 0x1E))
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeBleue.png");
            printf("1");
        }

        else if ((couleur==1)&&(carac == 0x9E))
        {
           tuile = IMG_Load("Graphique/Etoiles/EtoileViolette.png");
           printf("1");
        }
        else if((couleur == 2)&&(carac == 0x9E))
        {
           tuile = IMG_Load("Graphique/Etoiles/EtoileCyan.png");
           printf("1");
        }
        else if((couleur == 3)&&(carac == 0x9E))
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileJaune.png");
            printf("1");
        }
        else if((couleur == 4)&&(carac == 0x9E))
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileRouge.png");
            printf("1");
        }
        else if((couleur == 5)&&(carac == 0x9E))
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileVerte.png");
            printf("1");
        }
        else if((couleur == 6)&&(carac == 0x9E))
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileBleue.png");
            printf("1");
        }


    return tuile;
}

char retournervaleur(T_TUILE plateau[13][27],int i,int j)
{
    return (plateau[13][27].forme);
}


