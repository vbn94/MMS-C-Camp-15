#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

int main(int argc, char **argv, char *env[]){
    /*if(execlp("ls", "ls", "-l", NULL) == -1){
        perror("exec");
    } */
    char *args[] = {"ls", "-l", NULL};
    
    if(execvpe("ls", args, env) == -1){
        perror("exec");
    }
    return 0;
}