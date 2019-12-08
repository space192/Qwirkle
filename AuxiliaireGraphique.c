#include "prototypes.h"

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

    }
    return tuile;
}

int caracMainJoueurGraphique(T_TUILE main[][6], int j, int l)
{
    return main[j][l].forme;
}

int couleurMainJoueurGraphique(T_TUILE main[][6], int j, int l)
{
    return main[j][l].couleur;
}

void InitialisercaracMainJoueurGraphique(T_TUILE main[][6], int j, int l)
{
    main[j][l].forme = ' ';
}

void InitialisercouleurMainJoueurGraphique(T_TUILE main[][6], int j, int l)
{
    main[j][l].couleur = 0;
}

int recupererValeur(T_TUILE plateau[13][27], int y, int x)
{
    return plateau[y][x].forme;
}

int recupererCouleur(T_TUILE plateau[13][27], int y, int x)
{
    return plateau[y][x].couleur;
}



int allocationCoordoneesMain(SDL_Rect positionClic)
{
    int i, xOriginal = 1382 , yOriginal = 992,xOriginal2 = 90 , yOriginal2 = 960,xOriginal3 = 90 , yOriginal3 = 920;
    int deplacement;

    if((positionClic.x > xOriginal2) && (positionClic.x < xOriginal2+493) && (positionClic.y > yOriginal2) && (positionClic.y < yOriginal2+40))
    {
        deplacement = 7;
    }
    else if((positionClic.x > xOriginal3) && (positionClic.x < xOriginal3+493) && (positionClic.y > yOriginal3) && (positionClic.y < yOriginal3+40))
    {
        deplacement = 6;
    }
    else if((positionClic.x > 0) && (positionClic.x < 69) && (positionClic.y > 1021) && (positionClic.y < 1080))
    {
        deplacement = -1;
    }

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

int allocationCoordoneesPause(SDL_Rect positionClic)
{
    int deplacement;

    if((positionClic.x > 758) && (positionClic.x < 1172) && (positionClic.y > 383) && (positionClic.y < 463))
    {
        deplacement = 1;
    }
    else if((positionClic.x > 758) && (positionClic.x < 1172) && (positionClic.y > 463) && (positionClic.y < 532))
    {
        deplacement = 2;
    }
    else if((positionClic.x > 0) && (positionClic.x < 69) && (positionClic.y > 1021) && (positionClic.y < 1080))
    {
        deplacement = -1;
    }


    return deplacement;
}

SDL_Rect allocationCoordoneesMain2(SDL_Rect positionClic)
{
    int i, xOriginal = 1313 , yOriginal = 992;


    for(i = 0; i<= 6; i++)
    {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+121) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+69))
            {
                positionClic.x = xOriginal + 69;
                positionClic.y = yOriginal;

            }
            xOriginal = xOriginal + 69;
    }

    return positionClic;
}




SDL_Rect allocationCoordoneesPlateau(SDL_Rect positionClic)
{
    int i, j, xOriginal = 70, yOriginal = 40;

    for(i = 0; i<= 13; i++)
    {
        for(j=0; j <= 27 ; j++)
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

    for(i = 0; i<= 13; i++)
    {
        for(j=0; j <= 27 ; j++)
        {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+69) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+69))
            {
                valeur=j;
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
    for(i = 0; i<= 13; i++)
    {
        for(j=0; j <= 27 ; j++)
        {
            if((positionClic.x > xOriginal) && (positionClic.x < xOriginal+69) && (positionClic.y > yOriginal) && (positionClic.y < yOriginal+69))
            {
                valeur = i;
            }
            xOriginal = xOriginal + 69;
        }
        xOriginal = 70;
        yOriginal = yOriginal + 69;
    }
    return valeur;
}

SDL_Surface *attribuerImageMain(int carac,int couleur)
{
    SDL_Surface *tuile = NULL;
    char rond = 0xFE, carre = 0x04, losange= 0x1E, triangle = 0x05, trefle = 0x06, etoile = 0x9E, rien = ' ';
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
            tuile = IMG_Load("Graphique/Carres/CarreRouge.png");
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

    }

    else if(carac == rien)
    {
        tuile = IMG_Load("Graphique/TuileVide.png");
    }
    return tuile;
}
