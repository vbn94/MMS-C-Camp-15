#include <stdio.h>
#include <stdlib.h>

int* getNum(){
    int* a = malloc(sizeof(int));
    printf("Address of a: %p\n", a);
    *a = 10;
    return a;
}

int main(){
    int *p = getNum();
    printf("Address of p: %p\n", p);
    printf("%d\n", *p);
    free(p);
    /*int* number = malloc(sizeof(int));
    *number = 50;
    printf("%d\n", *number);
    free(number);

    char* sym = malloc(sizeof(char));
    *sym = 'z';
    printf("%c\n", *sym);
    free(sym);*/
    return 0;
}