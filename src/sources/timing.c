#include "../headers/timing.h"

void IniciarTimer(Timer *timer){
timer->TempoInicial = clock();
}

void PararTimer(Timer *timer){
timer->TempoFinal = clock();
timer->TempoTotal = (double)(timer->TempoFinal - timer->TempoInicial)/CLOCKS_PER_SEC;
}

double TempoTotal(Timer timer){
    return timer.TempoTotal;
}
