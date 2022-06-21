#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>

#define N 10

int main(){
    for (int i = 0; i < N; i++){
        pid_t pid = fork();
        if (-1 == pid){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid){
            srand(time(NULL) + i);
            // code in child
            int num = rand() % 10;
            for (int i = 0; i < 15; i++){
                printf("My number is %d\n", num);
                sleep(1);
            }
            exit(EXIT_SUCCESS);
        }
    }
    for (int i = 0; i < N; i++){
        wait(NULL);
    }
    return EXIT_SUCCESS;
}