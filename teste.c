#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define size 10

int v[size];

void * function (void *arg){
    int *valor =(int*)(arg);
    int i;
    if (*valor == 1){
        printf("Thread 1 executando ...\n");
        for(i = 0; i < size/2; i++){
            v[i]=1;
        }
    }
    else{
        printf("Thread 2 executando ...\n");
        for(i = size/2; i < size; i++){
            v[i]=2;
        }

    }
}

int main(){

pthread_t t1, t2;
int a1 = 1;
int a2 = 2;
int i;

pthread_create(&t1, NULL, function,(void *)(&a1));
pthread_create(&t2, NULL, function,(void *)(&a2));

pthread_join(t1,NULL);
pthread_join(t2,NULL);

for(i=0;i<size;i++){
    printf("%d",v[i]);
}
printf("\n");



exit(0);

}