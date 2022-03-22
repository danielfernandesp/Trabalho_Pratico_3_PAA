#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers/BMH.h"
#include "headers/shiftAnd.h"
#include "headers/shiftAndAproximado.h"
#include "headers/leituraArquivo.h"
#include "headers/frequencia.h"

int main(int argc, char const *argv[]) {

  Analise_frequencia analise_frequencia[26];
  Texto texto;

  char *arquivoEntrada;
  char *arquivoFreqTextoPT;
  int k;
  char *padrao = (char*)malloc(sizeof(char)); //memoria dinamicamente alocada para padrao que se desconhece o tamanho
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
      strcpy(nomeArquivo,'freq_Lingua_Portuguesa');
      printf("%s", nomeArquivo);
      arquivoFreqTextoPT = LeituraArquivo(nomeArquivo);
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
            inicializa_texto(&texto, arquivoEntrada,arquivoFreqTextoPT);
            imprime_texto_criptografado(&texto);
            imprime_chave(analise_frequencia);
            imprime_texto_parc_decifrado(&texto);
            break;
           }else{
            if(!imprime_chave){
              printf("ERRO: imprimir o estado atual de chaves...o programa será encerrado\n");  
              exit(0);
            }else{
              imprime_texto_criptografado(&texto);
              imprime_chave(analise_frequencia);
              imprime_texto_parc_decifrado(&texto);
              break;
            }
           }
        case 2:
          if(calcula_frequencia(&texto,analise_frequencia)){
            printf("Análise concluída\n");
            //imprime_frequencia_analise(&texto,analise_frequencia);
          }else{
            printf("ERRO: Não foi possível fazer a análise de frequência no texto criptografado \n");
            break;
          }
          break;
        case 3: //shift and aprox
          if(inicializado){
            printf("Qual o padrão utilizado?\n ");
            scanf("%s",padrao);
            int tamanhoPadrao = strlen(padrao);
            ShiftAnd(analise_frequencia, &texto,padrao,arquivoEntrada,tamanhoPadrao); 
            break;
          }
        default:
          printf("Opcao invalida, tente novamente\n");
      }
    }
  }  

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

