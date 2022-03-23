#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/shiftAnd.h"
#include "../headers/analise.h"

int * FazMascara(char * padrao,int tamanhoPadrao) //Realiza o alocamento e preenchimento da mascara do padrao
{  
  int * M;
  M = (int *)calloc(256, sizeof(int)); //128
  for(int i=0;i < tamanhoPadrao; i++){
    M[padrao[i]] = M[padrao[i]] | 1 << (tamanhoPadrao-i-1);
  }
  return M;
}

void ShiftAnd(Analise_frequencia f[TAMALFABETO], Texto *t, char * padrao, char * texto, int tamanhoPadrao)
{ 
  int tamanhoTexto = strlen(t->textoDecifrado);
  int R, ocorrencias = 0;
  int * M;

  int inicial, final;

  M = FazMascara(padrao,tamanhoPadrao); //Inicialmente é chamado metodo para criar mascara para o padrao
  R = 0;

  for(int i = 0; i < tamanhoTexto; i++){ //Em seguida busca ShiftAnd é realizada
    R = (((R >> 1) | (1 << (tamanhoPadrao-1)) ) & M[t->textoOriginal[i]]);
    if((R & 1) != 0){ // somente onde houve casamento (onde não há sequencias de 0's)  
      //inicial =  i - tamanhoPadrao + 1;
      //final = inicial + tamanhoPadrao - 1;
      //marcaPosicao(f, t, inicial, final, padrao); 
      ocorrencias++;
      printf("\t--> Casamento na posicao: %3d <--\n", i - tamanhoPadrao + 2);
    }
  }
  printf("Ocorrencias: %d\n\n", ocorrencias);
  free(M);
}



     