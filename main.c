#include "prototypes.h"



int main()
{

    T_TUILE main[6];
    T_TUILE pioche[36];
    main[0].forme= ' ';
    main[0].couleur=1;
    main[1].forme= ' ';
    main[1].couleur=2;
    main[2].forme= ' ';
    main[2].couleur=3;
    main[3].forme= ' ';
    main[3].couleur=4;
    main[4].forme= 	' ';
    main[4].couleur=5;
    main[5].forme= ' ';
    main[5].couleur=6;
    afficherMainJoueur(&main);


    definirPiocheDegrade(&pioche);
    retraitPiocheDegrade(&pioche,&main);
    afficherMainJoueur(&main);
    menu();

    return 0;
}
