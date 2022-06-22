#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void hint(int s){
    printf("Hint: multiplication first!\n");
}

int main(){
    pid_t pid = fork();
    if (-1 == pid){
        perror("fork");
        return EXIT_FAILURE;
    }
    if (0 == pid){
        // child
        sleep(5);
        kill(getppid() ,SIGUSR1);
    } else {
        //parent
        signal(SIGUSR1, hint);
        printf("5 + 3*2 = ?");
        int num;
        scanf("%d", &num);
        if (11 == num){
            printf("Bravo! Yes!\n");
        } else {
            printf("Error! No!\n");
        }
        kill(SIGTERM, pid);
        wait(NULL);
    }
    return 0;
}