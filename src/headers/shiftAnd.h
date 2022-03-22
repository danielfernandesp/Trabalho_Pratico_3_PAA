#ifndef SHITFAND_H_INCLUDED
#define SHITFAND_H_INCLUDED

#include "frequencia.h"

int * FazMascara(char *padrao,int tamanhoPadrao);
void ShiftAnd(Analise_frequencia f[TAMALFABETO], Texto *t, char * padrao, char * texto, int tamanhoPadrao);
#endif
