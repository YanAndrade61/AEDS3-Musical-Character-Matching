#include<stdio.h>
#include<stdlib.h>
#include"bmh.h"
#define MaxTamAlfabeto 12

/*Procura casamentos utilizando o algoritmo BMH*/
int bmh(Musica msc, Musica trecho){

    int i,k,j,dif,aux,pos_inicial;
    int tabela[MaxTamAlfabeto];
    int mult[] = {1,2,4};

    //Cria a tabela de deslocamento e a preenche 
    for (j = 0; j < MaxTamAlfabeto; j++){
        tabela[j] = trecho.tam;
    }
    for (j = 0; j < trecho.tam-1; j++){
        aux = trecho.notas[j].valor-1;
        tabela[aux] = trecho.tam-j-1; 

        for (i = 0; i < 3; i++){
            if(aux+mult[i]<12){
                tabela[aux+mult[i]] = trecho.tam-j-1;
            }
            else{
                tabela[aux-12+mult[i]] = trecho.tam-j-1;
            }
            if(aux-mult[i]>=0){
                tabela[aux-mult[i]] = trecho.tam-j-1;
            }
            else{
                tabela[aux+12-mult[i]] = trecho.tam-j-1;
            }
        }       
    }
    i = trecho.tam-1;

    //Realiza a busca por casamentos
    while(i < msc.tam){
        k = i;
        j = trecho.tam-1;
        pos_inicial = 1;
        while(comparar_notas(msc.notas[k].valor,trecho.notas[j].valor,&dif,pos_inicial) && (j>=0)){
            if(j == 0){
                return k;
            }
            pos_inicial = 0;
            j--;
            k--;
        }
        i = i + tabela[msc.notas[i].valor-1];
    }
    return -1;   
}

/*Executa o metodo BMH para todos os casos*/
void cmd_bmh(Lista l){

    Celula* aux = l.primeiro->prox;
    int achou;
    FILE* fp = NULL;
    fp = fopen("tp3.out","w");
    if (fp == NULL)
    {
        fprintf(stderr, "cmd_bmh : Erro ao abir arquivo de saida\n");
        return;
    }

    while(aux != NULL){

        achou = bmh(aux->c.musica,aux->c.trecho);
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
