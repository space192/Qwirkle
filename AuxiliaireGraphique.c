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
    if(carac == 0xFE)
    {
        if (couleur==1)
        {
           tuile = IMG_Load("Graphique/Ronds/RondViolet.png");
        }
        else if(couleur == 2)
        {
            tuile = IMG_Load("Graphique/Ronds/RondCyan.png");
        }
        else if(couleur == 3)
        {
            tuile = IMG_Load("Graphique/Ronds/RondJaune.png");
        }
        else if(couleur == 4)
        {
            tuile = IMG_Load("Graphique/Ronds/RondRouge.png");
        }
        else if(couleur == 5)
        {
            tuile = IMG_Load("Graphique/Ronds/RondVert.png");
        }
        else if(couleur == 6)
        {
            tuile = IMG_Load("Graphique/Ronds/RondBleu.png");
        }

    }
    else if(carac == 0x04)
    {
        if (couleur==1)
        {
           tuile = IMG_Load("Graphique/Carrés/CarréViolet.png");
        }
        else if(couleur == 2)
        {
           tuile = IMG_Load("Graphique/Carrés/CarréCyan.png");
        }
        else if(couleur == 3)
        {
            tuile = IMG_Load("Graphique/Carrés/CarréJaune.png");
        }
        else if(couleur == 4)
        {
            tuile = IMG_Load("Graphique/Carrés/CarréOrange.png");
        }
        else if(couleur == 5)
        {
            tuile = IMG_Load("Graphique/Carrés/CarréVert.png");
        }
        else if(couleur == 6)
        {
            tuile = IMG_Load("Graphique/Carrés/CarréBleu.png");
        }
    }
    else if(carac == 0x05)
    {
        if (couleur==1)
        {
           tuile = IMG_Load("Graphique/Triangles/TriangleViolet.png");
        }
        else if(couleur == 2)
        {
           tuile = IMG_Load("Graphique/Triangles/TriangleCyan.png");
        }
        else if(couleur == 3)
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleJaune.png");
        }
        else if(couleur == 4)
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleRouge.png");
        }
        else if(couleur == 5)
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleVert.png");
        }
        else if(couleur == 6)
        {
            tuile = IMG_Load("Graphique/Triangles/TriangleBleue.png");
        }
    }
    else if(carac == 0x06)
    {
        if (couleur==1)
        {
           tuile = IMG_Load("Graphique/Trèfles/TrefleViolet.png");
        }
        else if(couleur == 2)
        {
           tuile = IMG_Load("Graphique/Trèfles/TrefleCyan.png");
        }
        else if(couleur == 3)
        {
            tuile = IMG_Load("Graphique/Trèfles/TrefleJaune.png");
        }
        else if(couleur == 4)
        {
            tuile = IMG_Load("Graphique/Trèfles/TrefleRouge.png");
        }
        else if(couleur == 5)
        {
            tuile = IMG_Load("Graphique/Trèfles/TrèfleVert.png");
        }
        else if(couleur == 6)
        {
            tuile = IMG_Load("Graphique/Trèfles/TrefleBleue.png");
        }
    }
    else if(carac == 0x1E)
    {
        if (couleur==1)
        {
           tuile = IMG_Load("Graphique/Losanges/LosangeViolet.png");
        }
        else if(couleur == 2)
        {
           tuile = IMG_Load("Graphique/Losanges/LosangeCyan.png");
        }
        else if(couleur == 3)
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeJaune.png");
        }
        else if(couleur == 4)
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeRouge.png");
        }
        else if(couleur == 5)
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeVert.png");
        }
        else if(couleur == 6)
        {
            tuile = IMG_Load("Graphique/Losanges/LosangeBleue.png");
        }
    }
    else if(carac == 0x9E)
    {
        if (couleur==1)
        {
           tuile = IMG_Load("Graphique/Etoiles/EtoileViolette.png");
        }
        else if(couleur == 2)
        {
           tuile = IMG_Load("Graphique/Etoiles/EtoileCyan.png");
        }
        else if(couleur == 3)
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileJaune.png");
        }
        else if(couleur == 4)
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileRouge.png");
        }
        else if(couleur == 5)
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileVerte.png");
        }
        else if(couleur == 6)
        {
            tuile = IMG_Load("Graphique/Etoiles/EtoileBleue.png");
        }
    }
    return tuile;
}

