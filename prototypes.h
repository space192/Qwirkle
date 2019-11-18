#ifndef PROTOTYPES_H_INCLUDED
#define PROTOTYPES_H_INCLUDED
#include "constantes.h"
void menu();

void definirPiocheDegrade(T_TUILE* pioche[36]);

void definirPiocheNormale(T_TUILE* pioche[108]);

void retraitPiocheNormale(T_TUILE* pioche[108],T_TUILE* main[6]);

void retraitPiocheDegrade(T_TUILE* pioche[36],T_TUILE* main[6]);

#endif // PROTOTYPES_H_INCLUDED
