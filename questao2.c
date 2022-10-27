#include <stdio.h>
#include <pthread.h>

pthread_t babuino_oeste;

pthread_t babuino_leste;

int corda = 0;

void * passar (int p_param){
    int a = (p_param);

    if(a==1)
        printf("Babuindo pra leste. ->      ");
    else
        printf("Babuindo pra Oeste: ->      ");

    int b = 0;
    b = corda;
    corda = a+b;
    printf("Valor da corda: %d, id da thread: %d\n", corda, pthread_self());
    for(int j =0; j < 1000000000; j++){}

}


int main(){
    int babLeste = 1;
    int babOeste = -1;

    printf("Valor de inicio da corda: %d\n", corda);

    for(int i =0; i< 5; i++)
    {
        pthread_create(&babuino_leste, NULL, passar, babLeste);
        pthread_create(&babuino_oeste, NULL, passar, babOeste);
    }

        pthread_join(babuino_leste,NULL);
        pthread_join(babuino_oeste,NULL);

    printf("Valor final da corda: %d\n", corda);

}