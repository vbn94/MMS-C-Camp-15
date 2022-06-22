#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(){
    printf("Hello!\n");
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        exit(EXIT_FAILURE);
    }
    if (0 == pid){
        // child 1
        sleep(1);
        if(execl("./sum", "./sum", "56", "4", NULL) == -1){
            perror("exec");
        }
    } else {
        pid_t pid2 = fork();
        if (-1 == pid2){
            perror("fork");
            exit(EXIT_FAILURE);
        }
        if (0 == pid2){
            // child 2
            char* args[] = { "./sum", "100", "50", NULL }; 
            if(execv("./sum", args) == -1){
                perror("exec");
            }
        } else {
           // parent
           wait(NULL);
           wait(NULL);
        }
    }


    return 0;
}