#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>


int main(){
    pid_t pid1 = fork();
    if (-1 == pid1){
        perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid1){
        // child (P2)
        pid_t pid2 = fork();
        if (-1 == pid2){
            perror("fork");
            return EXIT_FAILURE;
        }
        if (0 == pid2){
            // child (P3)
            printf("Hello. I'm P3: PID: %d, PPID, %d\n", getpid(), getppid());
            exit(EXIT_SUCCESS);
        } else {
            // child (P2)
            printf("Hello. I'm P2: PID: %d, PPID, %d\n", getpid(), getppid());
            wait(NULL);
            exit(EXIT_SUCCESS);
        }
        // code

    } else {
        // parent (P1)
        printf("Hello. I'm P1: PID: %d, PPID, %d\n", getpid(), getppid());
        wait(NULL);
    }
    printf("Hello MMS!\n");
    return EXIT_SUCCESS;
}