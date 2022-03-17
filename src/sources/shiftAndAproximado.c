#include <stdio.h>
#include <stdlib.h>
#include "../headers/shiftAndAproximado.h"

void ShiftAndAproximado(TipoTexto T, long n, TipoPadrao P, long m, long k,int Operacoes[]){
long Masc[MAXCHAR],i,j,Ri,Rant,Rnovo;
long R[ NUMMAXERROS + 1];

    for (i = 0;i < MAXCHAR;i++){ //Preparação de mascara.
        Masc[i] = 0;
    }
    for (i = 1;i <= m;i++){
        Masc[P[i -1] + 127] |= 1 << (m - i);
    }
    R[0] = 0;
    Ri = 1 << (m - 1);
    for (j = 1;j <= k;j++){
        R[j] = (1 << (m - j)) | R[j -1];
    }
    for (i = 0;i < n; i++){ //Inicio de pesquisa
        Rant = R[0];
        Rnovo = ((((unsigned long)Rant) >> 1) | Ri) & Masc[T[i] + 127];
        R[0] = Rnovo;
    for (j = 1;j <= k;j++){
        Rnovo = ((((unsigned long)R[j]) >> 1) & Masc[T[i] + 127]) | (Rant*Operacoes[0]) | (((unsigned long) ((Rant*Operacoes[2])) | (Rnovo*Operacoes[1])) >> 1);
        //Ao final da linha acima Rant corresponde a operacoes de insercao, o segundo Rant corresponde a operacoes de substituicao e Rnovo corresponde a operacoes de remocao
        //Cada uma das tres posicoes no vetor Operacoes[] pode ser 0 ou 1. 1 para ativar a operacao que multiplica, 0 para destivar.
        Rant = R[j];
        R[j] = Rnovo | Ri ;
    }
    if ((Rnovo & 1) != 0){
        printf("\t--> Casamento na posicao: %12ld <--\n",i + 1);
    }
    }
}