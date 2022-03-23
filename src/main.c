#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "headers/shiftAnd.h"
#include "headers/shiftAndAproximado.h"
#include "headers/leituraArquivo.h"
#include "headers/analise.h"

int main(int argc, char const *argv[]) {

  Analise_frequencia analise_frequencia[26];
  Texto texto;

  char *arquivoEntrada;
  char *arquivoFreqTextoPT;
  int k;
  char *padrao = (char*)malloc(sizeof(char)); //memoria dinamicamente alocada para padrao que se desconhece o tamanho
  char nomeArquivo[33]; 
  
  printf("=== TRABALHO 3 - PAA - GRUPO 8 === \n");

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
      arquivoFreqTextoPT = "freq_Lingua_Portuguesa"; 
      arquivoFreqTextoPT = LeituraArquivo(arquivoFreqTextoPT);
      inicializado = false;
      flagParar = 0;
    }

    while(flagParar != 1){

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
            imprime_frequencia_analise(&texto,analise_frequencia);
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
        case 6:
          printf("Saindo ... obrigado por utilizar o programa!\n ");
          exit(0);
          break;
        default:
          printf("Opcao invalida, tente novamente\n");
          break;
      }
    }
  }  
  return 0;
}

