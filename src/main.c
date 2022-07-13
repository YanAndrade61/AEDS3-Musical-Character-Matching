#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/time.h>
#include"entrada.h"
#include"lista.h"
#include"params.h"
#include"forcabruta.h"
#include"bmh.h"
#include"shiftand.h"
#include"kmp.h"


int main(int argc, char **argv){

    Lista l;
    params_t params;
    struct timeval start, end;

    if(!passa_args(argc,argv,&params)){
        return 0;
    }

    if(params.tempo == 1){
        gettimeofday(&start,NULL);
    }
    
    l = entrada(params.arq_entrada);

    switch (params.estrategia)
    {
    case 1:
        cmd_forca_bruta(l);
        break;
    case 2:
        cmd_kmp(l);
        break;
    case 3:
        cmd_bmh(l);
        break;
    case 4:
        cmd_shift_and(l);
        break;
    default:
        break;
    }

    destroiL(&l);
    if(params.tempo == 1){
        gettimeofday(&end,NULL);
        obter_tempo(start,end);
    }


    return 0;
}