#include <stdio.h>
#include <stdlib.h>

int* sum(int a, int b){
    int* s = malloc(sizeof(int));
    *s = a + b;
    return s;
}

int main(){
    int *suma = sum(5, 6);
    printf("Suma = %d\n", *suma);
    free(suma);
    return 0;
}