#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5
#define M 8

int main(){
    srand(time(NULL));
    int** array = malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++){
       *(array + i) = malloc(M * sizeof(int));
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            array[i][j] = rand() % 10;
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", array[i][j]);
        }
        putchar('\n');
    }

    putchar('\n');
    putchar('\n');

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", i[array][j]);
        }
        putchar('\n');
    }

    putchar('\n');
    putchar('\n');

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            printf("%d ", *(*(array + i) + j));
        }
        putchar('\n');
    }
    // free dyn array
    for (int i = 0; i < N; i++){
        free(array[i]);
    }
    free(array);
    return EXIT_SUCCESS;
}