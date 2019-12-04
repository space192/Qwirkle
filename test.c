#include "prototypes.h"

int test(int x,int y,T_TUILE main[][6],T_TUILE plateau[][27],int joueurActif, int tuileJoueur,int *lockC, int *lockF, int *pscore)
{
    int res1 = 1,res2 = 1,res3 = 1,res4 = 1,i,j,k,*l = NULL, connecte = 0,coleurTuile1=0, lockFtemp= 1, lockCtemp=1;
    int colortemp1, colortemp2, score =0;
    char formetemp1, formetemp2, formeTuile1;
    for(i=0;i<4;i++)
    {
        *pscore = 0;
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

        while((formetemp2!=' ' && colortemp2 != 0) && (*l!=0))
        {
            colortemp1 = main[joueurActif][tuileJoueur].couleur;
            colortemp2 = plateau[y+k][x+j].couleur;
            formetemp1 = main[joueurActif][tuileJoueur].forme;
            formetemp2 = plateau[y+k][x+j].forme;
            if(formetemp1 == formetemp2 && *lockF == 1&& *l == 1) //lockF = 1
            {
                if(colortemp1 != colortemp2)
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                    connecte=1;
                    *lockC= 0;
                    score++;
                }
                else if(colortemp1 == colortemp2)
                {
                    *l = 0;
                }
            }
            else if(formetemp1 == formetemp2 && *lockF == 0 && *l == 1)
            {
                *l = 0;
            }
            else if(formetemp1 != formetemp2 && *l == 1)
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
                    *lockC= 0;
                    score++;
                }
            }
            else if(colortemp1 == colortemp2 && *lockC == 1 && *l == 1)
            {
                if(formetemp1 != formetemp2 )
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                    connecte = 1;
                    *lockF= 0;
                    score++;
                }
                else if(formetemp1 == formetemp2)
                {
                    *l = 0;
                }
            }
            else if(colortemp1 == colortemp2 && *lockC == 0 && *l == 1)
            {
                *l = 0;
            }
            else if(colortemp1 != colortemp2 && *l == 1)
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
                    *lockF= 0;
                    score++;
                }
            }
            if(*l == 0)
            {
                if(formetemp2 == ' ' && colortemp2 == 0)
                {
                    *l = 1;
                    formeTuile1 = formetemp2;
                    coleurTuile1 = colortemp2;
                    score++;
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
        *pscore = *pscore + score;
        return 1;
    }
    else
    {
        *pscore = 0;
        return 0;
    }
}
