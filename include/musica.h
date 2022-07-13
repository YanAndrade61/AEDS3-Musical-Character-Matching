#ifndef __MUSICA_H__
#define __MUSICA_H__

typedef struct nota Nota;
typedef struct musica Fita;
typedef struct musica Musica;

struct nota{

    char nota[3];
    int valor;

};

struct musica{

    int tam;
    Nota* notas;

};

Musica criaM(int tam, char* musica);
int comparar_notas(int musica, int trecho, int* mult, int pos_inicial);
int valorNota(char* nota);
void imprimeM(Musica m);

#endif