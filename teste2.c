#include <stdio.h>
#include <pthread.h>
#include <process.h>


pthread_t rotina[2];

typedef struct struct_f2{

    char texto[20];
    float valor;
} struct_f2;


void * rotina_f1( void * p_param)
{
    int x = * ((int *)p_param);

    printf("parametro: %d\n", x);

    for(int i = x; i<5; ++i){

        printf("numero %d id thread: %d\n", i, pthread_self());
        for( int j=0; j< 1000000000; j++){}
    }

    pthread_exit(0);
}

void * rotina_f2(void * p_param){

    struct_f2 * f2 = (struct_f2 *)p_param;
    
    for(int i =0; i <5; ++i){

        printf("Texto %s, valor: %f   id thread: %d\n\n ",f2->texto, f2->valor, pthread_self());

        for(int j=0; j< 2000000000; j++){}
    }
    
    pthread_exit(0);
}

int main(){

    printf("INICIANDO...\n\n");

    int parametro =1;
    struct_f2 f2 = {"TExTO",1.23};

    pthread_create(&rotina[0], NULL, rotina_f1, &parametro);
    pthread_create(&rotina[1], NULL, rotina_f2, &f2);

    printf("id da thread 1: %d\n\n",rotina[0]);
    printf("id da thread 2: %d\n\n",rotina[1]);

    int rc = (int)pthread_join(rotina[0], NULL);
    rc = (int)pthread_join(rotina[1], NULL);

    printf("finalizado com o rc %d\n\n", rc);
}