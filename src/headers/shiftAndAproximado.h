#ifndef SHITFANDAPROXIMADO_H_INCLUDED
#define SHITFANDAPROXIMADO_H_INCLUDED

// Macros
#define MAXTAMTEXTO 1000
#define MAXTAMPADRAO 10
#define MAXCHAR 256 
#define NUMMAXERROS 10

typedef char TipoTexto [MAXTAMTEXTO];
typedef char TipoPadrao[MAXTAMPADRAO];
void shiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, long k,int Operacoes[]);

#endif