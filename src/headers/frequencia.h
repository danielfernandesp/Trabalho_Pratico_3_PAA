#ifndef FREQUENCIA_H_INCLUDED
#define FREQUENCIA_H_INCLUDED

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
}Texto;

bool inicializa_texto(Texto t,char *arquivoEntrada);
bool inicializa_freq(Analise_frequencia frequencia[TAMALFABETO]);
void conta_letras(Analise_frequencia frequencia[TAMALFABETO], char *ArquivoEntrada);
//void frequencia(Analise_frequencia frequencia[TAMALFABETO]);
void imprime_analise(Analise_frequencia frequencia[TAMALFABETO]);
void troca(int *xp, int *yp);

void imprime_menu();
bool imprime_chave(Analise_frequencia frequencia[TAMALFABETO]);
bool imprime_texto_criptografado(Texto t);

#endif