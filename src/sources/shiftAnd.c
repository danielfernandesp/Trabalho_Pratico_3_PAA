#include "../headers/shiftAnd.h"

int * FazMascara(char * P,int m){  //Realiza o alocamento e preenchimento da mascara do padrao
  int * M;
  M = (int *)calloc(256, sizeof(int)); //128
  for(int i=0;i < m; i++){
    M[P[i]] = M[P[i]] | 1 << (m-i-1);
  }
  return M;
}
void ShiftAnd(char * P, char * T,int m,int n){ //Algoritmo ShiftAnd
  int R;
  int i;
  int * M;
  M = FazMascara(P,m); //Inicialmente é chamado metodo para criar mascara para o padrao
  R = 0;
  for(i = 0; i < n; i++){ //Em seguida busca ShiftAnd é realizada
      R = (((R >> 1) | (1 << (m-1)) ) & M[T[i]]);
      if((R & 1) != 0){
          printf("\t--> Casamento na posicao: %3d <--\n", i - m + 2);
      }
  }
  free(M);
}
