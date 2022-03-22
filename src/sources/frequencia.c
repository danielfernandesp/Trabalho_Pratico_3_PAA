#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include "../headers/frequencia.h"

#define TAMALFABETO 26

bool inicializa_texto(Texto *t,char *arquivoEntrada, char *arquivoFreqLinguaPT){

  if(arquivoEntrada){
    t->textoOriginal = (char* )calloc(1000000,sizeof(char));
    t->textoDecifrado = (char*)calloc(1000000,sizeof(char));
    t->posicaoMarcada = (char*)calloc(1000000,sizeof(char));
    for(int i = 0; arquivoEntrada[i] != '\0'; i++){
      t->textoOriginal[i] = arquivoEntrada[i];
      t->textoDecifrado[i] = arquivoEntrada[i];
      t->posicaoMarcada[i] = ' ';
    }
  }else{
    return false;
  }
  
  if(arquivoFreqLinguaPT){
    t->frequenciaAlfabeto = (char*)calloc(1000000,sizeof(char));
    for(int i=0; arquivoFreqLinguaPT[i] != '\0' ;i++){
      t->frequenciaAlfabeto[i] = arquivoFreqLinguaPT[i];
    }
  }else{
    return false;
  }

  return true;
}

bool inicializa_freq(Analise_frequencia frequencia[TAMALFABETO]){

  for(int i='A'; i<='Z'; i++){  
      frequencia[i].letraAlfabeto = i;
      frequencia[i].letraMapeada = ' ';
      frequencia[i].contador = 0;
  }
  
  return true;
}

void conta_letras(Analise_frequencia frequencia[TAMALFABETO],Texto *t)
{
  int  j;
  for(int i = 'A'; i <= 'Z'; i++) {
        for(int j = 0; t->textoOriginal[j] != '\0'; j++)
        {
          if(t->textoOriginal[j]==i || t->textoOriginal[j] == tolower(i))
            frequencia[i].contador += 1;
      }
  }
}

bool imprime_texto_criptografado(Texto *t)
{
    
  printf("=== Texto Criptografado ===\n");

  for(int i = 0; t->textoOriginal[i] != '\0'; i++){
    printf("%c", t->textoOriginal[i]);
  }

  printf("\n");

  return true;
}

bool imprime_chave(Analise_frequencia frequencia[TAMALFABETO])
{

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

bool imprime_texto_parc_decifrado(Texto *t)
{

  printf("=== TEXTO PARCIALMENTE DECIFRADO ===\n");

  for(int i = 0; t->textoDecifrado[i] != '\0'; i++){
    printf("%c", t->textoDecifrado[i]);
  }

  printf("\n");

  for(int i = 0; t->textoDecifrado[i] != '\0'; i++){
    printf("%c", t->posicaoMarcada[i]);
  }

  printf("\n");
  
  return true;

}


bool calcula_frequencia(Texto *t, Analise_frequencia frequencia[TAMALFABETO])
{
  
  int  j;
  int aux = 0;

  // Pesquisa letras diferentes do texto
  for(int i = 'A'; i <= 'Z'; i++) { 
    for(int j = 0; t->textoOriginal[j] != '\0'; j++)
    {
      if(t->textoOriginal[j]==i || t->textoOriginal[j] == tolower(i)) 
      {
        frequencia[i].contador += 1;
        aux = aux + frequencia[i].contador;
      }
    }
  }

  //Calcula porcentagem para cada letra 
  for(int i = 'A'; i <= 'Z'; i++) {
      for(int j = 0; t->textoOriginal[j] != '\0'; j++){
        if(t->textoOriginal[j]==i || t->textoOriginal[j] == tolower(i)){
            frequencia[i].frequencia =100.0*frequencia[i].contador/aux; // Cálculo da porcentagem
          }
      }
  }
  return true;
}


void marcaPosicao(Analise_frequencia f[TAMALFABETO], Texto *t, int inicial, int final, char * padrao)
{
  for(int i = 0; t->textoOriginal[i] != '\0'; i++){
    if(i == inicial || i == final){ 
      for(int j = 'A'; j <= 'Z'; j++){
        if(f[j].letraAlfabeto == padrao[i])
          f[j].letraMapeada = padrao[i];
      }
      t->posicaoMarcada[i] = '^';
      t->textoDecifrado[i] = t->textoOriginal[i];
    }
  }

  /*
  // Prencheer CHAVE de acordo com a frequencia das letras no texto
  for(int i = 'A'; i <= 'Z'; i++) { 
    for(int j = 0; t->textoOriginal[j] != '\0'; j++)
    {
      if(f[i].contador > 0){
        
      }
    }
  }*/
} 




/*
void imprime_frequencia_analise(Texto *t, Analise_frequencia frequencia[TAMALFABETO])
{
  
  struct Analise_frequencia af_temp;

  int aux;

  printf("Letra,\tCont.,\tFreq.\n");
 
  for(int i='B'; i < 'Z';i++){
      for (int j = 'A'; j <= 'Z'; j++) {
        if(f[i].contador > 0){ // Imprime somente onde há frequencias registradas
          if (f[i].contador > f[i + 1].contador) {
            aux =  f[i].contador;
            f[i].contador =  f[i + 1].contador;
            f[i+1].contador = aux;
          }
      printf("%c\t",f[i].letraAlfabeto);
      printf("%d\t",f[i].contador);
      printf("%2.f %%\t \n",f[i].frequencia);
        }
    }
  }

  printf("\n");
}*/

void imprime_menu(){
    printf("Opções:\n");
    printf("1 - Apresentar o estado atual da criptoanálise \n");
    printf("2 - Fazer análise de frequência no texto criptografado \n");
    printf("3 - Realizar casamento exato de caracteres no texto criptografado \n");
    printf("4 - Realizar casamento aproximado de caracteres no texto parcialmente decifrado \n");
    printf("5 - Alterar chave de criptografia \n");
    printf("6 - Exportar resultado e encerrar o programa \n");
}

