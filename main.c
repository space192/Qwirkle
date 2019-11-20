#include "prototypes.h"



int main()
{
    T_TUILE pioche[36];

    int BS=36;

    T_TUILE main0[6];
    main0[0].forme= ' ';
    main0[0].couleur=1;
    main0[1].forme= ' ';
    main0[1].couleur=2;
    main0[2].forme= ' ';
    main0[2].couleur=3;
    main0[3].forme= ' ';
    main0[3].couleur=4;
    main0[4].forme= ' ';
    main0[4].couleur=5;
    main0[5].forme= ' ';
    main0[5].couleur=6;


    T_TUILE main1[6];
    main1[0].forme= ' ';
    main1[0].couleur=1;
    main1[1].forme= ' ';
    main1[1].couleur=2;
    main1[2].forme= ' ';
    main1[2].couleur=3;
    main1[3].forme= ' ';
    main1[3].couleur=4;
    main1[4].forme= ' ';
    main1[4].couleur=5;
    main1[5].forme= ' ';
    main1[5].couleur=6;



    T_TUILE main2[6];
    main2[0].forme= ' ';
    main2[0].couleur=1;
    main2[1].forme= ' ';
    main2[1].couleur=2;
    main2[2].forme= ' ';
    main2[2].couleur=3;
    main2[3].forme= ' ';
    main2[3].couleur=4;
    main2[4].forme= ' ';
    main2[4].couleur=5;
    main2[5].forme= ' ';
    main2[5].couleur=6;



    T_TUILE main3[6];
    main3[0].forme= ' ';
    main3[0].couleur=1;
    main3[1].forme= ' ';
    main3[1].couleur=2;
    main3[2].forme= ' ';
    main3[2].couleur=3;
    main3[3].forme= ' ';
    main3[3].couleur=4;
    main3[4].forme= ' ';
    main3[4].couleur=5;
    main3[5].forme= ' ';
    main3[5].couleur=6;



    T_TUILE main4[6];
    main4[0].forme= ' ';
    main4[0].couleur=1;
    main4[1].forme= ' ';
    main4[1].couleur=2;
    main4[2].forme= ' ';
    main4[2].couleur=3;
    main4[3].forme= ' ';
    main4[3].couleur=4;
    main4[4].forme= ' ';
    main4[4].couleur=5;
    main4[5].forme= ' ';
    main4[5].couleur=6;



    T_TUILE main5[6];
    main5[0].forme= ' ';
    main5[0].couleur=1;
    main5[1].forme= ' ';
    main5[1].couleur=2;
    main5[2].forme= ' ';
    main5[2].couleur=3;
    main5[3].forme= ' ';
    main5[3].couleur=4;
    main5[4].forme= ' ';
    main5[4].couleur=5;
    main5[5].forme= ' ';
    main5[5].couleur=6;

    T_TUILE main6[6];
    main6[0].forme= ' ';
    main6[0].couleur=1;
    main6[1].forme= ' ';
    main6[1].couleur=2;
    main6[2].forme= ' ';
    main6[2].couleur=3;
    main6[3].forme= ' ';
    main6[3].couleur=4;
    main6[4].forme= ' ';
    main6[4].couleur=5;
    main6[5].forme= ' ';
    main6[5].couleur=6;

    definirPiocheDegrade(pioche);

    retraitPiocheDegrade(pioche,main0,&BS);
    retraitPiocheDegrade(pioche,main1,&BS);
    retraitPiocheDegrade(pioche,main2,&BS);
    retraitPiocheDegrade(pioche,main3,&BS);
    retraitPiocheDegrade(pioche,main4,&BS);
    retraitPiocheDegrade(pioche,main5,&BS);
    retraitPiocheDegrade(pioche,main6,&BS);


    afficherMainJoueur(main0);
    afficherMainJoueur(main1);
    afficherMainJoueur(main2);
    afficherMainJoueur(main3);
    afficherMainJoueur(main4);
    afficherMainJoueur(main5);
    afficherMainJoueur(main6);






    menu();

    return 0;
}
