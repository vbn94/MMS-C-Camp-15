#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>

void sayHello(int sig){
    printf("Hello! I'm here!\n");
}

int main(){
    signal(SIGUSR1, sayHello);
    sleep(20);
    return 0;
}