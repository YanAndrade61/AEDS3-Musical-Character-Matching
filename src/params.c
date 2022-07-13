#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include<sys/resource.h>
#include<sys/time.h>
#include"params.h"

/*Obtem tempo de execucao do programa e o imprime no terminal*/
void obter_tempo(struct timeval inicio,struct timeval fim){

    float tempo_total = 0;
    struct rusage programa;

    tempo_total=(fim.tv_sec - inicio.tv_sec) + 1e-6*(fim.tv_usec - inicio.tv_usec);
    printf("\tTempo total de execucao: %.6f s\n", tempo_total);
    getrusage(0,&programa);
    printf("\tTempo de usuario: %.6lf s.\n",programa.ru_utime.tv_sec + programa.ru_utime.tv_usec*0.000001);
    printf("\tTempo de sistema: %.6lf s.\n",programa.ru_stime.tv_sec + programa.ru_stime.tv_usec*0.000001);

}

/*Verifica e retorna os parametros passados*/
int passa_args(int argc, char **argv, params_t *params)
{
    char c = 0;

    if (!argv || !params || argc < 3)
    {
        fprintf(stderr, "Parse_args : Falta de parametros\n");
        return 0;
    }
    memset(params, 0, sizeof(params_t));
    
    sprintf(params->arq_entrada, "%s", argv[1]);
    
    //Verifica se estrategia é valida
    if (atoi(argv[2]) > 4 || atoi(argv[2]) < 1)
    {
        fprintf(stderr, "Parse_args : Estrategia nao indentificada\n");
        return 0;
    }
    params->estrategia = atoi(argv[2]);
    
    while ((c = getopt(argc, argv, "t")) != -1)
    {
        switch (c)
        {
        case 't': // Imprimir tempo de execucao no terminal
            params->tempo = 1;
            break;
        default:
            printf("Modo de execucao: ./tp3 arquivo-de-entrada.txt <estrategia> -t<tempo exe.>\n");
            return 0;
        }
    }

    if (strlen(params->arq_entrada) == 0)
    {
        fprintf(stderr, "Parse_args : O arquivos de entrada deve ser especificado.\n");
        return 0;
    }
    
    return 1;
}