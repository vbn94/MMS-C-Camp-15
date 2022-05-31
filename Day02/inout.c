#include <stdio.h>

int main(){
    char sym;
    while (scanf("%c", &sym) != EOF){
        printf("%c", sym);
    }
    return 0;
}