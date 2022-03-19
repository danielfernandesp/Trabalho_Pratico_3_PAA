#ifndef TIMING_H
#define TIMING_H

#include <time.h>

typedef struct {
    clock_t TempoInicial;
    clock_t TempoFinal;
    double TempoTotal;
} Timer;
void IniciarTimer(Timer *timer);
void PararTimer(Timer *timer);
double TempoTotal(Timer timer);

#endif

//Funcoes e estruturas para exibicao do tempo de execucao
