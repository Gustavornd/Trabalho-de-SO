#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define threads 40

long compartilhada = 0; //memoria compartilhada.
sem_t semaphore;

void *threadfunction (void *arg){

    int a, b;
    for(long j = 0; j < 100000; j ++){
        sem_wait(&semaphore);

        a = compartilhada;
        b = 1;
        compartilhada = a + b; // incremento de 1 ; condição de corrida.

        sem_post(&semaphore);
    }

}

int main(){

    pthread_t t[threads];
    int s;

    sem_init(&semaphore, 0, 1);

    for(int i = 0; i < threads; ++i){
        s = pthread_create(&t[i], NULL, threadfunction, NULL);
    }

    for(int i = 0; i < threads; ++i)
    s =pthread_join(t[i],NULL);

    printf("compartilhada = %ld\n",compartilhada);
}