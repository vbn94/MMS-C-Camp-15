#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>

void *routine1(void* arg){
    for (int i = 0; i < 5; i++){
        printf("Hello\n");
        sleep(1);
    }
}

void *routine2(void* arg){
    for (int i = 0; i < 5; i++){
        printf("MMS C Camp\n");
        sleep(1);
    }
}

int main(){
    pthread_t th1, th2;
    if(pthread_create(&th1, NULL, routine1, NULL)){
        perror("pthread_create");
        return EXIT_FAILURE;
    }
    if(pthread_create(&th2, NULL, routine2, NULL)){
        perror("pthread_create");
        return EXIT_FAILURE;
    }    
    if(pthread_join(th1, NULL)){
        perror("pthread_join");
        return EXIT_FAILURE;
    }
    if(pthread_join(th2, NULL)){
        perror("pthread_join");
        return EXIT_FAILURE;
    }
    return 0;
}