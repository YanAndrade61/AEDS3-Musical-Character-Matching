#ifndef __PARAMS_H__
#define __PARAMS_H__
typedef struct params params_t;

struct params{

    char arq_entrada[200];
    int estrategia;
    int tempo;

};

int passa_args(int , char ** , params_t* );
void obter_tempo(struct timeval ,struct timeval );

#endif