#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 3
#define MAX 101
int main(){
    char buff[MAX]; // max 100 chars
    char** names = malloc(N * sizeof(char*));
    
    for (int i = 0; i < N; i++){
        fgets(buff, MAX, stdin);
        buff[strlen(buff) - 1] = '\0';
        int len = strlen(buff);
        names[i] = malloc((len + 1) * sizeof(char));
        strncpy(names[i], buff, len + 1);
    }

    for (int i = 0; i < N; i++){
        printf("Name: %s\n", names[i]);
    }

    for (int i = 0; i < N; i++){
        free(names[i]);
    }
    free(names);
    return EXIT_SUCCESS;
}