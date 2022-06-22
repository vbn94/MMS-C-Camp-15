#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

#define COUNT 10

void *routine(void* arg){
    sleep(1);
    printf("MMS C Camp!\n");
}

int main(){
    pthread_t th[COUNT];
    for (int i = 0; i < COUNT; i++){
        if(pthread_create(&th[i], NULL, routine, NULL)){
            perror("create");
            return EXIT_FAILURE;
        }
    }
    for (int i = 0; i < COUNT; i++){
        if(pthread_join(th[i], NULL)){
            perror("join");
            return EXIT_FAILURE;
        }
    }
    return 0;
}