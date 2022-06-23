#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>

#define COUNT 100

int number = 0;

void *routine(void* arg){
    sleep(1);
    for (int i = 0; i < 100; i++){
        number++;
    }
}

int main(){
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if(pthread_create(&th[i], NULL, routine, NULL)){
            perror("create");
            exit(EXIT_FAILURE);
        }
    }

    for (int i = 0; i < COUNT; i++){
        if(pthread_join(th[i], NULL)){
            perror("join");
            exit(EXIT_FAILURE);
        }
    }
    printf("Number = %d\n", number);
    return 0;
}