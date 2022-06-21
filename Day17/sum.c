#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <time.h>


int main(int argc, char** argv){
    int fd[2];
    
    if(pipe(fd) == -1){
        perror("pipe");
        return EXIT_FAILURE;
    }

    pid_t pid = fork();

    if (0 == pid){
        // child
        close(fd[0]);
        int num1, num2, totalChild;
        sscanf(argv[3], "%d", &num1);
        sscanf(argv[4], "%d", &num2);
        totalChild = num1 + num2;
        printf("Sum child: %d\n", totalChild);
        write(fd[1], &totalChild, sizeof(totalChild));
        close(fd[1]);
    } else {
        // parent
        close(fd[1]);
        int num1, num2, totalParent;
        sscanf(argv[1], "%d", &num1);
        sscanf(argv[2], "%d", &num2);
        totalParent = num1 + num2;
        printf("Sum parent: %d\n", totalParent);
        wait(NULL);
        int totalChild;
        read(fd[0], &totalChild, sizeof(totalChild));
        close(fd[0]);
        int total = totalParent + totalChild;
        printf("Total: %d\n", total);
    }

    return EXIT_SUCCESS;
}