#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"entrada.h"

/*Le o arquivo de entrada e retorna uma lista com os casos*/
Lista entrada(char* nome){

    FILE* fp;
    Lista lista;
    Caso aux;
    Musica musica;
    Musica trecho;
    int M,T,cont=0;
    char linha[1000000];

    fp = fopen(nome,"r");
    if(fp == NULL){
        fprintf(stderr, "entrada : Erro ao abir arquivo de entrada\n");
        exit(EXIT_FAILURE);
    }
    criaL(&lista);

    while(!feof(fp)){
        
        fgets(linha,1000000,fp);
        sscanf(linha,"%d %d\n",&M,&T);
        if(M == 0 && T == 0){
            break;
        }
        //Pega a musica
        fgets(linha,1000000,fp);
        musica = criaM(M,linha);
        fgets(linha,1000000,fp);
        trecho = criaM(T,linha);
        aux = criaI(T,M,musica,trecho);
        insereI(aux,&lista);
        cont++;
    }
    lista.tam = cont;
    fclose(fp);
    return lista;

};