#include "prototypes.h"

int test(int x,int y,T_TUILE main,T_TUILE plateau,int joueurActif, int tuileJoueur)
{
    int i = x ,res1,res2,res3,res4;
    while((plateau[y][i+1].forme != ' ' && plateau[y][i+1] < 26) || res1 != 0)
    {
        if(main[joueurActif][tuileJoueur].forme == plateau[y][i+1].forme)
        {
            if(main[joueurActif][tuileJoueur].couleur != plateau[y][i+1].couleur)
            {
                res1 = 1;
            }
            else if(main[joueurActif][tuileJoueur].couleur == plateau[y][i+1].couleur)
            {
                res1 = 0;
            }
        }
        else if(main[joueurActif][tuileJoueur].couleur == plateau[y][i+1].couleur)
        {
            if(main[joueurActif][tuileJoueur].forme != plateau[y][i+1].forme)
            {
                res1 = 1;
            }
            else if(main[joueurActif][tuileJoueur].forme == plateau[y][i+1].forme)
            {
                res1 = 0;
            }
        }
        i++;
    }

    i=x;

    while((plateau[y][i-1].forme != ' ' && plateau[y][i-1] >= 0) || res2 != 0)
    {
        if(main[joueurActif][tuileJoueur].forme == plateau[y][i-1].forme)
        {
            if(main[joueurActif][tuileJoueur].couleur != plateau[y][i-1].couleur)
            {
                res2 = 1;
            }
            else if(main[joueurActif][tuileJoueur].couleur == plateau[y][i-1].couleur)
            {
                res2 = 0;
            }
        }
        else if(main[joueurActif][tuileJoueur].couleur == plateau[y][i-1].couleur)
        {
            if(main[joueurActif][tuileJoueur].forme != plateau[y][i-1].forme)
            {
                res2 = 1;
            }
            else if(main[joueurActif][tuileJoueur].forme == plateau[y][i-1].forme)
            {
                res2 = 0;
            }
        }
        i--;
    }

    i=y;

    while((plateau[i+1][x].forme != ' ' && plateau[i+1][x] < 26) || res3 != 0)
    {
        if(main[joueurActif][tuileJoueur].forme == plateau[i+1][x].forme)
        {
            if(main[joueurActif][tuileJoueur].couleur != plateau[i+1][x].couleur)
            {
                res3 = 1;
            }
            else if(main[joueurActif][tuileJoueur].couleur == plateau[i+1][x].couleur)
            {
                res3 = 0;
            }
        }
        else if(main[joueurActif][tuileJoueur].couleur == plateau[i+1][x]couleur)
        {
            if(main[joueurActif][tuileJoueur].forme != plateau[i+1][x].forme)
            {
                res3 = 1;
            }
            else if(main[joueurActif][tuileJoueur].forme == plateau[i+1][x].forme)
            {
                res3 = 0;
            }
        }
        i++;
    }

    i=y;

    while((plateau[i-1][x].forme != ' ' && plateau[i-1][x] >= 0) || res4 != 0)
    {
        if(main[joueurActif][tuileJoueur].forme == plateau[i-1][x].forme)
        {
            if(main[joueurActif][tuileJoueur].couleur != plateau[i-1][x].couleur)
            {
                res4 = 1;
            }
            else if(main[joueurActif][tuileJoueur].couleur == plateau[i-1][x].couleur)
            {
                res4 = 0;
            }
        }
        else if(main[joueurActif][tuileJoueur].couleur == plateau[i-1][x].couleur)
        {
            if(main[joueurActif][tuileJoueur].forme != plateau[i-1][x].forme)
            {
                res4 = 1;
            }
            else if(main[joueurActif][tuileJoueur].forme == plateau[i-1][x].forme)
            {
                res4 = 0;
            }
        }
        i--;
    }

}
