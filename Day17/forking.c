#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(){
    printf("MMS C Camp 15\n");
    fflush(stdout);
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid){
        // code for child
        /*for (int i = 0; i < 5; i++){
            printf("Hello! I'm child process!\n");
            sleep(2);
        }*/
        printf("Child: My PID: %d\n", getpid());
        printf("Child: My PPID: %d\n", getppid());
    } else {
        // code for parent
        /*for (int i = 0; i < 5; i++){
            printf("Hello! I'm parent process!\n");
            sleep(1);
        }*/
        sleep(1);
        printf("Parent: My PID: %d\n", getpid());
        printf("Parent: My child PID: %d\n", pid);
        wait(NULL);
        printf("Bye bye!\n");
    }
    return EXIT_SUCCESS;
}