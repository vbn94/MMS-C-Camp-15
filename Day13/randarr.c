#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));
    int n;
    scanf("%d", &n);
    int* numbers = malloc(n * sizeof(int));
    if (NULL == numbers){
        fprintf(stderr, "Malloc error\n");
        return EXIT_FAILURE;
    }
    for (int i = 0; i < n; i++){
        numbers[i] = rand() % 10;
    }
    int m;
    scanf("%d", &m);
    numbers = realloc(numbers, sizeof(int) * (n + m));
    if (NULL == numbers){
        fprintf(stderr, "Realloc error\n");
        return EXIT_FAILURE;
    }
    for (int i = n; i < n + m; i++){
        numbers[i] = 10 + rand() % 10;
    }
    int p;
    scanf("%d", &p);
    numbers = realloc(numbers, sizeof(int) * (n + m + p));
    if (NULL == numbers){
        fprintf(stderr, "Realloc error\n");
        return EXIT_FAILURE;
    }
    for (int i = n + m; i < n + m + p; i++){
        numbers[i] = 20 + rand() % 10;
    }

    for (int i = 0; i < n + m + p; i++){
        printf("%d ", numbers[i]);
    }
    putchar('\n');
    free(numbers);
    return 0;
}