#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/*Cria item*/
Caso criaI(int tamT, int tamM, Musica musica, Musica trecho){
    Caso c;    
    c.tamM = tamM;
    c.tamT = tamT;
    c.musica = musica;
    c.trecho = trecho;

    return c;
}

/*Cria lista vazia*/
void criaL(Lista* l){
    l->primeiro = (Celula*)malloc(sizeof(Celula));
    l->ultimo=l->primeiro;
    l->ultimo->prox = NULL;
}

/*Verifica se a lista esta vazia*/
int vaziaL(Lista l){
    return (l.primeiro == l.ultimo);
}

/*Insere o Caso na lista*/
void insereI(Caso x,Lista* l){
    l->ultimo->prox = (Celula*)malloc(sizeof(Celula));
    l->ultimo = l->ultimo->prox;
    l->ultimo->c = x;
    l->ultimo->prox = NULL; 
}

/*Retira Caso da lista*/
void retiraI(Celula* C, Lista* l, Caso* x){
    
    Celula* aux = C->prox;

    *x = aux->c;
    C->prox = aux->prox;
    if(C->prox == NULL){
        l->ultimo = C;
    }
    free(aux);
}

/*Destroi item*/
void destroiI(Caso c){

    free(c.musica.notas);
    free(c.trecho.notas);

}

/*Destroi lista*/
void destroiL(Lista* l){

    Celula* aux = l->primeiro->prox;

    while(aux != NULL){
        destroiI(aux->c);
        free(l->primeiro);
        l->primeiro = aux;
        aux = aux->prox;
    }    
    if (l->primeiro != NULL){
        free(l->primeiro);
    }
}

/*Imprime lista no terminal*/
void imprimeL(Lista* l){

    Celula* auxC = l->primeiro->prox;

    while(auxC != NULL)
    {
        printf("%d %d\n",auxC->c.tamM,auxC->c.tamT);
        imprimeM(auxC->c.musica);
        imprimeM(auxC->c.trecho);
        auxC = auxC->prox;
    }
}