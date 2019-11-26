#include "prototypes.h"

int test(int x,int y,T_TUILE main[][6],T_TUILE plateau[][26],int joueurActif, int tuileJoueur)
{
    int res1 = 0,res2 = 1,res3 = 1,res4 = 1;
    int colortemp1, colortemp2;
    char formetemp1, formetemp2;

    colortemp1 = main[joueurActif][tuileJoueur].couleur;
    colortemp2 = plateau[y][x+1].couleur;
    formetemp1 = main[joueurActif][tuileJoueur].forme;
    formetemp2 = plateau[y][x+1].forme;
    if(formetemp1 == formetemp2)
    {
        if(colortemp1 != colortemp2)
        {
            res1 = 1;
        }
        else if(colortemp1 == colortemp2)
        {
            res1 = 0;
        }
    }
    else if(formetemp1 != formetemp2)
    {
        if(colortemp1 != colortemp2)
        {
            res1 = 0;
        }
        else if(colortemp1 == colortemp2)
        {
            res1 = 1;
        }
    }
    else if(colortemp1 == colortemp2)
    {
        if(formetemp1 != formetemp2)
        {
            res1 = 1;
        }
        else if(formetemp1 == formetemp2)
        {
            res1 = 0;
        }
    }
    else if(colortemp1 != colortemp2)
    {
        if(formetemp1 !=formetemp2)
        {
            res1 = 0;
        }
        else if(formetemp1 == formetemp2)
        {
            res1 = 1;
        }
    }
    if(plateau[y][x].forme != ' ' && plateau[y][x].couleur != 0)
    {
        res1 = 0;
    }
    return res1;
}
