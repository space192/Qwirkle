#include "prototypes.h"
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
    char rond = 0xFE, carre = 0x04, losange= 0x1E, triangle = 0x05, trefle = 0x06, etoile = 0x9E;
    if(carac ==rond)
    {
        switch(couleur)
        {
        case 1:
            tuile = IMG_Load("Graphique/Ronds/RondViolet.png");
            break;
        case 2:
            tuile = IMG_Load("Graphique/Ronds/RondCyan.png");
            break;
        case 3:
            tuile = IMG_Load("Graphique/Ronds/RondJaune.png");
            break;
        case 4:
            tuile = IMG_Load("Graphique/Ronds/RondRouge.png");
            break;
        case 5:
            tuile = IMG_Load("Graphique/Ronds/RondVert.png");
            break;
        case 6:
            tuile = IMG_Load("Graphique/Ronds/RondBleu.png");
            break;
        }
    }
    else if(carac == carre)
    {
        switch(couleur)
        {
        case 1:
            tuile = IMG_Load("Graphique/Carres/CarreViolet.png");
            break;
        case 2:
            tuile = IMG_Load("Graphique/Carres/CarreCyan.png");
            break;
        case 3:
            tuile = IMG_Load("Graphique/Carres/CarreJaune.png");
            break;
        case 4:
            tuile = IMG_Load("Graphique/Carres/CarreOrange.png");
            break;
        case 5:
            tuile = IMG_Load("Graphique/Carres/CarreVert.png");
            break;
        case 6:
            tuile = IMG_Load("Graphique/Carres/CarreBleu.png");
            break;
        }
    }
    else if(carac == triangle)
    {
        switch(couleur)
        {
        case 1:
            tuile = IMG_Load("Graphique/Triangles/TriangleViolet.png");
            break;
        case 2:
            tuile = IMG_Load("Graphique/Triangles/TriangleCyan.png");
            break;
        case 3:
            tuile = IMG_Load("Graphique/Triangles/TriangleJaune.png");
            break;
        case 4:
            tuile = IMG_Load("Graphique/Triangles/TriangleRouge.png");
            break;
        case 5:
            tuile = IMG_Load("Graphique/Triangles/TriangleVert.png");
            break;
        case 6:
            tuile = IMG_Load("Graphique/Triangles/TriangleBleue.png");
            break;
        }
    }
    else if (carac == trefle)
    {
        switch(couleur)
        {
        case 1:
            tuile = IMG_Load("Graphique/Trefles/TrefleViolet.png");
            break;
        case 2:
            tuile = IMG_Load("Graphique/Trefles/TrefleCyan.png");
            break;
        case 3:
            tuile = IMG_Load("Graphique/Trefles/TrefleJaune.png");
            break;
        case 4:
            tuile = IMG_Load("Graphique/Trefles/TrefleRouge.png");
            break;
        case 5:
            tuile = IMG_Load("Graphique/Trefles/TrefleVert.png");
            break;
        case 6:
            tuile = IMG_Load("Graphique/Trefles/TrefleBleue.png");
            break;
        }
    }

    else if(carac == losange)
    {
        switch(couleur)
        {
        case 1:
            tuile = IMG_Load("Graphique/Losanges/LosangeViolet.png");
            break;
        case 2:
            tuile = IMG_Load("Graphique/Losanges/LosangeCyan.png");
            break;
        case 3:
            tuile = IMG_Load("Graphique/Losanges/LosangeJaune.png");
            break;
        case 4:
            tuile = IMG_Load("Graphique/Losanges/LosangeRouge.png");
            break;
        case 5:
            tuile = IMG_Load("Graphique/Losanges/LosangeVert.png");
            break;
        case 6:
            tuile = IMG_Load("Graphique/Losanges/LosangeBleue.png");
            break;
        }

    }
    else if(carac == etoile)
    {
        switch(couleur)
        {
        case 1:
            tuile = IMG_Load("Graphique/Etoiles/EtoileViolette.png");
            break;
        case 2:
            tuile = IMG_Load("Graphique/Etoiles/EtoileCyan.png");
            break;
        case 3:
            tuile = IMG_Load("Graphique/Etoiles/EtoileJaune.png");
            break;
        case 4:
            tuile = IMG_Load("Graphique/Etoiles/EtoileRouge.png");
            break;
        case 5:
            tuile = IMG_Load("Graphique/Etoiles/EtoileVerte.png");
            break;
        case 6:
            tuile = IMG_Load("Graphique/Etoiles/EtoileBleue.png");
            break;
        }
        return tuile;
    }
}

int caracMainJoueurGraphique(T_TUILE main[][6], int j, int l)
{
    return main[j][l].forme;
}

int couleurMainJoueurGraphique(T_TUILE main[][6], int j, int l)
{
    return main[j][l].couleur;
}

int allocationCoordoneesMain(SDL_Rect positionClic)
{
    int i, j, xOriginal = 1382 , yOriginal = 992;
    int deplacement;
    for(i = 0; i<= 6; i++)
    {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+121) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+69))
            {
                deplacement = i;
            }
            xOriginal = xOriginal + 69;
    }
    return deplacement;
}

SDL_Rect allocationCoordoneesPlateau(SDL_Rect positionClic)
{
    int i, j, xOriginal = 70, yOriginal = 40;
    printf("test");
    for(i = 0; i<= 26; i++)
    {
        for(j=0; j <= 13 ; j++)
        {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+69) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+69))
            {
                positionClic.x = xOriginal;
                positionClic.y = yOriginal;
            }
            xOriginal = xOriginal + 69;
        }
        xOriginal = 70;
        yOriginal = yOriginal + 69;
    }
    return positionClic;
}

int allocationX(SDL_Rect positionClic)
{
    int i, j, xOriginal = 70, yOriginal = 40;
    int valeur;
    printf("test");
    for(i = 0; i<= 26; i++)
    {
        for(j=0; j <= 13 ; j++)
        {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+69) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+69))
            {
                valeur=i;
            }
            xOriginal = xOriginal + 69;
        }
        xOriginal = 70;
        yOriginal = yOriginal + 69;
    }
    return valeur;
}

int allocationY(SDL_Rect positionClic)
{
    int i, j, xOriginal = 70, yOriginal = 40;
    int valeur;
    printf("test");
    for(i = 0; i<= 26; i++)
    {
        for(j=0; j <= 13 ; j++)
        {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+69) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+69))
            {
                valeur = j;
            }
            xOriginal = xOriginal + 69;
        }
        xOriginal = 70;
        yOriginal = yOriginal + 69;
    }
    return valeur;
}
