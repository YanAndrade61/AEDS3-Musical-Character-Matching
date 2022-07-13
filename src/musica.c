#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"musica.h"

/*Cria musica*/
Musica criaM(int tam, char* musica){

    Musica a;
    char* pt;
    
    a.tam = tam;
    a.notas = (Nota*)calloc(tam,sizeof(Nota));
    
    pt = strtok(musica," \n");

    for (int i = 0; i < tam && pt; i++){

        strcpy(a.notas[i].nota,pt);
        a.notas[i].valor = valorNota(pt);
        pt = strtok(NULL," \n");
    }

    return a;

}

/*compara se duas notas são equivalentes e qual a distancia em meios-tons delas*/
int comparar_notas(int musica, int trecho, int* mult, int pos_inicial){
    int s, dif;

    if(musica > trecho){
        dif = musica - trecho;
        s = 1;
    }
    else{
        dif = trecho - musica;
        s = -1;
    }
    if(dif > 6){
       dif = 12-dif;
       s = s * -1;
    }
    if(!pos_inicial){
        if(dif*s == *mult){
            return 1;
        }
        else{
            return 0;
        }
    }

    if(dif == 0 || dif == 1|| dif == 2 || dif == 4){
        *mult = dif * s;
        return 1;
    }
    else{
        *mult = dif * s;
        return 0;
    }
}

/*transforma os caracteres das notas em números*/
int valorNota(char* nota){

    char letra = nota[0];
    char modificacao = '0';
    int valores[]= {1,3,4,6,8,9,11};
    int valor,ind;
    if (strlen(nota) > 1){
        modificacao = nota[1];
    }
    ind = (int)letra % 65;
    valor = valores[ind];

    if (modificacao == '#'){
        valor += 1;
    }
    if (modificacao == 'b'){
        valor -= 1;
    }
    //Caso do Ab
    if(valor < 1){
        valor = 12;
    }

    return valor;

}

/*imprime a musica no terminal*/
void imprimeM(Musica m){

    for (int i = 0; i < m.tam; i++)
    {
        //printf("%s_%d ",m.notas[i].nota,m.notas[i].valor);
        printf("%s ",m.notas[i].nota);
    }
    printf("\n");


};