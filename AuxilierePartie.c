#include "prototypes.h"


void definirPiocheDegrade(T_TUILE *pioche)
{
    int i;

    for(i=0;i<6;i++)// Carrés
    {
        pioche[i].forme = 0xDB;
        pioche[i].couleur=(i+1);
    }
    for(i=6;i<12;i++)// Rond
    {
        pioche[i].forme= 0x09;
        pioche[i].couleur=i+1;
    }
    for(i=12;i<18;i++)// Triangles
    {
        pioche[i].forme= 0x1E;
        pioche[i].couleur=i+1;
    }
    for(i=18;i<24;i++)// Etoiles
    {
        pioche[i].forme= 0x0F;
        pioche[i].couleur=i+1;
    }
    for(i=24;i<30;i++)// Croix
    {
        pioche[i].forme= 0xC5;
        pioche[i].couleur=i+1;
    }
    for(i=30;i<36;i++)// Trèfle
    {
        pioche[i].forme= 0x05;
        pioche[i].couleur=i+1;
    }

}


void definirPiocheNormale(T_TUILE *pioche)
{
    int i;
    int j;
    int ajout=0;
    int X=0;
    int Y=0;

    for(j=0;j<3;j++) //On fait la boucle 3 fois
    {

        for(i=0+ajout;i<6;i++)// Carrés
        {
            pioche[i].forme= 0xDB;
            pioche[i].couleur=i+1;
        }
        for(i=6+ajout;i<12;i++)// Rond
        {
            pioche[i].forme= 0x09;
            pioche[i].couleur=i+1;
        }
        for(i=12+ajout;i<18;i++)// Triangles
        {
            pioche[i].forme= 0x1E;
            pioche[i].couleur=i+1;
        }
        for(i=18+ajout;i<24;i++)// Etoiles
        {
            pioche[i].forme= 0x1E;
            pioche[i].couleur=i+1;
        }
        for(i=24+ajout;i<30;i++)// Croix
        {
            pioche[i].forme= 0xC5;
            pioche[i].couleur=i+1;
        }
        for(i=30+ajout;i<36;i++)// Trèfle
        {
            pioche[i].forme= 0x05;
            pioche[i].couleur=i+1;
        }
     ajout= ajout+36;
    }
}
void retraitPiocheNormale(T_TUILE *pioche,T_TUILE *main)
{
    int i;
    int BS=108;
    srand(time(NULL));
    T_TUILE temp;
    int alea;

    while(BS!=0)
    {
    for(i=0;i<6;i++)
    {
        alea== rand()%BS;

        if (main[i].forme= ' ')
        {
           main[i].forme=pioche[alea].forme;
           temp.forme = pioche[alea].forme;
           pioche[alea].forme=pioche[BS].forme;
           pioche[BS].forme=temp.forme;

           main[i].couleur=pioche[alea].couleur;
           temp.couleur = pioche[alea].couleur;
           pioche[alea].couleur=pioche[BS].couleur;
           pioche[BS].couleur=temp.couleur;

           BS--;
        }

    }
    }
}



void retraitPiocheDegrade(T_TUILE *pioche,T_TUILE *main)
{
    int i;
    int BS=36;
    srand(time(NULL));
    T_TUILE temp;
    int alea;

    while(BS!=0)
    {
    for(i=0;i<6;i++)
    {
        alea== rand()%BS;

        if (main[i].forme= ' ')
        {
           main[i].forme=pioche[alea].forme;
           temp.forme = pioche[alea].forme;
           pioche[alea].forme=pioche[BS].forme;
           pioche[BS].forme=temp.forme;

           main[i].couleur=pioche[alea].couleur;
           temp.couleur = pioche[alea].couleur;
           pioche[alea].couleur=pioche[BS].couleur;
           pioche[BS].couleur=temp.couleur;

           BS--;
        }

    }
    }
}

void gotoligcol(int lig, int col)
{
    COORD mycoord;
    mycoord.X = col;
    mycoord.Y = lig;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), mycoord);
}

void afficherTerrain()
{
    int i,j,k;
    printf("%c", 0xC9);
    for(i=0; i < 25;i++)
    {
        printf("%c%c", 0xCD, 0xCB);
    }
    printf("%c%c\n", 0xCD,0xBB);
    for(i = 0; i < 12; i++)
    {
        for(j=0; j < 26 ;j++)
        {
            printf("%c ", 0xBA);
        }
        printf("%c\n", 0xBA);
        if(i!=11)
        {
            printf("%c", 0xCC);
            for(k=0;k < 25;k++)
            {
                printf("%c%c", 0xCD, 0xCE);
            }
            printf("%c%c\n", 0xCD,0xB9);
        }
    }
    printf("%c", 0xc8);
    for(i = 0;i< 25; i++)
    {
        printf("%c%c", 0xCD, 0xCA);
    }
    printf("%c%c", 0xCD,0xBC);
    gotoligcol(1,1);
}

void deplacerCurseur(int *x, int *y)
{
    char c;
    if(getch() == 224)
    {
        c = getch();
        switch(c)
        {
        case 72:
            *x-= 2;
            break;
        case 80:
            *x+= 2;
            break;
        case 75:
            *y-= 2;
            break;
        case 77:
            *y+= 2;
            break;
        }
    }
    if(*y >= 53)
    {
        *y=1;
    }
    else if(*y <= 0)
    {
        *y+=2;
    }
    else if(*x >= 25)
    {
        *x=1;
    }
    gotoligcol(*x, *y);
}

void afficherMainJoueur()
{
    int i;
    printf("%c", 0xC9);
    for(i=0; i < 25;i++)
    {
        printf("%c%c", 0xCD, 0xCB);
    }
    printf("%c%c\n", 0xCD,0xBB);
    printf("%c",0xCC);

}

void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void afficherNom(T_JOUEUR joueur)
{
    gotoligcol(2, 60);
    printf("C'est a : %s de jouer!\n", joueur.nom);
    gotoligcol(1, 1);
}
