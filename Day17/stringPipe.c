#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>
#include <string.h>


int main(int argc, char** argv){

    int fd[2];
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_SUCCESS;
    }
    pid_t pid = fork();

    if (0 == pid){
        // child
        close(fd[0]);
        char *str = "MMS C Camp!\n";
        int len = strlen(str) + 1;
        write(fd[1], &len, sizeof(int));
        write(fd[1], str, strlen(str) + 1);
        close(fd[1]);

    } else {
        // parent
        close(fd[1]);
        char buff[200];
        int n;
        read(fd[0], &n, sizeof(int));
        read(fd[0], buff, n);
        printf("String: %s", buff);
        close(fd[0]);
        wait(NULL);
    }

    return EXIT_SUCCESS;
}