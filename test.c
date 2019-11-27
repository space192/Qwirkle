#include "prototypes.h"

int test(int x,int y,T_TUILE main[][6],T_TUILE plateau[][26],int joueurActif, int tuileJoueur,int *lockC, int *lockF)
{
    int res1 = 1,res2 = 1,res3 = 1,res4 = 1,i,j,k,*l = NULL, connecte = 0,coleurTuile1=0;
    int colortemp1, colortemp2;
    char formetemp1, formetemp2, formeTuile1;
    for(i=0;i<4;i++)
    {
        switch(i)
        {
        case 0:
            j=1;
            k=0;
            l = &res1;
            break;
        case 1:
            j=-1;
            k=0;
            l = &res2;
            break;
        case 2:
            j=0;
            k=1;
            l = &res3;
            break;
        case 3:
            j=0;
            k=-1;
            l = &res4;
            break;
        }

        formetemp2 = plateau[y+k][x+j].forme;

        while(formetemp2!=' ')
        {
            colortemp1 = main[joueurActif][tuileJoueur].couleur;
            colortemp2 = plateau[y+k][x+j].couleur;
            formetemp1 = main[joueurActif][tuileJoueur].forme;
            formetemp2 = plateau[y+k][x+j].forme;
            if(formetemp1 == formetemp2 && *lockF == 1)
            {
                if(colortemp1 != colortemp2)
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                    connecte=1;
                }
                else if(colortemp1 == colortemp2)
                {
                    *l = 0;
                }
            }
            else if(formetemp1 == formetemp2 && *lockF == 0)
            {
                *l = 0;
            }
            else if(formetemp1 != formetemp2)
            {
                if(colortemp1 != colortemp2)
                {
                    *l = 0;
                }
                else if(colortemp1 == colortemp2)
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                    connecte = 1;
                }
            }
            else if(colortemp1 == colortemp2 && *lockC == 1)
            {
                if(formetemp1 != formetemp2)
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                    connecte = 1;
                }
                else if(formetemp1 == formetemp2)
                {
                    *l = 0;
                }
            }
            else if(colortemp1 == colortemp2 && *lockC == 0)
            {
                *l = 0;
            }
            else if(colortemp1 != colortemp2)
            {
                if(formetemp1 !=formetemp2)
                {
                    *l = 0;
                }
                else if(formetemp1 == formetemp2)
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                    connecte = 1;
                }
            }
            if(plateau[y][x].forme != ' ' && plateau[y][x].couleur != 0)
            {
                *l = 0;
            }
            if(*l == 0)
            {
                if(formetemp2 == ' ' && colortemp2 == 0)
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                }
                else
                {
                    *l = 0;
                }
            }
            if(i==0)
            {
                j++;
            }
            else if(i==1)
            {
                j--;
            }
            else if(i==2)
            {
                k++;
            }
            else if(i==3)
            {
                k--;
            }
        }

    }
    if(res1 == 1 && res2 == 1 && res3 == 1 && res4 == 1 && connecte == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
