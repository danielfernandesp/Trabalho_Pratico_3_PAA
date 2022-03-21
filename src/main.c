#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers/BMH.h"
#include "headers/shiftAnd.h"
#include "headers/shiftAndAproximado.h" // Para busca no texto parcialmente decifrado
#include "headers/leituraArquivo.h"
#include "headers/frequencia.h"

int main(int argc, char const *argv[]) {

  Analise_frequencia analise_frequencia[26];
  Texto texto;

  char* arquivoEntrada;
  int k;
  char *Padrao = (char*)malloc(sizeof(char)); //memoria dinamicamente alocada para padrao que se desconhece o tamanho
  char nomeArquivo[33]; //Variavel para receber nome de abertura de arquivo

  while(1){

    bool flagParar, inicializado;

    printf("Entre com o nome do arquivo de entrada (.txt): ");
    scanf("%s",nomeArquivo);
    arquivoEntrada =  LeituraArquivo(nomeArquivo); 

    while(!arquivoEntrada){
      printf("Digite o nome do arquivo novamente: ");
      scanf("%s",nomeArquivo);
      arquivoEntrada =  LeituraArquivo(nomeArquivo); 
    }

    if(arquivoEntrada){
      inicializado = false;
      flagParar = 0; 
    }

    while(flagParar!=1){

      int opcao;

      imprime_menu();

      printf("Entre com uma opcao válida\n");
      scanf("%d", &opcao );
      printf("\n");

      switch (opcao)
      {
        case 1:
          if(!inicializado){
            inicializado = inicializa_freq(analise_frequencia);
            inicializa_texto(texto, arquivoEntrada);
            imprime_texto_criptografado(texto);
            imprime_chave(analise_frequencia);
           }else{
            if(!imprime_chave){
              printf("Erro ao imprimir o estado atual de chaves...o programa será encerrado\n");  
              exit(0);
            }else{
              imprime_texto_criptografado(texto);
              imprime_chave(analise_frequencia);
            }
           }
        case 2:
          break;
        default:
          printf("Opcao invalida, tente novamente\n");
      }
    }
  }  


  // opcao 2 -  Análise de frequência
  //conta_letras(analise_frequencia,arquivoEntrada);
  //frequencia(analise_frequencia);
  
  // opcao 3 - Busca no texto criptografado

  //printf("Entre com o padrao: ");
  //scanf("%s",Padrao);

  //int P = strlen(Padrao); // atribuindo o tamanho do padrão entrado, util para o algoritmo SA
  //ShiftAnd(Padrao,arquivoEntrada,P,strlen(arquivoEntrada));

  // opcao 4 - Busca no texto parcialmente decifrado


  /*
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
    if(Operacoes[0] !=1 && Operacoes[0] !=0){
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

  */
  return 0;
}

