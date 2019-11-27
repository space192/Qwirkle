#include "prototypes.h"


void definirPiocheDegrade(T_TUILE *pioche)
{
    int i;
    for(i=0;i<6;i++)// Carrés
    {
        pioche[i].forme = 0xFE;
        pioche[i].couleur=(i+1);
    }
    for(i=6;i<12;i++)//Losange
    {
        pioche[i].forme= 0x04;
        pioche[i].couleur=i-5;
    }
    for(i=12;i<18;i++)// Trèfle
    {
        pioche[i].forme= 0x05;
        pioche[i].couleur=i-11;
    }
    for(i=18;i<24;i++)// Pique
    {
        pioche[i].forme= 0x06;
        pioche[i].couleur=i-17;
    }
    for(i=24;i<30;i++)// Triangle
    {
        pioche[i].forme= 0x1E;
        pioche[i].couleur=i-23;
    }
    for(i=30;i<36;i++)// Croix
    {
        pioche[i].forme= 0x9E;
        pioche[i].couleur=i-29;
    }
}


void definirPiocheNormale(T_TUILE *pioche)
{
    int i;
    int j;
    int k;
    int ajout=0;

    for(j=0;j<3;j++) //On fait la boucle 3 fois
    {

        k=1;
        for(i=(0+ajout);i<(6+ajout);i++)// Carrés
        {
            pioche[i].forme= 0xFE;
            pioche[i].couleur=k;
            k++;

        }
        k=1;
        for(i=(6+ajout);i<(12+ajout);i++)// Losange
        {
            pioche[i].forme= 0x04;
            pioche[i].couleur=k;
            k++;
        }
        k=1;
        for(i=(12+ajout);i<(18+ajout);i++)// Trèfle
        {
            pioche[i].forme= 0x05;
            pioche[i].couleur=k;
            k++;
        }
        k=1;
        for(i=(18+ajout);i<(24+ajout);i++)// Pique
        {
            pioche[i].forme= 0x06;
            pioche[i].couleur=k;
            k++;
        }
        k=1;
        for(i=(24+ajout);i<(30+ajout);i++)// Triangle
        {
            pioche[i].forme= 0x1E;
            pioche[i].couleur=k;
            k++;
        }
        k=1;
        for(i=(30+ajout);i<(36+ajout);i++)// Croix
        {
            pioche[i].forme= 0x9E;
            pioche[i].couleur=k;
            k++;
        }
        k=1;

     ajout= (ajout+36);
    }
}
void retraitPioche(T_TUILE *pioche,T_TUILE main[][6], int *BS, int k)
{
    int i,j, alea;
    srand(time(NULL));
    T_TUILE temp;
    for(j = 0; j < k ; j++)
    {
        if((*BS)!=0)
        {
            for(i=0;i<6;i++)
            {
                alea= rand()%(*BS);
                if(main[j][i].forme == ' ')
                {
                    *BS -= 1;
                    main[j][i].forme=pioche[alea].forme;
                    temp.forme = pioche[alea].forme;
                    pioche[alea].forme=pioche[*BS].forme;
                    pioche[*BS].forme=temp.forme;

                    main[j][i].couleur=pioche[alea].couleur;
                    temp.couleur = pioche[alea].couleur;
                    pioche[alea].couleur=pioche[*BS].couleur;
                    pioche[*BS].couleur=temp.couleur;
                }
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

void afficherTerrain(T_TUILE plateau[12][26])
{
    int i,j,k;
    system("cls");
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
            printf("%c", 0xBA);
            Color(plateau[i][j].couleur,0);
            printf("%c",plateau[i][j].forme);
            Color(15,0);
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

void deplacerCurseur(int *x, int *y, int *num)
{
    int c;
    c = getch();
    switch(c)
    {
    case 224:
    {
        c = getch();
        switch(c)
        {
        case 72:
            *y-= 2;
            break;
        case 80:
            *y+= 2;
            break;
        case 75:
            *x-= 2;
            break;
        case 77:
            *x+= 2;
            break;
        }
        break;
    }
    case 'a': //0
        *num = 0;
        break;
    case 'z': //1
        *num = 1;
        break;
    case 'e': //2
        *num = 2;
        break;
    case 'r': //3
        *num = 3;
        break;
    case 't': //4
        *num = 4;
        break;
    case 'y': //5
        *num = 5;
        break;
    case 'c': //6
        *num = 6;
        break;
    case 'p': //7
        *num = 7;
        break;
    }
    if(*x >= 53)
    {
        *x=1;
    }
    else if(*x <= 0)
    {
        *x+=2;
    }
    else if(*y >= 25)
    {
        *y=1;
    }
    gotoligcol(*y, *x);
}

void afficherMainJoueur(T_TUILE main[][6], int j, int x, int y)
{
    int i,l, m = 25, n = 13;

    gotoligcol(m, n);

    printf("%c", 0xC9);
    for(i=0; i < 5 ; i++)
    {
        printf("%c%c", 0xCD, 0xCB);
    }
    printf("%c%c", 0xCD,0xBB);
    m++;

    gotoligcol(m++, n);
    for(l=0; l<6 ; l++)
    {
        printf("%c", 0xBA);
        Color(main[j][l].couleur, 0);
        printf("%c", main[j][l].forme);
        Color(15, 0);
    }
    printf("%c", 0xBA);
    gotoligcol(m++, n);
    printf("%c", 0xCC);
    for(i=0;i<5;i++)
    {
    printf("%c", 0xCD);
    printf("%c", 0xCE);
    }
    printf("%c", 0xCD);
    printf("%c", 0xB9);
    gotoligcol(m++, n);
    printf("%c", 0xBA);
    printf("%c", 'a');
    printf("%c", 0xBA);
    printf("%c", 'z');
    printf("%c", 0xBA);
    printf("%c", 'e');
    printf("%c", 0xBA);
    printf("%c", 'r');
    printf("%c", 0xBA);
    printf("%c", 't');
    printf("%c", 0xBA);
    printf("%c", 'y');
    printf("%c", 0xBA);
    gotoligcol(m++, n);
    printf("%c",0xC8);
    for(i=0; i < 5;i++)
    {
        printf("%c%c", 0xCD, 0xCA);
    }
    printf("%c%c", 0xCD,0xBC);
    gotoligcol(y,x);
}

void Color(int couleurDuTexte,int couleurDeFond)
{
    HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void afficherNom(T_JOUEUR *joueur, int j)
{
    int i;
    gotoligcol(2, 60);
    for(i=0; i < 20 ; i++)
    {
        printf(" ");
    }
    gotoligcol(2, 60);
    printf("C'est a %s de jouer!\n", joueur[j].nom);
    gotoligcol(1, 1);
}

void Leaderbord(T_JOUEUR *joueur, int x, int y, int nombreJoueurs)
{
    int i,j,k = 16;
    gotoligcol(14, 76);
    printf("Leaderbord");
    gotoligcol(15, 65);
    printf("%c", 0xC9);
    for(i=0 ; i < 29; i++)
    {
        printf("%c", 0xCD);
    }
    printf("%c", 0xBB);
    for(j = 16; j <= 19 ; j++)
    {
        gotoligcol(j, 65);
        printf("%c", 0xBA);
        gotoligcol(j, 95);
        printf("%c", 0xBA);
    }
    gotoligcol(j, 65);
    printf("%c", 0xC8);
    gotoligcol(j, 66);
    for(i = 0; i < 29; i++)
    {
        printf("%c", 0xCD);
    }
    printf("%c", 0xBC);
    for(i = 0 ; i < nombreJoueurs ; i++)
    {
        gotoligcol(k++, 66);
        printf("Le Score du Joueur %d vaut: %d", i+1, joueur->score);
    }
    gotoligcol(y,x);
}

void initialiserMain(T_TUILE main[][6], int nombreJoueurs)
{
    int i,j;
    for(i=0;i<nombreJoueurs;i++)
    {
        for(j=0;j<6;j++)
        {
            main[i][j].forme= ' ';
        }
    }
}

void remplacerTuile(T_TUILE main[][6],T_TUILE *pioche, int j, int *BS)
{
    int i;
    srand(time(NULL));
    T_TUILE temp;
    int alea;
        if((*BS)!=0)
        {
            for(i=0;i<6;i++)
            {
                alea= rand()%(*BS);

                    main[j][i].forme=pioche[alea].forme;
                    temp.forme = pioche[alea].forme;
                    pioche[alea].forme=pioche[*BS].forme;
                    pioche[*BS].forme=temp.forme;

                    main[j][i].couleur=pioche[alea].couleur;
                    temp.couleur = pioche[alea].couleur;
                    pioche[alea].couleur=pioche[*BS].couleur;
                    pioche[*BS].couleur=temp.couleur;

            }
        }
}

void remplirMain(T_TUILE main[][6],T_TUILE *pioche, int j, int *BS)
{
    int i, alea;
    srand(time(NULL));
    T_TUILE temp;
        if((*BS)!=0)
        {
            for(i=0;i<6;i++)
            {
                alea= rand()%(*BS);
                if(main[j][i].forme == ' ')
                {
                    *BS -= 1;
                    main[j][i].forme=pioche[alea].forme;
                    temp.forme = pioche[alea].forme;
                    pioche[alea].forme=pioche[*BS].forme;
                    pioche[*BS].forme=temp.forme;

                    main[j][i].couleur=pioche[alea].couleur;
                    temp.couleur = pioche[alea].couleur;
                    pioche[alea].couleur=pioche[*BS].couleur;
                    pioche[*BS].couleur=temp.couleur;
                }
            }
        }
}

void initialiserPlateau(T_TUILE plateau[][26])
{
    int i,k;
    for(i=0;i<12;i++)
    {
        for(k=0;k<26;k++)
        {
            plateau[i][k].forme= ' ';
            plateau[i][k].couleur= 0;
        }
    }
}

void afficherTuile( T_TUILE main[][6], int i, int k,T_TUILE plateau[12][26],int x,int y)
{
    int l,m;
    l=(x-1)/2;
    m=(y-1)/2;
    Color(main[i][k].couleur, 0);
    printf("%c", main[i][k].forme);
    Color(15, 0);
    plateau[m][l].forme=main[i][k].forme;
    plateau[m][l].couleur=main[i][k].couleur;
    main[i][k].forme = ' ';
    main[i][k].couleur = 0;
}

void afficherTitre()
{
    int i;
    Color(11, 0);
    printf("%c",0xC9);
    for(i=0;i<24;i++)
    {
        printf("%c",0xCD);
    }
    printf("%c\n",0xBB);
    printf("%C-Bienvenue dans Qwirkle-%C\n",0xBA,0xBA);
    printf("%c",0xC8);
    for(i=0;i<24;i++)
    {
        printf("%c",0xCD);
    }
    printf("%c\n\n\n\n",0xBC);

    Color(15, 0);
}
