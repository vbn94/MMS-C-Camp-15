#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid){
        // child
        while (1){
       //     printf("Hello from child!\n");
            sleep(1);
        }
    } else {
        // parent
        while (1){
        //    printf("Hello from parent!\n");
            sleep(2);
        }
        wait(NULL);
    }
    return 0;
}