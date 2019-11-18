#include "constantes.h"
#include "prototypes.h"

void definirPiocheDegrade(T_TUILE* pioche[36])
{
    int i;
    int X=0;
    int Y=0;

    for(i=0;i<6;i++)// Carrés
    {
        pioche[i]->forme= '0xDB';
        pioche[i]->couleur=i+1;
    }
    for(i=6;i<12;i++)// Rond
    {
        pioche[i]->forme= '0x09';
        pioche[i]->couleur=i+1;
    }
    for(i=12;i<18;i++)// Triangles
    {
        pioche[i]->forme= '0x1E';
        pioche[i]->couleur=i+1;
    }
    for(i=18;i<24;i++)// Etoiles
    {
        pioche[i]->forme= '0x0F';
        pioche[i]->couleur=i+1;
    }
    for(i=24;i<30;i++)// Croix
    {
        pioche[i]->forme= '0xC5';
        pioche[i]->couleur=i+1;
    }
    for(i=30;i<36;i++)// Trèfle
    {
        pioche[i]->forme= '0x05';
        pioche[i]->couleur=i+1;
    }
}


void definirPiocheNormale(T_TUILE* pioche[108])
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
            pioche[i]->forme= '0xDB';
            pioche[i]->couleur=i+1;
        }
        for(i=6+ajout;i<12;i++)// Rond
        {
            pioche[i]->forme= '0x09';
            pioche[i]->couleur=i+1;
        }
        for(i=12+ajout;i<18;i++)// Triangles
        {
            pioche[i]->forme= '0x1E';
            pioche[i]->couleur=i+1;
        }
        for(i=18+ajout;i<24;i++)// Etoiles
        {
            pioche[i]->forme= '0xOF';
            pioche[i]->couleur=i+1;
        }
        for(i=24+ajout;i<30;i++)// Croix
        {
            pioche[i]->forme= '0xC5';
            pioche[i]->couleur=i+1;
        }
        for(i=30+ajout;i<36;i++)// Trèfle
        {
            pioche[i]->forme= '0x05';
            pioche[i]->couleur=i+1;
        }
     ajout= ajout+36;
    }

void retraitPiocheNormale(T_TUILE* pioche[108],T_TUILE* main[6])
{
    int i;
    int BS=108;
    srand(time(NULL));
    T_TUILE* temp;
    int alea;

    while(BS!=0)
    {
    for(i=0;i<6;i++)
    {
        alea== rand()%BS;

        if (main[i]->forme= ' ')
        {
           main[i]->forme=pioche[alea]->forme;
           temp->forme = pioche[alea]->forme;
           pioche[alea]->forme=pioche[BS]->forme;
           pioche[BS]->forme=temp->forme;

           main[i]->couleur=pioche[alea]->couleur;
           temp->couleur = pioche[alea]->couleur;
           pioche[alea]->couleur=pioche[BS]->couleur;
           pioche[BS]->couleur=temp->couleur;

           BS--;
        }

    }
    }
}



void retraitPiocheDegrade(T_TUILE* pioche[36],T_TUILE* main[6])
{
    int i;
    int BS=36;
    srand(time(NULL));
    T_TUILE* temp;
    int alea;

    while(BS!=0)
    {
    for(i=0;i<6;i++)
    {
        alea== rand()%BS;

        if (main[i]->forme= ' ')
        {
           main[i]->forme=pioche[alea]->forme;
           temp->forme = pioche[alea]->forme;
           pioche[alea]->forme=pioche[BS]->forme;
           pioche[BS]->forme=temp->forme;

           main[i]->couleur=pioche[alea]->couleur;
           temp->couleur = pioche[alea]->couleur;
           pioche[alea]->couleur=pioche[BS]->couleur;
           pioche[BS]->couleur=temp->couleur;

           BS--;
        }

    }
    }
}






