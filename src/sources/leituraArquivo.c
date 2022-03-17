#include <stdio.h>
#include <stdlib.h>
#include "../headers/leituraArquivo.h"

char* LeituraArquivo(char * Entrada){
  
  FILE * f;
  
  char Buffer[33];  //Buffer para leitura de palavra por palavra
  char * ArqSaida = (char*)calloc(1000000,sizeof(char)); //Variavel para armazenamento de texto.Texto maximo suportado: 1000000 de caracteres;
  f = fopen(Entrada,"r");
  if(f==NULL){
    printf("Erro durante abertura de arquivo!\n");
    return NULL;
  }
  else{
    strcpy(ArqSaida,"\0");  //Inicialmente atribuimos \0 para declarar variaveis string vazias.
    strcpy(Buffer,"\0");
    while(fscanf(f,"%s",Buffer)!=EOF){
      strcat(ArqSaida,Buffer); //Cada palavra lida é concatenada na variavel de texto
      strcat(ArqSaida," "); //Depois de cada palavra é concatenado um espaço
      strcpy(Buffer,"\0"); //Em seguida variavel buffer é declarada vazia denovo
    }
    strcat(ArqSaida,"\0"); //Ao final da leitura, é concatenado no fim da variavel de texto \0 para indicar fim do texto;
    return ArqSaida; //Endereço da variavel texto é retornado.
  }
}