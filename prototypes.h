#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED

void menu();

void definirPiocheDegrade(T_TUILES* pioche[36]);

void definirPiocheNormale(T_TUILES* pioche[108]);

void retraitPiocheNormale(T_TUILES* pioche[108],T_TUILES* main[6]);

void retraitPiocheDegrade(T_TUILES* pioche[36],T_TUILES* main[6]);

#endif // PROTOTYPES_H_INCLUDED
