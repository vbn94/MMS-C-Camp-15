#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void closed(int s){
    printf("STOP!\n");
    exit(EXIT_SUCCESS);
}

int main(){
    struct sigaction sa;
    sa.sa_handler = closed;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGINT, &sa, NULL);
    
    while (1){
        printf("Hello MMS C Camp 15!\n");
        sleep(2);
    }
    return 0;
}