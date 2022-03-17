#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers/BMH.h"
#include "headers/shiftAnd.h"
#include "headers/shiftAndAproximado.h" // Para busca no texto parcialmente decifrado
#include "headers/leituraArquivo.h"


int main(int argc, char const *argv[]) {
  int k;
  char *Padrao = (char*)malloc(sizeof(char)); //memoria dinamicamente alocada para padrao que se desconhece o tamanho
  char Entrada[33]; //Variavel para receber nome de abertura de arquivo
  printf("Entre com o nome do arquivo de entrada (.txt): ");
  scanf("%s",Entrada);
  char* Txt = LeituraArquivo(Entrada); //Chamando leitura de arquivo de entrada.
  printf("Entre com o padrao: ");
  scanf("%s",Padrao);
  int Operacoes[3];
  int P = strlen(Padrao); //Atribuindo tamanho do padrao entrado.
  printf("Entre com o tamanho de k: ");
  scanf("%d",&k);
  if(k>=P){ //Caso variavel k sja maior ou igual ao tamanho do padrao, o programa informa sobre condicao de busca
    printf("O tamanho de k é maior ou igual ao tamanho do padrão!\n");
  }
  printf("Deseja utilizar operacao de insercao?\n\t1 - Sim\n\t0 - Nao\n");
  do{
    printf("Entre: ");
    scanf("%d",&Operacoes[0]); //Recebendo escolha do usuario com relacao a opcao de uso de operacao de insercao
    if(Operacoes[0]!=1 && Operacoes[0]!=0){
      printf("Erro! Entrada invalida!\n");
    }
  }while(Operacoes[0]!=1 && Operacoes[0]!=0);

  printf("Deseja utilizar operacao de remocao?\n\t1 - Sim\n\t0 - Nao\n");
  do{
    printf("Entre: ");
    scanf("%d",&Operacoes[1]); //Recebendo escolha do usuario com relacao a opcao de uso de operacao de remocao
    if(Operacoes[1]!=1 && Operacoes[1]!=0){
      printf("Erro! Entrada invalida!\n");
    }
  }while(Operacoes[1]!=1 && Operacoes[1]!=0);

  printf("Deseja utilizar operacao de substituicao?\n\t1 - Sim\n\t0 - Nao\n");
  do{
    printf("Entre: ");
    scanf("%d",&Operacoes[2]); //Recebendo escolha do usuario com relacao a opcao de uso de operacao de substituicao
    if(Operacoes[2]!=1 && Operacoes[2]!=0){
      printf("Erro! Entrada invalida!\n");
    }
  }while(Operacoes[2]!=1 && Operacoes[2]!=0);
  printf("\nAlgoritmo Shift-And Aproximado: \n");
  ShiftAndAproximado(Txt,strlen(Txt),Padrao,P,k,Operacoes); //Chamando algoritmo ShiftAndAprox
  return 0;
}
