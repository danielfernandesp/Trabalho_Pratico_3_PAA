#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/frequencia.h"

#define TAMALFABETO 26


bool inicializa_texto(Texto t,char *arquivoEntrada){

  if(arquivoEntrada){
    t.textoOriginal = (char*)calloc(1000000,sizeof(char)); 
    for(int i = 0; arquivoEntrada[i] != '\0'; i++){
      t.textoOriginal[i] = arquivoEntrada[i];
      printf("%c", t.textoOriginal[i]);
    }
  }
  return true;
}

bool inicializa_freq(Analise_frequencia frequencia[TAMALFABETO]){

    for(int i='A'; i<='Z'; i++){
        frequencia[i].letraAlfabeto = i;
        frequencia[i].letraMapeada = ' ';
        frequencia[i].contador = 0;
        //printf("%c \n", frequencia[i].letraAlfabeto);
        //printf("%c \n", frequencia[i].letraMapeada);
    }

    return true;
}

void conta_letras(Analise_frequencia frequencia[TAMALFABETO], char *ArquivoEntrada){
  int  j;
  for(int i = 'A'; i <= 'Z'; i++) {
        for(int j = 0; ArquivoEntrada[j] != '\0'; j++)
        {
          if(ArquivoEntrada[j]==i || ArquivoEntrada[j] == tolower(i))
          {
          frequencia[i].contador += 1;
          }
      }
  }
}


bool imprime_texto_criptografado(Texto t){
    
  printf("=== Texto Criptografado ===\n");

  for(int i = 0; t.textoOriginal[i] != '\0'; i++){
    printf("%c", t.textoOriginal[i]);
  }

  printf("\n");

  return true;
}

bool imprime_chave(Analise_frequencia frequencia[TAMALFABETO]){
    
    printf("=== CHAVE ===\n");

    for(int i='A'; i <='Z';i++){
      printf("%c",frequencia[i].letraAlfabeto);
    }
    printf("\n");
    for(int i='A'; i <='Z';i++){
      printf("%c",frequencia[i].letraMapeada);
    }
    printf("\n");
    return true;
}

void imprime_menu(){
    printf("Opções:\n");
    printf("1 - Apresentar o estado atual da criptoanálise \n");
    printf("2 - Fazer análise de frequência no texto criptografado \n");
    printf("3 - Realizar casamento exato de caracteres no texto criptografado \n");
    printf("4 - Realizar casamento aproximado de caracteres no texto parcialmente decifrado \n");
    printf("5 - Alterar chave de criptografia \n");
    printf("6 - Exportar resultado e encerrar o programa \n");
}

/*void frequencia(Analise_frequencia frequencia[TAMALFABETO]){

    int contador=0;
    for(int i='A'; i <='Z';i++){
      contador += frequencia[i].contador;
    }
    float aux = 0;
    /*for(int i='A'; i <='Z';i++){
      if(frequencia[i].contador > 0){
        aux = frequencia[i].contador/contador;
        printf("%f %%\n",aux);
      }
    }
}*/


/* 
void imprime_analise(Analise_frequencia frequencia[TAMALFABETO]){
    
   int k, j, aux;

    for (k = 'A' ; k < 'Z'; k++) {
        for (j = 'A'; j < 'Z' - 1; j++) {
            if (frequencia[j].contador > frequencia[j + 1].contador){
                aux          = frequencia[j].contador;
                frequencia[j].contador     = frequencia[j + 1].contador;
                frequencia[j + 1].contador = aux;
            }
        }
        printf("%c %d\n",frequencia[k].letraAlfabeto, frequencia[k].contador );
    }
}*/