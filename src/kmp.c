#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"kmp.h"

/*Procura casamentos utilizando o algoritmo KMP*/
int kmp(Musica msc, Musica trecho){

    int i=0,j=1,dif,pos_inicial=1;
    int tabela[trecho.tam];

    //Cria a tabela de deslocamento e a preenche
    tabela[0]=0;
    while(j < trecho.tam){
        if(comparar_notas(trecho.notas[i].valor,trecho.notas[j].valor,&dif,pos_inicial)){
            tabela[j]= i+1;
            i++;
            j++;
        }
        else if(i != 0){
            i = tabela[i-1];
        }
        else{
            tabela[j] = 0;
            j++;
        }            
    }
    
    //Realiza a busca por casamentos
    i = 0;
    j = 0;
    while(i < msc.tam-trecho.tam+1){
        pos_inicial = 1;
        
        while(comparar_notas(msc.notas[i].valor,trecho.notas[j].valor,&dif,pos_inicial)){
            if(j == trecho.tam-1){
                return i-j;
            }
            pos_inicial = 0;
            j++;
            i++;
        }
        if(j != 0){
            j = tabela[j-1];
        }
        else{
            i++;
        }
    }
    return -1;   
}

/*Executa o metodo BMH para todos os casos*/
void cmd_kmp(Lista l){

    Celula* aux = l.primeiro->prox;
    int achou;
    FILE* fp = NULL;
    fp = fopen("tp3.out","w");
    if (fp == NULL){
        fprintf(stderr, "cmd_kmp : Erro ao abir arquivo de saida\n");
        return;
    }

    while(aux != NULL){

        achou = kmp(aux->c.musica,aux->c.trecho);
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