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
    char matriz[2][200];
}Texto;

bool inicializa_texto(Texto *t,char *arquivoEntrada, char *arquivoFreqLinguaPT);
void imprime_analise(Analise_frequencia f[TAMALFABETO]);
bool inicializa_freq(Analise_frequencia f[TAMALFABETO]);
void imprime_menu();
bool imprime_texto_criptografado(Texto *t);
bool imprime_chave(Analise_frequencia f[TAMALFABETO]);
bool imprime_texto_parc_decifrado(Texto *t);
void imprime_frequencia_analise(Texto *t, Analise_frequencia f[TAMALFABETO]);

bool calcula_frequencia(Texto *t, Analise_frequencia f[TAMALFABETO]);
#endif