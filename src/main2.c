#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "headers/BMH.h"
#include "headers/shiftAnd.h"
#include "headers/timing.h"
#include "headers/leituraArquivo.h"
#define DEBUG 1

int main(int argc, char const *argv[]) {
  Timer timer;  //Variavel para temporizacao
  char *Padrao = (char*)malloc(sizeof(char));  //memoria dinamicamente alocada para padrao que se desconhece o tamanho
  char Entrada[33]; //Variavel para receber nome de abertura de arquivo
  printf("Entre com o nome do arquivo de entrada (.txt): ");
  scanf("%s",Entrada);
  char* Txt = LeituraArq(Entrada);   //Chamando leitura de arquivo de entrada.
  printf("Entre com o padrao: ");
  scanf("%s",Padrao);
  int P = strlen(Padrao);  //Atribuindo tamanho do padrao entrado.
  printf("\nAlgoritmo Shift-And: \n");
  if(DEBUG){
    IniciarTimer(&timer);  //Caso DEBUG esteja ativado, tempo é computado e impresso
    ShiftAnd(Padrao,Txt,P,strlen(Txt));  //Chamando algoritmo ShiftAnd
    PararTimer(&timer);
    printf("\n-> O tempo de execucao do algoritmo Shift-And foi de %lf segundos\n\n", TempoTotal(timer));
  }
  else{
    ShiftAnd(Padrao,Txt,P,strlen(Txt));
  }
  printf("\nAlgoritmo BMH: \n");
  if(DEBUG){
    IniciarTimer(&timer); //Caso DEBUG esteja ativado, tempo é computado e impresso
    BMH(Txt,strlen(Txt),Padrao,P); //Chamando algoritmo BMH
    PararTimer(&timer);
    printf("\n-> O tempo de execucao do algoritmo BMH foi de %lf segundos\n\n", TempoTotal(timer));
  }
  else{
    BMH(Txt,strlen(Txt),Padrao,P);
  }

  free(Txt);  //Liberando memoria dinamica usada pelo texto de entrada.
  return 0;
}
