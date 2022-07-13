#include<stdio.h>
#include<stdlib.h>
#include"forcabruta.h"

/*Procura casamentos utilizando o algoritmo forca bruta*/
int forca_bruta(Musica msc, Musica trecho){

    int k,j,dif,pos_inicial;
    for (int i = 0; i < msc.tam-trecho.tam; i++){
        k = i;
        j = 0;
        pos_inicial = 1;
        while(comparar_notas(msc.notas[k].valor,trecho.notas[j].valor,&dif,pos_inicial)){
            
            if(j >= trecho.tam-1){
                return i;
            }
            pos_inicial = 0;
            j++;
            k++;
        }
    }
    return -1;    
}

/*Executa o metodo força bruta para todos os casos*/
void cmd_forca_bruta(Lista l){

    Celula* aux = l.primeiro->prox;
    int achou;
    FILE* fp = NULL;
    fp = fopen("tp3.out","w");
    if (fp == NULL)
    {
        fprintf(stderr, "cmd_forca_bruta : Erro ao abir arquivo de saida\n");
        return;
    }

    while(aux != NULL){

        achou = forca_bruta(aux->c.musica,aux->c.trecho);
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