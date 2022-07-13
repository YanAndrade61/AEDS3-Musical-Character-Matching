#include <stdio.h>
#include <stdlib.h>
#include "shiftand.h"

/*Procura casamentos utilizando o algoritmo Shift-and*/
int shift_and(Musica msc, Musica trecho){
    int c, d, aux, aux2, valormax, M[7][12], R[7] = {0,0,0,0,0,0,0};
    int mult[3] = {1,2,4};

    for(c=0; c<12; c++){
        for(d=0; d<7; d++){
            M[d][c] = 0;
        }
    }

    aux2 = 1;
    for(c=trecho.tam-1; c>-1; c--){
        aux = trecho.notas[c].valor -1;
        if(M[0][aux] == 0){
            M[0][aux] = aux2;
        }
        else{
            M[0][aux] |= aux2;
        }

        for(d=0; d<3; d++){
            if(aux+mult[d]<12){
                M[d+1][aux+mult[d]] = M[0][aux];
            }
            else{
                M[d+1][aux-12+mult[d]] = M[0][aux];
            }
            if(aux-mult[d]>=0){
                M[d+4][aux-mult[d]] = M[0][aux];
            }
            else{
                M[d+4][aux+12-mult[d]] = M[0][aux];
            }
        }

        aux2<<=1;
    }

    valormax = aux2>>1 ;

    for(c=0; c<msc.tam; c++){
        aux = msc.notas[c].valor -1;

        for(d=0; d<7; d++){
            R[d] >>= 1;
            R[d] |= valormax;

            R[d] &= M[d][aux];

            if(R[d]%2 == 1){
                return c - trecho.tam +1;
            }
        }
    }

    return -1; 
}

/*Executa o metodo Shift-and para todos os casos*/
void cmd_shift_and(Lista l){

    Celula* aux = l.primeiro->prox;
    int achou;
    FILE* fp = NULL;
    fp = fopen("tp3.out","w");
    if (fp == NULL)
    {
        fprintf(stderr, "cmd_shift_and : Erro ao abir arquivo de saida\n");
        return;
    }

    while(aux != NULL){

        achou = shift_and(aux->c.musica,aux->c.trecho);
        if(achou != -1){
            fprintf(fp,"S %d\n",achou);
        }
        else{
            fprintf(fp,"N\n");
        }
        aux = aux->prox;
    }
    fclose(fp);

}