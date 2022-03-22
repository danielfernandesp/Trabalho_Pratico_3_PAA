#ifndef FREQUENCIA_H_INCLUDED
#define FREQUENCIA_H_INCLUDED

#include <stdbool.h>

#define TAMALFABETO 26

typedef struct{
    char letraAlfabeto;
    char letraMapeada;
    int contador;
    float frequencia;
}Analise_frequencia;

typedef struct{
    char *textoOriginal;
    char *textoDecifrado;
    char *posicaoMarcada;
    char *frequenciaAlfabeto;
}Texto;

bool inicializa_texto(Texto *t,char *arquivoEntrada, char *arquivoFreqLinguaPT);
bool inicializa_freq(Analise_frequencia frequencia[TAMALFABETO]);
void imprime_analise(Analise_frequencia frequencia[TAMALFABETO]);
void troca(int *xp, int *yp);

void imprime_menu();

bool imprime_texto_criptografado(Texto *t);
bool imprime_chave(Analise_frequencia frequencia[TAMALFABETO]);
bool imprime_texto_parc_decifrado(Texto *t);
void imprime_frequencia_analise(Texto *t, Analise_frequencia f[TAMALFABETO]);

bool calcula_frequencia(Texto *t, Analise_frequencia frequencia[TAMALFABETO]);

void marcaPosicao(Analise_frequencia f[TAMALFABETO], Texto *t, int inicial, int final, char * padrao);

#endif