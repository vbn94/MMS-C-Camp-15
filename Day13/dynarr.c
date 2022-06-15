#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUNT 10

int main(){
    srand(time(NULL));
     //int* array = malloc(sizeof(int) * COUNT);
    int* array = calloc(COUNT, sizeof(int));
    if (NULL == array){
        fprintf(stderr, "Malloc error!\n");
        return EXIT_FAILURE;
    }
    // *array -> array[0], *(array + 1) -> array[1], *(array + 2) = array[2]....
    for (int i = 0; i < COUNT; i++){
        array[i] = rand() % 10;
    }

    
    array = realloc(array, COUNT * 2 * sizeof(int));
    
    for (int i = COUNT; i < COUNT * 2; i++){
        array[i] = rand() % 10;
    }

    for (int i = 0; i < COUNT * 2; i++){
        printf("%d ", array[i]);
    }
    putchar('\n');

    free(array);

    /*int *counters = malloc(sizeof(int) * COUNT);
    for (int i = 0; i < COUNT; i++){
        counters[i] = 0;
    } */
    // int *counters = calloc(COUNT, sizeof(int));
    return 0;
}