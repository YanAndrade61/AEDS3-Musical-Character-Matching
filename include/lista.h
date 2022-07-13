#ifndef __LISTA_H__
#define __LISTA_H__

#include"musica.h"

typedef struct caso Caso;
typedef struct lista Lista;
typedef struct celula Celula;

struct caso{

    int tamM;
    int tamT;
    Musica musica;
    Musica trecho;

};

struct celula{

    Caso c;
    Celula* prox;

};

struct lista{

    int tam;
    Celula* primeiro;
    Celula* ultimo;

};

Caso criaI(int, int, Musica, Musica);
int vaziaL(Lista);
void criaL(Lista*);
void insereI(Caso,Lista*);
void retiraI(Celula*, Lista*, Caso*);
void destroiL(Lista*);
void imprimeL(Lista*);

#endif